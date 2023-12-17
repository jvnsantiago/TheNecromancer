#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <iostream>
#include <string>
using namespace std;

class Personagem {
protected:
  string name;
  string classe;
  int hp;
  int remaining_hp;
  int strength;
  int agility;
  int defense;
  int mana;
  int remaining_mana;
  int luck;

public:
  virtual ~Personagem() {};
  void attack();
  string getClasse();
  void setClasse(string classe);
  string getName();
  void setName(string name);
  int getHp();
  void setHp(int hp);
  int getRemaining_HP();
  void setRemaining_HP(int remaining_hp);
  int getStrength();
  void setStrength(int strength);
  int getDefense();
  void setDefense(int defense);
  int getAgility();
  void setAgility(int agility);
  int getMana();
  void setMana(int mana);
  int getRemaining_Mana();
  void setRemaining_Mana(int remaining_mana);
  int getLuck();
  void setLuck(int luck);
};

#endif