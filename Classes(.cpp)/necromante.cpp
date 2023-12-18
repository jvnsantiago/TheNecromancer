#include "necromante.h"
#include <cstdlib>
#include <ctime>
#include <string>

Necromante::Necromante() {
  classe = "necromante";
  name = "Necromante";
  hp = 50;
  remaining_hp = hp;
  strength = 2;
  agility = 1;
  defense = 2;
  luck = 2;
  mana = 5;
  vector_spells[0] = "Death";
  vector_spells[1] = "Shield";
  vector_spells[2] = "Slow";
}

Necromante::~Necromante() { delete[] vector_spells; }

int Necromante::ComportamentoNecromante() {
  unsigned seed = time(0);
  srand(seed);
  int option = rand() % 5;
  if (option > 3) {
    std::cout << std::endl
              << "O Necromante usou " << vector_spells[0] << std::endl;
  } else {
    std::cout << std::endl
              << "O Necromante usou " << vector_spells[option] << std::endl;
  }
  if (option == 0 || option > 3) {
    return 0;
  } else if (option == 1) {
    return 1;
  } else if (option == 2) {
    return 2;
  } else {
    return 3;
  }
}

void Necromante::use_spell(int i, Necromante &N1, Personagem &personagem) {
  if (i == 0) {
    personagem.setRemaining_HP(personagem.getRemaining_HP() - 5);
  } else if (i == 1) {
    N1.setDefense(personagem.getDefense() + 1);
  } else if (i == 2) {
    personagem.setAgility(personagem.getAgility() - 1);
  } else if (i == 3) {
    int dano = N1.getStrength() - personagem.getDefense();
    if (dano > 0) {
      personagem.setRemaining_HP(personagem.getRemaining_HP() - dano);
      std::cout << std::endl << "O Necromante te atacou" << std::endl;
    } else if (dano <= 0) {
      std::cout << std::endl
                << "O Necromante te atacou, mas não causou dano" << std::endl;
    }
  }
}