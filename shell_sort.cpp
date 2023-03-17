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

void insertion_sort(int *vetor, int tam, int k){
    for(int i = k; i < tam; i+=k){
        int aux = vetor[i];
        int j = i-k;
        while (aux < vetor[j] && j >= 0){
            vetor[j+k] = vetor[j];
            j-=k;
        }
        vetor[j+k] = aux;
    }
}

void shell_sort(int *vetor, int tam){
    int ks[7] = {23, 17, 13, 7, 3 , 2, 1};
    for (int i = 0; i < 7; i++){
        insertion_sort(vetor, tam, ks[i]);
    }
    
}

int main(){
    time_t t;
    srand(time(&t));
    int vetor[50];

    criaVetor(vetor, 50);
    printVetor(vetor, 50);

    shell_sort(vetor, 50);
    printVetor(vetor, 50);
    return 0;
}
