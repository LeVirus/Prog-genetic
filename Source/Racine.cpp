#include "Racine.hpp"
#include "constantes.hpp"
#include "Carte.hpp"
#include "Population.hpp"
#include <iostream>

using namespace std;

Racine::Racine(unsigned short nombreVille, unsigned short nombreIndividu){
  nbreVille=nombreVille; 
  nbreIndividu=nombreIndividu;
  //if(  !texture.loadFromFile( "Images/textureA.png" )  )cout<<"fail load im"<<endl;
  frame=0;
  pop=new Population(nombreVille, nbreIndividu);
  
  carte=new Carte(nombreVille);
}

void Racine::initialiser(){
	
}

void Racine::lancerProg(){
	fenetre.gestionEvent();
} 

Racine::~Racine(){}
