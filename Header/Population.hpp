#ifndef POP
#define POP

#include <vector>
#include <set>
#include "Individu.hpp"


class Population{
	private:
		std::vector<unsigned short> classement;
		std::vector<Individu> tabIndividu;
		std::vector<Individu>::iterator itTabInd;
		unsigned short nbrIndividu, nbrVille;
	public:
		Population();
		Population(unsigned short nombreVille, unsigned short nombreIndividu);
		Population(const std::vector<unsigned short> &vect);
		Population(const std::vector<Individu> &vect);
		void init(const std::vector<Individu> &vect);
		bool estPresent(float fitness);
		void setClassement();
		unsigned short searchClassement(unsigned short num);
		void replaceInd(unsigned short pos, const Individu &a);
		void replaceIndElit(const Individu &a, unsigned short place);
		const std::vector<Individu> getVectorInd();
		void afficherPop();
		~Population();
};

#endif
