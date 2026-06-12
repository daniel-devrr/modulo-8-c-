#include <iostream>
using namespace std;

int main()
{
    // 1. Criamos as gavetas (Variáveis Inteiras)
    int palpiteBrasil, palpiteEgito;
    int realBrasil, realEgito, realAfricaDoSul, realMarrocos, realFrança, realArgentina, realAlemanha, realCostaRica;
    // msg > cout O resultado de BRASIL X EGITO FOI: << real << " x " << real

    cout << "Bolão Copa 2026";
    cout << "Jogos Cadastrados:\n";
    cout << "Brasil x Egito\n";
    cout << "Africa do Sul x Marrocos\n";
    cout << "Franca x Argentina\n";
    cout << "Alemanha x Costa Rica\n";    

    // 2. O computador pergunta e você digita (cout e cin)

    cout << "PRIMEIRO JOGO | BRASIL x EGITO";
    cout << "Digite seu palpite para o BRASIL: ";
    cin >> palpiteBrasil;

    cout << "Digite seu palpite para o EGITO: ";
    cin >> palpiteEgito;

    // Só para testar se ele guardou certo:
    cout << "Voce apostou: " << palpiteBrasil << " x " << palpiteEgito << endl;

    int pontos = 0;

    if (palpiteBrasil == realBrasil && palpiteEgito == realEgito)
    {

        int ganhaPonto = 10;

        pontos = pontos + ganhaPonto;
        cout << "\nO resultado de BRASIL X EGITO FOI: " << realBrasil << " x " << realEgito;
        cout << "\nParabens! Voce acertou seus palpites. " << "\nGanhou " << ganhaPonto << " pontos\n";
        cout << "\nPontos acumulados: " << pontos << endl;
    }
    else
    {
        cout << "\nO resultado de BRASIL X EGITO FOI: " << realBrasil << " x " << realEgito;
        cout << "\nNao foi o resultado exato..." << endl;
    }
    return 0;
}
