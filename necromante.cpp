#include "necromante.h"
#include <cstdlib>
#include <ctime>

Necromante::Necromante() {
  classe = "necromante";
  name = "Necromante";
  hp = 50;
  remaining_hp = hp;
  agility = 1;
  defense = 2;
  luck = 2;
  mana = 5;
  vector_spells[0] = "Death";
  vector_spells[1] = "Shield";
  vector_spells[2] = "Slow";
}

Necromante::~Necromante(){
  delete[] vector_spells;
}



int Necromante::ComportamentoNecromante() {
  unsigned seed = time(0);
  srand(seed);
  int option = rand() % 4;
  if (option == 0) {
    return 0;
  } else if (option == 0) {
    return 1;
  } else if (option == 2) {
    return 2;
  } else {
    return 3;
  }
}