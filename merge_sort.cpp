#include <iostream>
#include <time.h>
//#include <math.h>

#define TAM1 5
#define TAM2 5
#define TAM3 TAM1+TAM2

#define T 5

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

void criaVetorzao(int *vetorUniao, int tam, int *vetor1,int tamv1, int *vetor2, int tamv2){    
    for (int i = 0; i < tamv1; i++){
        int aux = vetor1[i];
        vetorUniao[i] = aux;
    }
    for (int i = 0, j = tamv1; i < tamv2, j < tam; i++, j++){
        int aux = vetor2[i];
        vetorUniao[j] = aux; 
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

void intercalar(int *vetor, int inicio, int meio, int fim){
    int marcadorV1 = inicio;
    int marcadorV2 = meio+1;
    int indiceVetor = 0;
    int tam_vetor = (fim-inicio)+1;
    int vetor_resultado[tam_vetor];
    
    
    while (marcadorV1 <= meio && marcadorV2 <= fim){
        if (vetor[marcadorV1] < vetor[marcadorV2]){
            vetor_resultado[indiceVetor] = vetor[marcadorV1];
            marcadorV1++;
        }else{
            vetor_resultado[indiceVetor] = vetor[marcadorV2];
            marcadorV2++;
        }
        indiceVetor++;
    }
    if(marcadorV1 > meio){ //se terminar o vetor1 //preenche co o resto do vetor2
        for(int a = marcadorV2; a <= fim; a++){
            vetor_resultado[indiceVetor] = vetor[a];
            indiceVetor++;
        }
    }
    else if(marcadorV2 > fim){//se terminar o vetor2 //preenche co o resto do vetor1
        for(int b = marcadorV1; b <= meio; b++){
            vetor_resultado[indiceVetor] = vetor[b];
            indiceVetor++;
        }
    }
    //printVetor(vetor, fim2);
    for(int i = inicio; i < tam_vetor; i++){ //começa do inicio pois como o merge vai quebrando pode pegar um vetor q começa na posição 4
        vetor[i] = vetor_resultado[i];
    }
}

void merge_sort(int *vetor, int inicio, int fim){
    if(inicio >= fim){
        return;
    }
    //int meio = floor((fim+inicio)/2);
    int meio = (fim+inicio)/2;
    merge_sort(vetor, inicio, meio);
    merge_sort(vetor, meio+1, fim);
    intercalar(vetor, inicio, meio, fim);
    //printVetor(vetor, fim-inicio);
}


int main(){
    time_t t;
    srand(time(&t));
    int vetor[TAM1];
    int vetor2[TAM2];
    int vetorzao[TAM3];
    /*int v[7] = {3,2,7,8,1,5,10};
    int v2[7] = {2,4,6,1,3,5,7};
    int v3[5] = {10,2,7,0,4};*/

    criaVetor(vetor, TAM1);
    //bubbleSort(vetor, TAM1);
    printVetor(vetor, TAM1);
    criaVetor(vetor2, TAM2);
    //bubbleSort(vetor2, TAM2);
    printVetor(vetor2, TAM2);

    criaVetorzao(vetorzao, TAM3, vetor, TAM1, vetor2, TAM2);
    printVetor(vetorzao, TAM3);

    //intercalar(vetorzao,0,TAM1-1,TAM3-1);
    //printVetor(vetorzao, TAM3);

    merge_sort(vetorzao,0,9);
    printVetor(vetorzao, TAM3);

    //intercalar(v2,0,2,6);
    /*merge_sort(vetor2,0,7);
    printVetor(vetor2, 8);*/

    //intercalar(v3,0,0,1);
    //merge_sort(v3,0,4);
    //printVetor(v3, 5);

    
    return 0;
}