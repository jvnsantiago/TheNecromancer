#include "guerreiro.h"
#include "ladino.h"
#include "mago.h"
#include "necromante.h"
#include "personagem.h"
#include <fstream>
#include <iostream>
#include <string>

void menuInicial();
void createCharacter();
void game(Personagem &player);
int menuJogo(Personagem &player);
void Pontuacao(int turno, Personagem &player);
void checaPontuacao();

int main() { menuInicial(); }

void menuInicial() {
  int option = 0;
  std::cout << "Entre com a opção desejada: " << std::endl;
  std::cout << "1 - Começar o jogo" << std::endl;
  std::cout << "2 - Checar Pontuação" << std::endl;
  std::cout << "3 - Sair" << std::endl;
  // CASO HAJA TEMPO std::cout << " - Checar status de cada classe" <<
  // std::endl;

  std::cin >> option;
  if (option == 1) {
    createCharacter();
  } else if (option == 2) {
    checaPontuacao();
  } else if (option == 3) {
    std::cout << std::endl << "Obrigado por jogar!" << std::endl;
  } else {
    std::cout << "Entre com uma opção válida" << std::endl;
    return menuInicial();
  }
}

void createCharacter() {
  int option = 0;
  std::string n;
  std::cout << std::endl << "Escolha a classe desejada: " << std::endl;
  std::cout << "1 - Guerreiro" << std::endl;
  std::cout << "2 - Ladino" << std::endl;
  std::cout << "3 - Mago" << std::endl;
  // CASO HAJA TEMPO std::cout << "4 - Personalizado" << std::endl;
  std::cin >> option;
  if (option == 1) {
    std::cout << std::endl << "Digite o nome do personagem: " << std::endl;
    std::cin >> n;
    Personagem *player = new Guerreiro;
    player->setName(n);
    game(*player);
  } else if (option == 2) {
    std::cout << std::endl << "Digite o nome do personagem: " << std::endl;
    std::cin >> n;
    Personagem *player = new Ladino;
    player->setName(n);
    game(*player);
  } else if (option == 3) {
    std::cout << std::endl << "Digite o nome do personagem: " << std::endl;
    std::cin >> n;
    Personagem *player = new Mago;
    player->setName(n);
    game(*player);
  } else {
    std::cout << "Entre com uma opção válida" << std::endl;
    std::cin >> n;
    return createCharacter();
  }
}

