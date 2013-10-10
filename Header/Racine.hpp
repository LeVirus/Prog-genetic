#ifndef RAC
#define RAC

#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "constantes.hpp"
#include "Individu.hpp"
#include "Population.hpp"
#include "Carte.hpp"

class Racine{
  private:
	 sf::Texture texture;
	 short largeurFenetre, longueurFenetre, frame, nbreVille, nbreIndividu;
	 sf::RenderWindow window;
	 Population *pop;
	 Carte *carte;
	 
  public:
	 Racine(unsigned short nombreVille, unsigned short nombreIndividu);
	 void lancerProg();
	 void initialiser();
	 ~Racine();
};

#endif 
