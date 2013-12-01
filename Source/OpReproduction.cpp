#include "OpReproduction.hpp"
#include "constantes.hpp"
#include "Individu.hpp"
#include "Carte.hpp"
#include "Population.hpp"
#include <algorithm>
#include <iostream>

extern Population *popG;
extern  Carte *carteG;

using namespace std;

OpReproduction::OpReproduction(){}

OpReproduction::OpReproduction(const std::vector<unsigned short> &vect){
	init(vect);
}

void OpReproduction::init(const std::vector<unsigned short> &vect){//charger les individus selectionné dans opSelect
	if(vect.size()%2==0)indNewGen.resize(vect.size());
	else indNewGen.resize(vect.size()-1);
	std::vector<Individu> mem=popG->getVectorInd();//recup popInitiale
	for(unsigned short i=0;i<indNewGen.size();i++){
		indNewGen[i].modifInd( popG->getVectorInd()[ vect[i] ] );
	}
}

Population OpReproduction::newGen(unsigned short choose){
	unsigned short tailleParcour=indNewGen[0].getParcour().size();
	for(unsigned short i=0;i<indNewGen.size()/2;i++){
		unsigned short random=rand()%( tailleParcour-2 )+1,
									 randomB=tailleParcour-(rand()%(tailleParcour-random-1)+1);
		if(choose==CROISEMENT_SIMPLE)//simple
			croisement(random, i*2 );//recup taille parcour
		else if(choose==CROISEMENT_COMPLEXE)//complexe
			croisement(random, randomB, i*2 );//recup taille parcour
		if( popG->estPresent( indNewGen[2*i].getFitness() ) )mutation( indNewGen[i*2] );
		if( popG->estPresent( indNewGen[2*i+1].getFitness() ) )mutation( indNewGen[i*2+1] );
	}
	return Population(indNewGen);
}

void OpReproduction::croisement(unsigned short point,unsigned short curseur){
	if(point>=indNewGen[0].getParcour().size())return;
	std::vector<unsigned short> tmpA=indNewGen[curseur].getParcour(), tmpB=indNewGen[curseur+1].getParcour(), tmp;
	tmp.resize(point);
	std::vector<unsigned short>::iterator itA=std::find(tmpA.begin(), tmpA.end(),tmpA[point] ),
		itB=std::find(tmpB.begin(), tmpB.end(),tmpB[point] );
	std::copy (tmpB.begin(), itB, tmp.begin());
	std::copy (tmpA.begin(), itA, tmpB.begin());
	verifInd(tmpB);
	indNewGen[curseur].modifInd(tmpB);
	std::copy (tmp.begin(), tmp.end(), tmpA.begin());
	verifInd(tmpA);
	indNewGen[curseur+1].modifInd(tmpA);
}

void OpReproduction::croisement(unsigned short pointA,unsigned short pointB,unsigned short curseur){
	if(pointA>=indNewGen[0].getParcour().size() || pointB>=indNewGen[0].getParcour().size())return;
	if(pointA>=pointB)return;
	std::vector<unsigned short> tmpA=indNewGen[curseur].getParcour(), tmpB=indNewGen[curseur+1].getParcour(), tmp;
	tmp.resize(pointB-pointA);
	std::vector<unsigned short>::iterator 
		itA=std::find(tmpA.begin(), tmpA.end(),tmpA[pointA] ),
		itAA=std::find(tmpA.begin(), tmpA.end(),tmpA[pointB] ),
		itB=std::find(tmpB.begin(), tmpB.end(),tmpB[pointA] ),
		itBB=std::find(tmpB.begin(), tmpB.end(),tmpB[pointB] );
	std::copy (itB, ++itBB, tmp.begin());
	std::copy (itA, ++itAA, itB);
	itBB--;
	itAA--;
	verifInd(tmpB);
	indNewGen[curseur].modifInd(tmpB);
	std::copy (tmp.begin(), tmp.end(), itA);
	verifInd(tmpA);
	indNewGen[curseur+1].modifInd(tmpA);
}

void OpReproduction::mutation(Individu &a){
	unsigned short randA, randB;
	randA=rand()%a.getParcour().size();
	do{
		randB=rand()%a.getParcour().size();
	}while(randA==randB);
	a.reverseCaseTab(randA, randB);
}

void OpReproduction::verifInd(std::vector<unsigned short> &vect){
	for(unsigned int y=0;y<vect.size();++y){
		if(std::find(vect.begin(), vect.end(),y )==vect.end()){//si valeur absente
			for(unsigned int z=0;z<vect.size();++z){//chercher les valeurs presente plusieurs fois
				if(z==y)continue;
				std::vector<unsigned short>::iterator itt=std::find(vect.begin(), vect.end(),z ), ittB;
				if(itt==vect.end())continue;//si valeur absente
				ittB=itt;
				ittB++;
				ittB=std::find(ittB, vect.end(),z );
				if(ittB==vect.end())continue;//si valeur presente une fois
				(*itt)=y;//sinon remplace la valeur
				break;
			}
		}
	}
}

OpReproduction::~OpReproduction(){

}
