#ifndef INDD
#define INDD

#include <vector>

class Individu{
	private:
		float distanceTotale, fitness;
		std::vector<short> parcour;
	public:
		Individu();
		std::vector<short> getParcour() const;
		Individu(unsigned short taille);
		Individu(const std::vector<short> &vect);
		Individu(const Individu &a);
		void modifInd(const std::vector<short> &vect);
		void modifInd(const Individu &a);
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
