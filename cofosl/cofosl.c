#ifndef _COFOSL_C_
#define _COFOSL_

#include "cofosl.h"

#define TRUE 0
#define FALSE 1


//função para criar a lista
SlList *sllcreate(int numItens){
    SlList *l;
    l =(SlList *)malloc(sizeof(SlList)*numItens);
    if(l!=NULL){
        l->first = NULL;
        return l;
    }
    return NULL;
}

//Função para inserir como o primeiro
int sllInsertFirst(SlList *l,void *data){
    SlNode *newnode,*next;
    if(l!=NULL){
        newnode = (SlNode *)malloc(sizeof(SlNode));
        if(newnode!=NULL){
            newnode->data = data;
            next = l->first;
            newnode->next =next;
            l->first = newnode;
            return TRUE;
        }
    }
    return FALSE;
}


//função para destruir a lista
int sllDestroyLista(SlList *l){
    SlNode *rem,*next;
    void *data;
    if(l!=NULL){
        rem = l->first;
        while(rem!=NULL){
            next = rem->next;
            free(rem->data);
            free(rem);
            rem = next;
        }
        l->first = NULL;
        return TRUE;
    }
    return FALSE;
}

//Verifica a quantidade de Nós(Elementos) dentro da minha lista
int sllNumItens(SlList *l){
    SlNode *atual;
    int num=0;
    if(l!=NULL){
        if(l->first!=NULL){
            atual = l->first;
            while(atual!=NULL){
                num++;
                atual = atual->next;
            }
            return num;
        }
    }
    return num;
}

//função para remover o segundo elemento
int sllRemoveSecond(SlList *l){
    SlNode *prevSec,*second,*nexSec;
    if(l!=NULL){
        if(l->first!=NULL){
            prevSec = l->first;
            second = prevSec->next;
            if(second!=NULL){
                nexSec = second->next;
                prevSec->next = nexSec;
                free(second);
            }
            else{
                prevSec->next= NULL;
            }
            return TRUE;
        }
    }
    return FALSE;
}

#endif