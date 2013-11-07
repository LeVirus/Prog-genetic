#ifndef OPS
#define OPS

#include <vector>
#include "Individu.hpp"

class Population;

struct StockTraitement{
	short rouletteCumul, stSelectRang;
};

class OpSelect{
	private:
		float etendue;
		std::vector<StockTraitement> stockDonneesPop;
		std::vector<Individu> vectMemo;
	public:
		OpSelect();
		void init();
		short roulette(short choose);
		short tournoi(unsigned short nbrPairInd, unsigned short nbrPairParticipant);
		short elitisme(unsigned short nbrASelect);
		~OpSelect();
};

#endif
