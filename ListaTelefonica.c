/*  Trabalho 2 (AGENDA-TELEFONICA)
    Nome: Victor Alves de Carvalho
    Matricula: 16/0147140
    Nome: Pedro Felipe de Oliveira Ribeiro
    Matrícula:16/0141168
    Estrutura de Dados - Turma B  2017/01 */

/*DIRETIVAS DE PRE-PROCESSAMENTO PARA A FUNCAO SYSTEM("CLS")*/
#if defined(__MINGW32__) || defined(_MSC_VER)
#define limpar_tela() system("cls")
#else
#define limpar_tela() system("clear")
#endif // defined

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//ListaTelefonica.h
struct usuario{
	char nome[40];
	char email[50];
	char tel[20];
};

typedef struct node *lista;

//cabecalho das funcoes
lista* criaLista();
void liberaLista(lista *li);
int listaVazia(lista *li);
int inserirFinal(lista *li, struct usuario a);
struct usuario infoUsuario(void);
int buscarUsuario(lista *li);
int mostrarLista(lista *li,int count);
int remover(lista *li);
int editarUsuario(lista *li);
int ordenarLista(lista *li);
char* strupr(char* s);

void menu(void);
void titulo(void);

//Variaveis Globais

int count = 0; //Numero de contatos da lista

//ListaTelefonica.c
struct node{
	struct usuario dados;
	struct node *prox;
};
typedef struct node elem;

