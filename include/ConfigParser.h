#ifndef CONFIGPARSER_H
#define CONFIGPARSER_H

#include <string>
#include <vector>
#include <map>
#include <memory>

// Data-taking years known to the framework, keyed by their two-digit token
// (MET18, gogoGZ_18 -> "18"), with the run they belong to and their
// integrated luminosity in fb^-1.
namespace LumiMap {

struct YearInfo {
    std::string run;
    double lumi;
};

inline const std::map<std::string, YearInfo>& Years() {
    static const std::map<std::string, YearInfo> years = {
        {"16", {"Run2", 36.32}},
        {"17", {"Run2", 42.01}},
        {"18", {"Run2", 59.50}},
        {"22", {"Run3", 34.12}},
        {"23", {"Run3", 28.27}},
        {"24", {"Run3", 109.82}},
        {"25", {"Run3", 113.67}}
    };
    return years;
}

inline const std::vector<std::string>& Runs() {
    static const std::vector<std::string> runs = {"Run2", "Run3"};
    return runs;
}

inline bool IsKnownYear(const std::string& token) {
    return Years().count(token) > 0;
}

// Run of a known year token, "" otherwise.
inline std::string RunOfYear(const std::string& token) {
    auto it = Years().find(token);
    return it == Years().end() ? "" : it->second.run;
}

inline bool IsKnownRun(const std::string& run) {
    for (const auto& r : Runs())
        if (r == run)
            return true;
    return false;
}

inline double YearLumi(const std::string& token) {
    auto it = Years().find(token);
    return it == Years().end() ? 0. : it->second.lumi;
}

// Data keys end in the year (MET18, DisplacedJet18); "" if it is not a known year.
inline std::string DataYearToken(const std::string& key) {
    if (key.size() < 2)
        return "";
    std::string year = key.substr(key.size() - 2);
    return IsKnownYear(year) ? year : "";
}

// Signal keys carry the year after their last underscore (gogoGZ_18); "" if
// there is no underscore or the suffix is not a known year.
inline std::string SignalYearToken(const std::string& key) {
    std::size_t split_pos = key.rfind("_");
    if (split_pos == std::string::npos || split_pos + 1 >= key.size())
        return "";
    std::string year = key.substr(split_pos + 1);
    return IsKnownYear(year) ? year : "";
}

} // namespace LumiMap

struct BinConfig {
    std::string name;
    std::string description;
    std::vector<std::string> cuts;
};

struct SystematicConfig {
    std::string name;
    std::string type;
    double value;
    std::vector<std::string> processes;
};

struct AnalysisConfig {
    std::string name;
    double luminosity;
    std::string output_json;
    std::string output_dir;

    double sampleLifetime;
    double targetLifetime;
    double sampleZrate;
    double sampleGrate;
    double targetZrate;
    double targetGrate;
    
    std::vector<std::string> backgrounds;
    std::vector<std::string> signals;
    std::vector<std::string> data;

    // signal luminosity per two-digit year token, resolved from the data years
    // and LumiMap (or sampleLumis); signals without a year use `luminosity`
    std::map<std::string, double> sigLumi;
    std::string sampleSplit;    
    std::vector<std::string> splitTypes = {"none","yearSplit","runSplit"};

    bool mc_closure;
    std::string mc_closure_background_mode;
    
    std::vector<BinConfig> bins;
    std::vector<SystematicConfig> systematics;
    
    // Runtime options
    int verbosity;
    bool parallel;
    bool dry_run;
};

class ConfigParser {
public:
    ConfigParser();
    ~ConfigParser();
    
    bool LoadConfig(const std::string& config_file);
    const AnalysisConfig& GetConfig() const { return config_; }
    
    // Utility methods
    std::string GetCombinedCuts(const std::string& bin_name) const;
    void PrintConfig() const;
    bool ValidateConfig() const;
    
private:
    AnalysisConfig config_;
    bool LoadYAML(const std::string& config_file);
    void SetDefaults();
};

#endif
