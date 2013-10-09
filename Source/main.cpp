#include "Racine.hpp"
#include "Carte.cpp"

using namespace std;

int main(){
  srand(time(NULL));
  Carte a(5);
  a.affichage();
  return 0;
}