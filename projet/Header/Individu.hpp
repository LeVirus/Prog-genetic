#ifndef INDD
#define INDD

class Individu{
  private:
	 float distanceTotale;
	 unsigned short *parcour;
	 short tailleTab;
  public:
	 Individu();
	 void setNbrVille(unsigned short taille);
	 void afficherInd();
	 void initInd();
	 void reverseCaseTab(unsigned short &a, unsigned short &b);
	 ~Individu();
};

#endif 
