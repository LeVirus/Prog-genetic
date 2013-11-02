#include "Population.hpp"
#include "Individu.hpp"

Population::Population(unsigned short nombreVille, unsigned short nombreIndividu){
	nbrVille=nombreVille; 
	nbrIndividu=nombreIndividu;
	tabIndividu=new Individu[nbrIndividu];
	for(unsigned short i=0;i<nbrIndividu;i++){
		tabIndividu[i].initInd(nbrVille);
	 	tabIndividu[i].afficherInd();
	}
	
}

void Population::afficherPop(){
	if(!tabIndividu)return;
	for(unsigned short i=0;i<nbrIndividu;i++){
	 	tabIndividu[i].afficherInd();
	}
}

Population::~Population(){
	if(tabIndividu)delete tabIndividu;
}

