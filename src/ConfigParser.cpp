#include "ConfigParser.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cctype>

namespace {
bool ParseBool(const std::string& value) {
    std::string lowered = value;
    std::transform(lowered.begin(), lowered.end(), lowered.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return lowered == "true" || lowered == "1" || lowered == "yes";
}
}

// Simple YAML parser implementation
// For production use, consider yaml-cpp library
class SimpleYAMLParser {
public:
    std::map<std::string, std::string> values;
    std::map<std::string, std::vector<std::string>> lists;
    std::map<std::string, std::map<std::string, std::string>> sections;
    std::map<std::string, std::vector<std::string>> anchors;
    
    bool parse(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error: Cannot open config file: " << filename << std::endl;
            return false;
        }
        
        // First pass: collect all anchors
        std::vector<std::string> lines;
        std::string line;
        while (std::getline(file, line)) {
            lines.push_back(line);
        }
        file.close();
        
        // Parse anchors first
        parseAnchors(lines);
        
        // Second pass: normal parsing with anchor expansion
        std::string current_section = "";
        std::string current_subsection = "";
        std::string current_anchor_key = "";  // Track current anchor being defined
        
        for (const std::string& line_raw : lines) {
            line = line_raw;
            // Check indentation level BEFORE trimming
            size_t indent = 0;
            for (char c : line) {
                if (c == ' ') indent++;
                else break;
            }
            
            // Remove comments and trim whitespace
            size_t comment_pos = line.find('#');
            if (comment_pos != std::string::npos) {
                line = line.substr(0, comment_pos);
            }
            
            // Trim whitespace
            line.erase(0, line.find_first_not_of(" \t"));
            line.erase(line.find_last_not_of(" \t") + 1);
            
            if (line.empty()) continue;
            
            if (indent == 0) {
                // Top level section
                if (line.back() == ':') {
                    std::string section_key = line.substr(0, line.length() - 1);
                    
                    // Check if this is an anchor definition at top level
                    size_t anchor_pos = section_key.find('&');
                    if (anchor_pos != std::string::npos) {
                        current_anchor_key = section_key.substr(anchor_pos + 1);
                        current_anchor_key.erase(0, current_anchor_key.find_first_not_of(" \t"));
                        current_section = section_key.substr(0, anchor_pos);
                        current_section.erase(current_section.find_last_not_of(" \t") + 1);
                        // Clear any existing content for this anchor
                        anchors[current_anchor_key].clear();
                        std::cout << "DEBUG: Found top-level anchor definition '" << current_anchor_key << "' for section '" << current_section << "'" << std::endl;
                    } else {
                        current_section = section_key;
                        current_anchor_key = "";
                    }
                    current_subsection = "";
                }
            } else if (indent <= 2) {
                // Second level
                if (line.back() == ':') {
                    current_subsection = line.substr(0, line.length() - 1);
                    current_subsection.erase(0, current_subsection.find_first_not_of(" \t"));
                    
                    // Check if this is an anchor definition
                    size_t anchor_pos = current_subsection.find('&');
                    if (anchor_pos != std::string::npos) {
                        current_anchor_key = current_subsection.substr(anchor_pos + 1);
                        current_anchor_key.erase(0, current_anchor_key.find_first_not_of(" \t"));
                        current_subsection = current_subsection.substr(0, anchor_pos);
                        current_subsection.erase(current_subsection.find_last_not_of(" \t") + 1);
                        // Clear any existing content for this anchor
                        anchors[current_anchor_key].clear();
                    } else {
                        current_anchor_key = "";
                    }
                } else {
                    parseKeyValue(line, current_section, current_subsection, current_anchor_key);
                }
            } else {
                // Third level or list items
                parseKeyValue(line, current_section, current_subsection, current_anchor_key);
            }
        }
        
