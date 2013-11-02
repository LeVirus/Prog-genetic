#include "Individu.hpp"
#include <ctime>
#include <iostream>

using namespace std;

Individu::Individu(){
	tailleTab=0;
}

void Individu::initInd(unsigned short taille){
	 if(tailleTab!=0)return;
	 tailleTab=taille;
	 parcour=new unsigned short[tailleTab];
	 for(short g=0;g<tailleTab;++g){
		parcour[g]=g;
	 }

	 
	 for(unsigned short i=tailleTab;i>0;--i){
		unsigned short stock=rand()%i;
		reverseCaseTab(parcour[stock], parcour[i-1]);
		afficherInd();
	 }
}

void Individu::reverseCaseTab(unsigned short &a, unsigned short &b){
	if(a==b)return;
	unsigned short tmp=a;
	a=b;
	b=tmp;
}

void Individu::afficherInd(){
	for(unsigned short i=0;i<tailleTab;i++){
	 cout<<parcour[i]<<"   ";
	}
	cout<<endl;
}

Individu::~Individu(){
	 cout<<"qsdfg"<<endl;
	if(parcour)delete parcour;
}

