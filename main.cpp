#include <iostream>
#include "Stack.cpp"

/*
    TODO:

    DONE:
    #criar um método que imprime a quantidade de elemento no seu nó
    #criar um método que atualiza o valor de um nó

    #criar um método que adiciona o nó em um determinado index [0]
    #criar um método que insere o valor no final[]

    #criar um metódo que remove o nó com o index
        #criar um metódo que remove o primeiro nó
        #criar um metódo que remove o ultimo nó
*/

int main()
{
    Stack stek;

    stek.Emplace(69);
    stek.Emplace(420);
    stek.Emplace(666);

    stek.Insert(13);
    stek.Insert(24);

    // TODO: Encapsulate
    stek.At(0)->val = 777;

    for(int i = 0; i < stek.Size(); i++)
    {
        std::cout << stek.At(i)->val << std::endl;
    }

    std::cout << std::endl << stek.Size() << std::endl;
    
    return 0;
}