#ifndef FEN
#define FEN

#include <SFML/Graphics.hpp>
#include <SFGUI/SFGUI.hpp>
#include "Racine.hpp"

struct Donnees{
  unsigned short nbrVille, nbrIndividu, opSelect, opReplace, modeCroisement, modeExec;
};

class Fenetre{
  private:
	 Racine *ptrRacine;
	 sf::RenderWindow windowSF;
	 sfg::SFGUI sfgui;
	 sfg::SpinButton::Ptr spinNombreVille, spinNombreInd;
	 sfg::ComboBox::Ptr combOpSelect, combOpReplace, combModCroismnt, combModExec;
	 Donnees donnees;
  public:
	 Fenetre(Racine *a);
	 void gestionEvent();
	 void setNombreVille();
	 void setNombreInd();
	 void chooseSelectionOperator();
	 void chooseReplaceOperator();
	 void chooseModeCroisement();
	 void chooseModeExecution();
	 void signalReset();
	 void signalLaunch();
	 ~Fenetre();
};

#endif 
