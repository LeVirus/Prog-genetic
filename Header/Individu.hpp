#ifndef INDD
#define INDD

#include <vector>

class Individu{
	private:
		float distanceTotale, fitness;
		std::vector<unsigned short> parcour;
	public:
		Individu();
		std::vector<unsigned short> getParcour() const;
		Individu(unsigned short taille);
		Individu(const std::vector<unsigned short> &vect);
		Individu(const Individu &a);
		void modifInd(const std::vector<unsigned short> &vect);
		void modifInd(const Individu &a);
		void calculFitness();
		float getFitness();
		void afficherInd()const;
		void initInd(unsigned short taille);
		void reverseCaseTab(unsigned short &a, unsigned short &b);
		//Individu copierInd()const;
		Individu operator=(const Individu &a) const;
		~Individu();
};

#endif 
