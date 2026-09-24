#include "SampleTool.h"



SampleTool::SampleTool(){


	string pathPrefix = "root://cmseos.fnal.gov//store/user/lpcsusylep/malazaro/KUCMSSkims/skims_v52/";

	MasterDict["gogoGZ"] = {pathPrefix+"gogoGZ_mGl-2300_mN2-1300_mN1-1000_ct0p1__SVHPM100_FullMini_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2300_mN2-1300_mN1-1000_ct0p5__SVHPM100_FullMini_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2300_mN2-1600_mN1-1000_ct0p1__SVHPM100_FullMini_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2300_mN2-1600_mN1-1000_ct0p5__SVHPM100_FullMini_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2300_mN2-1600_mN1-500_ct0p1__SVHPM100_FullMini_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2300_mN2-1600_mN1-500_ct0p5__SVHPM100_FullMini_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2300_mN2-2200_mN1-2100_ct0p1__SVHPM100_FullMini_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2300_mN2-2200_mN1-2100_ct0p5__SVHPM100_FullMini_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2300_mN2-2200_mN1-2150_ct0p1__SVHPM100_FullMini_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2300_mN2-2200_mN1-2150_ct0p5__SVHPM100_FullMini_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2300_mN2-2250_mN1-2150_ct0p1__SVHPM100_FullMini_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2300_mN2-2250_mN1-2150_ct0p5__SVHPM100_FullMini_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2300_mN2-2250_mN1-2200_ct0p1__SVHPM100_FullMini_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2300_mN2-2250_mN1-2200_ct0p5__SVHPM100_FullMini_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2500_mN2-1200_mN1-500_ct0p1__SVHPM100_FullMini_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2500_mN2-1200_mN1-500_ct0p5__SVHPM100_FullMini_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2500_mN2-2000_mN1-1000_ct0p1__SVHPM100_FullMini_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2500_mN2-2000_mN1-1000_ct0p5__SVHPM100_FullMini_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2500_mN2-2000_mN1-1500_ct0p1__SVHPM100_FullMini_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2500_mN2-2000_mN1-1500_ct0p5__SVHPM100_FullMini_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2500_mN2-2400_mN1-2300_ct0p1__SVHPM100_FullMini_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2500_mN2-2400_mN1-2300_ct0p5__SVHPM100_FullMini_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2500_mN2-2400_mN1-2350_ct0p1__SVHPM100_FullMini_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2500_mN2-2400_mN1-2350_ct0p5__SVHPM100_FullMini_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2500_mN2-2450_mN1-2350_ct0p1__SVHPM100_FullMini_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2500_mN2-2450_mN1-2350_ct0p5__SVHPM100_FullMini_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2500_mN2-2450_mN1-2400_ct0p1__SVHPM100_FullMini_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2500_mN2-2450_mN1-2400_ct0p5__SVHPM100_FullMini_v37__llpCombineSkim.root"};

	MasterDict["gogoGZ10"] = {pathPrefix+"gogoGZ_mGl-2300_mN2-1300_mN1-1000_ct0p1__SVHPM100_FullMini_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2300_mN2-1600_mN1-1000_ct0p1__SVHPM100_FullMini_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2300_mN2-1600_mN1-500_ct0p1__SVHPM100_FullMini_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2300_mN2-2200_mN1-2100_ct0p1__SVHPM100_FullMini_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2300_mN2-2200_mN1-2150_ct0p1__SVHPM100_FullMini_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2300_mN2-2250_mN1-2150_ct0p1__SVHPM100_FullMini_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2300_mN2-2250_mN1-2200_ct0p1__SVHPM100_FullMini_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2500_mN2-1200_mN1-500_ct0p1__SVHPM100_FullMini_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2500_mN2-2000_mN1-1000_ct0p1__SVHPM100_FullMini_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2500_mN2-2000_mN1-1500_ct0p1__SVHPM100_FullMini_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2500_mN2-2400_mN1-2300_ct0p1__SVHPM100_FullMini_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2500_mN2-2400_mN1-2350_ct0p1__SVHPM100_FullMini_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2500_mN2-2450_mN1-2350_ct0p1__SVHPM100_FullMini_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2500_mN2-2450_mN1-2400_ct0p1__SVHPM100_FullMini_v37__llpCombineSkim.root"};

	MasterDict["gogoGZ50"] = {pathPrefix+"gogoGZ_mGl-2300_mN2-1300_mN1-1000_ct0p5__SVHPM100_FullMini_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2300_mN2-1600_mN1-1000_ct0p5__SVHPM100_FullMini_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2300_mN2-1600_mN1-500_ct0p5__SVHPM100_FullMini_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2300_mN2-2200_mN1-2100_ct0p5__SVHPM100_FullMini_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2300_mN2-2200_mN1-2150_ct0p5__SVHPM100_FullMini_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2300_mN2-2250_mN1-2150_ct0p5__SVHPM100_FullMini_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2300_mN2-2250_mN1-2200_ct0p5__SVHPM100_FullMini_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2500_mN2-1200_mN1-500_ct0p5__SVHPM100_FullMini_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2500_mN2-2000_mN1-1000_ct0p5__SVHPM100_FullMini_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2500_mN2-2000_mN1-1500_ct0p5__SVHPM100_FullMini_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2500_mN2-2400_mN1-2300_ct0p5__SVHPM100_FullMini_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2500_mN2-2400_mN1-2350_ct0p5__SVHPM100_FullMini_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2500_mN2-2450_mN1-2350_ct0p5__SVHPM100_FullMini_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2500_mN2-2450_mN1-2400_ct0p5__SVHPM100_FullMini_v37__llpCombineSkim.root"};


	MasterDict["gogoGZFAST"] = {pathPrefix+"gogoGZ_mGl-2300_mN2-1300_mN1-1000_ct0p1__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2300_mN2-1300_mN1-1000_ct0p5__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2300_mN2-1600_mN1-1000_ct0p1__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2300_mN2-1600_mN1-1000_ct0p5__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2300_mN2-1600_mN1-500_ct0p1__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2300_mN2-1600_mN1-500_ct0p5__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2300_mN2-2200_mN1-2100_ct0p1__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2300_mN2-2200_mN1-2100_ct0p5__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2300_mN2-2200_mN1-2150_ct0p1__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2300_mN2-2200_mN1-2150_ct0p5__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2300_mN2-2250_mN1-2150_ct0p1__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2300_mN2-2250_mN1-2150_ct0p5__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2300_mN2-2250_mN1-2200_ct0p1__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2300_mN2-2250_mN1-2200_ct0p5__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2500_mN2-1200_mN1-500_ct0p1__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2500_mN2-1200_mN1-500_ct0p5__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2500_mN2-2000_mN1-1000_ct0p1__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2500_mN2-2000_mN1-1000_ct0p5__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2500_mN2-2000_mN1-1500_ct0p1__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2500_mN2-2000_mN1-1500_ct0p5__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2500_mN2-2400_mN1-2300_ct0p1__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2500_mN2-2400_mN1-2300_ct0p5__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2500_mN2-2400_mN1-2350_ct0p1__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2500_mN2-2400_mN1-2350_ct0p5__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2500_mN2-2450_mN1-2350_ct0p1__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2500_mN2-2450_mN1-2350_ct0p5__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2500_mN2-2450_mN1-2400_ct0p1__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                        pathPrefix+"gogoGZ_mGl-2500_mN2-2450_mN1-2400_ct0p5__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root"};

	MasterDict["gogoGZFAST10"] = {pathPrefix+"gogoGZ_mGl-2300_mN2-1300_mN1-1000_ct0p1__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2300_mN2-1600_mN1-1000_ct0p1__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2300_mN2-1600_mN1-500_ct0p1__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2300_mN2-2200_mN1-2100_ct0p1__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2300_mN2-2200_mN1-2150_ct0p1__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2300_mN2-2250_mN1-2150_ct0p1__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2300_mN2-2250_mN1-2200_ct0p1__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2500_mN2-1200_mN1-500_ct0p1__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2500_mN2-2000_mN1-1000_ct0p1__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2500_mN2-2000_mN1-1500_ct0p1__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2500_mN2-2400_mN1-2300_ct0p1__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2500_mN2-2400_mN1-2350_ct0p1__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2500_mN2-2450_mN1-2350_ct0p1__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2500_mN2-2450_mN1-2400_ct0p1__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root"};

	MasterDict["gogoGZFAST50"] = {pathPrefix+"gogoGZ_mGl-2300_mN2-1300_mN1-1000_ct0p5__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2300_mN2-1600_mN1-1000_ct0p5__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2300_mN2-1600_mN1-500_ct0p5__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2300_mN2-2200_mN1-2100_ct0p5__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2300_mN2-2200_mN1-2150_ct0p5__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2300_mN2-2250_mN1-2150_ct0p5__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2300_mN2-2250_mN1-2200_ct0p5__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2500_mN2-1200_mN1-500_ct0p5__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2500_mN2-2000_mN1-1000_ct0p5__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2500_mN2-2000_mN1-1500_ct0p5__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2500_mN2-2400_mN1-2300_ct0p5__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2500_mN2-2400_mN1-2350_ct0p5__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2500_mN2-2450_mN1-2350_ct0p5__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root",
                          pathPrefix+"gogoGZ_mGl-2500_mN2-2450_mN1-2400_ct0p5__SVHPM100_Fast1_SxyScaleNominal_v37__llpCombineSkim.root"};
	
	MasterDict["MET16"] = {pathPrefix+"MET_Run2016B-ver1_HIPM_UL2016_MiniAODv2-v2__SVHPM100_MiniAODv2_v34__llpCombineSkim.root",
                	       pathPrefix+"MET_Run2016B-ver2_HIPM_UL2016_MiniAODv2-v2__SVHPM100_MiniAODv2_v34__llpCombineSkim.root",
			       pathPrefix+"MET_Run2016C-HIPM_UL2016_MiniAODv2-v2__SVHPM100_MiniAODv2_v34__llpCombineSkim.root",
			       pathPrefix+"MET_Run2016D-HIPM_UL2016_MiniAODv2-v2__SVHPM100_MiniAODv2_v34__llpCombineSkim.root",
			       pathPrefix+"MET_Run2016E-HIPM_UL2016_MiniAODv2-v2__SVHPM100_MiniAODv2_v34__llpCombineSkim.root",
			       pathPrefix+"MET_Run2016F-HIPM_UL2016_MiniAODv2-v2__SVHPM100_MiniAODv2_v34__llpCombineSkim.root",
			       pathPrefix+"MET_Run2016F-UL2016_MiniAODv2-v2__SVHPM100_MiniAODv2_v34__llpCombineSkim.root",
			       pathPrefix+"MET_Run2016G-UL2016_MiniAODv2-v2__SVHPM100_MiniAODv2_v34__llpCombineSkim.root",
			       pathPrefix+"MET_Run2016H-UL2016_MiniAODv2-v2__SVHPM100_MiniAODv2_v34__llpCombineSkim.root"};

	MasterDict["MET17"] = {pathPrefix+"MET_Run2017B-UL2017_MiniAODv2-v1__SVHPM100_MiniAODv2_v34__llpCombineSkim.root",
	                       pathPrefix+"MET_Run2017C-UL2017_MiniAODv2-v1__SVHPM100_MiniAODv2_v34__llpCombineSkim.root",
			       pathPrefix+"MET_Run2017D-UL2017_MiniAODv2-v1__SVHPM100_MiniAODv2_v34__llpCombineSkim.root",
			       pathPrefix+"MET_Run2017E-UL2017_MiniAODv2-v1__SVHPM100_MiniAODv2_v34__llpCombineSkim.root",
			       pathPrefix+"MET_Run2017F-UL2017_MiniAODv2-v1__SVHPM100_MiniAODv2_v34__llpCombineSkim.root"};

	MasterDict["MET18"] = {pathPrefix+"MET_Run2018A-UL2018_MiniAODv2_GT36-v1__SVHPM100_MiniAODv2_v34__llpCombineSkim.root",
	                       pathPrefix+"MET_Run2018B-UL2018_MiniAODv2_GT36-v1__SVHPM100_MiniAODv2_v34__llpCombineSkim.root",
			       pathPrefix+"MET_Run2018C-UL2018_MiniAODv2_GT36-v1__SVHPM100_MiniAODv2_v34__llpCombineSkim.root",
			       pathPrefix+"MET_Run2018D-UL2018_MiniAODv2_GT36-v1__SVHPM100_MiniAODv2_v34__llpCombineSkim.root"};

	
	MasterDict["MET22"] = {pathPrefix+"JetMET_Run2022C-19Dec2023-v1__SVHPM100_v34__llpCombineSkim.root",
                               pathPrefix+"JetMET_Run2022D-19Dec2023-v1__SVHPM100_v34__llpCombineSkim.root",
                               pathPrefix+"JetMET_Run2022E-19Dec2023-v1__SVHPM100_v34__llpCombineSkim.root",
                               pathPrefix+"JetMET_Run2022F-19Dec2023-v2__SVHPM100_v34__llpCombineSkim.root",
                               pathPrefix+"JetMET_Run2022G-19Dec2023-v1__SVHPM100_v34_PixSeedFix__llpCombineSkim.root"};

	MasterDict["MET23"] = {pathPrefix+"JetMET0_Run2023B-19Dec2023-v1__SVHPM100_v34_PixSeedFix__llpCombineSkim.root",
	                       pathPrefix+"JetMET0_Run2023C-19Dec2023-v1__SVHPM100_v34_PixSeedFix__llpCombineSkim.root",
			       pathPrefix+"JetMET0_Run2023D-19Dec2023-v1__SVHPM100_v34_PixSeedFix__llpCombineSkim.root",
			       pathPrefix+"JetMET1_Run2023B-19Dec2023-v1__SVHPM100_v34_PixSeedFix__llpCombineSkim.root",
			       pathPrefix+"JetMET1_Run2023C-19Dec2023-v1__SVHPM100_v34_PixSeedFix__llpCombineSkim.root",
			       pathPrefix+"JetMET1_Run2023D-19Dec2023-v1__SVHPM100_v34_PixSeedFix__llpCombineSkim.root"};

	MasterDict["MET24"] = {pathPrefix+"JetMET0_Run2024C-MINIv6NANOv15-v1__SVHPM100_v34__llpCombineSkim.root",
	                       pathPrefix+"JetMET0_Run2024D-MINIv6NANOv15-v1__SVHPM100_v34__llpCombineSkim.root",
			       pathPrefix+"JetMET0_Run2024E-MINIv6NANOv15-v1__SVHPM100_v34__llpCombineSkim.root",
			       pathPrefix+"JetMET0_Run2024F-MINIv6NANOv15-v2__SVHPM100_v34__llpCombineSkim.root",
			       pathPrefix+"JetMET0_Run2024G-MINIv6NANOv15-v2__SVHPM100_v34__llpCombineSkim.root",
			       pathPrefix+"JetMET0_Run2024H-MINIv6NANOv15-v2__SVHPM100_v34__llpCombineSkim.root",
			       pathPrefix+"JetMET0_Run2024I-MINIv6NANOv15-v2__SVHPM100_v34__llpCombineSkim.root",
			       pathPrefix+"JetMET0_Run2024I-MINIv6NANOv15_v2-v1__SVHPM100_v34__llpCombineSkim.root",
			       pathPrefix+"JetMET1_Run2024C-MINIv6NANOv15-v1__SVHPM100_v34__llpCombineSkim.root",
			       pathPrefix+"JetMET1_Run2024D-MINIv6NANOv15-v1__SVHPM100_v34__llpCombineSkim.root",
			       pathPrefix+"JetMET1_Run2024E-MINIv6NANOv15-v1__SVHPM100_v34__llpCombineSkim.root",
			       pathPrefix+"JetMET1_Run2024F-MINIv6NANOv15-v2__SVHPM100_v34__llpCombineSkim.root",
			       pathPrefix+"JetMET1_Run2024G-MINIv6NANOv15-v2__SVHPM100_v34__llpCombineSkim.root",
			       pathPrefix+"JetMET1_Run2024H-MINIv6NANOv15-v2__SVHPM100_v34__llpCombineSkim.root",
			       pathPrefix+"JetMET1_Run2024I-MINIv6NANOv15-v1__SVHPM100_v34__llpCombineSkim.root",
			       pathPrefix+"JetMET1_Run2024I-MINIv6NANOv15_v2-v2__SVHPM100_v34__llpCombineSkim.root"};
	
	MasterDict["MET25"] = {pathPrefix+"kucmsntuple_JetMET_R25_SVHPM100_v34_JetMET0_Run2025C__SVHPM100_v34__llpCombineSkim.root",
	                       pathPrefix+"kucmsntuple_JetMET_R25_SVHPM100_v34_JetMET0_Run2025Cv1__SVHPM100_v34__llpCombineSkim.root",
			       pathPrefix+"kucmsntuple_JetMET_R25_SVHPM100_v34_JetMET0_Run2025Cv2__SVHPM100_v34__llpCombineSkim.root",
			       pathPrefix+"kucmsntuple_JetMET_R25_SVHPM100_v34_JetMET0_Run2025E__SVHPM100_v34__llpCombineSkim.root",
			       pathPrefix+"kucmsntuple_JetMET_R25_SVHPM100_v34_JetMET0_Run2025F__SVHPM100_v34__llpCombineSkim.root",
			       pathPrefix+"kucmsntuple_JetMET_R25_SVHPM100_v34_JetMET0_Run2025Fv2__SVHPM100_v34__llpCombineSkim.root",
			       pathPrefix+"kucmsntuple_JetMET_R25_SVHPM100_v34_JetMET1_Run2025Cv1__SVHPM100_v34__llpCombineSkim.root",
			       pathPrefix+"kucmsntuple_JetMET_R25_SVHPM100_v34_JetMET1_Run2025Cv2__SVHPM100_v34__llpCombineSkim.root",
			       pathPrefix+"JetMET0_Run2025D-PromptReco-v1__SVHPM100_v34__llpCombineSkim.root",
			       pathPrefix+"JetMET1_Run2025D-PromptReco-v1__SVHPM100_v34__llpCombineSkim.root",
			       pathPrefix+"JetMET1_Run2025E-PromptReco-v1__SVHPM100_v34__llpCombineSkim.root",
			       pathPrefix+"JetMET1_Run2025F-PromptReco-v1__SVHPM100_v34__llpCombineSkim.root",
			       pathPrefix+"JetMET1_Run2025Fv2__SVHPM100_v34__llpCombineSkim.root",
			       pathPrefix+"JetMET1_Run2025G-PromptReco-v1__SVHPM100_v34__llpCombineSkim.root"};
	
	pathPrefix = "root://cmseos.fnal.gov//store/user/lpcsusylep/malazaro/KUCMSSkims/skims_v49/";
	MasterDict["Wjets"] = {pathPrefix+"WJets_R18_SVIPM100_MiniAOD_v34_WJetsToLNu_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8_rjrskim.root",
				pathPrefix+"WJets_R18_SVIPM100_MiniAOD_v34_WJetsToLNu_HT-1200To2500_TuneCP5_13TeV-madgraphMLM-pythia8_rjrskim.root",
				pathPrefix+"WJets_R18_SVIPM100_MiniAOD_v34_WJetsToLNu_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8_rjrskim.root",
				pathPrefix+"WJets_R18_SVIPM100_MiniAOD_v34_WJetsToLNu_HT-2500ToInf_TuneCP5_13TeV-madgraphMLM-pythia8_rjrskim.root",
				pathPrefix+"WJets_R18_SVIPM100_MiniAOD_v34_WJetsToLNu_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8_rjrskim.root",
				pathPrefix+"WJets_R18_SVIPM100_MiniAOD_v34_WJetsToLNu_HT-600To800_TuneCP5_13TeV-madgraphMLM-pythia8_rjrskim.root",
				pathPrefix+"WJets_R18_SVIPM100_MiniAOD_v34_WJetsToLNu_HT-70To100_TuneCP5_13TeV-madgraphMLM-pythia8_rjrskim.root",
				pathPrefix+"WJets_R18_SVIPM100_MiniAOD_v34_WJetsToLNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8_rjrskim.root"};		
			

	MasterDict["Zjets"] = {pathPrefix+"ZJets_R18_SVIPM100_MiniAOD_v34_ZJetsToNuNu_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8_rjrskim.root",
				pathPrefix+"ZJets_R18_SVIPM100_MiniAOD_v34_ZJetsToNuNu_HT-1200To2500_TuneCP5_13TeV-madgraphMLM-pythia8_rjrskim.root",
				pathPrefix+"ZJets_R18_SVIPM100_MiniAOD_v34_ZJetsToNuNu_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8_rjrskim.root",
				pathPrefix+"ZJets_R18_SVIPM100_MiniAOD_v34_ZJetsToNuNu_HT-2500ToInf_TuneCP5_13TeV-madgraphMLM-pythia8_rjrskim.root",
				pathPrefix+"ZJets_R18_SVIPM100_MiniAOD_v34_ZJetsToNuNu_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8_rjrskim.root",
				pathPrefix+"ZJets_R18_SVIPM100_MiniAOD_v34_ZJetsToNuNu_HT-600To800_TuneCP5_13TeV-madgraphMLM-pythia8_rjrskim.root",
				pathPrefix+"ZJets_R18_SVIPM100_MiniAOD_v34_ZJetsToNuNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8_rjrskim.root"};


	MasterDict["Top"] = {pathPrefix+"TTJets_R18_SVIPM100_MiniAOD_v34_TTJets_TuneCP5_13TeV-madgraphMLM-pythia8_rjrskim.root"};
						 
	MasterDict["Gjets"] = {pathPrefix+"GJets_R18_SVHPM100_MiniAOD_v2_v34_GJets_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8_rjrskim.root",
				pathPrefix+"GJets_R18_SVHPM100_MiniAOD_v2_v34_GJets_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8_rjrskim.root",
				pathPrefix+"GJets_R18_SVHPM100_MiniAOD_v2_v34_GJets_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8_rjrskim.root",
				pathPrefix+"GJets_R18_SVHPM100_MiniAOD_v2_v34_GJets_HT-40To100_TuneCP5_13TeV-madgraphMLM-pythia8_rjrskim.root",
				pathPrefix+"GJets_R18_SVHPM100_MiniAOD_v2_v34_GJets_HT-600ToInf_TuneCP5_13TeV-madgraphMLM-pythia8_rjrskim.root"};
	

	MasterDict["QCD"] = {pathPrefix+"QCD_R18_SVIPM100_MiniAOD_v34_QCD_HT1000to1500_TuneCP5_13TeV-madgraphMLM-pythia8_rjrskim.root",
				pathPrefix+"QCD_R18_SVIPM100_MiniAOD_v34_QCD_HT100to200_TuneCP5_13TeV-madgraphMLM-pythia8_rjrskim.root",
				pathPrefix+"QCD_R18_SVIPM100_MiniAOD_v34_QCD_HT1500to2000_TuneCP5_13TeV-madgraphMLM-pythia8_rjrskim.root",
				pathPrefix+"QCD_R18_SVIPM100_MiniAOD_v34_QCD_HT2000toInf_TuneCP5_13TeV-madgraphMLM-pythia8_rjrskim.root",
				pathPrefix+"QCD_R18_SVIPM100_MiniAOD_v34_QCD_HT200to300_TuneCP5_13TeV-madgraphMLM-pythia8_rjrskim.root",
				pathPrefix+"QCD_R18_SVIPM100_MiniAOD_v34_QCD_HT300to500_TuneCP5_13TeV-madgraphMLM-pythia8_rjrskim.root",
				pathPrefix+"QCD_R18_SVIPM100_MiniAOD_v34_QCD_HT500to700_TuneCP5_13TeV-madgraphMLM-pythia8_rjrskim.root",
				pathPrefix+"QCD_R18_SVIPM100_MiniAOD_v34_QCD_HT50to100_TuneCP5_13TeV-madgraphMLM-pythia8_rjrskim.root",
				pathPrefix+"QCD_R18_SVIPM100_MiniAOD_v34_QCD_HT700to1000_TuneCP5_13TeV-madgraphMLM-pythia8_rjrskim.root"};	
						 
	pathPrefix = "root://cmseos.fnal.gov//store/user/lpcsusylep/malazaro/KUCMSSkims/skims_v46/";
	MasterDict["DB"] = {pathPrefix+"WZ_R18_IPM100_v24_LLPGskim_v24_rjrvars.root"};

	MasterDict["Box"] = {pathPrefix+"DiPJBox_R18_SVIPM100_v31_DiPhotonJetsBox_M40_80-sherpa_rjrskim.root",
				pathPrefix+"DiPJBox_R18_SVIPM100_v31_DiPhotonJetsBox_MGG-0to40_rjrskim.root",
				pathPrefix+"DiPJBox_R18_SVIPM100_v31_DiPhotonJetsBox_MGG-80toInf_rjrskim.root"};	

	MasterDict["gogoG"] = {pathPrefix+"SMS_SVIPM100_v31_gogoG_AODSIM_mGl-1500_mN2-500_mN1-100_ct0p1_rjrskim.root",
				pathPrefix+"SMS_SVIPM100_v31_gogoG_AODSIM_mGl-2000_mN2-1000_mN1-1_ct0p1_rjrskim.root",
				pathPrefix+"SMS_SVIPM100_v31_gogoG_AODSIM_mGl-2000_mN2-1000_mN1-250_ct0p1_rjrskim.root",	
				pathPrefix+"SMS_SVIPM100_v31_gogoG_AODSIM_mGl-2000_mN2-1000_mN1-500_ct0p1_rjrskim.root", 
				pathPrefix+"SMS_SVIPM100_v31_gogoG_AODSIM_mGl-2000_mN2-1500_mN1-1000_ct0p1_rjrskim.root",
				pathPrefix+"SMS_SVIPM100_v31_gogoG_AODSIM_mGl-2000_mN2-1500_mN1-1_ct0p1_rjrskim.root",   
				pathPrefix+"SMS_SVIPM100_v31_gogoG_AODSIM_mGl-2000_mN2-1500_mN1-250_ct0p1_rjrskim.root", 
				pathPrefix+"SMS_SVIPM100_v31_gogoG_AODSIM_mGl-2000_mN2-1500_mN1-500_ct0p1_rjrskim.root", 
				pathPrefix+"SMS_SVIPM100_v31_gogoG_AODSIM_mGl-2000_mN2-1900_mN1-1000_ct0p1_rjrskim.root",
				pathPrefix+"SMS_SVIPM100_v31_gogoG_AODSIM_mGl-2000_mN2-1900_mN1-1500_ct0p1_rjrskim.root",
				pathPrefix+"SMS_SVIPM100_v31_gogoG_AODSIM_mGl-2000_mN2-1900_mN1-1_ct0p1_rjrskim.root",   
				pathPrefix+"SMS_SVIPM100_v31_gogoG_AODSIM_mGl-2000_mN2-1900_mN1-250_ct0p1_rjrskim.root", 
				pathPrefix+"SMS_SVIPM100_v31_gogoG_AODSIM_mGl-2000_mN2-1900_mN1-500_ct0p1_rjrskim.root", 
				pathPrefix+"SMS_SVIPM100_v31_gogoG_AODSIM_mGl-2000_mN2-1950_mN1-1000_ct0p1_rjrskim.root",
				pathPrefix+"SMS_SVIPM100_v31_gogoG_AODSIM_mGl-2000_mN2-1950_mN1-1500_ct0p1_rjrskim.root",
				pathPrefix+"SMS_SVIPM100_v31_gogoG_AODSIM_mGl-2000_mN2-1950_mN1-1900_ct0p1_rjrskim.root",
				pathPrefix+"SMS_SVIPM100_v31_gogoG_AODSIM_mGl-2000_mN2-1950_mN1-1_ct0p1_rjrskim.root",   
				pathPrefix+"SMS_SVIPM100_v31_gogoG_AODSIM_mGl-2000_mN2-1950_mN1-250_ct0p1_rjrskim.root", 
				pathPrefix+"SMS_SVIPM100_v31_gogoG_AODSIM_mGl-2000_mN2-1950_mN1-500_ct0p1_rjrskim.root", 
				pathPrefix+"SMS_SVIPM100_v31_gogoG_AODSIM_mGl-2000_mN2-500_mN1-1_ct0p1_rjrskim.root",    
				pathPrefix+"SMS_SVIPM100_v31_gogoG_AODSIM_mGl-2000_mN2-500_mN1-250_ct0p1_rjrskim.root",  
				pathPrefix+"SMS_SVIPM100_v31_gogoG_AODSIM_mGl-2500_mN2-1500_mN1-1000_ct0p1_rjrskim.root"};
						   
	MasterDict["gogoZ"] = {	pathPrefix+"SMS_SVIPM100_v31_gogoZ_AODSIM_mGl-1500_mN2-500_mN1-100_ct0p1_rjrskim.root",
				pathPrefix+"SMS_SVIPM100_v31_gogoZ_AODSIM_mGl-2000_mN2-1900_mN1-200_ct0p001_rjrskim.root",
				pathPrefix+"SMS_SVIPM100_v31_gogoZ_AODSIM_mGl-2000_mN2-1900_mN1-200_ct0p1_rjrskim.root",
				pathPrefix+"SMS_SVIPM100_v31_gogoZ_AODSIM_mGl-2000_mN2-1900_mN1-200_ct0p3_rjrskim.root",
				pathPrefix+"SMS_SVIPM100_v31_gogoZ_AODSIM_mGl-2000_mN2-1900_mN1-350_ct0p001_rjrskim.root",
				pathPrefix+"SMS_SVIPM100_v31_gogoZ_AODSIM_mGl-2000_mN2-1900_mN1-350_ct0p1_rjrskim.root",
				pathPrefix+"SMS_SVIPM100_v31_gogoZ_AODSIM_mGl-2000_mN2-1900_mN1-350_ct0p3_rjrskim.root",
				pathPrefix+"SMS_SVIPM100_v31_gogoZ_AODSIM_mGl-2000_mN2-1950_mN1-1900_ct0p1_rjrskim.root",
				pathPrefix+"SMS_SVIPM100_v31_gogoZ_AODSIM_mGl-2000_mN2-400_mN1-200_ct0p001_rjrskim.root",
				pathPrefix+"SMS_SVIPM100_v31_gogoZ_AODSIM_mGl-2000_mN2-400_mN1-200_ct0p1_rjrskim.root",
				pathPrefix+"SMS_SVIPM100_v31_gogoZ_AODSIM_mGl-2000_mN2-400_mN1-200_ct0p3_rjrskim.root",
				pathPrefix+"SMS_SVIPM100_v31_gogoZ_AODSIM_mGl-2000_mN2-400_mN1-350_ct0p001_rjrskim.root",
				pathPrefix+"SMS_SVIPM100_v31_gogoZ_AODSIM_mGl-2000_mN2-400_mN1-350_ct0p1_rjrskim.root",
				pathPrefix+"SMS_SVIPM100_v31_gogoZ_AODSIM_mGl-2000_mN2-400_mN1-350_ct0p3_rjrskim.root"};


	MasterDict["sqsqG"] = { pathPrefix+"SMS_SVIPM100_v31_sqsqG_AODSIM_mGl-1700_mN2-1500_mN1-100_ct0p1_rjrskim_v43.root",
				pathPrefix+"SMS_SVIPM100_v31_sqsqG_AODSIM_mGl-1700_mN2-300_mN1-100_ct0p1_rjrskim_v43.root",
				pathPrefix+"SMS_SVIPM100_v31_sqsqG_AODSIM_mGl-1850_mN2-1650_mN1-100_ct0p1_rjrskim_v43.root",
				pathPrefix+"SMS_SVIPM100_v31_sqsqG_AODSIM_mGl-1850_mN2-300_mN1-100_ct0p1_rjrskim_v43.root",
				pathPrefix+"SMS_SVIPM100_v31_sqsqG_AODSIM_mGl-2000_mN2-1800_mN1-100_ct0p1_rjrskim_v43.root",
				pathPrefix+"SMS_SVIPM100_v31_sqsqG_AODSIM_mGl-2000_mN2-300_mN1-100_ct0p1_rjrskim_v43.root",
				pathPrefix+"SMS_SVIPM100_v31_sqsqG_AODSIM_mGl-2150_mN2-1950_mN1-100_ct0p1_rjrskim_v43.root",
				pathPrefix+"SMS_SVIPM100_v31_sqsqG_AODSIM_mGl-2150_mN2-300_mN1-100_ct0p1_rjrskim_v43.root"};
 


}
void SampleTool::LoadBkgs( stringlist& bkglist ){
	// Clear any existing background dictionary
	BkgDict.clear();
	
	for( long unsigned int i=0; i<bkglist.size(); i++){
		//check if background exists
		if( MasterDict.count(bkglist[i]) == 0 ){
			std::cout<<"Bkg: "<<bkglist[i]<<" not found ... skipping ...\n";
			continue;
		} 
		BkgDict[bkglist[i]] = MasterDict[bkglist[i]];		
	}
}
void SampleTool::LoadSigs( stringlist& siglist ){
	// Clear any existing signal dictionary and keys
	SigDict.clear();
	SignalKeys.clear();
	//TODO - add check that if no year is specified for signal, all years are included
	for( long unsigned int i=0; i<siglist.size(); i++){
		if( MasterDict.count(siglist[i]) == 0 ){
			std::cout<<"Sig: "<<siglist[i]<<" not found ... skipping ...\n";
			continue;
		}
		SigDict[siglist[i]] = MasterDict[siglist[i]];
	}
	//build signal keys
	stringlist s_strings{};
	for(long unsigned int i=0; i<siglist.size(); i++){
		std::vector< std::string > keylist{};
		s_strings = SigDict[siglist[i]];
		for( long unsigned int j=0; j< s_strings.size(); j++){
			//keylist.push_back( GetSignalTokens( s_strings[j] ) );
			SignalKeys.push_back( BFTool::GetSignalTokens( s_strings[j] ) );
		}
	}
}
void SampleTool::LoadData( stringlist& datalist ){
	for( long unsigned int i=0; i<datalist.size(); i++){
		//check if data exists
		if( MasterDict.count(datalist[i]) == 0 ){
			std::cout<<"Data sample: "<<datalist[i]<<" not found ... skipping ...\n";
			continue;
		} 
		DataDict[datalist[i]] = MasterDict[datalist[i]];		
	}
}
void SampleTool::PrintDict( map<string,stringlist>& d ){
	for(auto it = d.cbegin(); it != d.cend(); ++it){
    	std::cout << "key:"<< it->first << ":\n";
    	stringlist str = it->second;
    	for (std::vector<string>::iterator it2 = str.begin(); it2 != str.end(); ++it2) {
        std::cout << *it2 << " \n";
    	}
    	
	}
	std::cout<<"\n";
	
}

void SampleTool::PrintKeys( stringlist sl ){
	
	for( long unsigned int i = 0; i<sl.size(); i++){
		std::cout<<sl[i]<<"\n";
	}

}


