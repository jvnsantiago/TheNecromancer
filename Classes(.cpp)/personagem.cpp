#include "personagem.h"

string Personagem::getClasse() { return classe; }

void Personagem::setClasse(string classe) { this->classe = classe; }

string Personagem::getName() { return name; };

void Personagem::setName(string name) { this->name = name; }

int Personagem::getHp() { return hp; }

void Personagem::setHp(int hp) { this->hp = hp; }

int Personagem::getRemaining_HP() { return remaining_hp; }

void Personagem::setRemaining_HP(int remaining_hp) { this->remaining_hp = remaining_hp;}

int Personagem::getStrength() { return strength; }

void Personagem::setStrength(int strength) { this->strength = strength; }

int Personagem::getAgility() { return agility; }

void Personagem::setAgility(int agility) { this->agility = agility; }

int Personagem::getDefense() { return defense; }

void Personagem::setDefense(int defense) { this->defense = defense; }
  
int Personagem::getMana() { return mana; }

void Personagem::setMana(int mana) { this->mana = mana; }

int Personagem::getRemaining_Mana() { return remaining_mana; }

void Personagem::setRemaining_Mana(int remaining_mana) { this->remaining_mana = remaining_mana; }

int Personagem::getLuck() { return luck; }

void Personagem::setLuck(int luck) { this->luck = luck; }
