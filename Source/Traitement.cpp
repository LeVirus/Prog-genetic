#include "Population.hpp"
#include "Traitement.hpp"

using namespace std;

extern Population *popG;

Traitement::Traitement(){
	
}

void Traitement::roulette(){
	float min=10000.f, etendue=0;
	short nbrA, tmp, tmpA=0, final=0;
	std::vector<short> tmpTab;
	tmpTab.resize(vectMemo.size());
	auto vectMemo=vectorInd();
	for(std::vector<Individu>::iterator it=vectorInd.begin();it<vectorInd.end();it++){
		if( min>(*it).getFitness() )min=(*it).getFitness();
	}
	min--;
	for(std::vector<Individu>::iterator itA=vectorInd.begin();itA<vectorInd.end();itA++){
		etandu+=(*it).getFitness()-min;
		tmpTab[tmpA]=etandu;
		tmpA++;
	}
	tmpA--;
	nbrA=rand()%etandu;
	for(std::vector<Individu>::iterator itB=tmpTab.end();itB<tmpTab.begin();itB--){
		if(tmpA==0)break;
		if( nbrA>tmpTab[tmpA-1] ){
			final=tmpA;
			break;
		}
	}
	vectorInd[final].afficherInd();
}

Traitement::~Traitement(){

}
