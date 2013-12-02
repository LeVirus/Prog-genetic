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
	launched=false;
	pop=NULL;
	carte=NULL;
	stockDonnees=NULL;
	classeOpSelect=new OpSelect;
	fenetre=new Fenetre(this);
}

void Racine::launch(Donnees *d){
unsigned short cmpt=0;
		std::vector<unsigned short> vectOpSelect; 
		Population enfants;
	if(!launched){
		launched=true;
		classeOpReprod=new OpReproduction;
		//bool undone=true;
		//unsigned short cmpt=0;
		if(stockDonnees)return;
		stockDonnees=d;
		carte=new Carte(stockDonnees->nbrVille);
		carteG=carte;
		//carte->affichage();
		pop=new Population(stockDonnees->nbrVille, stockDonnees->nbrIndividu);
		popG=pop;//var globale
		pop->afficherPop();
	}
		do{
	cout<<"DEBUT ITERATION "<<endl<<endl<<endl;
	classeOpSelect->init();
	switch(d->opSelect){
		case ROULETTE:
			vectOpSelect=classeOpSelect->roulette(d->nbrIndSelect,0);
			break;
		case SELECT_RANG:
			vectOpSelect=classeOpSelect->roulette(d->nbrIndSelect,1);
			break;
		case TOURNOI:
			vectOpSelect=classeOpSelect->tournoi(d->nbrIndSelect, 10);
			break;
		case ELITISME:
			vectOpSelect=classeOpSelect->elitisme(d->nbrIndSelect);
			break;
		default:
			return;
	};
	classeOpReprod->init(vectOpSelect);
	Population stock=classeOpReprod->newGen(d->opReprod);
	//stock.afficherPop();
	enfants.init( classeOpReprod->newGen(d->opReprod).getVectorInd() );
	//enfants.afficherPop();
	switch(d->opReplace){
		case REPLACE_STAT:
			classeOpReplace.remplacementStat(vectOpSelect, enfants.getVectorInd());
			break;
		case REPLACE_ELIT:
			classeOpReplace.remplacementElit(enfants.getVectorInd());
			break;
		default:
			return;
	};
	//cmpt++;
	cout<<"debut affich "<<endl;
	pop->afficherPop();
	cout<<"fin affich total"<<endl<<endl;
	cout<<"FIN ITERATION "<<endl<<endl<<endl;
	if(d->modeExec==1) break;
	cmpt++;
	}while(cmpt<d->nbrIteration);
}

void Racine::lancerProg(){
	fenetre->gestionEvent();
} 

Racine::~Racine(){
	if(fenetre)delete fenetre;
	if(carte)delete carte;
	if(pop)delete pop;
	if(classeOpSelect)delete classeOpSelect;
}
