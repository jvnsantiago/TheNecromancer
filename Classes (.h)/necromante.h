#ifndef NECROMANTE_H
#define NECROMANTE_H

#include "personagem.h"
#include <iostream>
#include <string>

class Necromante : public Personagem {
private:
  std::string *vector_spells = new std::string[3];

public:
  Necromante();
  ~Necromante();
  void use_spell(std::string *vector_spells);
  int ComportamentoNecromante();
};

#endif