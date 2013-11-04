#include "Individu.hpp"
#include "Carte.hpp"
#include <ctime>
#include <iostream>

using namespace std;

extern Carte *carteG;

Individu::Individu(){
	tailleTab=0;
}

void Individu::initInd(unsigned short taille){
  distanceTotale=0;
  fitness=100000.f;
	 if(tailleTab!=0)return;
	 tailleTab=taille;
	 parcour=new unsigned short[tailleTab];
	 for(short g=0;g<tailleTab;++g){
		parcour[g]=g;
	 }

	 
	 for(unsigned short i=tailleTab;i>0;--i){
		unsigned short stock=rand()%i;
		reverseCaseTab(parcour[stock], parcour[i-1]);
	 }
	 calculFitness();
}

void Individu::reverseCaseTab(unsigned short &a, unsigned short &b){
	if(a==b)return;
	unsigned short tmp=a;
	a=b;
	b=tmp;
}

void Individu::calculFitness(){
  short ii;
	if(!parcour)return;
	for(unsigned short i=0;i<tailleTab;++i){
	  if(i!=tailleTab-1)ii=i+1;
	  else ii=0;//fermer la boucle
		distanceTotale+=carteG->returnDistance(parcour[i], parcour[ii]);
	}
	fitness-=distanceTotale;
}

void Individu::afficherInd(){
	for(unsigned short i=0;i<tailleTab;i++){
	 cout<<parcour[i]<<"   ";
	}
	cout<<endl;
	cout<<"fitness::"<<fitness<<endl<<"distanceTotale::"<<distanceTotale<<endl;
}

Individu::~Individu(){
	if(parcour)delete [] parcour;
}

