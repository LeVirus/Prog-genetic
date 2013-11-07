#ifndef TRA
#define TRA

#include <vector>
#include "Individu.hpp"

class Population;

struct StockTraitement{
  short rouletteCumul, stSelectRang;
};

class Traitement{
	private:
	  	float etendue;
		std::vector<StockTraitement> stockDonneesPop;
		std::vector<Individu> vectMemo;
	public:
	 Traitement();
	 void init();
	 short roulette(short choose);
	 short tournoi(unsigned short nbrPairInd, unsigned short nbrPairParticipant);
	 short elitisme(unsigned short nbrASelect);
	 ~Traitement();
};

#endif