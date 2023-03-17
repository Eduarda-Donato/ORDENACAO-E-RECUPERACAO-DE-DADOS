#include <iostream>
#include <time.h>

void printVetor(int *vetor, int tam){
    for (int i = 0; i < tam; i++){
        printf("%d ", vetor[i]);
    } 
    printf("\n");
}

void criaVetor(int *vetor, int tam){
    for (int i = 0; i < tam; i++){
        vetor[i] = rand() % 100;
    } 
}

void swap(int *vetor, int a, int b){
    int aux = vetor[a];
    vetor[a] = vetor[b];
    vetor[b] = aux;
}

void bubbleSort(int *vetor, int tam){
    for (int i = 0; i < tam; i++){
        for (int j = 0; j < tam-1; j++){
            if ((vetor[j] > vetor[j+1])){
                swap(vetor,j,j+1);
            }
        }
    }
}

/*void bubbleSort(int *vetor, int tam){
    int troca = 1;
    while (troca){
        troca = 0;
        for (int i = 0; i < tam; i++){
            if (vetor[i] > vetor[i+1]){
                swap(vetor, i, i+1);
                troca = 1;
            }   
        }
    }
    
}*/

/*void bubbleSort(int *vetor, int tam){
    for (int i = 0; i < tam; i++){
        int j = 0;
        while (j < tam -1){
            if ((vetor[j] > vetor[j+1])){
                swap(vetor,j,j+1);
            } 
            j++;
        }
    }
}*/


int main(){
    time_t t;
    srand(time(&t));
    int vetor[10];

    criaVetor(vetor, 10);
    printVetor(vetor, 10);

    bubbleSort(vetor, 10);
    printVetor(vetor, 10);
    return 0;
}