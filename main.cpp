// menu (jogar ou sair) [CHECK]
// pedir aos jogadores escolherem qual tipo de jogo farão
// pedir a cada jogador uma pilha e quantas pecas quer tirar
// verificar se eh possivel retirar essa quantidade de peças, 
// se sim, retirar e passar a vez, se nao, pedir outra quantidade
// a cada rodada, verificar se há jogador vencedor, se sim, o parabenizar e retornar ao menu
// indicar erros apropriados a cada entrada invalida dos usuarios.

#include <iostream>
#include <string>
#include <stack>

void exiba() {
    std::cout << "======================================\n";
    std::cout << "SEJAM BEM VINDOS AOS JOGOS DE NIM!!!\n";
    std::cout << "======================================\n";
    std::cout << "O que vocês desejam fazer?\n\n";
    std::cout << "1) Jogar;\n";
    std::cout << "2) Sair;\n";
    std::cout << "======================================\n";
    std::cout << "Opção: ";
}
void defina(char& querer) {
    std::string k;
    std::cin >> k;

    if (k.size() > 1) {
        querer = '0';
    } else {
        querer = k[0];
    }

    while (querer != '1' && querer != '2') {
        std::cout << "Insira uma opção valida (1 ou 2):";
        defina(querer);
    }
}

int main() {
    char querer = '1';
    while (querer == '1') {
        exiba();
        defina(querer);

        if (querer == '2') {
            std::cout << "Programa encerrado... voltem sempre!\n";
        }
    }
}