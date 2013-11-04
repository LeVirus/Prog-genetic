#ifndef INDD
#define INDD

class Individu{
  private:
	 float distanceTotale, fitness;
	 unsigned short *parcour;
	 short tailleTab;
  public:
	 Individu();
	 void calculFitness();
	 void afficherInd();
	 void initInd(unsigned short taille);
	 void reverseCaseTab(unsigned short &a, unsigned short &b);
	 ~Individu();
};

#endif 
