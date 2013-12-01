#ifndef FEN
#define FEN

#include <SFML/Graphics.hpp>
#include <SFGUI/SFGUI.hpp>
#include "Racine.hpp"

struct Donnees{
	unsigned short nbrVille, nbrIndividu, nbrIndSelect, opReprod ,opSelect, opReplace, modeCroisement, modeExec;
};//penser a implementer opReprod et nbrOpSelect

class Fenetre{
	private:
		Racine *ptrRacine;
		sf::RenderWindow windowSF;
		sfg::SFGUI sfgui;
		sfg::SpinButton::Ptr spinNombreVille, spinNombreInd, spinNbrIndSelect;
		sfg::ComboBox::Ptr combOpSelect, combOpReplace, combModCroismnt, combModExec;
		Donnees donnees;
	public:
		Fenetre(Racine *a);
		void gestionEvent();
		void setNombreVille();
		void setNombreInd();
		void setNombreIndSelect();
		void chooseSelectionOperator();
		void chooseReplaceOperator();
		void chooseModeCroisement();
		void chooseModeExecution();
		void signalReset();
		void signalLaunch();
		short nombreMaxIndividus(short nombreVille);
		~Fenetre();
};

#endif 
