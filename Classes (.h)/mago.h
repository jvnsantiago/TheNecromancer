#ifndef MAGO_H
#define MAGO_H

#include "personagem.h"
#include <iostream>
#include <string>

class Mago : public Personagem {
private:
  std::string *vector_spells = new std::string[3];

public:
  Mago();
  ~Mago();
  void use_spell(std::string *vector_spells);
};

#endif