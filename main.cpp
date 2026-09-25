#include <iostream>
#include <string>
#include <map>
#include <utility>

void exiba_menu_principal() {
    std::cout << "======================================\n";
    std::cout << "SEJAM BEM VINDOS AOS JOGOS DE NIM!!!\n\n";
    std::cout << "Nesses jogos para dois jogadores, vocês revezarao retirando peças de pilhas, \ne ganha quem retirar a ultima peca. Em cada vez, o jogador deve retirar 1 ou 2 pecas de somente uma pilha.\n";
    std::cout << "\n======================================\n";
    std::cout << "O que vocês desejam fazer?\n\n";
    std::cout << "1) Jogar;\n";
    std::cout << "2) Sair;\n";
    std::cout << "======================================\n";
    std::cout << "Opção: ";
}
void defina_opcao(char& opcao, int x) {
    std::string k;
    std::cin >> k;

    if (k.size() > 1) {
        opcao = '0';
    } else {
        opcao = k[0];
    }
    
    while (!(opcao >= '1' && (char)(49 + x) >= opcao)) {
        std::cout << "Insira uma opção valida: ";
        defina_opcao(opcao, x);
    }
    
}
void exiba_menu_jogos() {
    std::cout << "======================================\n";
    std::cout << "Opçoes de jogos: \n";
    std::cout << "\n1) 3 pilhas com 5 pecas cada\n";
    std::cout << "2) 4 pilhas com 7 pecas cada\n";
    std::cout << "3) 5 pilhas com 9 pecas cada\n";
    std::cout << "\nInserir opção: ";
}
struct Pilha {
    std::map <int, int> pilhas;
    int tipo_de_jogo;
    void gerar(char& jogo) {
        tipo_de_jogo = jogo;
        if (jogo == '1') {
            for (int i = 0; i < 3; i ++) {
                pilhas[i + 1] = 5;
            }
        } else if (jogo == '2') {
            for (int i = 0; i < 4; i ++) {
                pilhas[i + 1] = 7;
            }
        } else {
            for (int i = 0; i < 5; i ++) {
                pilhas[i + 1] = 9;
            }
        }
    }

    void exibir() {
        std::cout << "\n";
        for (std::pair <int, int> x : pilhas) {
            std::cout << "Pilha " << x.first << ": ";
            for (int i = 0; i < x.second; i ++) {
                std::cout << "[]";
            }
            std::cout << "\n";
        }
    }

    void retirar(char pilha_que_devemos_retirar, char quant_pecas) {
        while (pilhas[(int)pilha_que_devemos_retirar - 48] < (int)quant_pecas - 48) {
            
            std::cout << "Não foi possível retirar essa quantidade de pecas da pilha.\n";
            
            if (pilhas[(int)pilha_que_devemos_retirar - 48] == 0) {
                std::cout << "Escolha outra pilha para retirar essa quantidade de peças: ";
                defina_opcao(pilha_que_devemos_retirar, tipo_de_jogo + 2);

            } else {
                std::cout << "Escolha outra quantidade de peças para retirar da mesma pilha: ";
                defina_opcao(quant_pecas, 1);
            }
        }

        pilhas[(int)pilha_que_devemos_retirar - 48] -= (int)quant_pecas - 48;
    }

    bool ha_vencedor() {
        for (std::pair <int, int> x: pilhas) {
            if (x.second != 0) {
                return false;
            }
        }
        return true;
    }

};

int main() {
    char querer = '1';
    while (querer == '1') {
        exiba_menu_principal();
        defina_opcao(querer, 1);

        if (querer == '2') {
            std::cout << "Programa encerrado... voltem sempre!\n";
        }

        char jogo;
        exiba_menu_jogos();
        defina_opcao(jogo, 2);

        Pilha pilha;
        pilha.gerar(jogo);
        
        int jogador_atual = 2;
        while (!pilha.ha_vencedor()) {
            std::cout << "======================================\n";
            std::cout << "\nEstado atual das pilhas: \n";
            pilha.exibir();
            jogador_atual = 3 - jogador_atual;
            std::cout << "======================================\n";
            std::cout << "\nJogador atual: " << jogador_atual << "\n";

            char qual_pilha_retirar;
            std::cout << "De qual pilha voce quer retirar? ";
            defina_opcao(qual_pilha_retirar, jogo + 2);

            char retirar_da_pilha; 
            std::cout << "Insira quantas pecas voce quer retirar: ";
            defina_opcao(retirar_da_pilha, 1);

            pilha.retirar(qual_pilha_retirar, retirar_da_pilha);

            if(pilha.ha_vencedor()) {
                std::cout << "\nPARABÉNS!! O jogador " << jogador_atual << " venceu!\n\n";
            }
        }
    }
}