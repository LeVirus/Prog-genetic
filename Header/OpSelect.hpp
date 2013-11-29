#ifndef OPS
#define OPS

#include <vector>
#include "Individu.hpp"

class Population;

struct StockTraitement{
	unsigned short rouletteCumul, stSelectRang;
};

class OpSelect{
	private:
		float etendue;
		std::vector<StockTraitement> stockDonneesPop;
		std::vector<Individu> vectMemo;
	public:
		OpSelect();
		const std::vector<StockTraitement> &getDonneesPop();
		unsigned short getWorst();
		void init();
		std::vector<unsigned short> roulette(unsigned short nbrInd, unsigned short choose);
		std::vector<unsigned short> tournoi(unsigned short nbrPairInd, unsigned short nbrPairParticipant);
		std::vector<unsigned short> elitisme(unsigned short nbrASelect);
		~OpSelect();
};

#endif
