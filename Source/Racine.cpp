#include "Racine.hpp"
#include "constantes.hpp"
#include "Carte.hpp"
#include "Population.hpp"
#include <iostream>

using namespace std;

Racine::Racine(unsigned short nombreVille, unsigned short nombreIndividu){
  largeurFenetre=500; 
  longueurFenetre=400;
	nbreVille=nombreVille; 
	nbreIndividu=nombreIndividu;
  if(  !texture.loadFromFile( "Images/textureA.png" )  )cout<<"fail load im"<<endl;
  frame=0;
  pop=new Population(nombreVille, nbreIndividu);
  window.create(sf::VideoMode(largeurFenetre, longueurFenetre), "shoot", sf::Style::Default);
carte=new Carte(nombreVille);
}

void Racine::initialiser(){
	
}

void Racine::lancerProg(){
	unsigned short stock=0;
	window.setFramerateLimit(20);
	//sfg::Button::Ptr button = sfg::Button::Create( "Hello" );
	//m_label = sfg::Label::Create( "Hello world!" );
	//sf::Event event;
	window.display();
	while ( window.isOpen() ){
	  //sf::Clock temps;
		//window.pollEvent(event);
		if (/* event.type == sf::Event::Closed  ||*/  sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) ){
		  window.close();
		  break;
		}
		window.clear(sf::Color::Black);
		do{
		  if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Up ) )stock--;
		  else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Down ) )stock++;
		  if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Left ) )
			 if(stock>3)stock-=4;
			 else stock-=4;
		  else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Right ) )
			 if(stock<4)stock+=4;
		 // joueur->deplacerJoueur(stock);
		  if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Return ) )break;//valider
		  //window.draw( image menu );
		  //window.draw( image selecteur en fonction de stock );
		  //window.display();
		}while(true);
		switch(stock){
		  case NOMBRE_VILLE:
			 break;
		  case TAILLE_POP_INIT:
			 break;
		  case CHOIX_OP_SELECT:
			 break;
		  case CHOIX_OP_REMPLACE:
			 break;
		  case CHOIX_MOD_CROISE:
			 break;
		  case REINIT:
			 break;
		  case OPTIONS_AVANCEES:
			 break;
		  case DEMARAGE_ALGO:
			 break;
		  default:
			 return;
			 break;
		}
		//window.draw( joueur->getSprite() );
		window.display();
	}
} 

Racine::~Racine(){}
