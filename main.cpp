#include "Racine.hpp"

using namespace std;

class Carte;
class Population;

Carte *carteG;
Population *popG;

int main(){
  srand(time(NULL));
  Racine a;
  a.lancerProg();
  return 0;
}
