#include <iostream>
#include <time.h>

void cria_vetor(int* v, int tam){ 
    for (int i = 0; i < tam; i++){ 
        v[i] = rand() % 10; }
    }
    void print_vetor(int* v, int tam){ 
        for (int i = 0; i < tam; i++){ 
            printf("%d ", v[i]); 
        } 
        printf("\n");
    }
    void zera_vetor(int* v, int tam){ 
        for (int i = 0; i < tam; i++){ 
            v[i] = 0; 
        }
    }
void counting_sort(int* v, int tam){ 
    int maior = 0; int v_aux[tam]; 
    zera_vetor(v_aux, tam); 
    for (int i = 0; i < tam; i++){ 
        if (v[i] > maior){ maior = v[i]; 
        } 
    } 
    maior += 1; 
    int v_contador[maior]; 
    zera_vetor(v_contador,maior);
    for (int i = 0; i < tam; i++){ 
        int aux = v[i]; 
        v_contador[v[i]] += 1; 
    } 
    //print_vetor(v_contador,maior); 
    //printf("\n"); 
    for (int i = 0; i < tam; i++){ 
        if(i != 0){ 
            v_contador[i] = v_contador[i] + v_contador[i-1]; 
            } 
    } 
    //print_vetor(v_contador,maior);
    for (int i = 0; i < tam; i++){ 
        int aux = v[i]; 
        int posicao_fim = v_contador[aux]-1; 
        v_contador[aux]--; 
        v_aux[posicao_fim] = aux; 
    } 
    //print_vetor(v_aux, tam);
    for (int i = 0; i < tam; i++){ 
        v[i] = v_aux[i]; 
        }
}

int main(int argc, char const *argv[]){ 
    time_t t; 
    srand(time(&t)); 
    int v[10];
    cria_vetor(v, 10); 
    print_vetor(v,10); 
    counting_sort(v,10); 
    print_vetor(v,10); 
    return 0;
}
