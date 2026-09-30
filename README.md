# LLP Combine 
An RDataframe interface to go from TTree skims to combine datacards and fits

### Build instructions
BFI - can work locally just update sample tool constructor prefix accordingly (to find you files)

BFI/BF - designed for el9 on LPC due to constraints from Combine

Local BFI builds just clone and `make`

LPC build
- Use el9 .. so `ssh -Y <username>@cmslpc-el9.fnal.gov`
- We will use the most up to date architectures etc, so your profile/rc should do this:
```
export SCRAM_ARCH=el9_amd64_gcc12
source /cvmfs/cms.cern.ch/cmsset_default.sh
source /cvmfs/cms.cern.ch/crab3/crab.sh
```

The combine version is v10
https://cms-analysis.github.io/HiggsAnalysis-CombinedLimit/latest/#combine-v10-recommended-version

This combine version will use CMSSW 14 and we set it up like usual:
```
cmsrel CMSSW_14_1_0_pre4
cd CMSSW_14_1_0_pre4/src
cmsenv
git -c advice.detachedHead=false clone --depth 1 --branch v10.2.1 https://github.com/cms-analysis/HiggsAnalysis-CombinedLimit.git HiggsAnalysis/CombinedLimit
cd HiggsAnalysis/CombinedLimit
scramv1 b clean; scramv1 b # always make a clean build
```

It may complain about gcc architecture .. we will use the el9 one because it is recommended - this is fine, ignore the message

We also will use combineHarvester for it's datacard automation API,
https://cms-analysis.github.io/CombineHarvester/

Combine harvester  also needs set up in the CMSSW src
```
git clone https://github.com/cms-analysis/CombineHarvester.git CombineHarvester
git checkout v3.0.0-pre1
scram b
```

The RDataframe framework is here,
https://github.com/Jphsx/LLPCombine
Also clone this into the CMSSW src
`git clone git@github.com:Jphsx/LLPCombine.git`


When everything is cloned and scram b'd go into the LLPCombine directory

to make BFI step do `make` to make the BF step do `make cmssw`

the binaries to run are then just `BFI.x` and `BF.x`

### Workflow TLDR;
- main.cpp is where BFI's are set up
  - load all the necessary bkgs and signals from sample tool
  - define strings to create (cut) your signal bin
  - `BFI->ReportRegions(0)` launches the event loop
  - Write the results to a json
- JSON is the intermediate BFI format
  - the JSON mapping is dictionary-like BINNAME[ PROCESS[ YIELDS]]
  - the process are background or signal by name
  - the yields are a vector of 3 quantities, {base_events, weighted_events, statistical_error}
- BFmain.cpp is what sets up datacards
  - define your input json and datacard output directory here
  - additional systematics can be constructed in BuildFit.cpp
  - This BF design avoids shapes templates and ROOT histograms -- we do everything by hand, which is way faster
- running combine macro
  - examples to run/collect limits and significance is in macros folder

### Implementation details and expected conventions

**Expected file formats**
Each file in sample tool will have it's own dataframe, do not combine them. If it has a different cross-section (e.g. HT slice) then it needs it's own data frame because I chose to use a constant weight when propagating statistical error. Typically you might sumW2 object with a histogram but we are avoiding ROOT for the sake of performace, thus the statistical errors are calculated by hand.

**Run2/Run3 split fits (BF fit config)**
A fit config can build one simultaneous likelihood with separate Run2 and Run3 categories:
```yaml
datasplit: run        # or omit / "none" for the unsplit fit
```
- The BFI JSON must be run-split (`samples: split: runSplit` in the analysis config), i.e. every bin exists as `<bin>_Run2` and `<bin>_Run3`. BF stops before building anything if a required bin is missing, and says when the JSON looks unsplit (or split for an unsplit fit config).
- Keep writing unsuffixed bin/channel names in the fit config; BF expands every configured bin to its `_Run2`/`_Run3` categories.
- Shape-transfer norms (`<buoy>Norm_Run2`), ABCD rateParams (`scale_<bin>_Run2`, SR formulas) and template scales are built per run from that run's yields only.
- The signal keeps one process name in both runs, so a single signal strength `r` governs both.
- Configured systematics take `split_correlation`:
  - `uncorrelated` (default when omitted): one nuisance per run, `<name>_Run2` and `<name>_Run3`
  - `correlated`: one nuisance `<name>` shared by the matching Run2 and Run3 bins
  
  In an unsplit fit the field has no effect and the nuisance keeps exactly `<name>`.

**ABCD template processes (BF fit config)**
A process in an ABCD control channel can be templated bin-by-bin from another ABCD channel:
```yaml
ABCD_fit:
  template_processes:
    - source_channel: "DelPho_TightIsoEarlyCR"
      target_channel: "DelPho_NotBHEarlyCR"
      process: "bkgprompt"
      transfer_factor: auto    # or a number, e.g. 0.8
```
Each target bin `i` gets `process` with rate = data yield of source bin `i`, scaled by the rateParam `scale_<target_channel>_<process>` (with a `_Run2`/`_Run3` suffix in a run-split fit) initialized to the transfer factor. `auto` is the smallest target/source data-yield ratio over the target bins (bins where the ratio is undefined are ignored). In a data-driven asimov fit the templated yield is also subtracted from the target channel's ABCD prediction. Any number of entries is allowed; each target bin needs a source bin with the same index.

**Signal file format and naming conventions**
Both BFI and BF expect signals to be 1 file per grid point with the signal name (process name) and mass information in the file name. These get parsed and passed into JSON/datacards with the common tool header `BuildFitTools.h`.

**Event loop design philosophy**
The way we calculate the amount of weighted events in  a bin is by creating the event weight branch in the dataframe and then summing the event weights in that bin. In principle SFs and corrections can be applied in the same way: just add a new branch that creates a new SF weight, multiply evtWt and SFevtwt into a new branch newEvtWt. Now the number of events in the bin will be the sum over newEvtWt branch.

**Obey RDataFrame lazy execution**
The Filters book operations (bin creation) on the dataframe but the result of that operation isn't acquired until an action on the dataframe is executed. Action happens when you dereference a result, triggering the event loop. After the event loop  the result ptrs that hold what you want to filter (or count or sum etc.) will be populated. Don't trigger multiple event loops, the run time will blow up

