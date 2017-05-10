//O arquivo apresenta system("cls"), caso necessario, comente a linha dele.

#include <stdio.h>
#include <stdlib.h>

    typedef struct pilha Pilha;

    struct pilha{
        int numero;
        Pilha *proximo;
        int posicao;
    };

void inserir(Pilha **top);
void listar(Pilha *top);
void esvaziar(Pilha **top);
void excluir(Pilha **top);

void inserir(Pilha **top){
    Pilha *novo; //ponteiro para o elemento a ser inserido;

    novo = (Pilha *)malloc(sizeof(Pilha));

    if(novo==NULL){
        printf("Sem memoria!");
        exit(1);
    }
    else{
        printf("Informe o numero: ");
        scanf("%d",&novo->numero);
        if(*top==NULL){
            novo->proximo = NULL;
        }
        else{
            novo->proximo = *top;
        }
        *top = novo;
    }
}

void listar(Pilha *top){
    Pilha *aux;

    if(top==NULL){
        printf("PILHA VAZIA!");
    }
    else{
        aux=top;
        while(aux != NULL){
            printf("%d\n",aux->numero);
            aux = aux->proximo;
        }
    }

}

void esvaziar(Pilha **top){
    Pilha *aux;
    while(*top != NULL){
        aux = (*top)->proximo;
        free(*top);
        *top = aux;
    }
}

void excluir(Pilha **top){
    Pilha *aux;

    aux = (*top)->proximo;
    free(*top);
    *top = aux;

}

int main(void){
    int op;
    Pilha *topo = NULL;

    do{
        puts("1 - INSERIR");
        puts("2 - LISTAR");
        puts("3 - EXCLUIR");
        puts("4 - ESVAZIAR A PILHA");
        puts("5 - SAIR");
        printf("----------\n");
        printf("OPCAO: ");
        scanf("%d",&op);
            switch(op){
                case 1:
                    inserir(&topo);
                    break;
                case 2:
                    listar(topo);
                    getchar();
                    getchar();
                    break;
                case 3:
                    excluir(&topo);
                    break;
                case 4:
                    esvaziar(&topo);
                    break;
            }
        system("cls");
    }while(op != 5);
return 0;

}
