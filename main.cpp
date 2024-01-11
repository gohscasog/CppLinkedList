#include <iostream>
#include "Stack.cpp"

/*
    TODO:
    #criar um método que adiciona o nó em um determinado index [0]
    #criar um método que insere o valor no final[]
    #criar um método que atualiza o valor de um nó
    #criar um metódo que remove o primeiro nó
    #criar um metódo que remove o ultimo nó
    #criar um metódo que remove o nó com o index
    #criar um método que imprime a quantidade de elemento no seu nó
*/

int main()
{
    try
    {
        Stack stek;

        stek.Emplace(69);
        stek.Emplace(420);
        stek.Emplace(666);

        stek.Insert(13);
        stek.Insert(24);

        stek.InsertAt(0, 0);
        stek.InsertAt(-1, 2);
        stek.InsertAt(1, stek.Size() - 1);

        stek.Set(777, 0);
        stek.Set(123, 2);
        stek.Set(999, stek.Size() - 1);

        stek.Pop();
        stek.Pull();

        stek.Remove(0);
        stek.Remove(2);
        stek.Remove(stek.Size() - 1);
        
        std::cout << stek.Size() << "\n\n";

        for(int i = 0; i < stek.Size(); i++)
        {
            std::cout << stek.Get(i) << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(...)
    {
        std::cerr << "Unhandled exception" << '\n';
    }
    
    return 0;
}