#include "Carte.hpp"
#include <cstdlib>
#include <iostream>
#include <cmath>
#include "constantes.hpp"
 
using namespace std;

Carte::Carte(short nombre){
  nbrVille=nombre;
  tabVille=new Ville[nbrVille];
  tabDistanceVille=new float*[nbrVille];
  tabDistanceVille[0]=new float[nbrVille*nbrVille];
  for(short i=1;i<nbrVille;i++)tabDistanceVille[i]=tabDistanceVille[0] + i * nbrVille;
  initVille();
}

void Carte::initVille(){
  for(unsigned short k=0;k<nbrVille;k++){
	 tabVille[k].x=rand()%LONGUEUR_CARTE+1;
	 tabVille[k].y=rand()%LARGEUR_CARTE+1;
  }
  for(unsigned short j=0;j<nbrVille;j++)
	  for(unsigned short i=0;i<nbrVille;i++){
		 if(  i==j  ){
			tabDistanceVille[i][j]=0;
			//i+=nbrVille;
		 }
		 else {
			if( i<j )continue;
			tabDistanceVille[i][j]=distance(tabVille[i], tabVille[j]);
			tabDistanceVille[j][i]=tabDistanceVille[i][j];
		 }
	  }
}

/*void Carte::procheVoisins(short choix){
  short stock=0, stockTotal=0, villeActuelle=choix, villeActuelleTmp, tmpI;
  short tabTmp[nbrVille];
  if(choix>=nbrVille)return;
  chaineVille.clear();
  for(short g=1;g<nbrVille;++g){
	 chaineVille.push_front(g);
  }
for(itVille=chaineVille.begin();itVille!=chaineVille.end();itVille++)cout<<(*itVille)<<" s ";
  //itVille=chaineVille.erase(itVille+=choix);
  
  
  
  while( !chaineVille.empty() ){
	 //itVille=chaineVille.begin();//suprimmer la ville actuelle de la liste
	 //chaineVille.erase(itVille+=villeActuelle);
	 chaineVille.remove(villeActuelle);
	 //itVille=chaineVille.begin();//replacer iterator au debut de liste
	 //itVille++;
	 for(itVille=chaineVille.begin();itVille!=chaineVille.end();itVille++){
//cout<<(*itVille);
		if( tabVille[villeActuelle][ (*itVille) ]>stock ){
		  stock=tabVille[villeActuelle][ (*itVille) ];
		  villeActuelleTmp=tmpI;
		}
	 }
	 villeActuelle=villeActuelleTmp;
	 stockTotal+=stock;
	 //itVille=chaineVille.erase(itVille);
  }
  cout<<"stock"<<stockTotal<<endl;
}*/

void Carte::affichage(){
  cout<<endl<<"AFFICHAGE CARTE"<<endl;
  for(short j=0;j<nbrVille;j++){
	 cout<<j<<"   "<<tabVille[j].x<<"   "<<tabVille[j].y<<endl;
  }
  cout<<endl;
  for(short i=0;i<nbrVille*nbrVille;i++){
	 if(i%nbrVille==0)cout<<endl;
	 cout<< tabDistanceVille[0][i];
	 if( tabDistanceVille[0][i]<10 )cout<<"   ";
	 else cout<<"  ";
  }
  cout<<endl<<"FIN AFFICHAGE CARTE"<<endl;
}

float Carte::distance(Ville a, Ville b){
  return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}

float Carte::returnDistance(short villeA, short villeB){
  if( !tabDistanceVille ||  villeA>nbrVille-1  || villeA<0  ||  villeB<0 || villeB> nbrVille-1 )
	 return 0;
  return tabDistanceVille[villeA][villeB];
}

Carte::~Carte(){
  delete tabDistanceVille[0];
  delete tabDistanceVille;
  delete tabVille;

}

 
