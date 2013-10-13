#ifndef FEN
#define FEN

#include <SFML/Graphics.hpp>
#include <SFGUI/SFGUI.hpp>

class Fenetre{
  private:
	 sf::RenderWindow windowSF;
	 sfg::SFGUI sfgui;
	 sfg::SpinButton::Ptr spinNombreVille, spinNombreInd;
	 sfg::ComboBox::Ptr combOpSelect, combOpReplace, combModCroismnt;
  public:
	 Fenetre();
	 void gestionEvent();
	 void test();
	 void testA();
	 void testCombo();
	 ~Fenetre();
};

#endif 
