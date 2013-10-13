#ifndef FEN
#define FEN

#include <SFML/Graphics.hpp>
#include <SFGUI/SFGUI.hpp>
#include <string>

class Fenetre{
  private:
	 sf::RenderWindow windowSF;
	 sfg::SFGUI sfgui;
	 sfg::SpinButton::Ptr spinNombreVille, spinNombreInd;
	 sfg::ComboBox::Ptr combOpSelect, combOpReplace, combModCroismnt;
	 short nbrVille, nbrIndividu;
	 string opSelect, opReplace, modeCroisement;
  public:
	 Fenetre();
	 void gestionEvent();
	 void setNombreVille();
	 void setNombreInd();
	 void chooseSelectionOperator();
	 void chooseReplaceOperator();
	 void chooseModeCroisement();
	 void signalReset();
	 void signalLaunch();
	 ~Fenetre();
};

#endif 
