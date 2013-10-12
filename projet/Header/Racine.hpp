#ifndef RAC
#define RAC

#include <SFGUI/SFGUI.hpp>
#include <SFML/Graphics.hpp>
//#include <fstream>
//#include <string>
//#include <sstream>

class Population;
class Carte;

class Racine{
  private:
	 sf::Texture texture;
	 short largeurFenetre, longueurFenetre, frame, nbreVille, nbreIndividu;
	 sf::RenderWindow render_window;
	 sfg::SFGUI m_sfgui;
	 Population *pop;
	 Carte *carte;
	 
  public:
	 Racine(unsigned short nombreVille, unsigned short nombreIndividu);
	 void lancerProg();
	 void initialiser();
	 ~Racine();
};

#endif 
