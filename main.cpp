// pedir a cada jogador uma pilha e quantas pecas quer tirar
// verificar se eh possivel retirar essa quantidade de peças, 
// se sim, retirar e passar a vez, se nao, pedir outra quantidade
// a cada rodada, verificar se há jogador vencedor, se sim, o parabenizar e retornar ao menu
// indicar erros apropriados a cada entrada invalida dos usuarios.

#include <iostream>
#include <string>
#include <stack>

void exiba_menu_principal() {
    std::cout << "======================================\n";
    std::cout << "SEJAM BEM VINDOS AOS JOGOS DE NIM!!!\n\n";
    std::cout << "Nesses jogos para dois jogadores, vocês revezarao retirando peças de pilhas, e ganha quem retirar a ultima peca. Em cada vez, o jogador deve retirar 1 ou 2 pecas de somente uma pilha.\n";
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

    if (x == 1) {
        while (opcao != '1' && opcao != '2') {
            std::cout << "Insira uma opção valida (1 ou 2):";
            defina_opcao(opcao, 1);
        }
    } else {
        while (opcao != '1' && opcao != '2' && opcao != '3') {
            std::cout << "Insira uma opção valida (1, 2 ou 3):";
            defina_opcao(opcao, 2);
        }
    }
}
void exiba_menu_jogos() {
    std::cout << "======================================\n";
    std::cout << "Opçoes de jogos: \n";
    std::cout << "1) 3 pilhas com 5 pecas cada\n";
    std::cout << "2) 4 pilhas com 7 pecas cada\n";
    std::cout << "3) 5 pilhas com 9 pecas cada\n";
    std::cout << "Inserir opção: ";
}

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
    }
}