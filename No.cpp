#include <iostream>
#include <stdlib.h>

class No{
public:
    int info;
    No* FE;
    No* FD;
    No(){
        info = 0;
        FE = NULL;
        FD = NULL;
    }
    /*Static */No* criaNo(int info){
        No* novo = new No();
        if(novo != NULL){
            novo->info = info;
            novo->FE = NULL;
            novo->FD = NULL;
        }
        return novo;
    }
};


