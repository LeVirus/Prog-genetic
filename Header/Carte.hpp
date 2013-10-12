#ifndef CAR
#define CAR

#include <list>

struct Ville{
  float x,y;
};

class Carte{
  private: 
	 unsigned short nbrVille;
	 float **tabDistanceVille;
	 Ville *tabVille;
	 std::list<short> chaineVille;
	 std::list<short>::iterator itVille;
  public:
	 Carte(short nombre);
	 void initVille();
	 void procheVoisins(short choix);
	 void affichage();
	 static float distance(Ville a, Ville b);
	 float returnDistance(short villeA, short villeB);
	 ~Carte();
}; 

#endif
