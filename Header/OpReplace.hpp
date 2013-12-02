#ifndef ORPP
#define ORPP

#include <vector>
#include "Individu.hpp"

class OpReplace{
	private: 
		unsigned short nbrVille;
		float **tabDistanceVille;
		//Ville *tabVille;
		//std::list<short> chaineVille;
		//std::list<short>::iterator itVille;
	public:
		OpReplace();
		void remplacementStat(std::vector<unsigned short> &vect, const std::vector<Individu> &newGen);
		void remplacementElit(const std::vector<Individu> &newGen);
		/*unsigned short retourNbrVille();
		void initVille();
		void procheVoisins(short choix);
		void affichage();
		static float distance(Ville a, Ville b);
		float returnDistance(short villeA, short villeB);
		unsigned short getNbrVille();*/
		~OpReplace();
}; 

#endif
