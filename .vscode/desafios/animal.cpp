#include <iostream>
#include <string>

using namespace std;

class Animal {
    public:
    string especie;
    string som;
    
    void emitirSom(){
        std::cout << "O " << especie << " está a " << som << std::endl;
    }
};

int main(){
    
    Animal animal1;
    
    animal1.som = "uivar";
    animal1.especie = "Lobo";
    
    animal1.emitirSom();
}