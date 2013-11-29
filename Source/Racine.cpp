#include "Racine.hpp"
#include "constantes.hpp"
#include "Carte.hpp"
#include "Population.hpp"
#include "Fenetre.hpp"
#include "OpSelect.hpp"
#include "OpReproduction.hpp"
#include <iostream>

using namespace std;

extern Carte *carteG;
extern Population *popG;

Racine::Racine(){
	pop=NULL;
	carte=NULL;
	stockDonnees=NULL;
	classeOpSelect=new OpSelect;
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
	bool undone=true;
	unsigned short cmpt=0;
	if(stockDonnees)return;
	stockDonnees=d;
	carte=new Carte(stockDonnees->nbrVille);
	carteG=carte;
	//carte->affichage();
	pop=new Population(stockDonnees->nbrVille, stockDonnees->nbrIndividu);
	popG=pop;//var globale
	do{
	cout<<"deby affich total"<<endl;
	pop->afficherPop();
	cout<<"fin affich total"<<endl;
	classeOpSelect->init();
	// std::vector<unsigned short> gro = classeOpSelect->roulette(5,1);
	// std::vector<unsigned short> gro = classeOpSelect->roulette(5,0);
	//std::vector<unsigned short> gro = classeOpSelect->tournoi(5, 10);
	std::vector<unsigned short> gro = classeOpSelect->elitisme(5);
	classeOpReprod=new OpReproduction(gro);
	cout<<"fin op reprod"<<endl;
	Population enfants=classeOpReprod->newGen();
	cout<<"fin newggg"<<endl;
	//enfants.afficherPop();
	//classeOpReplace.remplacementStat(gro, enfants.getVectorInd());
	classeOpReplace.remplacementElit(enfants.getVectorInd());
	cmpt++;
	}while(cmpt<3);
}

void Racine::lancerProg(){
	fenetre->gestionEvent();
} 

Racine::~Racine(){
	if(fenetre)delete fenetre;
	if(carte)delete carte;
	//if(pop)delete pop;BUUUUUUUUUUUUUUUUUUUGGGGGGGGGGGGGGGGGGGGGGGGGG
	if(classeOpSelect)delete classeOpSelect;
}
