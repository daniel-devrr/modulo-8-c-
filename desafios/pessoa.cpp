#include <iostream>
#include <string>

using namespace std;
class Pessoa
{
public:
    string nome;
    int idade;

    void mostraNome()
    {
        cout << "Nome: " << nome << " Idade: " << idade << endl;
    }
};

int main(){
    Pessoa pessoa1;
    pessoa1.nome = "Daniel";
    pessoa1.idade = 16;

    pessoa1.mostrarNome();

    return 0;
}