        return true;
    }
    
private:
    void parseAnchors(const std::vector<std::string>& lines) {
        std::string current_anchor = "";
        
        for (const std::string& line_raw : lines) {
            std::string line = line_raw;
            
            // Check indentation level BEFORE trimming
            size_t indent = 0;
            for (char c : line) {
                if (c == ' ') indent++;
                else break;
            }
            
            // Remove comments and trim whitespace
            size_t comment_pos = line.find('#');
            if (comment_pos != std::string::npos) {
                line = line.substr(0, comment_pos);
            }
            
            // Trim whitespace
            line.erase(0, line.find_first_not_of(" \t"));
            line.erase(line.find_last_not_of(" \t") + 1);
            
            if (line.empty()) continue;
            
            
            // Look for anchor definitions (pattern: "key: &anchor_name", not list items)
            size_t anchor_pos = line.find('&');
            size_t colon_pos = line.find(':');
            if (anchor_pos != std::string::npos && colon_pos != std::string::npos
                && line.front() != '-' && colon_pos < anchor_pos) {
                // key: &anchor_name pattern — colon precedes ampersand and not a list item
                current_anchor = line.substr(anchor_pos + 1);
                current_anchor.erase(0, current_anchor.find_first_not_of(" \t"));
                current_anchor.erase(current_anchor.find_last_not_of(" \t") + 1);
                // Clear any existing content for this anchor
                anchors[current_anchor].clear();
            } else if (line.back() == ':') {
                current_anchor = "";
            }
            
            if (!current_anchor.empty() && line.front() == '-') {
                // This is a list item for the current anchor
                std::string item = line.substr(1);
                item.erase(0, item.find_first_not_of(" \t"));
                // Remove quotes if present
                if (!item.empty() && ((item.front() == '"' && item.back() == '"') || 
                    (item.front() == '\'' && item.back() == '\''))) {
                    item = item.substr(1, item.length() - 2);
                }
                anchors[current_anchor].push_back(item);
            }
        }
    }
    void parseKeyValue(const std::string& line, const std::string& section, const std::string& subsection, const std::string& current_anchor = "") {
        if (line.front() == '-') {
            // List item
            std::string item = line.substr(1);
            item.erase(0, item.find_first_not_of(" \t"));
            
            // Handle references (*anchor_name)
            if (!item.empty() && item.front() == '*') {
                std::string anchor_name = item.substr(1);
                if (anchors.count(anchor_name)) {
                    // Expand the anchor
                    std::string key = section + (subsection.empty() ? "" : "." + subsection);
                    for (const auto& anchor_item : anchors[anchor_name]) {
                        lists[key].push_back(anchor_item);
                    }
                    return;
                }
            }
            
            // Remove quotes if present
            if (!item.empty() && ((item.front() == '"' && item.back() == '"') || 
                (item.front() == '\'' && item.back() == '\''))) {
                item = item.substr(1, item.length() - 2);
            }
            
            std::string key = section + (subsection.empty() ? "" : "." + subsection);
            lists[key].push_back(item);
            
            // If we're in an anchor definition, also store in anchors
            if (!current_anchor.empty()) {
                anchors[current_anchor].push_back(item);
            }
        } else {
            // Key-value pair
            size_t colon_pos = line.find(':');
            if (colon_pos != std::string::npos) {
                std::string key = line.substr(0, colon_pos);
                std::string value = line.substr(colon_pos + 1);
                
                // Trim whitespace
                key.erase(0, key.find_first_not_of(" \t"));
                key.erase(key.find_last_not_of(" \t") + 1);
                value.erase(0, value.find_first_not_of(" \t"));
                value.erase(value.find_last_not_of(" \t") + 1);
                
                // Check for anchor definition (key: &anchor_name)
                size_t anchor_pos = key.find('&');
                std::string anchor_name = "";
                if (anchor_pos != std::string::npos) {
                    // Extract anchor name
                    anchor_name = key.substr(anchor_pos + 1);
                    anchor_name.erase(0, anchor_name.find_first_not_of(" \t"));
                    // Remove the anchor part from the key
                    key = key.substr(0, anchor_pos);
                    key.erase(key.find_last_not_of(" \t") + 1);
                }
                
                // Handle array notation [item1, item2, ...]
                if (!value.empty() && value.front() == '[' && value.back() == ']') {
                    std::string array_content = value.substr(1, value.length() - 2);
                    std::string full_key = section + (subsection.empty() ? "" : "." + subsection) + "." + key;
                    
                    std::vector<std::string> items;
                    
                    // Split by comma
                    std::stringstream ss(array_content);
                    std::string item;
                    while (std::getline(ss, item, ',')) {
                        // Trim whitespace
                        item.erase(0, item.find_first_not_of(" \t"));
                        item.erase(item.find_last_not_of(" \t") + 1);
                        // Remove quotes
                        if (!item.empty() && ((item.front() == '"' && item.back() == '"') || 
                            (item.front() == '\'' && item.back() == '\''))) {
                            item = item.substr(1, item.length() - 2);
                        }
                        if (!item.empty()) {
                            items.push_back(item);
                            lists[full_key].push_back(item);
                        }
                    }
                    
                    // Store anchor if defined
                    if (!anchor_name.empty()) {
                        anchors[anchor_name].clear();
                        anchors[anchor_name] = items;
                    }
                } else {
                    // Regular key-value pair
                    // Remove quotes if present
                    if (!value.empty() && ((value.front() == '"' && value.back() == '"') || 
                        (value.front() == '\'' && value.back() == '\''))) {
                        value = value.substr(1, value.length() - 2);
                    }
                    
                    std::string full_key = section + (subsection.empty() ? "" : "." + subsection) + "." + key;
                    //std::cout << "full_key " << full_key << std::endl;
                    values[full_key] = value;
                }
            }
        }
    }
};

