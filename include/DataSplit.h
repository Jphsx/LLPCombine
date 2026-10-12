#ifndef DATASPLIT_H
#define DATASPLIT_H

// Data-split mode and bin-name utilities shared by BuildFit.
//
// Bin naming convention produced by BuildFitInput:
//
//     <channel><two-character bin index>[_<split label>]
//
//     DelPho_NotBHEarlyCR00          channel DelPho_NotBHEarlyCR, index 00
//     DelPho_NotBHEarlyCR00_Run2     same, split Run2
//
// Channel names may themselves contain underscores, so the split suffix is
// only ever recognized as a trailing "_<label>" with a known label, never by
// searching for the first underscore.

#include <algorithm>
#include <stdexcept>
#include <string>
#include <vector>

namespace DataSplit {

enum class DataSplitMode {
	None,
	Run
};

// Every split label BuildFit can recognize as a bin/parameter suffix.
inline const std::vector<std::string>& KnownSplitLabels(){
	static const std::vector<std::string> labels = {"Run2", "Run3"};
	return labels;
}

// Concrete labels for a mode. The unsplit fit uses a single empty label so
// that split-aware code paths run exactly once with unsuffixed names.
inline std::vector<std::string> SplitLabels(DataSplitMode mode){
	switch(mode){
		case DataSplitMode::Run: return {"Run2", "Run3"};
		case DataSplitMode::None: break;
	}
	return {""};
}

inline DataSplitMode ParseDataSplitMode(const std::string& value){
	if(value.empty() || value == "none")
		return DataSplitMode::None;
	if(value == "run")
		return DataSplitMode::Run;
	throw std::runtime_error("Unsupported datasplit '" + value + "' in fit config; supported values are 'none' and 'run'");
}

inline std::string ModeName(DataSplitMode mode){
	return mode == DataSplitMode::Run ? "run" : "none";
}

inline bool HasSuffix(const std::string& name, const std::string& suffix){
	return name.size() >= suffix.size() && name.compare(name.size() - suffix.size(), suffix.size(), suffix) == 0;
}

// Split label carried by a name ("" if it has no recognized trailing suffix).
inline std::string SplitOf(const std::string& name){
	for(const auto& label : KnownSplitLabels())
		if(HasSuffix(name, "_" + label))
			return label;
	return "";
}

// Name with any recognized trailing split suffix removed.
inline std::string BaseName(const std::string& name){
	std::string split = SplitOf(name);
	if(split.empty())
		return name;
	return name.substr(0, name.size() - split.size() - 1);
}

// Two-character bin index of a (possibly split) bin name.
inline std::string BinIdx(const std::string& bin){
	std::string base = BaseName(bin);
	if(base.size() < 3)
		throw std::runtime_error("Bin name '" + bin + "' is too short to contain a channel and a two-character bin index");
	return base.substr(base.size() - 2);
}

// Channel of a (possibly split) bin name: the base bin without its index.
inline std::string Channel(const std::string& bin){
	std::string base = BaseName(bin);
	BinIdx(base);
	return base.substr(0, base.size() - 2);
}

// Appends "_<split>" to a bin or parameter name. Idempotent for the same split;
// an empty split returns the name unchanged so unsplit fits keep their names.
inline std::string WithSplit(const std::string& name, const std::string& split){
	if(split.empty())
		return name;
	const auto& known = KnownSplitLabels();
	if(std::find(known.begin(), known.end(), split) == known.end())
		throw std::logic_error("Unknown split label '" + split + "'");
	std::string existing = SplitOf(name);
	if(existing == split)
		return name;
	if(!existing.empty())
		throw std::logic_error("Cannot apply split '" + split + "' to '" + name + "', which already carries split '" + existing + "'");
	return name + "_" + split;
}

} // namespace DataSplit

#endif
