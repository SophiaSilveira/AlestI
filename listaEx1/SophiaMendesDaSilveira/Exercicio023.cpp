/*
Nome do arquivo: Exercicio023
Nome do autor: Sophia Mendes da Silveira
Finalidade do programa: Executar um Insertion Sort
Data de criacao: 25/08/2023
*/

#include <iostream>

using namespace std;

struct Registro {
    string identificador;
    int linha;
};

void imprimeVet(Registro *dados, int fim) {
    for (int i = 0; i < fim; i++) {
        cout << dados[i].identificador << "/" << dados[i].linha << " ";
    }
    cout << endl;
}

void insertionSort(Registro *dados, int tam) {
    for (int i = 1; i < tam; ++i) {
        Registro base = dados[i];
        int j = i - 1;

        while (j >= 0 && (base.identificador < dados[j].identificador ||
                          (base.identificador == dados[j].identificador && base.linha < dados[j].linha))) {
            dados[j + 1] = dados[j];
            --j;
        }

        dados[j + 1] = base;
        imprimeVet(dados, tam);
    }
}

int main() {
    int tam;
    cin >> tam;

    Registro *vetor = new Registro[tam];

    for (int i = 0; i < tam; i++) {
        cin >> vetor[i].identificador >> vetor[i].linha;
    }

    insertionSort(vetor, tam);

    delete[] vetor;

    return 0;
}
