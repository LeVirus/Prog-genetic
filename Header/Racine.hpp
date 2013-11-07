#ifndef RAC
#define RAC


#include <SFML/Graphics.hpp>
#include <SFGUI/SFGUI.hpp>

class Population;
class Carte;
class Fenetre;
class OpSelect;
struct Donnees;

//Carte *carteG;

class Racine{
  private:
	 //sf::Texture texture;
	 Carte *carte;
	 short frame, nbreVille, nbreIndividu;
	 Population *pop;
	 Fenetre *fenetre;
	 OpSelect *classeAlgo;
	 Donnees *stockDonnees;
	 
  public:
	 Racine();
	 void lancerProg();
	 void launch(Donnees *d);
	 void initialiser();
	 ~Racine();
};

#endif 
