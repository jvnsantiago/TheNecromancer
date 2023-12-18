#include "ladino.h"
#include "personagem.h"

Ladino::Ladino() {
  classe = "ladino";
  hp = 25;
  remaining_hp = hp;
  strength = 3;
  agility = 3;
  defense = 1;
  luck = 3;
  mana = 3;
  remaining_mana = mana;
  vector_item[0] = "Healing Potion";
  vector_item[1] = "Mana Potion";
  vector_item[2] = "Strength Potion";
  vector_item[3] = "Agility Potion";
  vector_item[4] = "Luck Potion";
  vector_item[5] = "Defense Potion";
}

Ladino::~Ladino() { delete[] vector_item; }

int Ladino::Menu_item() {
  int option;
  std::cout << "Selecione o item que deseja usar: " << std::endl;
  std::cout << "1 - " << vector_item[0] << std::endl;
  std::cout << "2 - " << vector_item[1] << std::endl;
  std::cout << "3 - " << vector_item[2] << std::endl;
  std::cout << "4 - " << vector_item[3] << std::endl;
  std::cout << "5 - " << vector_item[4] << std::endl;
  std::cout << "6 - " << vector_item[5] << std::endl;
  std::cin >> option;
  if (option < 1 || option > 6) {
    std::cout << std::endl << "Entre com uma opção válida" << std::endl;
    return Menu_item();
  } else {
    return option;
  }
}

void Ladino::Use_item(int i, Ladino &l) {
  if (i == 1 && l.getRemaining_HP() < l.getHp()) {
    l.setRemaining_HP(l.getRemaining_HP() + 5);
    if (l.getRemaining_HP() > l.getHp()) {
      l.setRemaining_HP(l.getHp());
    }
    std::cout << std::endl
              << "Você usou uma poção de cura (+5 HP)" << std::endl;
  } else if (i == 2 && l.getRemaining_Mana() < l.getMana()) {
    l.setRemaining_Mana(l.getRemaining_Mana() + 5);
    if (l.getRemaining_Mana() > l.getMana()) {
      l.setRemaining_Mana(l.getMana());
    }
    std::cout << std::endl
              << "Você usou uma poção de mana (+5 MP)" << std::endl;
  } else if (i == 3 && l.getStrength() < 10) {
    l.setStrength(l.getStrength() + 1);
    std::cout << std::endl
              << "Você usou uma poção de força (+1 FOR)" << std::endl;
  } else if (i == 4 && l.getAgility() < 10) {
    l.setAgility(l.getAgility() + 1);
    std::cout << std::endl
              << "Você usou uma poção de agilidade (+1 AGI)" << std::endl;
  } else if (i == 5 && l.getLuck() < 10) {
    l.setLuck(l.getLuck() + 1);
    std::cout << std::endl
              << "Você usou uma poção de sorte (+1 SOR)" << std::endl;
  }
  else if (i == 6 && l.getDefense() < 10) {
    l.setDefense(l.getDefense() + 1);
    std::cout << std::endl
              << "Você usou uma poção de defesa (+1 DEF)" << std::endl;
  }
}

std::string Ladino::getVector_Item() { return *vector_item; }