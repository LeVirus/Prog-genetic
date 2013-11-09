#include "Racine.hpp"
#include "constantes.hpp"
#include "Carte.hpp"
#include "Population.hpp"
#include "Fenetre.hpp"
#include "OpSelect.hpp"
#include <iostream>

using namespace std;

extern Carte *carteG;
extern Population *popG;

Racine::Racine(){
	 pop=NULL;
	 carte=NULL;
	 stockDonnees=NULL;
	 classeAlgo=new OpSelect;
	 fenetre=new Fenetre(this);
	 //if(  !texture.loadFromFile( "Images/textureA.png" )  )cout<<"fail load im"<<endl;
}

void Racine::initialiser(){
	 //nbreVille=nombreVille; 
	 //nbreIndividu=nombreIndividu;
	 //pop=new Population(nombreVille, nbreIndividu);
	 
	 //carte=new Carte(nombreVille);
}

void Racine::launch(Donnees *d){
	 if(stockDonnees)return;
	 stockDonnees=d;
	 carte=new Carte(stockDonnees->nbrVille);
	 carteG=carte;
	 //carte->affichage();
	 pop=new Population(stockDonnees->nbrVille, stockDonnees->nbrIndividu);
	 popG=pop;
	 //pop->afficherPop();
	 classeAlgo->init();
	 std::vector<unsigned short> gro = classeAlgo->roulette(5,0);
	 //classeAlgo->roulette(1);
	 //classeAlgo->tournoi(5, 10);
	 //classeAlgo->elitisme(5);
}

void Racine::lancerProg(){
	fenetre->gestionEvent();
} 

Racine::~Racine(){
	 if(fenetre)delete fenetre;
	 if(carte)delete carte;
	 //if(pop)delete pop;BUUUUUUUUUUUUUUUUUUUGGGGGGGGGGGGGGGGGGGGGGGGGG
	 if(classeAlgo)delete classeAlgo;
}