namespace {
// Run-dependent kinematic vectors from the optional "kinematics:" block, as
// split label -> parameter name -> values. Values keep their YAML text so a
// resolved cut reads exactly as if the number had been written in place.
typedef std::map<std::string, std::map<std::string, std::vector<std::string>>> KinematicTables;

bool IsNumber(const std::string& s) {
    if (s.empty()) return false;
    char* end = nullptr;
    std::strtod(s.c_str(), &end);
    return end == s.c_str() + s.size();
}

// Collects kinematics.<split>.<param>: [v0, v1, ...] entries.
bool ReadKinematicTables(const SimpleYAMLParser& parser, KinematicTables& tables) {
    const std::string prefix = "kinematics.";
    for (const auto& pair : parser.values) {
        if (pair.first.find(prefix) == 0 && (!pair.second.empty() || !parser.lists.count(pair.first))) {
            std::cerr << "Error: kinematics entry '" << pair.first << "' must be an inline array, e.g. [2000, 2600]" << std::endl;
            return false;
        }
    }
    for (const auto& pair : parser.lists) {
        if (pair.first.find(prefix) != 0) continue;
        std::string remainder = pair.first.substr(prefix.size());
        size_t dot_pos = remainder.find('.');
        // "kinematics.<split>" lists are not parameters: SimpleYAMLParser files the
        // items of later top-level anchors (e.g. "bLep00: &bLep00") under the last
        // section.subsection it opened, so they can land here.
        if (dot_pos == std::string::npos) continue;
        if (remainder.find('.', dot_pos + 1) != std::string::npos) {
            std::cerr << "Error: kinematics entry '" << pair.first << "' must be nested as kinematics: <split>: <parameter>: [...]" << std::endl;
            return false;
        }
        std::string split = remainder.substr(0, dot_pos);
        std::string param = remainder.substr(dot_pos + 1);
        for (const auto& value : pair.second) {
            if (!IsNumber(value)) {
                std::cerr << "Error: kinematics." << split << "." << param << " contains non-numeric value '" << value << "'" << std::endl;
                return false;
            }
        }
        tables[split][param] = pair.second;
    }
    return true;
}

// Replaces every ${param[index]} in a cut with the value for this split.
// Cuts without "${" are returned unchanged.
bool ResolveKinematicPlaceholders(const std::string& cut, const std::string& split, const std::string& bin_name,
                                  const KinematicTables& tables, std::string& resolved) {
    resolved.clear();
    size_t pos = 0;
    while (true) {
        size_t start = cut.find("${", pos);
        if (start == std::string::npos) {
            resolved += cut.substr(pos);
            return true;
        }
        resolved += cut.substr(pos, start - pos);

        const std::string context = "bin '" + bin_name + "' (split '" + split + "'), cut \"" + cut + "\"";
        size_t end = cut.find('}', start);
        if (end == std::string::npos) {
            std::cerr << "Error: unterminated placeholder in " << context << std::endl;
            return false;
        }
        std::string placeholder = cut.substr(start, end - start + 1);
        std::string body = cut.substr(start + 2, end - start - 2);

        size_t open = body.find('[');
        bool well_formed = open != std::string::npos && open > 0 && body.back() == ']' && open + 2 < body.size();
        std::string param = well_formed ? body.substr(0, open) : "";
        std::string index_str = well_formed ? body.substr(open + 1, body.size() - open - 2) : "";
        for (char c : param)
            if (!(std::isalnum(static_cast<unsigned char>(c)) || c == '_')) well_formed = false;
        for (char c : index_str)
            if (!std::isdigit(static_cast<unsigned char>(c))) well_formed = false;
        if (!well_formed) {
            std::cerr << "Error: malformed placeholder " << placeholder << " in " << context
                      << "; expected ${parameter[index]}" << std::endl;
            return false;
        }

        if (split.empty()) {
            std::cerr << "Error: placeholder " << placeholder << " in " << context
                      << " requires a split (e.g. samples.split: \"runSplit\") with a matching kinematics block" << std::endl;
            return false;
        }
        auto table = tables.find(split);
        if (table == tables.end()) {
            std::cerr << "Error: placeholder " << placeholder << " in " << context
                      << " but no kinematics." << split << " block is defined" << std::endl;
            return false;
        }
        auto values = table->second.find(param);
        if (values == table->second.end()) {
            std::cerr << "Error: unknown kinematic parameter '" << param << "' in " << placeholder << " for " << context
                      << "; kinematics." << split << " defines:";
            for (const auto& p : table->second) std::cerr << " " << p.first;
            std::cerr << std::endl;
            return false;
        }
        size_t index = index_str.size() > 9 ? values->second.size() : std::stoul(index_str);
        if (index >= values->second.size()) {
            std::cerr << "Error: index " << index_str << " out of range for kinematics." << split << "." << param
                      << " (size " << values->second.size() << ") in " << context << std::endl;
            return false;
        }
        resolved += values->second[index];
        pos = end + 1;
    }
}

// Builds the bins of one split (binsplit "" for no split) from the bins: block,
// resolving kinematic placeholders against that split's table.
bool ResolveBinsForSplit(SimpleYAMLParser& parser, const std::string& binsplit,
                         const KinematicTables& tables, std::vector<BinConfig>& bins) {
    for (const auto& pair : parser.lists) {
        if (pair.first.find("bins.") == 0) {
            std::string full_key = pair.first;
            std::string bin_name;

            // Extract bin name from the key
            size_t bins_pos = full_key.find("bins.");
            if (bins_pos != std::string::npos) {
                std::string remainder = full_key.substr(bins_pos + 5); // Remove "bins."
                size_t dot_pos = remainder.find('.');

                if (dot_pos != std::string::npos) {
                    // Key like "bins.single_bin.cuts" - not used in our format
                    continue;
                } else {
                    // Key like "bins.single_bin" - this is our cuts list
                    bin_name = remainder;
                }
            }
            if(binsplit != "")
                bin_name += "_"+binsplit;

            if (!bin_name.empty()) {
                BinConfig bin_config;
                bin_config.name = bin_name;
                for (const auto& cut : pair.second) {
                    std::string resolved;
                    if (!ResolveKinematicPlaceholders(cut, binsplit, bin_name, tables, resolved))
                        return false;
                    bin_config.cuts.push_back(resolved);
                }

                // Look for description
                std::string desc_key = "bins." + bin_name + ".description";
                if (parser.values.count(desc_key)) {
                    bin_config.description = parser.values[desc_key];
                }

                bins.push_back(bin_config);
            }
        }
    }
    return true;
}
}

