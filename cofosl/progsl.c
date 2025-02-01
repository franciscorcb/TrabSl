#include "cofosl.h"

int cmp(int a, int b) {
    if (a == b) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void letraDaMusica(int n){
    if(n>0 && n<5){
        if(n==1){
            printf("Musica:Never Enouth by Eminem    ");
        }
        else if(n==2){
            printf("Musica:Unstoppable by SIA    ");
        }
        else if(n==3){
            printf("Musica:Two faced by Linkin Park    ");
        }
        else if(n==4){
            printf("Musica:Earth Song by Michael Jackson    ");
        }
    }
}

Spotify *cadUsuario(){
    Spotify *newUser;
    newUser = (Spotify *)malloc(sizeof(Spotify));

    if(newUser!=NULL){
        printf("Digite seu nome: ");
        scanf("%s", newUser->nome);

        printf("________________________\n");
        printf("\n[1] Never Enouth - Eminem\n[2] Unstoppable -  SIA\n[3] Two Faced - Link Park\n[4] Earth Song - Michael Jackson\n");
        printf("________________________\n\n");
        printf("Adicione uma musica no seu album: ");
        scanf("%d", &(newUser->escolha));

        printf("\nApoie seu cantor! Ajude-o Financeiramente: ");
        scanf("%f", &(newUser->apoia));
        printf("________________________\n");

        return newUser;
    }
    return NULL;
}

void imprimirLista(SlList *l){
    SlNode *spec;
    if(l!=NULL){
        if(l->first!=NULL){
            spec = l->first;
            while(spec!=NULL){
                Spotify *user = (Spotify *)spec->data;
                printf("%s    ",user->nome);
                letraDaMusica(user->escolha);
                printf("%.2f",user->apoia);
                printf("\n_ _ _ _ _ _ _ _ _ _ _\n\n");

                spec = spec->next;
            }   
        }
    }
}


void acharUsuario(SlList *l,void *nome, int escolha, float apoia){
    SlNode *spec;
    int stat;
    int flag=FALSE;
    if(l!=NULL){
        if(l->first!=NULL){
            spec = l->first;
            while(spec!=NULL){
                Spotify *user = (Spotify *)spec->data;
                stat = strcmp(nome, user->nome);
                if(stat == TRUE && apoia == user->apoia && escolha == user->escolha){
                    printf("\nUsuario encontrado:\n\n");
                    printf("%s    ",user->nome);
                    printf("%d    ",user->escolha);
                    printf("%.2f\n",user->apoia);
                    printf(".............................\n");
                    flag =TRUE;
                }
                spec = spec->next;
            }
        }
    }
    if(flag != TRUE){
        printf("\nUsuario nao encontrado\n\n");
    }
}


int removeSpec(SlList *l,void *nome, int escolha, float apoia){
    SlNode *spec,*prev;
    int stat;

    if(l!=NULL){
        if(l->first!=NULL){
            spec = l->first;
            prev = NULL;
            while(spec!=NULL){
                Spotify *user = (Spotify *)spec->data;
                stat = strcmp(nome, user->nome);
                if(stat == TRUE && apoia == user->apoia && escolha == user->escolha){
                    if(prev!=NULL){
                        prev->next = spec->next;
                    }
                    else{
                        l->first = spec->next;
                    }
                    free(spec->data);
                    free(spec);
                    return TRUE;
                }
                prev = spec;
                spec = spec->next;
            }
        }
    }
    return FALSE;
}

int main(){
    SlList *lista;
    Spotify *dados;
    int elm=TRUE,escolha;
    char vNome[30];
    int vEscolha;
    float vApoia;

    lista = sllcreate(5);

    if(lista!=NULL){
        printf("\n============== Spotify ==============\n");
        while(elm==TRUE){
            printf("O que voce deseja fazer?\n[1]Cadastrar usuario\n[2]Listar os elementos da Lista\n[3]Consultar um usuario\n[4]Remover o segundo elemento da lista\n[5]Remover usuario especifico\n[6]Esvaziar lista\n[7]Sair\n");
            printf("--------------------------\n");
            scanf("%d",&escolha);
            if(escolha==1){
                dados = cadUsuario();
                sllInsertFirst(lista,dados);
            }

            else if(escolha==2){
                int cadastros = sllNumItens(lista);
                printf("\nNumero de cadastros :%d\n\n",cadastros);
                imprimirLista(lista);
            }

            else if(escolha==3){
                printf("Preencha as areas a seguir:\n");
                printf("Nome:");
                scanf("%s",vNome);

                printf("Escolha:");
                scanf("%d",&vEscolha);

                printf("Apoio: ");
                scanf("%f",&vApoia);
                acharUsuario(lista,(void *)vNome,vEscolha,vApoia);
                
            }

            else if(escolha == 4){
                if(sllRemoveSecond(lista)==TRUE){
                    printf("\nUsuario removido\n\n");
                }
                else{
                    printf("\nNao foi possivel remover\n\n");
                }
            }

            else if(escolha == 5){

                printf("Preencha as areas a seguir:\n");
                printf("Nome:");
                scanf("%s",vNome);

                printf("Escolha:");
                scanf("%d",&vEscolha);

                printf("Apoio: ");
                scanf("%f",&vApoia);
                if(removeSpec(lista,(void *)vNome,vEscolha,vApoia)==TRUE){
                    printf("\nUsuario removido com sucesso\n\n");
                }
                else{
                    printf("\nUsuario nao encontrado\n\n");
                }

            }

            else if(escolha==6){
                if(sllDestroyLista(lista) == TRUE){
                    printf("\nA lista foi esvaziada\n\n");
                }
                else{
                    printf("\nA lista ja esta vazia\n\n");
                }
            }

            else if(escolha == 7){
                elm=FALSE;
            }
        }
    }
    sllDestroyLista(lista);
    free(lista);

    system("pause");
    return 0;
}