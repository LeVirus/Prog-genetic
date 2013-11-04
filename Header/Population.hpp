#ifndef POP
#define POP

#include <vector>
#include "Individu.hpp"


class Population{
  private:
	 std::vector<Individu> tabIndividu;
	 std::vector<Individu>::iterator itTabInd;
	 unsigned short nbrIndividu, nbrVille;
  public:
	 Population(unsigned short nombreVille, unsigned short nombreIndividu);
	 std::vector<Individu> vectorInd();
	 void afficherPop();
	 ~Population();
};

#endif
