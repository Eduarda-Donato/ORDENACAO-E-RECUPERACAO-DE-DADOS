#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "No.cpp"

class arvoreBinaria{
public:
    No* raiz;

    arvoreBinaria(){
        this->raiz = NULL;
    }
    
    bool inserir(No** root, int info){
        if (*root == NULL){
            *root = raiz->criaNo(info);
            return(*root != NULL);
        }
        int direcao = rand()%1+1;
        if (direcao ==0){
            return inserir(&(*root)->FE,info);
        }else{
            return inserir(&(*root)->FD, info);
        }
        
    }

    bool inserirRecursivo(int info){
        return inserir(&raiz,info);
    }

    void printPreOrdem(No* No){
        if(No != NULL){
            printf("info = %d", No->info);
            printPreOrdem(No->FE);
            printPreOrdem(No->FD);
        }
    }
    void print(){
        return printPreOrdem(raiz);
        printf("oi");
    }

    No* busca(No* r, int info){
        if (r == NULL){
            return NULL;
        }
        if (r->info == info){
            return r;
        }
        No* esq = busca(r->FE, info);
        if (esq != NULL){
            return esq;
        }
        No* dir = busca(r->FD, info);
        if (dir != NULL){
            return dir;
        }
        return NULL;
    }
};

int main(){
    time_t t;
    srand(time(&t));
    return 0;
    arvoreBinaria* arv = new arvoreBinaria();
    /*arv->inserirRecursivo(5);
    arv->inserirRecursivo(2);
    arv->inserirRecursivo(7);
    arv->inserirRecursivo(8);
    arv->inserirRecursivo(0);
    arv->inserirRecursivo(3);*/
    arv->print();
}


