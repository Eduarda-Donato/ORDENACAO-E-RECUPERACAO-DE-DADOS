#include <iostream>
#include <time.h>

#define TAM1 5
#define TAM2 3
#define TAM3 TAM1+TAM2

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

void swap(int *vetor, int a,int b){
    int aux = vetor[a];
    vetor[a] = vetor[b];
    vetor[b] = aux;
}

int selection(int *vetor, int tam, int inicio){
    int indiceDoMenor = inicio;
    for (int i = inicio+1; i < tam; i++){
        if (vetor[i] < vetor[indiceDoMenor]){
            indiceDoMenor = i;
        }
    }
    return indiceDoMenor;
}


void selection_sort(int *vetor, int tam){
    for (int  i = 0; i < tam; i++){
        int indiceDoMenor = selection(vetor, tam, i);
        //printf("i = %d     indice = %d\n",i,indiceDoMenor);
        if(vetor[i] != vetor[indiceDoMenor]){
            swap(vetor, indiceDoMenor, i);
        }
    }
    
}

int selection_inverso(int *vetor, int tam, int inicio){
    int indiceDoMaior = inicio;
    for (int i = inicio+1; i < tam; i++){
        if (vetor[i] > vetor[indiceDoMaior]){
            indiceDoMaior = i;
        }
    }
    return indiceDoMaior;
}


void selection_sort_inverso(int *vetor, int tam){
    for (int  i = 0; i < tam; i++){
        int indiceDoMaior = selection_inverso(vetor, tam, i);
        //printf("i = %d     indice = %d\n",i,indiceDoMaior);
        if(vetor[i] != vetor[indiceDoMaior]){
            swap(vetor, indiceDoMaior, i);
        }
    }
    
}

void insertion_sort(int *vetor, int tam){
    for (int i = 1; i < tam; i++){
        int aux = vetor[i];
        int j = i - 1;
        while ((aux < vetor[j]) && (j >= 0)){
            vetor[j+1] = vetor[j];
            j--; 
        }
        vetor[j+1] = aux;
    }
}


void bubble_sort(int *vetor, int tam){
    int troca =1;
    while (troca){
        troca = 0;
        for (int i = 0; i < tam-1; i++){
            if (vetor[i] > vetor[i+1]){
                swap(vetor,i,i+1);
                troca = 1;
            }
        }
    }
}


void bubble_sort_inverso(int *vetor, int tam){
    int troca =1;
    while (troca){
        troca = 0;
        for (int i = 0; i < tam-1; i++){
            if (vetor[i] < vetor[i+1]){
                swap(vetor,i,i+1);
                troca = 1;
            }
        }
    }
}



void merge_sort(int *vetor, int inicio, int fim){
    if(inicio >= fim){
        return;
    }
    int meio = (fim+inicio)/2;
    merge_sort(vetor, inicio, meio);
    merge_sort(vetor, meio+1, fim);
    //merge(vetor, inicio, meio, fim);
}



int main(){
    time_t t;
    srand(time(&t));
    int vetor[10];
    int vetor2[8] = {7,5,1,0,10,2,6,1};

    criaVetor(vetor, 10);
    printVetor(vetor, 10);

    //insertion_sort(vetor2, 3);
    //bubble_sort(vetor, 10);
    //bubble_sort_inverso(vetor2, 8);
    //selection_sort(vetor,10);
    selection_sort_inverso(vetor,10);
    //printVetor(vetor2, 8);
    //merge_sort(vetor2, 0,7);
    printVetor(vetor, 10);
    return 0;
}
