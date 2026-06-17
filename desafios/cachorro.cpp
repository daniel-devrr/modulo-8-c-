#include <iostream>
#include <string>

using namespace std;

class Cachorro {
    public:
    string nome;
    string raca;
    
    void latir() {
        std::cout << "Auau! " << nome << " está latindo!" << std::endl;
        
    }
};

int main(){
    
    Cachorro cao1;
    cao1.nome = "Roberval";
    cao1.raca = "PitBugs";
    
    cao1.latir();
}