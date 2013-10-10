#include "Racine.hpp"

using namespace std;

Individu::Individu(){
	tailleTab=0;
}

void Individu::setNbrVille(unsigned short taille){
  if(tailleTab!=0)return;
  tailleTab=taille;
}

void Individu::initInd(){
	unsigned short tmpTaille=tailleTab;
	//unsigned short tabVille[tailleTab];
	unsigned short *tabTmp=new unsigned short[tailleTab];
	parcour=new unsigned short[tailleTab];
  for(short g=0;g<tailleTab;++g){
	 tabTmp[g]=g;
  }

	
	for(unsigned short i=0;i<tailleTab;++i){
		unsigned short stock=rand()%tmpTaille;
		parcour[i]=tabTmp[stock];
		reverseCaseTab(tabTmp[stock], tabTmp[tmpTaille-1]);
		tmpTaille--;
	}
  delete tabTmp;
}

void Individu::reverseCaseTab(unsigned short &a, unsigned short &b){
	if(a==b)return;
	unsigned short tmp=a;
	b=a;
	a=tmp;
}

void Individu::afficherInd(){
	for(unsigned short i=0;i<tailleTab;i++){
	 cout<<parcour[i]<<"   "<<endl;
	}
}

Individu::~Individu(){
	delete parcour;
}

