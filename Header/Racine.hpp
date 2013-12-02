#ifndef RAC
#define RAC


#include <SFML/Graphics.hpp>
#include <SFGUI/SFGUI.hpp>
#include "OpReplace.hpp"

class Population;
class Carte;
class Fenetre;
class OpSelect;
class OpReproduction;
struct Donnees;

//Carte *carteG;

class Racine{
  private:
	bool launched;
	 OpReplace classeOpReplace;
	 //sf::Texture texture;
	 OpReproduction *classeOpReprod;
	 Carte *carte;
	 short frame, nbreVille, nbreIndividu;
	 Population *pop;
	 Fenetre *fenetre;
	 OpSelect *classeOpSelect;
	 Donnees *stockDonnees;
	 
  public:
	 Racine();
	 void lancerProg();
	 void launch(Donnees *d);
	 void initialiser();
	 ~Racine();
};

#endif 
