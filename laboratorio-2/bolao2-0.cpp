#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int NUM_JOGOS = 4;
const int NUM_APOSTADORES = 3;

class Jogo {
public:
    string timeCasa;
    string timeFora;
    int golsCasa;
    int golsFora;

    void cadastrarPlacar(string casa, string fora, int gCasa, int gFora) {
        timeCasa = casa;
        timeFora = fora;
        golsCasa = gCasa;
        golsFora = gFora;
    }
};

class Apostador {
private:
    string nome;
    int* palpitesGolsCasa;
    int* palpitesGolsFora;
    int pontuacaoTotal;

public:
    Apostador() {
        nome = "";
        pontuacaoTotal = 0;
        palpitesGolsCasa = new int[NUM_JOGOS];
        palpitesGolsFora = new int[NUM_JOGOS];
    }

    ~Apostador() {
        delete[] palpitesGolsCasa;
        delete[] palpitesGolsFora;
    }

    void setNome(string n) { nome = n; }
    string getNome() const { return nome; }
    int getPontuacao() const { return pontuacaoTotal; }

    void setPalpite(int indiceJogo, int gCasa, int gFora) {
        if (indiceJogo >= 0 && indiceJogo < NUM_JOGOS) {
            palpitesGolsCasa[indiceJogo] = gCasa;
            palpitesGolsFora[indiceJogo] = gFora;
        }
    }

    //Lógica de cálculo atualizada para Casa/Fora
    void calcularPontos(Jogo* jogosReais) {
        pontuacaoTotal = 0; 

        for (int i = 0; i < NUM_JOGOS; i++) {
            int realCasa = jogosReais[i].golsCasa;
            int realFora = jogosReais[i].golsFora;
            int palpiteCasa = palpitesGolsCasa[i];
            int palpiteFora = palpitesGolsFora[i];

            // Regra do Placar Exato (10 pontos)
            if (palpiteCasa == realCasa && palpiteFora == realFora) {
                pontuacaoTotal += 10;
            }
            // Regra de Acertar apenas o Vencedor/Empate (5 pontos)
            else {
                bool acertouVencedorCasa = (palpiteCasa > palpiteFora) && (realCasa > realFora);
                bool acertouVencedorFora = (palpiteFora > palpiteCasa) && (realFora > realCasa);
                bool acertouEmpate = (palpiteCasa == palpiteFora) && (realCasa == realFora);

                if (acertouVencedorCasa || acertouVencedorFora || acertouEmpate) {
                    pontuacaoTotal += 5;
                }
            }
        }
    }
};

bool compararApostadores(const Apostador* a, const Apostador* b) {
    return a->getPontuacao() > b->getPontuacao();
}

int main() {
    Jogo jogosReais[NUM_JOGOS];

    Apostador* apostadores[NUM_APOSTADORES];
    for (int i = 0; i < NUM_APOSTADORES; i++) {
        apostadores[i] = new Apostador();
    }

    int opcao;
    bool jogosCadastrados = false;
    bool palpitesCadastrados = false;

    do {
        cout << "\n=== SISTEMA DE BOLAO DA COPA ===" << endl;
        cout << "1. Cadastrar resultados dos jogos reais" << endl;
        cout << "2. Cadastrar palpites dos apostadores" << endl;
        cout << "3. Calcular pontuacao" << endl;
        cout << "4. Exibir ranking" << endl;
        cout << "5. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: {
                cout << "\n--- Cadastro de Resultados Reais ---" << endl;
                for (int i = 0; i < NUM_JOGOS; i++) {
                    string casa, fora;
                    int gCasa, gFora;
                    
                    cin.ignore(); // Limpa o buffer antes de ler strings
                    cout << "\nJogo " << i + 1 << " - Nome do Time da Casa: ";
                    getline(cin, casa);
                    cout << "Jogo " << i + 1 << " - Nome do Time de Fora: ";
                    getline(cin, fora);
                    
                    cout << "Placar (" << casa << " x " << fora << ") - Digite os gols (Casa Fora): ";
                    cin >> gCasa >> gFora;
                    
                    jogosReais[i].cadastrarPlacar(casa, fora, gCasa, gFora);
                }
                jogosCadastrados = true;
                cout << "\nResultados salvos com sucesso!" << endl;
                break;
            }
            case 2: {
                if (!jogosCadastrados) {
                    cout << "\n[ERRO] Cadastre os jogos reais primeiro para sabermos quais sao os times!" << endl;
                    break;
                }

                cout << "\n--- Cadastro de Palpites (3 Apostadores) ---" << endl;
                cin.ignore(); 
                for (int i = 0; i < NUM_APOSTADORES; i++) {
                    string nome;
                    cout << "\nNome do Apostador " << i + 1 << ": ";
                    getline(cin, nome);
                    apostadores[i]->setNome(nome);

                    // Aqui está a mágica: o loop mostra o nome real dos times que você cadastrou no passo 1!
                    for (int j = 0; j < NUM_JOGOS; j++) {
                        int pCasa, pFora;
                        cout << "  Palpite para: " << jogosReais[j].timeCasa << " x " << jogosReais[j].timeFora << endl;
                        cout << "  Gols (Casa Fora): ";
                        cin >> pCasa >> pFora;
                        apostadores[i]->setPalpite(j, pCasa, pFora);
                    }
                    cin.ignore();
                }
                palpitesCadastrados = true;
                break;
            }
            case 3: {
                if (!jogosCadastrados || !palpitesCadastrados) {
                    cout << "\n[ERRO] Cadastre os jogos e palpites antes de calcular!" << endl;
                } else {
                    for (int i = 0; i < NUM_APOSTADORES; i++) {
                        apostadores[i]->calcularPontos(jogosReais);
                    }
                    cout << "\nPontuacoes calculadas com sucesso!" << endl;
                }
                break;
            }
            case 4: {
                if (!jogosCadastrados || !palpitesCadastrados) {
                    cout << "\n[ERRO] Nao ha dados suficientes para gerar o ranking!" << endl;
                    break;
                }

                sort(apostadores, apostadores + NUM_APOSTADORES, compararApostadores);

                cout << "\n=== RANKING DO BOLAO ===" << endl;
                for (int i = 0; i < NUM_APOSTADORES; i++) {
                    cout << i + 1 << "o - " << apostadores[i]->getNome() 
                         << " - " << apostadores[i]->getPontuacao() << " pontos" << endl;
                }
                break;
            }
            case 5:
                cout << "\nEncerrando..." << endl;
                break;
            default:
                cout << "\nOpcao invalida!" << endl;
        }

    } while (opcao != 5);

    for (int i = 0; i < NUM_APOSTADORES; i++) {
        delete apostadores[i];
    }

    return 0;
}
