#include <iostream>

#include "StringArrayList.hpp"

int main () {
    StringArrayList * l = new StringArrayList (28);

    if ( l -> maxSize () != 28 || !l -> isEmpty () ) cerr << " ERRO01 " << endl ;

    string saudacao [] = { " Bom ", "dia , ", " pessoal !", " Bom ", "dia , ", " Bom "};
    int tamSaudacao = sizeof ( saudacao ) / sizeof ( string );

    l -> add ( saudacao [1]); l -> add ( saudacao [2]); l -> add (0 , saudacao [0]); l -> add ( saudacao [3]); l -> add ( saudacao [4]); l -> add ( saudacao [5]);
    
    if ( l -> contains (" teste ") ) cerr << " ERRO02 " << endl ;
    if ( !l -> contains ( saudacao [0]) || !l -> contains ( saudacao [1]) || !l -> contains ( saudacao [2]) ) cerr << " ERRO03 " << endl ;
    for ( int i =0; i <l -> size (); ++ i) if ( l -> indexOf (i , saudacao [ i ]) != i ) cerr << " ERRO04 " << endl ;
    if ( l -> indexOf ( saudacao [0])!=0 || l -> indexOf ( saudacao [1])!=1 || l -> indexOf ( saudacao [2])!=2) cerr << " ERRO05 " << endl ;
    
    l -> remove ( l -> size () -1 ); l -> remove ( l -> size () -1 ); l -> remove ( l -> size () -1 );
    cout << l -> str () << endl;

    if ( l -> size () != 3 || l -> isFull () || l -> isEmpty () ) cerr << " ERRO06 " << endl ;
    for ( int i =0; i <l -> size (); ++ i) { string s; bool res = l -> get (i ,s ); if ( ! res || s != saudacao [i] ) cerr << " ERRO07 " << endl ; }
    
    l -> add (" din â mica ."); l -> remove (1); l -> remove (0); l -> remove (0);
    l -> add (0 ," Lista "); l -> add (1 ," ligada "); l -> add (2 ,"é "); l -> add (3 ," uma "); l -> add (4 ," estrutura ");
    l -> add (5 ,"de "); l -> add (6 ," dados "); l -> add (7 ," estranha "); l -> add (8 ,"e "); l -> remove (7);
    l -> add (7 ," linear "); l -> add (2 ,"ou "); l -> add (3 ," lista "); l -> add (4 ," encadeada ");
    
    cout << l -> str () << endl ;
    
    if ( l -> size () != 13 || l -> isFull () || l -> isEmpty () ) cerr << " ERRO08 " << endl ;
   
    l -> clear ();
   
    if ( l -> str ()!= "" || l -> maxSize () != 28 || !l -> isEmpty () ) cerr << " ERRO09 " << endl ;
   
    string palavras [] = { " apontam ", "que ", " refer ê ncias ", " duas ", "ou ", " uma ", " tamb ém ", "e ", " dados ", " cont ém ", " nodo ",
    " cada ", "que ", " sendo ", "nodos , ", "de ", " sequ ê ncia ", " uma ", "por ", " composta ", "é ", "Ela " };
    
    int tamPalavras = sizeof ( palavras ) / sizeof ( string );
    
    for ( int i =0; i < tamPalavras ; ++ i ) l -> add ("?");
    for ( int i= tamPalavras -1; i >=0; --i) l -> set ( tamPalavras -1 -i , palavras [i ]);
    if ( l -> size () != 22 || l -> isFull () || l -> isEmpty () ) cerr << " ERRO10 " << endl ;
    
    l -> add (" anterior "); l -> add ("ou "); l -> add (" posterior ."); l -> add (22 ," para "); l -> add (23 ,"o "); l -> add (24 ," nodo ");
    
    cout << l -> str () << endl ;
    
    if ( l -> size () != 28 || !l -> isFull () || l -> isEmpty () || l -> add (".") || l -> add (0 ,".") ) cerr << " ERRO11 " << endl ;
    
    delete l;
    
    return 0;
}