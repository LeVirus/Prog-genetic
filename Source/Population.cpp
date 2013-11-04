#include "Population.hpp"
#include "Individu.hpp"
#include <iostream>

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


std::vector<Individu> Population::vectorInd(){
	return tabIndividu;
}

void Population::afficherPop(){
	for(itTabInd=tabIndividu.begin();itTabInd<tabIndividu.end();itTabInd++){
	 	(*itTabInd).afficherInd();
	}
}

Population::~Population(){
}

