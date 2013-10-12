#ifndef RAC
#define RAC


#include <SFML/Graphics.hpp>
#include <SFGUI/SFGUI.hpp>


class Population;
class Carte;

class Racine{
  private:
	 sf::Texture texture;
	 short largeurFenetre, longueurFenetre, frame, nbreVille, nbreIndividu;
	 sf::RenderWindow window;
	 sfg::SFGUI sfgui;
	 Population *pop;
	 Carte *carte;
	 
  public:
	 Racine(unsigned short nombreVille, unsigned short nombreIndividu);
	 void lancerProg();
	 void initialiser();
	 ~Racine();
};

#endif 
