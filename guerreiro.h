#ifndef GUERREIRO_H
#define GUERREIRO_H

#include "personagem.h"
#include <iostream>
#include <string>

class Guerreiro : public Personagem {
private:
  void defender();
public:
  Guerreiro();
  ~Guerreiro();
};

#endif