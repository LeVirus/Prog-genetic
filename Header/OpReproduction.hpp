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
		OpReproduction(const std::vector<unsigned short> &vect);
		Population newGen();
		void croisement( Individu a, Individu b, short point,short curseur);
		void croisement(Individu a, Individu b);
		~OpReproduction();
};

#endif
