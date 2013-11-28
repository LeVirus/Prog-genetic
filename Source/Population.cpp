#include "Population.hpp"
#include "Individu.hpp"
#include <iostream>
#include <algorithm>

extern Population *popG;

using namespace std;

Population::Population(unsigned short nombreVille, unsigned short nombreIndividu){
	nbrVille=nombreVille; 
	nbrIndividu=nombreIndividu;
	tabIndividu.resize(nbrIndividu);
	for(itTabInd=tabIndividu.begin();itTabInd<tabIndividu.end();itTabInd++){
		(*itTabInd).initInd(nbrVille);
		//tabIndividu[i].afficherInd();
	}

}

Population::Population(const std::vector<Individu> &vect){
	nbrVille=vect[0].getParcour().size(); 
	nbrIndividu=vect.size();
	tabIndividu.resize(nbrIndividu);
	for(unsigned short i=0;i<tabIndividu.size();++i){
		tabIndividu[i].modifInd(vect[i]);
	}
}

Population::Population(const std::vector<unsigned short> &vect){
	if(popG){
		nbrVille=popG->nbrVille; 
		nbrIndividu=popG->nbrIndividu;
		tabIndividu.resize(popG->nbrIndividu);
		std::vector<Individu> memInd=popG->getVectorInd();

		for(unsigned short i=0;i<tabIndividu.size();++i)
			itTabInd[i]=memInd[ vect[i] ];
	}
}

const std::vector<Individu> Population::getVectorInd(){
	return tabIndividu;
}

void Population::afficherPop(){
	for(itTabInd=tabIndividu.begin();itTabInd<tabIndividu.end();itTabInd++){
		(*itTabInd).afficherInd();
	}
}

Population::~Population(){}

