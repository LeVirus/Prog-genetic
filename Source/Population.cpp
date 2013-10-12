#include "Population.hpp"
#include "Individu.hpp"

Population::Population(unsigned short nombreVille, unsigned short nombreIndividu){
	nbrVille=nombreVille; 
	nbrIndividu=nombreIndividu;
	tabIndividu=new Individu[nombreIndividu];
	for(unsigned short i=0;i<nbrIndividu;i++){
	 	tabIndividu[i].afficherInd();
	}
	
}

void Population::afficherPop(){
	for(unsigned short i=0;i<nbrIndividu;i++){
	 	tabIndividu[i].afficherInd();
	}
}

Population::~Population(){
	delete tabIndividu;
}