ConfigParser::ConfigParser() {
    SetDefaults();
}

ConfigParser::~ConfigParser() {}

void ConfigParser::SetDefaults() {
    config_.name = "default_analysis";
    config_.luminosity = 400.0;
    config_.output_json = "output.json";
    config_.output_dir = "./json/";
    config_.verbosity = 1;
    config_.parallel = false;
    config_.dry_run = false;
	config_.sampleLifetime = -1;
	config_.targetLifetime = -1;
	config_.sampleZrate = -1;
	config_.sampleGrate = -1;
	config_.targetZrate = -1;
	config_.targetGrate = -1;
    config_.mc_closure = false;
    config_.mc_closure_background_mode = "combined";
}

bool ConfigParser::LoadConfig(const std::string& config_file) {
    return LoadYAML(config_file);
}

bool ConfigParser::LoadYAML(const std::string& config_file) {
    SimpleYAMLParser parser;
    
    if (!parser.parse(config_file)) {
        return false;
    }
    
    // Parse analysis section
    if (parser.values.count("analysis.name")) {
        config_.name = parser.values["analysis.name"];
    }
    if (parser.values.count("analysis.luminosity")) {
        config_.luminosity = std::stod(parser.values["analysis.luminosity"]);
    }
    if (parser.values.count("analysis.output_json")) {
        config_.output_json = parser.values["analysis.output_json"];
    }
    if (parser.values.count("analysis.output_dir")) {
        config_.output_dir = parser.values["analysis.output_dir"];
    }
   
	// Get reweighting options
    if ( parser.values.count("lifetimeWeights.sampleLifetime")){
		config_.sampleLifetime = std::stod(parser.values["lifetimeWeights.sampleLifetime"]);
	}
	if ( parser.values.count("lifetimeWeights.targetLifetime")){
        config_.targetLifetime = std::stod(parser.values["lifetimeWeights.targetLifetime"]);
    }
	if ( parser.values.count("decayWeights.sampleZrate")){
        config_.sampleZrate = std::stod(parser.values["decayWeights.sampleZrate"]);
    }
	if ( parser.values.count("decayWeights.sampleGrate")){
        config_.sampleGrate = std::stod(parser.values["decayWeights.sampleGrate"]);
    }
	if ( parser.values.count("decayWeights.targetZrate")){
        config_.targetZrate = std::stod(parser.values["decayWeights.targetZrate"]);
    }
	if ( parser.values.count("decayWeights.targetGrate")){
        config_.targetGrate = std::stod(parser.values["decayWeights.targetGrate"]);
    }    

    // Parse samples
    if (parser.lists.count("samples.backgrounds")) {
        config_.backgrounds = parser.lists["samples.backgrounds"];
    }
    if (parser.lists.count("samples.signals")) {
        config_.signals = parser.lists["samples.signals"];
    }
    if (parser.lists.count("samples.data")) {
    	config_.data = parser.lists["samples.data"];
    }
    if (parser.values.count("samples.split")) {
    	config_.sampleSplit = parser.values["samples.split"];
    }
    else{
    	config_.sampleSplit = "none";
    }
 
    //get years of specified data
    std::vector<std::string> datayrs;
    for(auto data : config_.data){
        datayrs.push_back( data.substr(data.size() - 2) );
    }

 
    //get years of specified signals
    std::vector<std::string> sigyrs;
    for (auto sig : config_.signals){
	if(sig.find("_") != std::string::npos)
        sigyrs.push_back( sig.substr(sig.find("_")+1) );
    }
 
    //parse signal lumis
    double totsiglumi = 0;
    for (const auto& pair : parser.values) {
        if (pair.first.find("sampleLumis.") == 0){
            //if want to change what the year key is or suffix is for sig_YEAR, can change that parsing here
            std::string year = pair.first.substr(pair.first.find(".")+3);
            //make sure year in lumikey is included in signal list
            if(std::count(sigyrs.begin(), sigyrs.end(), year) == 0){
                std::cout << "Signal for year " << year << " not specified. Not setting lumi." << std::endl;
                continue; 
            }
            config_.sigLumi[year] = std::stod(pair.second);
	        totsiglumi += std::stod(pair.second);		
        }
    }
    //if 1+ years specified in lumi dict and 2+ years specified in signal, but their total lumi doesnt add up to the overall lumi, throw warning
    //if no years specified, set sig lumi to overall lumi (same for only 1 year)
    if((config_.sigLumi.size() > 0 || sigyrs.size() > 1) && totsiglumi != config_.luminosity){
	std::string proceed;
        std::cout << "WARNING: Set total luminosity to " << config_.luminosity << " but specified signal year-by-year luminosity is " << totsiglumi << " total." << std::endl;
        std::cout << "Are you sure you want to proceed? y/n" << std::endl;
        std:: cin >> proceed;
        if(proceed != "y")
                return false;
    }

    if (parser.values.count("mc_closure.enabled")) {
        config_.mc_closure = ParseBool(parser.values["mc_closure.enabled"]);
    }
    if (parser.values.count("mc_closure.background_mode")) {
        config_.mc_closure_background_mode = parser.values["mc_closure.background_mode"];
        std::transform(config_.mc_closure_background_mode.begin(), config_.mc_closure_background_mode.end(),
                       config_.mc_closure_background_mode.begin(),
                       [](unsigned char c){ return std::tolower(c); });
    }
    //check split type for bins before making them
    if(std::find(config_.splitTypes.begin(), config_.splitTypes.end(), config_.sampleSplit) == config_.splitTypes.end()){
            std::cerr << "Error: sampleSplit type " << config_.sampleSplit << " is not valid. Please replace with one of the following:";
            for(auto split : config_.splitTypes)
                std::cerr << " " << split;
            std::cerr << std::endl;
            return false; 
    }
   

    std::vector<std::string> binsplits;
    if(config_.sampleSplit == config_.splitTypes[1]){ // year split
        //sorting required for set intersection
        std::sort(datayrs.begin(), datayrs.end());
        std::sort(sigyrs.begin(), sigyrs.end());
        std::set_intersection(datayrs.begin(), datayrs.end(), sigyrs.begin(), sigyrs.end(),std::back_inserter(binsplits));
    }
    else if(config_.sampleSplit == config_.splitTypes[2]){ // run split
        binsplits = {"Run2","Run3"};
    }
    else{ // no split
        binsplits.push_back("");
    }
 
    // Optional run-dependent kinematic vectors referenced by ${param[index]} in cuts
    KinematicTables kinematic_tables;
    if (!ReadKinematicTables(parser, kinematic_tables)) {
        return false;
    }

    // Parse bins
    for(auto binsplit : binsplits){
        if (!ResolveBinsForSplit(parser, binsplit, kinematic_tables, config_.bins)) {
            return false;
        }
    }
    
    // Parse options
    if (parser.values.count("options.verbosity")) {
        config_.verbosity = std::stoi(parser.values["options.verbosity"]);
    }
    if (parser.values.count("options.parallel")) {
        config_.parallel = ParseBool(parser.values["options.parallel"]);
    }
    if (parser.values.count("options.dry_run")) {
        config_.dry_run = ParseBool(parser.values["options.dry_run"]);
    }
    
    return ValidateConfig();
}

