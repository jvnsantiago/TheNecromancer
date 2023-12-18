#include "mago.h"

Mago::Mago() {
  classe = "mage";
  hp = 30;
  remaining_hp = hp;
  agility = 1;
  defense = 2;
  luck = 2;
  mana = 4;
  remaining_mana = mana;
  vector_spells[0] = "Fire";
  vector_spells[1] = "Ice";
  vector_spells[2] = "Acid";
}

Mago::~Mago(){
  delete[] vector_spells;
}