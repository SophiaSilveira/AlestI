/*
Nome do arquivo: Exercicio002
Nome do autor: Sophia Mendes da Silveira
Finalidade do programa: Executar um Buble Sort
Data de criacao: 25/08/2023
*/

#include <iostream>

using namespace std ;

int estaOrdenado ( int * dados , int tam ) {
    for ( int i =0; i < tam -1; ++ i ) if ( dados [i] < dados [i +1]) return 0;
    return 1;
}

void imprimeVet(int * dados,  int fim){
    for(int i = 0; i < fim; i++){
        cout << dados[i] << " ";
    }
    cout << endl;
}

void bubleSort (int * dados,  int fim){
    if(estaOrdenado(dados, fim)){
        imprimeVet(dados, fim);
        return;
    } 

   for(int i = 0; i < fim; i++){
    for(int l = 0; l < fim -1; l++){
        if(dados[l] < dados[l + 1]){
            int aux = dados[l];
            dados[l] = dados[l+1];
            dados[l+1] = aux;
        }

    }
    imprimeVet(dados, fim);
    if(estaOrdenado(dados, fim)){
        imprimeVet(dados, fim);
        return;
    } 
   }
}



int main () {

    int n;
    cin >> n;

    int * vetor = new int[n];

    for(int i = 0; i < n; i++){
        cin >> vetor[i];
    }
    
    bubleSort(vetor, n);

    delete vetor;

    return 0;
}