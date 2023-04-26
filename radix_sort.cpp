#include <iostream>
#include <time.h>

#define TAMV 10

void cria_vetor(int* v, int tam){ 
    for (int i = 0; i < tam; i++){ 
        v[i] = rand() % 9999; 
    }
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

void counting_sort(int* v, int tam, int dezena){ 
    int maior = 0; 
    int v_aux[tam] = { 0 }; 
    for (int i = 0; i < tam; i++){ 
        if (v[i] > maior){ 
            maior = v[i]; 
        } 
    } 
    maior += 1; 
    int v_contador[10] = { 0 }; 
    for (int i = 0; i < tam; i++){ 
        v_contador[(v[i] / dezena)%10] += 1; 
    } 
    print_vetor(v_contador,maior); 
    printf("\n"); 
    for (int i = 0; i < 10; i++){ 
        if(i != 0){ 
            v_contador[i] += v_contador[i-1]; 
        } 
    } 
    //print_vetor(v_contador,maior);
    for (int i = 0; i < tam; i++){ 
        int aux = (v[i]/ dezena)%10; 
        int posicao_fim = ((v_contador[aux]/dezena)%10)-1; 
        v_contador[aux]--; 
        v_aux[posicao_fim] = aux; 
    } 
    //print_vetor(v_aux, tam);
    for (int i = 0; i < tam; i++){ 
        v[i] = v_aux[i]; 
    }
}

void radix_sort(int* v, int tam){
    int maior = v[0];
    for  (int i = 0; i < tam; i++){ //procura o maior número para saber o número de digitos
        if (v[i] > maior){
            maior = v[i];
        }
    }
 
    for (int i = 1; maior / i > 0; i *= 10){    //pula em dezenas: 1,10,100,1000,10000
                                                //enquanto maior/i > 0 como é int pega só a parte inteira do resultado se for 0.006 fica só 0
        counting_sort(v, tam, i);
    }
    
}

int main(){ 
    time_t t; 
    srand(time(&t)); 
    int v[10];
    cria_vetor(v, 10); 
    print_vetor(v,10); 
    //counting_sort(v,10); 
    radix_sort(v,10);
    print_vetor(v,10); 
    return 0;
}