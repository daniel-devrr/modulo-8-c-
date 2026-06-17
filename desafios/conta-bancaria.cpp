#include <iostream>
#include <string>

using namespace std;

class Conta_Bancaria {
    public:
        string titular;
        float saldo;
        
        void depositar(float valor_deps) {
            saldo = saldo + valor_deps; 
        }
        
        void sacar(float valor_saque) {
            if (saldo >= valor_saque) { // Opcional: evita saldo negativo
                saldo = saldo - valor_saque;
            } else {
                cout << "Saldo insuficiente!" << endl;
            }
        }
};

int main() {
    Conta_Bancaria cnt1;
    cnt1.titular = "Roberval";
    cnt1.saldo = 1231.12;
    
    float deposito;
    float saque;
    
    cout << "Bem Vindo, " << cnt1.titular << endl;
    cout << "Seu Saldo atual e de: R$ " << cnt1.saldo << endl;
    
    cout << "\nDigite o valor de deposito: ";
    cin >> deposito;
    
    cout << cnt1.titular << " esta depositando R$ " << deposito << endl;
    cnt1.depositar(deposito);
    
    cout << "Novo Saldo: R$ " << cnt1.saldo << endl;
    
    cout << "\nDigite o valor de saque: ";
    cin >> saque;
    
    cout << cnt1.titular << " esta sacando R$ " << saque << endl;
    cnt1.sacar(saque); 
    
    cout << "Saldo Final: R$ " << cnt1.saldo << endl;

    return 0;
}
