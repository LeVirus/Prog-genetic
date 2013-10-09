Individu::Individu(unsigned short taille){
	tailleTab=taille;
}

void Individu::initInd(){
	unsigned short tabVille[tailleTab];
	unsigned short tabTmp[tailleTab], tmpTaille=taille;
	parcour=new unsigned short[tailleTab];
  for(short g=0;g<tailleTab;++g){
	 tabTmp[g]=g;
  }

	
	for(unsigned short i=0;i<tailleTab;++i){
		unsigned short stock=rand()%tmpTaille;
		parcour[i]=tabTmp[stock];
		reverseTab(tabTmp[stock], tabTmp[tmpTaille-1]);
		tmpTaille--;
	}
}

Individu::reverseTab(unsigned short &a, unsigned short &b){
	if(a==b)return;
	unsigned short tmp=a;
	b=a;
	a=tmp;
}

Individu::afficherInd(){
	for(unsigned short i=0;i<nbrVille;i++){
	 cout<<parcour[i]<<"   "<<endl;
	}
}

Individu::~Individu(){
	delete parcour;
}

