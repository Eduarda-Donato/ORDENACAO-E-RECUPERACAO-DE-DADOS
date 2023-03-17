#include <iostream>
#include <time.h>

using namespace std;
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

int particiona(int *vetor, int inicio, int fim){
    int pivo = vetor[fim];
    int indice_pivot = inicio;
    
    for(int i = inicio; i < fim; i++){
        if(vetor[i] < pivo){
            swap(vetor, i, indice_pivot);
            indice_pivot++;
        }
    }
    swap(vetor, indice_pivot, fim);
    return indice_pivot;
}


void quick_sort(int *vetor,int inicio,int fim){
    if(inicio >= fim){
        return;
    }
    //printVetor(vetor, 10);
    int indice_pivot = particiona(vetor,inicio,fim);
    quick_sort(vetor,inicio,indice_pivot-1);
    quick_sort(vetor,indice_pivot+1,fim);
    //printVetor(vetor, 10);
}

int main()
{
    time_t t;
    srand(time(&t));
    int vetor[10];

    criaVetor(vetor, 10);
    printVetor(vetor, 10);
    
    quick_sort(vetor, 0,9);
    printVetor(vetor, 10);
    

    return 0;
}