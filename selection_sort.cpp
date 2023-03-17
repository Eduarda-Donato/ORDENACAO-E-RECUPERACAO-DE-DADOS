#include <iostream>
#include <time.h>

#define TAM_VETOR 10

void criaVetor(int *vetor, int tam){
    for (int i = 0; i < tam; i++){
        vetor[i] = rand() % 100;
    }
    
}

void printVetor(int *vetor, int tam){
    for (int i = 0; i < tam; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void swap(int *vetor, int a, int b){
    int aux = vetor[a];
    vetor[a] = vetor[b];
    vetor[b] = aux;
}

int selection(int *vetor, int tam, int inicio){
    int indiceDoMenor = inicio;
    for (int i = inicio+1; i < tam; i++){       //inicio+1 pois sempre vai mudar por onde começar e o +1 é para n comparar o mesmo valor
        if (vetor[i] < vetor[indiceDoMenor]){   //compara os valores
            indiceDoMenor = i;
        }
    }
    return indiceDoMenor;
}

void selection_sort(int *vetor, int tam){
    for (int i = 0; i < tam; i++){
        int indiceDoMenor = selection(vetor, tam, i);
        if (indiceDoMenor != i){                //compara os indices
            swap(vetor, indiceDoMenor, i);
            printVetor(vetor,TAM_VETOR);
        }
        
    }
}

int main(){
    int vetor[TAM_VETOR];
    time_t t;
    srand(time(&t));

    criaVetor(vetor, TAM_VETOR);
    printVetor(vetor, TAM_VETOR);

    selection_sort(vetor, TAM_VETOR);
    printVetor(vetor, TAM_VETOR);

    return 0;
}