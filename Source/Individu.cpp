#include "Individu.hpp"
#include "Carte.hpp"
#include <ctime>
#include <iostream>
#include <algorithm>

using namespace std;

extern Carte *carteG;

Individu::Individu(){

}

std::vector<unsigned short> Individu::getParcour() const{
	return parcour;
}


Individu::Individu(unsigned short taille){
	initInd(taille);
}

Individu::Individu(const std::vector<unsigned short> &vect){
	modifInd(vect);
	calculFitness();
}

Individu::Individu(const Individu &a){
	modifInd(a.parcour);
	calculFitness();
}

void Individu::modifInd(const Individu &a){
	distanceTotale=0;
	fitness=100000.f;
	modifInd(a.parcour);
	calculFitness();
}

void Individu::modifInd(const std::vector<unsigned short> &vect){
	distanceTotale=0;
	fitness=100000.f;
	parcour.resize(vect.size() );
	std::copy(vect.begin(),vect.end(),parcour.begin());
	calculFitness();
}

void Individu::initInd(unsigned short taille){
	distanceTotale=0;
	fitness=100000.f;
	parcour.resize(taille);
	for(unsigned short g=0;g<parcour.size();++g){
		parcour[g]=g;
	}
	std::random_shuffle ( parcour.begin(), parcour.end() );//melanger tableau
	calculFitness();
}

void Individu::reverseCaseTab(unsigned short &a, unsigned short &b){
	if(a==b)return;
	unsigned short tmp=a;
	a=b;
	b=tmp;
}

float Individu::getFitness(){
	return fitness;
}

void Individu::calculFitness(){
	short ii;
	for(unsigned short i=0;i<parcour.size();++i){
		if(i!=parcour.size()-1)ii=i+1;
		else ii=0;//fermer la boucle
		distanceTotale+=carteG->returnDistance(parcour[i], parcour[ii]);
	}
	fitness-=distanceTotale;
}

void Individu::afficherInd()const{
	for(unsigned short i=0;i<parcour.size();i++){
		cout<<parcour[i]<<"   ";
	}
	cout<<endl;
	cout<<"fitness::"<<fitness<<endl<<"distanceTotale::"<<distanceTotale<<endl<<endl;
}

/*Individu Individu::copierInd() const{
	return Individu(parcour);
	}*/

Individu Individu::operator=(const Individu &a) const{
	return Individu(a);
}

Individu::~Individu(){
}

