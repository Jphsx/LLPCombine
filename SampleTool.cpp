#include "SampleTool.h"



SampleTool::SampleTool(){

//initialize master dictionary
	string pathPrefix = "../RJR_NTuples/batch5/";
	MasterDict["Wjets"] = {pathPrefix+"WJetsToLNu_HT-100To200_R18_IPM100_v24_LLPGskim_v23_rjrvars.root",
							pathPrefix+"WJetsToLNu_HT-1200To2500_R18_IPM100_v24_LLPGskim_v23_rjrvars.root",
							pathPrefix+"WJetsToLNu_HT-200To400_R18_IPM100_v24_LLPGskim_v23_rjrvars.root",
							pathPrefix+"WJetsToLNu_HT-2500ToInf_R18_IPM100_v24_LLPGskim_v23_rjrvars.root",
							pathPrefix+"WJetsToLNu_HT-400To600_R18_IPM100_v24_LLPGskim_v23_rjrvars.root",
							pathPrefix+"WJetsToLNu_HT-600To800_R18_IPM100_v24_LLPGskim_v23_rjrvars.root",
							pathPrefix+"WJetsToLNu_HT-800To1200_R18_IPM100_v24_LLPGskim_v23_rjrvars.root"};
							
	pathPrefix = "../RJR_NTuples/batch5/";
	MasterDict["Zjets"] = {pathPrefix+"ZJetsToNuNu_HT-1200To2500_R18_IPM100_v24_LLPGskim_v23_rjrvars.root",
							pathPrefix+"ZJetsToNuNu_HT-200To400_R18_IPM100_v24_LLPGskim_v23_rjrvars.root",
							pathPrefix+"ZJetsToNuNu_HT-2500ToInf_R18_IPM100_v24_LLPGskim_v23_rjrvars.root",
							pathPrefix+"ZJetsToNuNu_HT-400To600_R18_IPM100_v24_LLPGskim_v23_rjrvars.root",
							pathPrefix+"ZJetsToNuNu_HT-600To800_R18_IPM100_v24_LLPGskim_v23_rjrvars.root",
							pathPrefix+"ZJetsToNuNu_HT-800To1200_R18_IPM100_v24_LLPGskim_v23_rjrvars.root"};
	
	pathPrefix = "../RJR_NTuples/batch5/";
	MasterDict["Top"] = {pathPrefix+"TGJets_R18_IPM100_v24_LLPGskim_v23_rjrvars.root",
						pathPrefix+"TTGJets_R18_IPM100_v24_LLPGskim_v23_rjrvars.root",
						pathPrefix+"TTJets_R18_IPM100_v24_LLPGskim_v23_rjrvars.root",
						pathPrefix+"ttWJets_R18_IPM100_v24_LLPGskim_v23_rjrvars.root",
						pathPrefix+"ttZJets_R18_IPM100_v24_LLPGskim_v23_rjrvars.root"};
	
	pathPrefix = "../RJR_NTuples/batch7/";
	MasterDict["Gjets"] = {pathPrefix+"GJets_HT-100To200_R18_IPM100_v24_LLPGskim_v24_rjrvars.root",
							pathPrefix+"GJets_HT-200To400_R18_IPM100_v25_LLPGskim_v24_rjrvars.root",
							pathPrefix+"GJets_HT-400To600_R18_IPM100_v24_LLPGskim_v24_rjrvars.root",
							pathPrefix+"GJets_HT-40To100_R18_IPM100_v24_LLPGskim_v24_rjrvars.root",
							pathPrefix+"GJets_HT-600ToInf_R18_IPM100_v24_LLPGskim_v24_rjrvars.root"};	

	pathPrefix = "../RJR_NTuples/batch6/";
	MasterDict["gogoG"] = {pathPrefix+"gogoG_Sig_IPM100_v24_SMS-GlGl_AODSIM_mGl-2000_mN2-1000_mN1-1_LLPGskim_v24_rjrvars.root", 
						pathPrefix+"gogoG_Sig_IPM100_v24_SMS-GlGl_AODSIM_mGl-2000_mN2-1900_mN1-250_LLPGskim_v24_rjrvars.root",
						pathPrefix+"gogoG_Sig_IPM100_v24_SMS-GlGl_AODSIM_mGl-2000_mN2-1000_mN1-250_LLPGskim_v24_rjrvars.root",   
						pathPrefix+"gogoG_Sig_IPM100_v24_SMS-GlGl_AODSIM_mGl-2000_mN2-1900_mN1-500_LLPGskim_v24_rjrvars.root",
						pathPrefix+"gogoG_Sig_IPM100_v24_SMS-GlGl_AODSIM_mGl-2000_mN2-1000_mN1-500_LLPGskim_v24_rjrvars.root",  
						pathPrefix+"gogoG_Sig_IPM100_v24_SMS-GlGl_AODSIM_mGl-2000_mN2-1950_mN1-1000_LLPGskim_v24_rjrvars.root",
						pathPrefix+"gogoG_Sig_IPM100_v24_SMS-GlGl_AODSIM_mGl-2000_mN2-1500_mN1-1000_LLPGskim_v24_rjrvars.root",  
						pathPrefix+"gogoG_Sig_IPM100_v24_SMS-GlGl_AODSIM_mGl-2000_mN2-1950_mN1-1500_LLPGskim_v24_rjrvars.root",
						pathPrefix+"gogoG_Sig_IPM100_v24_SMS-GlGl_AODSIM_mGl-2000_mN2-1500_mN1-1_LLPGskim_v24_rjrvars.root",     
						pathPrefix+"gogoG_Sig_IPM100_v24_SMS-GlGl_AODSIM_mGl-2000_mN2-1950_mN1-1900_LLPGskim_v24_rjrvars.root",
						pathPrefix+"gogoG_Sig_IPM100_v24_SMS-GlGl_AODSIM_mGl-2000_mN2-1500_mN1-250_LLPGskim_v24_rjrvars.root",   
						pathPrefix+"gogoG_Sig_IPM100_v24_SMS-GlGl_AODSIM_mGl-2000_mN2-1950_mN1-1_LLPGskim_v24_rjrvars.root",
						pathPrefix+"gogoG_Sig_IPM100_v24_SMS-GlGl_AODSIM_mGl-2000_mN2-1500_mN1-500_LLPGskim_v24_rjrvars.root",   
						pathPrefix+"gogoG_Sig_IPM100_v24_SMS-GlGl_AODSIM_mGl-2000_mN2-1950_mN1-250_LLPGskim_v24_rjrvars.root",
						pathPrefix+"gogoG_Sig_IPM100_v24_SMS-GlGl_AODSIM_mGl-2000_mN2-1900_mN1-1000_LLPGskim_v24_rjrvars.root",  
						pathPrefix+"gogoG_Sig_IPM100_v24_SMS-GlGl_AODSIM_mGl-2000_mN2-1950_mN1-500_LLPGskim_v24_rjrvars.root",
						pathPrefix+"gogoG_Sig_IPM100_v24_SMS-GlGl_AODSIM_mGl-2000_mN2-1900_mN1-1500_LLPGskim_v24_rjrvars.root",  
						pathPrefix+"gogoG_Sig_IPM100_v24_SMS-GlGl_AODSIM_mGl-2000_mN2-500_mN1-1_LLPGskim_v24_rjrvars.root",
						pathPrefix+"gogoG_Sig_IPM100_v24_SMS-GlGl_AODSIM_mGl-2000_mN2-1900_mN1-1_LLPGskim_v24_rjrvars.root",     
						pathPrefix+"gogoG_Sig_IPM100_v24_SMS-GlGl_AODSIM_mGl-2000_mN2-500_mN1-250_LLPGskim_v24_rjrvars.root"};		

}
void SampleTool::LoadBkgs( stringlist& bkglist ){
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



