#include "OpReproduction.hpp"
#include "Individu.hpp"
#include "Carte.hpp"
#include "Population.hpp"
#include <algorithm>
#include <iostream>

extern Population *popG;
extern  Carte *carteG;

using namespace std;

OpReproduction::OpReproduction(const std::vector<unsigned short> &vect){
	indNewGen.resize(vect.size());
	std::vector<Individu> mem=popG->getVectorInd();//recup popInitiale
	for(unsigned short i=0;i<vect.size();i++){
		indNewGen[i].modifInd( popG->getVectorInd()[ vect[i] ] );
		//indNewGen[i].afficherInd();
	}
}

Population OpReproduction::newGen(){
	unsigned short tailleParcour=indNewGen[0].getParcour().size();
	//std::vector<Individu> mem=popG->getVectorInd();//recup popInitiale
	//Population generationSuivante(carteG->getNbrVille(), vectMemo.size()); 
	for(unsigned short i=0;i<indNewGen.size()/2;i++){
indNewGen[i*2].afficherInd();
indNewGen[i*2+1].afficherInd();
		//croisement(rand()%( tailleParcour-2 )+1, i*2 );//recup taille parcour
unsigned short random=rand()%( tailleParcour-2 )+1,
	randomB=tailleParcour-(rand()%(tailleParcour-random-1)+1);
		croisement(random, randomB, i*2 );//recup taille parcour
	}
	return Population(indNewGen);
}

void OpReproduction::croisement(unsigned short point,unsigned short curseur){
	if(point>=indNewGen[0].getParcour().size())return;
	std::vector<unsigned short> tmpA=indNewGen[curseur].getParcour(), tmpB=indNewGen[curseur+1].getParcour(), tmp;
	tmp.resize(point);
	std::vector<unsigned short>::iterator itA=std::find(tmpA.begin(), tmpA.end(),tmpA[point] ),
		itB=std::find(tmpB.begin(), tmpB.end(),tmpB[point] );
	cout<<"point::"<<point<<endl;
	std::copy (tmpB.begin(), itB, tmp.begin());
	std::copy (tmpA.begin(), itA, tmpB.begin());
	//for(unsigned int y=0;y<tmpA.size();++y)cout<<tmpB[y];
	//cout<<"  finB"<<endl;
	verifInd(tmpB);
	//for(unsigned int y=0;y<tmpA.size();++y)cout<<tmpB[y];
	//cout<<"  finB"<<endl;
	//indNewGen[curseur].afficherInd();
	indNewGen[curseur].modifInd(tmpB);
	//indNewGen[curseur].afficherInd();
	std::copy (tmp.begin(), tmp.end(), tmpA.begin());
	//for(unsigned int y=0;y<tmpA.size();++y)cout<<tmpA[y];
	//cout<<"  finA"<<endl;
	verifInd(tmpA);
	//for(unsigned int y=0;y<tmpA.size();++y)cout<<tmpA[y];
	//cout<<"  finA"<<endl;
	indNewGen[curseur+1].modifInd(tmpA);
	//indNewGen[curseur+1].afficherInd();

	//indNewGen[curseur+1].afficherInd();
	//indNewGen[curseur].afficherInd();
}

void OpReproduction::croisement(unsigned short pointA,unsigned short pointB,unsigned short curseur){
cout<<"tyd"<<pointA<<pointB<<endl;
	if(pointA>=indNewGen[0].getParcour().size() || pointB>=indNewGen[0].getParcour().size())return;
	if(pointA>=pointB)return;
cout<<"ddd"<<endl;
	std::vector<unsigned short> tmpA=indNewGen[curseur].getParcour(), tmpB=indNewGen[curseur+1].getParcour(), tmp;
	tmp.resize(pointB-pointA);
	std::vector<unsigned short>::iterator 
		itA=std::find(tmpA.begin(), tmpA.end(),tmpA[pointA] ),
		itAA=std::find(tmpA.begin(), tmpA.end(),tmpA[pointB] ),
		itB=std::find(tmpB.begin(), tmpB.end(),tmpB[pointA] ),
		itBB=std::find(tmpB.begin(), tmpB.end(),tmpB[pointB] );
	cout<<"pointA::"<<pointA<<endl;
	cout<<"pointB::"<<pointB<<endl;
	for(unsigned int y=0;y<tmpA.size();++y)cout<<tmpB[y];
	cout<<"  finB"<<endl;
	std::copy (itB, itBB, tmp.begin());
	std::copy (itA, itAA, itB);
	for(unsigned int y=0;y<tmpA.size();++y)cout<<tmpB[y];
	cout<<"  finB"<<endl;
	verifInd(tmpB);
	for(unsigned int y=0;y<tmpA.size();++y)cout<<tmpB[y];
	cout<<"  finB"<<endl;
	//indNewGen[curseur].afficherInd();
	indNewGen[curseur].modifInd(tmpB);
	//indNewGen[curseur].afficherInd();
	for(unsigned int y=0;y<tmpA.size();++y)cout<<tmpA[y];
	cout<<"  finA"<<endl;
	std::copy (tmp.begin(), tmp.end(), itA);
	for(unsigned int y=0;y<tmpA.size();++y)cout<<tmpA[y];
	cout<<"  finA"<<endl;
	verifInd(tmpA);
	for(unsigned int y=0;y<tmpA.size();++y)cout<<tmpA[y];
	cout<<"  finA"<<endl;
	indNewGen[curseur+1].modifInd(tmpA);
	indNewGen[curseur+1].afficherInd();

	//indNewGen[curseur+1].afficherInd();

}

void OpReproduction::mutation(std::vector<unsigned short> &vect){

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
