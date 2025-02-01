#ifndef _COFOSL_H
#define _COFOSL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 0
#define FALSE 1

//Estrutura slnode
typedef struct _SlNode_{
    void *data;
    struct _SlNode_ *next;
}SlNode;

//estrutura da lista
typedef struct _SlList_{
    SlNode *first;
}SlList;

//estrutura para pegar os dados do usuario
typedef struct _Spotify_ {
    char nome[30];
    int escolha;
    float apoia;
}Spotify;


SlList *sllcreate(int numItens);

int sllInsertFirst(SlList *l,void *data);

int sllDestroyLista(SlList *l);

int sllNumItens(SlList *l);

void *sllGetNext(SlList *l);

int sllRemoveSecond(SlList *l);




#endif