std::string ConfigParser::GetCombinedCuts(const std::string& bin_name) const {
    for (const auto& bin : config_.bins) {
        if (bin.name == bin_name) {
            if (bin.cuts.empty()) return "";
            
            std::string combined = "(" + bin.cuts[0] + ")";
            for (size_t i = 1; i < bin.cuts.size(); ++i) {
                combined += " && (" + bin.cuts[i] + ")";
            }
            return combined;
        }
    }
    return "";
}

void ConfigParser::PrintConfig() const {
    std::cout << "=== Analysis Configuration ===" << std::endl;
    std::cout << "Name: " << config_.name << std::endl;
    std::cout << "Luminosity: " << config_.luminosity << " fb^-1" << std::endl;
    std::cout << "Output JSON: " << config_.output_json << std::endl;
    std::cout << "Output Directory: " << config_.output_dir << std::endl;
   	std::cout << "Lifetime Settings-- " << "Sample:"<<config_.sampleLifetime<< " Target:" << config_.targetLifetime << "\n";
	std::cout << "Decay Settings-- " << " Zsample:"<<config_.sampleZrate<< " Gsample:"<<config_.sampleGrate<< " Ztarget:"<<config_.targetZrate<<" Gtarget:"<<config_.targetGrate<<"\n";

    std::cout << "\nBackgrounds: ";
    for (const auto& bg : config_.backgrounds) {
        std::cout << bg << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Signals: ";
    for (const auto& sig : config_.signals) {
        std::cout << sig << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Data: ";
    for (const auto& dat : config_.data) {
	std::cout << dat << " ";
    }
    std::cout << std::endl;
    std::cout << "MC closure: " << (config_.mc_closure ? "true" : "false");
    if (config_.mc_closure) {
        std::cout << " (" << config_.mc_closure_background_mode << " backgrounds)";
    }
    std::cout << std::endl;

    std::cout << "\nAnalysis Bins:" << std::endl;
    for (const auto& bin : config_.bins) {
        std::cout << "  " << bin.name << ": " << bin.description << std::endl;
        std::cout << "    Cuts: " << GetCombinedCuts(bin.name) << std::endl;
    }
    
    std::cout << "\nOptions:" << std::endl;
    std::cout << "  Verbosity: " << config_.verbosity << std::endl;
    std::cout << "  Parallel: " << (config_.parallel ? "true" : "false") << std::endl;
    std::cout << "  Dry run: " << (config_.dry_run ? "true" : "false") << std::endl;
}

bool ConfigParser::ValidateConfig() const {
    if (config_.luminosity <= 0) {
        std::cerr << "Error: Luminosity must be positive" << std::endl;
        return false;
    }
    
    if (config_.backgrounds.empty()) {
        std::cerr << "Warning: No background samples specified" << std::endl;
    }

    if (config_.mc_closure) {
        if (config_.backgrounds.empty()) {
            std::cerr << "Error: MC closure requires at least one background sample" << std::endl;
            return false;
        }
        if (config_.mc_closure_background_mode != "combined" &&
            config_.mc_closure_background_mode != "separate") {
            std::cerr << "Error: mc_closure.background_mode must be 'combined' or 'separate'" << std::endl;
            return false;
        }
    }
    
    if (config_.bins.empty()) {
        std::cerr << "Error: No analysis bins defined" << std::endl;
        return false;
    }
    
    return true;
}
