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
    string res = "";
    char e;
    bool res;

    cout << " CharStack(frase.lgth): "; CharStack stack(frase.length()); //print(stack);

    for(int i = 0; i < frase.length(); ++i){
        e = frase.at(i);
        if(e == ' ' || e == '.'){
            char c;
            while(stack.pop(c)){
                res += c;
            }
            res += e;
        }
        
    }

    e = 1; cout << " push (" << e << "): "; res = stack.push (e ); cout << ( res ?"OK ":" ERRO "); //print ( stack );
    e = 2; cout << " push (" << e << "): "; res = stack.push (e ); cout << ( res ?"OK ":" ERRO "); //print ( stack );
    e = 3; cout << " push (" << e << "): "; res = stack.push (e ); cout << ( res ?"OK ":" ERRO "); //print ( stack );
    res = stack . pop (e ); cout << " pop (" << e << "): "; cout << ( res ?"OK ":" ERRO "); //print ( stack );
    e = 4; cout << " push (" << e << "): "; res = stack . push (e ); cout << ( res ?"OK ":" ERRO "); //print ( stack );
    e = 5; cout << " push (" << e << "): "; res = stack . push (e ); cout << ( res ?"OK ":" ERRO "); //print ( stack );
    e = 6; cout << " push (" << e << "): "; res = stack . push (e ); cout << ( res ?"OK ":" ERRO "); //print ( stack );
    res = stack . pop (e ); cout << " pop (" << e << "): "; cout << ( res ?"OK ":" ERRO "); //print ( stack );
    res = stack . pop (e ); cout << " pop (" << e << "): "; cout << ( res ?"OK ":" ERRO "); //print ( stack );
    res = stack . pop (e ); cout << " pop (" << e << "): "; cout << ( res ?"OK ":" ERRO "); //print ( stack );
    res = stack . pop (e ); cout << " pop (" << e << "): "; cout << ( res ?"OK ":" ERRO "); //print ( stack );
    res = stack . pop (e ); cout << " pop (" << e << "): "; cout << ( res ?"OK ":" ERRO ");// print ( stack );
    e = 7; cout << " push (" << e << "): "; res = stack . push (e ); cout << ( res ?"OK ":" ERRO "); //print ( stack );
    cout << " clear (): OK "; stack . clear ();// print ( stack );
    return 0;
}