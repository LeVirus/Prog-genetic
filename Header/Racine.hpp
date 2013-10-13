#ifndef RAC
#define RAC


#include <SFML/Graphics.hpp>
#include <SFGUI/SFGUI.hpp>
#include "Fenetre.hpp"

class Population;
class Carte;

class Racine{
  private:
	 //sf::Texture texture;
	 short frame, nbreVille, nbreIndividu;
	 Population *pop;
	 Carte *carte;
	 Fenetre fenetre;
	 
  public:
	 Racine(unsigned short nombreVille, unsigned short nombreIndividu);
	 void lancerProg();
	 void initialiser();
	 ~Racine();
};

#endif 
