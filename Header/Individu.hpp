#ifndef IND
#define IND

class Individu{
  private:
	 float distanceTotale;
	 unsigned short *parcour;
	unsigned short tailleTab;
  public:
	 Individu(unsigned short taille);
	 void afficherInd();
	 void initInd();
	 void reverseTab(unsigned short &a, unsigned short &b);
	 ~Individu();
};

#endif 
