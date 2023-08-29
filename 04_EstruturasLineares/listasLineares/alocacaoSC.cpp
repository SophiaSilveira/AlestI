# include <iostream>

using namespace std;

int main () {
    int vetorEstatico [10]; // ALOCACAO ESTATICA
    for ( int i =0; i <10; ++ i ) vetorEstatico [i ] = i + 1;
    for ( int i =0; i <10; ++ i ) cout << vetorEstatico [i] << endl;

    const int TAM_MAX = 10;
    int vetorParcial [ TAM_MAX ]; // VETOR PARCIALMENTE PREENCHIDO
    int tamAtual = 0; // tamanho atual do vetor parcialmente preenchido
    for ( int i =0; i < TAM_MAX +1; ++ i )
        if ( tamAtual < TAM_MAX )
            vetorParcial [ tamAtual ++ ] = i +1;
    for ( int i =0; i < tamAtual ; ++ i) cout << vetorParcial [i ] << endl;

    int tam;
    cin >> tam;
    int * vetorDinamico = new int [ tam ]; // ALOCACAO DINAMICA
    for ( int i =0; i < tam ; ++ i) vetorDinamico [ i] = i +1;
    for ( int i =0; i < tam ; ++ i) cout << vetorDinamico [i] << endl;
    delete[] vetorDinamico;

    return 0;
}