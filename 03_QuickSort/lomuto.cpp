#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#define TAM 10000

using namespace std ;

int particiona(int * dados , int ini , int fim ){
    int pivot = dados[fim];
    int i = ini - 1, aux;
    for(int j = ini; j < fim; j++){
        if(dados[j] < pivot){
            i += 1;
            aux = dados[i];
            dados[i] = dados[j];
            dados[j] = aux;
        }        
    }
    if(pivot < dados[i + 1]){
        aux = dados[i + 1];
        dados[i + 1] = dados[fim];
        dados[fim] = aux;
    }
    return i + 1;
}

void quickSort (int * dados , int ini , int fim ){
    if(ini < fim){
        int p = particiona(dados, ini, fim);
        quickSort(dados, ini, p - 1);
        quickSort(dados, p + 1, fim);
    }
}

int estaOrdenado ( int * dados , int tam ) {
    for ( int i =0; i < tam -1; ++ i ) if ( dados [i] > dados [i +1]) return 0;
    return 1;
}

void executa( void(*pf)){
    int vetor [ TAM ];
    struct timeval antes,depois;
    unsigned long microssegundos;

    srand ( time (0));

    cout << "> Ordenado : ";
    for ( int i =0; i < TAM ; i ++) vetor [i] = i; // preenche o vetor ordenado
    gettimeofday (& antes , NULL ); pf( vetor ,0 , TAM -1); gettimeofday (& depois , NULL );
    microssegundos = ( depois . tv_sec - antes . tv_sec ) * 1000000 + depois . tv_usec - antes . tv_usec ;
    if ( estaOrdenado ( vetor , TAM )) cout << microssegundos << " us" << endl ; else cout << " FALHOU " << endl ;
    
    

    cout << "> Invertido : ";
    for ( int i =0; i < TAM ; i ++) vetor [i] = TAM - i; // preenche o vetor invertido
    gettimeofday (& antes , NULL ); quickSort ( vetor ,0 , TAM -1); gettimeofday (& depois , NULL );
    microssegundos = ( depois . tv_sec - antes . tv_sec ) * 1000000 + depois . tv_usec - antes . tv_usec ;
    if ( estaOrdenado ( vetor , TAM )) cout << microssegundos << " us" << endl ; else cout << " FALHOU " << endl ;

    cout << "> Aleatório : ";
    for ( int i =0; i < TAM ; i ++) vetor [i] = rand ()% TAM ; // preenche o vetor aleatoriamente
    gettimeofday (& antes , NULL ); quickSort ( vetor ,0 , TAM -1); gettimeofday (& depois , NULL );
    microssegundos = ( depois . tv_sec - antes . tv_sec ) * 1000000 + depois . tv_usec - antes . tv_usec ;
    if ( estaOrdenado ( vetor , TAM )) cout << microssegundos << " us" << endl ; else cout << " FALHOU " << endl ;
}

int main () {

    executa(quickSort);

   




    return 0;

}