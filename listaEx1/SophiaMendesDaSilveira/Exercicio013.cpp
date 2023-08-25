/*
Nome do arquivo: Exercicio013
Nome do autor: Sophia Mendes da Silveira
Finalidade do programa: Executar um Selection Sort
Data de criacao: 25/08/2023
*/

#include <iostream>

using namespace std ;

void imprimeVet(string * dados,  int fim){
     for (int i = 0; i < fim; i++) {
        dados[i][1] = '/';
        cout << dados[i] << " ";
    }
    cout << endl;
}

int separaNumeros(string * dados,  int local){
    string numbers;
    for(int i = 2; dados[local][i] != '\0'; i++) {
            numbers = numbers + dados[local][i]; 
    }
    return stoi(numbers);
}

void selectionSort(string * dados,  int fim){
        for (int i = 0; i < fim -1 ; ++ i ) {
        int local = i ;
        
            for (int j = i + 1; j < fim ; ++ j ){
                int localN = separaNumeros(dados, local);
                int jN = separaNumeros(dados, j);

                if (dados [ j ][0] < dados [ local ][0]) local = j;
                if(dados[j][0] == dados[local][0] )
                    if(jN < localN)local = j;
            }
       
          
            if ( local != i ) {
                string aux = dados [ local ];
                dados [ local ] = dados [ i ];
                dados [ i ] = aux ;


        }
        imprimeVet(dados, fim);
    }
}

int main () {


    string n;

    getline(cin, n);

    int tam = stoi(n);

    string * vetor = new string[tam];

    for(int i = 0; i < tam; i++){
       getline(cin, vetor[i]);
    }
    
    selectionSort(vetor, tam);

    return 0;
}