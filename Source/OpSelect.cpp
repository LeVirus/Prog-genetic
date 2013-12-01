#include "Population.hpp"
#include "OpSelect.hpp"
#include <set>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <iostream>

using namespace std;

extern Population *popG;

OpSelect::OpSelect(){
	srand(time(NULL));
	etendue=0.f;
}

unsigned short OpSelect::getWorst(){
	for(unsigned short i=0;i<stockDonneesPop.size();i++){
		if(stockDonneesPop[i].stSelectRang==1)return i;
	}
	return 0;
}

void OpSelect::init(){
	std::multiset<float> msetClassmtFitness;
	short positionTab=0, cmpt;
	float min=100000.f;
	vectMemo=popG->getVectorInd();//recup population de base
	cmpt=vectMemo.size();
	stockDonneesPop.resize(vectMemo.size());

	//soustrait le fitness min aux fitness 
	for(std::vector<Individu>::iterator it=vectMemo.begin();it<vectMemo.end();it++){
		if( min>(*it).getFitness() )min=(*it).getFitness();//
		msetClassmtFitness.insert( (*it).getFitness() );//inserer valeur dans le multiset
	}
	min--;

	//init Roulette et select rang
	for(std::vector<Individu>::iterator itA=vectMemo.begin();itA<vectMemo.end();itA++){
		etendue+=(*itA).getFitness()-min;
		stockDonneesPop[positionTab].rouletteCumul=etendue;//ecrire le cumul du fitness
		stockDonneesPop[positionTab].stSelectRang=0;
		positionTab++;
	}

	//init Select rang
	//parcour du multiset
	for(std::multiset<float>::iterator it=msetClassmtFitness.begin();it!=msetClassmtFitness.end();it++){
		//parcour du tableau Individu
		//chercher dans population initiale 
		for(unsigned short i=0;i<vectMemo.size();i++){
			//si case non remplie et fitness == case courrante du multiset
			if( stockDonneesPop[i].stSelectRang==0  
					&&  fabs( vectMemo[i].getFitness() - (*it) ) <  numeric_limits<float>::epsilon() ){
				stockDonneesPop[i].stSelectRang=cmpt;//cumulSelectRang;//placer la valeur dans le vector de données
				break;
			}
		}
		cmpt--;
	}
	for(unsigned short i=1;i<stockDonneesPop.size();i++){

		stockDonneesPop[i].stSelectRang+=stockDonneesPop[i-1].stSelectRang;
		//cout<<stockDonneesPop[i].stSelectRang<<endl<<"classment"<<endl;
	}

}


const std::vector<StockTraitement> &OpSelect::getDonneesPop(){
	return stockDonneesPop;
}

std::vector<unsigned short> OpSelect::roulette(unsigned short nbrInd, unsigned short choose){ 
	std::vector<unsigned short> stockInd;
	stockInd.resize(nbrInd);
	for(unsigned short j=0;j<nbrInd;j++){
		unsigned int nbrAleat, finall=0, tranche=vectMemo.size();
		if(choose==0){//roulette
			nbrAleat=rand()%static_cast<int>(etendue);
		}
		else if(choose==1){//select par rang
			for(short i=vectMemo.size()-1;i>0;i--)tranche+=i;
			nbrAleat=rand()%tranche;
		}

		for( short i=vectMemo.size()-1;i>0;i--){
			if(i==0){
				break;
			}
			if( choose==0  &&  nbrAleat>stockDonneesPop[i-1].rouletteCumul ){
				finall=i;
				break;
			}
			else if( choose==1  && nbrAleat>static_cast<unsigned short>(stockDonneesPop[i-1].stSelectRang ) ){
				finall=i;
				break;
			}
			//positionTab--;
		}
		//cout<<"final roulette ou select"<<nbrAleat<<"  "<<finall<<endl;
		//vectMemo[finall].afficherInd();
		/*stockInd[j]*/stockInd[j]=finall;

	}
	return stockInd;
}

std::vector<unsigned short> OpSelect::tournoi(unsigned short nbrInd, unsigned short nbrParticipant){
	std::set<short> setSelectAleat;
	std::set<short>::iterator itSetA, itSetB;
	std::vector<unsigned short> gagnants;

	if(nbrParticipant>vectMemo.size()  ||  nbrInd>vectMemo.size())return gagnants;//verif entrées coherentes
	gagnants.resize(nbrInd);

	for(unsigned short i=0;i<gagnants.size();i++){//1ere boucle
		setSelectAleat.clear();
		while(setSelectAleat.size()<nbrParticipant){
			setSelectAleat.insert(rand()%vectMemo.size());
		}
		while(setSelectAleat.size()!=1){//2eme boucle

			//verifier si les participants selectionnés ne sont pas deja dans le tableau "gagnants"
			for(unsigned short j=0;j<i;j++){
				if(  (*itSetA)==gagnants[j] ){
					setSelectAleat.erase( (*itSetA) );
					continue;
				}
				else if(  (*itSetB)==gagnants[j]  ){
					setSelectAleat.erase( (*itSetB) );
					continue;
				}
			}
			itSetA=setSelectAleat.begin();//premier element du set
			itSetB=setSelectAleat.begin();//deuxieme element du set
			itSetB++;
			//cout<<(*itSetA)<<"iii"<<vectMemo[(*itSetA)].getFitness()<<" comp "<<(*itSetB)<<"ii"<<vectMemo[(*itSetB)].getFitness()<<endl;
			if( vectMemo[ (*itSetA) ].getFitness()<vectMemo[ (*itSetB) ].getFitness() )//comparaison des elements
				setSelectAleat.erase(itSetA);
			else setSelectAleat.erase( (*itSetB) );
		}
		itSetA=setSelectAleat.begin();
		gagnants[i]=(*itSetA);//placer gagnant dans le tableau
	}
	return gagnants;
}

std::vector<unsigned short> OpSelect::elitisme(unsigned short nbrASelect){
	unsigned short tmp;
	std::vector<unsigned short> select;

	if(nbrASelect>vectMemo.size())return select;
	select.resize(nbrASelect);
	for(unsigned short i=1;i<nbrASelect+1;i++){
		for(unsigned short j=0;j<stockDonneesPop.size();j++){
			if(j!=0)tmp=stockDonneesPop[j].stSelectRang - stockDonneesPop[j-1].stSelectRang ;
			else tmp=stockDonneesPop[j].stSelectRang;
			if(tmp==vectMemo.size() - i){
				select[i-1]=j;//-1 pour corriger l'ecart (stSelectRang a partir de 1)
				break;
			}
		}
	}
	return select;
}

OpSelect::~OpSelect(){

}
