#include "Population.hpp"
#include "Individu.hpp"
#include <iostream>

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

Population::Population(const std::vector<unsigned short> &vect){
	if(popG){
		nbrVille=popG->nbrVille; 
		nbrIndividu=popG->nbrIndividu;
		tabIndividu.resize(popG->nbrIndividu);
	}
	for(itTabInd=tabIndividu.begin();itTabInd<tabIndividu.end();itTabInd++){
		(*itTabInd).initInd(nbrVille);
	}
	std::copy(vect.begin(),vect.end(), tabIndividu.begin());
}

	const std::vector<Individu> &Population::getVectorInd(){
		return tabIndividu;
	}

	void Population::afficherPop(){
		for(itTabInd=tabIndividu.begin();itTabInd<tabIndividu.end();itTabInd++){
			(*itTabInd).afficherInd();
		}
	}

	Population::~Population(){}

