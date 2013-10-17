#ifndef RAC
#define RAC


#include <SFML/Graphics.hpp>
#include <SFGUI/SFGUI.hpp>

class Population;
class Carte;
class Fenetre;
struct Donnees;

class Racine{
  private:
	 //sf::Texture texture;
	 short frame, nbreVille, nbreIndividu;
	 Population *pop;
	 Carte *carte;
	 Fenetre *fenetre;
	 Donnees *stockDonnees;
	 
  public:
	 Racine();
	 void lancerProg();
	 void launch(Donnees *d);
	 void initialiser();
	 ~Racine();
};

#endif 
