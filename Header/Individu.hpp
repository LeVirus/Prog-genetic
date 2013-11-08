#ifndef INDD
#define INDD

#include <vector>

class Individu{
	private:
		float distanceTotale, fitness;
		std::vector<short> parcour;
	public:
		Individu();
		Individu(unsigned short taille);
		Individu(std::vector<short> vect);
		void calculFitness();
		float getFitness();
		void afficherInd();
		void initInd(unsigned short taille);
		void reverseCaseTab(unsigned short &a, unsigned short &b);
		//Individu copierInd()const;
		Individu operator=(const Individu &a) const;
		~Individu();
};

#endif 