lista* criaLista(void){
    lista *li = (lista *)malloc(sizeof(lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

char* strupr(char* s){  //Implementacao da funcao strupr caso este programa esteja sendo executado na plataforma linux

    char* tmp = s;
    for(;*tmp;++tmp){
            *tmp = toupper(*tmp);
    }
    return s;
}

void liberaLista(lista *li){
    if(li != NULL){
        elem* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
    count = 0;
}

int listaVazia(lista *li){
	if(li == NULL){
		return 1;
	}
		if(*li == NULL){
			return 1;
		}
	return 0;
}

int inserirFinal(lista *li, struct usuario a){
	if(li == NULL){
		return 0;
	}
		elem* novo = (elem *)malloc(sizeof(elem));
		if(novo == NULL){	//nao foi possivel alocar memoria
			return 0;
		}
			novo->dados = a;
			novo->prox = NULL;
			if((*li) == NULL){	//lista vaiza: insere no inicio
				*li = novo;
			}else{
				elem *aux = *li;
				while(aux->prox != NULL){	//percorre ate o fim da lista
                    if(strcmp(aux->dados.nome,a.nome) == 0){
                        printf("============================================================\n");
                        printf("NOME JA EXISTENTE!\n");
                        printf("============================================================\n");
                        return 0;
                    }
                    aux = aux->prox;
				}
                    if(strcmp(aux->dados.nome,a.nome) == 0){
                        printf("============================================================\n");
                        printf("NOME JA EXISTENTE!\n");
                        printf("============================================================\n");
                        return 0;
                    }
				aux->prox = novo;
			}
        printf("============================================================\n");
		printf("CADASTRADO COM SUCESSO!\n");
        printf("============================================================\n");
	count++;
	return 1;
}

struct usuario infoUsuario(void){
    struct usuario n;
                        printf("============================================================\n");
                        printf("\t\t\tNOVO CONTATO\n");
                        printf("============================================================\n");
                        printf("Nome: ");
                        getchar();
                        char caractere;
                        int i = 0;
                        do{
                            caractere = getchar();
                            n.nome[i] = caractere;
                            ++i;
                        }while(caractere != '\n');
                        n.nome[i-1] = '\0';
                        strupr(n.nome);
                        printf("Email: ");
                        scanf("%s",&n.email);
                        printf("Telefone: ");
                        scanf("%s",&n.tel);

                        printf("\n");
    return n;
}

int buscarUsuario(lista *li){
    if(*li == NULL || li == NULL){
        printf("============================================================\n");
        printf("AGENDA VAZIA!\n");
        printf("============================================================\n");
        getchar();
        getchar();
        return 0;
    }
        char alvo[40];
        printf("BUSCAR NOME: ");
        getchar();
        char c;
        int i = 0;
            do{
                c = getchar();
                alvo[i] = c;
                i++;
            }while(c != '\n');
            alvo[i-1] = '\0';

    elem *p = *li;
    strupr(alvo);
    strupr(p->dados.nome);
    for(elem *p = *li;p != NULL;p=p->prox){
        int x = strcmp(p->dados.nome,alvo);
        if(x == 0){
            printf("============================================================\n");
            printf("\t\t D A D O S   D A   B U S C A\n");
            printf("============================================================\n");
            printf("NOME: %s\n",p->dados.nome);
            printf("E-MAIL: %s\n",p->dados.email);
            printf("TELEFONE: %s\n",p->dados.tel);
            printf("============================================================\n");
            getchar();
            return 1;
        }
    }
    printf("============================================================\n");
    printf("USUARIO NAO ENCONTRADO!\n");
    printf("============================================================\n");
    getchar();
 return 0;
}

int mostrarLista(lista *li,int count){
    if(li == NULL || *li == NULL){
        printf("============================================================\n");
        printf("AGENDA VAZIA!\n");
        printf("============================================================\n");
        return 0;
    }
    else{
        printf("============================================================\n");
        printf("\t\t\t  CONTATOS\n");
        printf("============================================================\n");
        for(elem *p = *li;p != NULL;p = p->prox){
            printf("NOME: %s\n",p->dados.nome);
            printf("E-MAIL: %s\n",p->dados.email);
            printf("TELEFONE: %s\n",p->dados.tel);
            printf("------------------------------------------------------------\n");
        }
        printf("\n");
        printf("CONTATOS: %d\n",count);	    
    }
    return 1;
}

int remover(lista *li){
    if(li == NULL || *li == NULL){
        printf("============================================================\n");
        printf("AGENDA VAZIA!\n");
        printf("============================================================\n");
        getchar();
        return 0;
    }
    elem *ant = *li;
    elem *no = *li;
    char alvo[40];
    char c;
    int i = 0;
    int op;
    printf("NOME A REMOVER: ");
    getchar();

        do{
            c = getchar();
            alvo[i] = c;
            i++;
        }while(c != '\n');
        alvo[i-1] = '\0';
        strupr(alvo);

    while(no != NULL && strcmp(no->dados.nome,alvo) != 0){
        ant = no;
        no = no->prox;
    }
    if(no == NULL){ //Nao encontrou o elemento
        printf("============================================================\n");
        printf("USUARIO NAO ENCONTRADO!\n");
        printf("============================================================\n");
        return 0;
    }
            printf("============================================================\n");
            printf("\t\t\tR E M O V E R\n");
            printf("============================================================\n");
            printf("NOME: %s\n",no->dados.nome);
            printf("E-MAIL: %s\n",no->dados.email);
            printf("TELEFONE: %s\n",no->dados.tel);
            printf("============================================================\n");

            printf("Deseja remove-lo?\n");
            printf("<1> - SIM\n");
            printf("<2> - NAO\n");
            printf("\nOpcao: ");
            scanf("%d",&op);
            while(op < 1 || op > 2){
                printf("Opcao invalida!\n");
                printf("\nOpcao: ");
                scanf("%d",&op);
            }
            if(op == 2){
                printf("============================================================\n");
                printf("OPERACAO CANCELADA!\n");
                printf("============================================================\n");
                return 0;
            }
    if(no == *li){   //Remover o primeiro
        *li = no->prox;
        printf("============================================================\n");
        printf("USUARIO REMOVIDO COM SUCESSO!\n");
        printf("============================================================\n");
        getchar();
        count--;
        return 1;
    }
            ant->prox = no->prox;
            free(no);
            printf("============================================================\n");
            printf("USUARIO REMOVIDO COM SUCESSO!\n");
            printf("============================================================\n");
            getchar();
            count--;
            return 1;
    }

int editarUsuario(lista *li){
    if(*li == NULL || li == NULL){
        printf("============================================================\n");
        printf("AGENDA VAZIA!\n");
        printf("============================================================\n");
        getchar();
        getchar();
        return 0;
    }
            printf("============================================================\n");
            printf("\t\t E D I T A R   C O N T A T O\n");
            printf("============================================================\n");

        char alvo[40];  //nome a buscar
        printf("NOME: ");
        getchar();
        char c;
        int i = 0;

            do{
                c = getchar();
                alvo[i] = c;
                i++;
            }while(c != '\n');
            alvo[i-1] = '\0';

    elem *p = *li;
    elem *aux = *li;
    strupr(alvo);
    strupr(p->dados.nome);

    elem *ant,*atual = *li;

    for(elem *p = *li;p != NULL;p=p->prox){ //buscar contato a ser editado
        int x = strcmp(p->dados.nome,alvo);
            if(x == 0){ //encontrou o usuario alvo
    printf("============================================================\n");
                printf("DADOS ATUAIS:\n");
                printf("NOME: %s\n",p->dados.nome);
                printf("E-MAIL: %s\n",p->dados.email);
                printf("TELEFONE: %s\n",p->dados.tel);
    printf("============================================================\n");
                    int x = 0;
                    int j = 0;
                    char ch;
                    elem *tmp;
                    printf("\t\tQUAL INFORMACAO DESEJA ALTERAR? \n");
                        printf("\t\t\t--------------\n");
                        printf("\t\t\t <1> NOME \n");
                        printf("\t\t\t <2> EMAIL\n");
                        printf("\t\t\t <3> TELEFONE\n");
                        printf("\t\t\t <4> EXIBIR DADOS\n");
                        printf("\t\t\t <5> SAIR\n");
                        printf("\t\t\t--------------\n");
                do{
                    printf("Opcao: ");
                    scanf("%d",&x);
                        switch(x){
                            case 1:
                                   printf("NOVO NOME: ");
                                   getchar();
                                   do{
                                       ch = getchar();
                                       tmp->dados.nome[j] = ch;
                                       j++;
                                   }while(ch != '\n');
                                   tmp->dados.nome[j-1] = '\0';
                                   strupr(tmp->dados.nome);
                                    if(strcmp(p->dados.nome,tmp->dados.nome) == 0){
                                        printf("\n\nNOME IGUAL O ATUAL.\n");
                                        printf("============================================================\n");
                                        printf("OPERACAO CANCELADA!\n");
                                        printf("============================================================\n");
                                        getchar();
                                        return 0;
                                    }
                                        while(aux != NULL){	//percorre ate o fim da lista checando se o nome ja existe
                                            if(strcoll(aux->dados.nome,tmp->dados.nome) == 0){
                                                printf("\n\nNOME JA EXISTENTE!\n");
                                                printf("============================================================\n");
                                                printf("OPERACAO CANCELADA!\n");
                                                printf("============================================================\n");
                                                getchar();
                                                return 0;
                                            }
                                            aux = aux->prox;
                                        }
                                    strcpy(p->dados.nome,tmp->dados.nome);
                                    printf("NOME ALTERADO COM SUCESSO!\n");
                                   printf("============================================================\n");
                                   break;
                           case 2:
                                   printf("NOVO EMAIL: ");
                                   scanf("%s",p->dados.email);
                                   printf("EMAIL ALTERADO COM SUCESSO!\n");
                                   printf("============================================================\n");
                                   break;
                           case 3:
                                   printf("NOVO TELEFONE: ");
                                   scanf("%s",p->dados.tel);
                                   printf("TELEFONE ALTERADO COM SUCESSO!\n");
                                   printf("============================================================\n");
                                   break;
                           case 4:
                                   printf("------------------------------------------------------------\n");
                                   printf("DADOS ATUAIS:\n");
                                   printf("NOME: %s\n",p->dados.nome);
                                   printf("E-MAIL: %s\n",p->dados.email);
                                   printf("TELEFONE: %s\n",p->dados.tel);
                                   printf("------------------------------------------------------------\n");
                        }
                    }while(x != 5);
                printf("============================================================\n");
                printf("OPERACAO FINALIZADA!\n");
                printf("============================================================\n");
                getchar();
                getchar();
                return 1;
            }
    }
    printf("============================================================\n");
    printf("USUARIO NAO ENCONTRADO!\n");
    printf("============================================================\n");
    getchar();
 return 0;
}

int ordenarLista(lista *li){
    if(*li == NULL || li == NULL){
        printf("============================================================\n");
        printf("AGENDA VAZIA!\n");
        printf("============================================================\n");
        getchar();
        getchar();
        return 0;
    }

    struct usuario temp;

        for(elem *ant = *li;ant != NULL;ant=ant->prox){
                for(elem *aux = ant->prox;aux != NULL;aux=aux->prox){
                        if(strcmp(ant->dados.nome,aux->dados.nome) > 0){
                            strcpy(temp.nome,ant->dados.nome);
                            strcpy(temp.email,ant->dados.email);
                            strcpy(temp.tel,ant->dados.tel);

                            strcpy(ant->dados.nome,aux->dados.nome);
                            strcpy(ant->dados.email,aux->dados.email);
                            strcpy(ant->dados.tel,aux->dados.tel);

                            strcpy(aux->dados.nome,temp.nome);
                            strcpy(aux->dados.email,temp.email);
                            strcpy(aux->dados.tel,temp.tel);
                        }
                }
        }
        printf("============================================================\n");
        printf("AGENDA ORDENADA!\n");
        printf("============================================================\n");
        getchar();
        getchar();
return 1;
}

int main(){
    int opt;
    struct usuario novo;    //novo contato
	lista *li;  //ponteiro de ponteiro
    li = criaLista();

        do{
            menu();
            printf("Opcao: ");
            scanf("%d",&opt);
            switch(opt){
                case 1:
                        novo = infoUsuario();
                        inserirFinal(li,novo);
                        getchar();
                        getchar();
                        break;
                case 2:
                        editarUsuario(li);
                        break;
                case 3:
                        remover(li);
                        getchar();
                        break;
                case 4:
                        mostrarLista(li,count);
                        getchar();
                        getchar();
                        break;
                case 5:
                        buscarUsuario(li);
                        break;
                case 6:
                        ordenarLista(li);
                        break;
                case 7:
                        liberaLista(li);
                        printf("============================================================\n");
                        printf("AGENDA LIMPA\n");
                        printf("============================================================\n");
                        getchar();
                        getchar();
                        criaLista();
                        break;
            }
            limpar_tela();
        }while(opt != 8);
    liberaLista(li);
    return 0;
}

void menu(void){
        titulo();
        printf("\n");
        printf("\t\t     [1] - INSERIR CONTATO\n");
     	printf("\t\t     [2] - EDITAR CONTATO\n");
        printf("\t\t     [3] - REMOVER CONTATO\n");
        printf("\t\t     [4] - MOSTRAR CONTATOS\n");
        printf("\t\t     [5] - BUSCAR CONTATO\n");
        printf("\t\t     [6] - ORDENAR AGENDA\n");
        printf("\t\t     [7] - LIMPAR AGENDA\n");
     	printf("\t\t     [8] - SAIR\n");
}

void titulo(void){
    printf("============================================================\n");
    printf("\t\tA G E N D A  -  T E L E F O N I C A\n");
    printf("============================================================\n");
}
