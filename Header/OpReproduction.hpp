#ifndef OPR
#define OPR

#include <vector>
#include "Individu.hpp"
#include "Population.hpp"

class OpReproduction{
	private:
		std::vector<unsigned short> vectMemo;
		std::vector<Individu> indNewGen;
	public:
		OpReproduction();
		OpReproduction(const std::vector<unsigned short> &vect);
		void init(const std::vector<unsigned short> &vect);
		Population newGen(unsigned short choose);
		void croisement(unsigned short point,unsigned short curseur);
		void croisement(unsigned short pointA, unsigned short pointB, unsigned short curseur);
		void mutation(Individu &a);
		void verifInd(std::vector<unsigned short> &vect);
		~OpReproduction();
};

#endif
