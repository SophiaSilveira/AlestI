#include <iostream>
#include <string>
#include "CharStack.hpp"

using namespace std;

/*void print ( CharStack &stack ) {// & informaque esapassando por referencia

    cout << " " << stack . str () << " size =" << stack . size () << "/" << stack . maxSize () << " top=";
    int t; bool res = stack . top (t );
    if ( res ) cout << t; else cout << "X";
    cout << " isEmpty =" << stack . isEmpty () << " isFull =" << stack . isFull () << endl ;
}*/

int main () {
    string frase = "ESTE EXERCICIO E MUITO FACIL.";
    string resFrase = "";
    char e;
    bool res;

    cout << frase << endl;;

    cout << " CharStack(frase.lgth): "; CharStack stack(frase.length()); 
    cout << endl;//print(stack);

    for(int i = 0; i < frase.length(); ++i){
        e = frase.at(i);

       
        if(e == ' ' || e == '.'){
            char c;
            while(stack.pop(c)){
                resFrase += c;
            }
            resFrase += e;
        }else{
            cout << " push (" << e << "): "; res = stack.push (e); 
            cout << ( res ?"OK ":" ERRO ");
            cout << endl;
        }
        
    }

    cout << resFrase;

    cout << " clear (): OK "; stack.clear();
    return 0;
}