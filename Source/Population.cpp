#include "Population.hpp"
#include "Individu.hpp"
#include <iostream>
#include <algorithm>

extern Population *popG;

using namespace std;

Population::Population(){}

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
	init(vect);
}


void Population::init(const std::vector<Individu> &vect){
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


void Population::replaceIndElit(const Individu &a, unsigned short place){
	tabIndividu[ searchClassement( place ) ].modifInd(a);
	//chercher l'individu le plus faible et le remplacer
}

bool Population::estPresent(float fitness){
	for(unsigned short i=0;i<tabIndividu.size();++i){
		if(tabIndividu[i].getFitness()==fitness)return true;
	}
	return false;
}

unsigned short Population::searchClassement(unsigned short num){
	setClassement();
cout<<"oyu"<<endl;

	if(num>classement.size())return 0;
	for(unsigned short i=0;i<classement.size();++i){
		if(classement[i]==num){cout<<i<<endl; return i;}
	}
cout<<"ffdf"<<endl;
	return 0;
}

void Population::setClassement(){
	classement.resize(tabIndividu.size());
	unsigned short mem,  cmpt=1; 
	float current;
	for(unsigned short i=0;i<classement.size();++i)classement[i]=0;
	for(unsigned short i=0;i<tabIndividu.size();++i){
		current=0;
		for(unsigned short j=0;j<tabIndividu.size();++j){
			if(classement[j]==0 && current<tabIndividu[j].getFitness()){
				current=tabIndividu[j].getFitness();
				mem=j;
			}
		}
			classement[mem]=cmpt;
			cmpt++;
	}
		cout<<"ffffiiin"<<endl;

}

const std::vector<Individu> Population::getVectorInd(){
	return tabIndividu;
}

void Population::afficherPop(){
	float max;
	for(unsigned short i=0;i<tabIndividu.size();++i){
		tabIndividu[i].afficherInd();
		if(max<tabIndividu[i].getFitness()){
			max=tabIndividu[i].getFitness();
		}
	}
	cout<<"_______________________________fitness max::"<<max<<endl<<endl<<endl<<endl;
}

Population::~Population(){}

