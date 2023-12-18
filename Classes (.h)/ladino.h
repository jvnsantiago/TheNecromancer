#ifndef LADINO_H
#define LADINO_H

#include "personagem.h"
#include <iostream>
#include <string>

class Ladino : public Personagem {
private:
  std::string *vector_item = new std::string[6];

public:
  Ladino();
  ~Ladino();
  std::string getVector_Item();
  int Menu_item();
  void Use_item(int i, Ladino &l);
};

#endif