#include "Racine.hpp"
#include "constantes.hpp"
#include "Carte.hpp"
#include "Population.hpp"
#include "Fenetre.hpp"
#include <iostream>

using namespace std;

extern Carte *carteG;

Racine::Racine(){
  pop=NULL;
	 stockDonnees=NULL;
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
	 pop->afficherPop();
	 
}

void Racine::lancerProg(){
	fenetre->gestionEvent();
} 

Racine::~Racine(){
	 if(fenetre)delete fenetre;
	 if(carte)delete carte;
	 if(pop)delete pop;

}
