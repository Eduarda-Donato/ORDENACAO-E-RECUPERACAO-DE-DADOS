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
void intercala(int *vetor, int inicio1, int fim1, int inicio2, int fim2) {
  int tam_vetor = (fim2 - inicio2 + 1) + (fim1 - inicio1 + 1);
  int vetor_aux[tam_vetor];
  int comeco = inicio1;
  int i = 0;

  while (inicio1 <= fim1 && inicio2 <= fim2) {
    if (vetor[inicio1] >= vetor[inicio2]) {
      vetor_aux[i] = vetor[inicio1];
      inicio1++;
    } else {
      vetor_aux[i] = vetor[inicio2];
      inicio2++;
    }
    i++;
  }

  while (inicio1 <= fim1) {
    vetor_aux[i++] = vetor[inicio1++];
  }

  while (inicio2 <= fim2) {
    vetor_aux[i++] = vetor[inicio2++];
  }

  for (int i = 0; i < tam_vetor; i++) {
    vetor[comeco++] = vetor_aux[i];
  }
}

void merge_sort(int *v, int inicio, int fim) {
  if (fim <= inicio) {
    return;
  }

  int meio = (inicio + fim) / 2;
  merge_sort(v, inicio, meio);
  merge_sort(v, meio + 1, fim);
  intercala(v, inicio, meio, meio + 1, fim);
}

int main(){
    time_t t;
    srand(time(&t));
    int vetor[10];

    criaVetor(vetor, 10);
    printVetor(vetor, 10);

    merge_sort(vetor,0,9);
    printVetor(vetor, 10);
}