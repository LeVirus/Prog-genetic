#ifndef POP
#define POP

class Individu;

class Population{
  private:
	 Individu *tabIndividu;
	 unsigned short nbrIndividu, nbrVille;
  public:
	 Population(unsigned short nombreVille, unsigned short nombreIndividu);
	 void afficherPop();
	 ~Population();
};

#endif
