#include "OpReproduction.hpp"
#include "OpReplace.hpp"
#include "Carte.hpp"
#include "Population.hpp"
#include <algorithm>
#include <iostream>

extern Population *popG;
extern  Carte *carteG;

using namespace std;

OpReplace::OpReplace(){
}

void OpReplace::remplacementStat(std::vector<unsigned short> &vect,const std::vector<Individu> &newGen){
	for(unsigned short i=0;i<newGen.size();++i){
		popG->replaceInd(vect[i],  newGen[i]);
		cout<<vect[i]<<endl;
	}
}

void OpReplace::remplacementElit(const std::vector<Individu> &newGen){
	unsigned short place=popG->getVectorInd().size();
	for(unsigned short i=0;i<newGen.size();++i){
		popG->replaceIndElit(newGen[i], place);
place--;
	}
}

OpReplace::~OpReplace(){
}