void game(Personagem &player) {
  int turno = 1;
  std::cout << std::endl;
  std::cout << "The Necromancer" << std::endl;
  std::cout << "Use your powers wisely to defeat the Necromancer" << std::endl
            << std::endl;
  Personagem *N1 = new Necromante;
  Necromante *ptrNecromante = dynamic_cast<Necromante *>(N1);
  if (player.getClasse() == "ladino") {
    int option = 0;
    int option2 = 0;
    int acaoNecro = 0;
    bool usoItem = true;
    Ladino *ptrPlayer = dynamic_cast<Ladino *>(&player);
    while (ptrPlayer->getRemaining_HP() > 0 &&
           ptrNecromante->getRemaining_HP() > 0) {
      bool NecroAtivo = true;
      if (usoItem == false &&
          ptrPlayer->getRemaining_Mana() < ptrPlayer->getMana()) {
        ptrPlayer->setRemaining_Mana(ptrPlayer->getRemaining_Mana() + 1);
      }
      std::cout << std::endl << "Turno " << turno << std::endl;
      if (ptrNecromante->getAgility() > ptrPlayer->getAgility()) {
        acaoNecro = ptrNecromante->ComportamentoNecromante();
        ptrNecromante->use_spell(acaoNecro, *ptrNecromante, *ptrPlayer);
        NecroAtivo = false;
      }
      option2 = menuJogo(*ptrPlayer);
      if (option2 == 1) {
        int dano = ptrPlayer->getStrength() - ptrNecromante->getDefense();
        if (dano > 0) {
          ptrNecromante->setRemaining_HP(ptrNecromante->getRemaining_HP() -
                                         dano);
          std::cout << "Você atacou o Necromante" << std::endl;
        } else if (dano <= 0) {
          std::cout << "Você atacou o Necromante, mas não causou dano";
        }
        usoItem = 0;
      } else if (option2 == 2 && ptrPlayer->getRemaining_Mana() > 0) {
        ptrPlayer->setRemaining_Mana(ptrPlayer->getRemaining_Mana() - 1);
        option = ptrPlayer->Menu_item();
        ptrPlayer->Use_item(option, *ptrPlayer);
        usoItem = 1;
      } else if (option2 == 2 && ptrPlayer->getRemaining_Mana() <= 0) {
        std::cout << "Você não tem mana suficiente para usar esta habilidade."
                  << std::endl;
        option2 = menuJogo(*ptrPlayer);
      }
      turno += 1;
      if (ptrNecromante->getAgility() <= ptrPlayer->getAgility() &&
          NecroAtivo == true) {
        acaoNecro = ptrNecromante->ComportamentoNecromante();
        ptrNecromante->use_spell(acaoNecro, *ptrNecromante, *ptrPlayer);
      }
    }
    if (ptrNecromante->getRemaining_HP() <= 0) {
      std::cout << "Você derrotou o Necromancer em: " << turno << " turnos!"
                << std::endl;
      
    }
    if (ptrPlayer->getRemaining_HP() <= 0) {
      std::cout << std::endl
                << "Você foi derrotado pelo Necromancer em: " << turno
                << " turnos!" << std::endl;
    }
    Pontuacao(turno, *ptrPlayer);
    free(ptrNecromante);
    free(ptrPlayer);
  }
}

int menuJogo(Personagem &player) {
  int option = 0;
  std::cout << std::endl << player.getName() << std::endl;
  std::cout << "HP(" << player.getRemaining_HP() << "/" << player.getHp() << ")"
            << std::endl;
  std::cout << "MP(" << player.getRemaining_Mana() << "/" << player.getMana()
            << ")" << std::endl;
  if (player.getClasse() == "ladino") {
    std::cout << std::endl << "1 - Atacar" << std::endl;
    std::cout << "2 - Usar item(-1 Mana)" << std::endl;
    std::cin >> option;
  } else if (player.getClasse() == "mago") {
    std::cout << std::endl << "1 - Atacar" << std::endl;
    std::cout << "2 - Usar magia(-1 Mana)" << std::endl;
    std::cin >> option;
  } else if (player.getClasse() == "guerreiro") {
    std::cout << std::endl << "1 - Atacar" << std::endl;
    std::cout << "2 - Defender (-1 Mana)" << std::endl;
    std::cin >> option;
  }
  if (option != 1 && option != 2) {
    std::cout << std::endl << "Entre com uma opção válida" << std::endl;
    return menuJogo(player);
  }
  return option;
}

void Pontuacao(int turno, Personagem &player) {
  int pontuacao = 0;
  if(player.getRemaining_HP() <= 0){
    pontuacao = 0+turno/2;
  }
  else{
    pontuacao = 100 - turno + player.getRemaining_HP();
  }
  std::ofstream file("pontuacao.txt", ios::app);
  if (file.is_open()) {
    file << player.getName() << " " << pontuacao << std::endl;
    file.close();
  } else {
    std::cout << "Não foi possível abrir o arquivo" << std::endl;
  }
}

void checaPontuacao() {
  std::ifstream file("pontuacao.txt");
  if (file.is_open()) {
    std::string line;
    std::cout << std::endl << "Pontuação dos jogadores:" << std::endl;
    while (std::getline(file, line)) {
      std::cout << line << std::endl;
    }
    file.close();
  } else {
    std::cout << "Não foi possível abrir o arquivo" << std::endl;
  }
  std::cout << std::endl;
  menuInicial();
}