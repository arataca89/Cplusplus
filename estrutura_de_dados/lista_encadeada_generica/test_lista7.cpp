/********************************************************************
 * Arquivo  : test_lista7.cpp
 * Data     : 20220402
 *  
 * Teste da lista encadeada usando um tipo definido pelo usuario.
 * 
 * Funcionalidades testadas:
 *      Criacao da lista
 *      push_fim()       
 *      pop_fim()
 *      print()
 *      Destruicao da lista
 * 
 * arataca89@gmail.com
 * Aulas particulares de programacao C/C++
 * *****************************************************************/
#include <iostream>
using std::ostream;
using std::cout;

#include <string>
using std::string;

#include "lista_encadeada.hpp"

class MyClass{
    friend ostream& operator<<(ostream& output, const MyClass& objeto){
        output << "{" << objeto.i << "," << objeto.d << "," << objeto.s << "}";
        return output;
    };

    public:
        MyClass(){};
        MyClass(int ii, double dd, string ss): i(ii), d(dd), s(ss) {};

    private:
        int i;
        double d;
        string s;
};

int main(){
    Lista<MyClass> lista1;

    MyClass mc1 = MyClass(1, 1.5, "primeiro");
    MyClass mc2 = MyClass(2, 2.5, "segundo");
    MyClass mc3 = MyClass(3, 3.5, "terceiro");
    MyClass mc4 = MyClass(4, 4.5, "quarto");
    MyClass mc5 = MyClass(5, 5.5, "quinto");

    MyClass objetos[5] = {mc1, mc2, mc3, mc4, mc5};

    cout << "\nInserindo no final:\n";
    for(int i = 0; i < 5; i++){
        Node<MyClass> n1 = Node<MyClass>(objetos[i]);
        lista1.push_fim(n1);
        lista1.print();
    }

    cout << '\n';
    
    for(int i = 0; i < 5; i++){
        MyClass mc6;
        Node<MyClass> n1 = Node<MyClass>(mc6);
        lista1.pop_fim(n1);
        cout << "Retirando o item ";
        cout << n1.dados() << " do final\n";
        lista1.print();
        cout << '\n';
    }

    cout << "\n";

    return 0;
}
/********************************************************************
 * arataca89@gmail.com
 * Aulas particulares de programacao C/C++
 * *****************************************************************/