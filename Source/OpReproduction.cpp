#include "OpReproduction.hpp"
#include "Individu.hpp"
#include "Carte.hpp"
#include "Population.hpp"
#include <algorithm>

extern Population *popG;
extern  Carte *carteG;

OpReproduction::OpReproduction(const std::vector<unsigned short> &vect){
	indNewGen.resize(vect.size());
	std::copy (vect.begin(), vect.end(), vectMemo.begin() );
}

Population OpReproduction::newGen(){

	std::vector<Individu> mem=popG->getVectorInd();//recup popInitiale
	//Population generationSuivante(carteG->getNbrVille(), vectMemo.size()); 
	for(unsigned short i=0;i<vectMemo.size()/2;i++){
		croisement( mem[2*i], mem[2*i+1], rand()%( mem.size()-2 )+2, i*2 );//a finir
	}
	if(mem.size()%2!=0){//si tab impair copier la derniere case
		indNewGen[ mem.size()-1 ]=mem[ mem.size()-1 ];
	}
	return Population(mem);
}

void OpReproduction::croisement( Individu a, Individu b, short point,short curseur){
	std::vector<short> tmp=a.getParcour();
	std::copy (tmp.begin()+point, tmp.end(), tmp.begin() );
	indNewGen[curseur]=tmp;
	tmp=b.getParcour();
	std::copy (tmp.begin(), tmp.begin()+point, tmp.begin() );
	indNewGen[curseur+1]=tmp;
}

OpReproduction::~OpReproduction(){

}
