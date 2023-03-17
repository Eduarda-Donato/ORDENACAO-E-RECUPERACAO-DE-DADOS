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

void insertionSort(int *vetor, int tam){
    for (int i = 1; i < tam; i++){
        int aux = vetor[i];
        int j = i - 1;
        while ((aux < vetor[j]) && (j >= 0)){
            vetor[j+1] = vetor[j]; //j+1 no primeiro loop seria igual a o i
                j--;
        }
        vetor[j+1] = aux; 
    }
}

int main(){
    time_t t;
    srand(time(&t));
    int vetor[10];

    criaVetor(vetor, 10);
    printVetor(vetor, 10);

    insertionSort(vetor, 10);
    printVetor(vetor, 10);
    return 0;
}


// 9|4 7 2 10 12 3
// 4 9|7 2 10 12 3
//     j i
// 4 7 9|2 10 12 3
// 2 4 7 9 10 12|3
// 2 3 4 7 9 10 12
