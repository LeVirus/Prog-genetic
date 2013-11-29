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
	classement.resize(nbrIndividu);
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

void Population::replaceInd(unsigned short pos,const Individu &a){
	if(pos>tabIndividu.size())return;
	tabIndividu[pos].modifInd(a);
}


void Population::replaceIndElit(const Individu &a){
	tabIndividu[ searchClassement( classement.size() ) ].modifInd(a);
}

bool Population::estPresent(float fitness){
	for(unsigned short i=0;i<tabIndividu.size();++i){
		if(tabIndividu[i].getFitness()==fitness)return true;
	}
	return false;
}

unsigned short Population::searchClassement(unsigned short num){
	setClassement();
	if(num>classement.size())return 0;
	for(unsigned short i=0;i<classement.size();++i){
		if(classement[i]==num)return i;
	}
	return 0;
}

void Population::setClassement(){
	unsigned short mem, current=0, cmpt=1; 
	for(unsigned short i=0;i<classement.size();++i)classement[i]=0;
	for(unsigned short i=0;i<tabIndividu.size();++i){
		for(unsigned short j=0;j<tabIndividu.size();++j){
			if(classement[j]==0 && current<tabIndividu[j].getFitness()){
				current=tabIndividu[j].getFitness();
				mem=j;
			}
			classement[mem]=cmpt;
			cmpt++;
		}
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

