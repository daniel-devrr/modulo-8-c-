#include <iostream>
#include <string>

using namespace std;

class Aluno {
    public:
    string nome;
    float nota1, nota2;
    float media;
    
    // Calcula a média e já salva no atributo da classe
    float calc_media(float n1, float n2){
        media = (n1 + n2) / 2;
        return media;
    }
    
    // Corrigido: adicionado o tipo 'float' ao parâmetro
    string apr_rpr(float valor_media){
        string result;
        
        // Corrigido: usando to_string() e o operador + para juntar os textos
        if(valor_media >= 7){ // Ajustado para >= 7 (7 também aprova)
            result = "Sua nota foi: " + to_string(valor_media) + " - Aprovado!";
        } else {
            result = "Sua nota foi: " + to_string(valor_media) + " - Reprovado!";
        }
        
        return result;
    }
};

int main(){
    Aluno aln1;
    
    aln1.nome = "Daniel";
    aln1.nota1 = 6;
    aln1.nota2 = 9;
    
    // Corrigido: passando as notas do objeto e salvando o retorno
    float media_calculada = aln1.calc_media(aln1.nota1, aln1.nota2);
    
    // Corrigido: passando a média e exibindo o resultado na tela com cout
    cout << aln1.apr_rpr(media_calculada) << endl;
    
    return 0;
}
