/*  Trabalho 1 (BATALHA-NAVAL)
    Nome: Victor Alves de Carvalho
    Matricula: 16/0147140
    Nome: Pedro Felipe de Oliveira Ribeiro
    Matrícula:160141168
    Estrutura de Dados - Turma B  2017/01 */

/*DIRETIVAS DE PRE-PROCESSAMENTO PARA A FUNCAO SYSTEM("CLS")*/
#if defined(__MINGW32__) || defined(_MSC_VER)
#define limpar_tela() system("cls")
#else
#define limpar_tela() system("clear")
#endif // defined

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define m 10
#define n 10

//CABECALHOS
void titulo(void);
void regras(void);
int menu(void);
void posicionar_m1(int mapa1[m][n]);
void posicionar_m2(int mapa2[m][n]);
void imprimeTabuleiro1(int mapa1[m][n]);
void imprimeTabuleiro2(int mapa2[m][n]);
void jogar(int mapa1[m][n],int mapa2[m][n]);
void historico1(int historicoJ1[m][n]);
void historico2(int historicoJ2[m][n]);
void legendaMapa(void);

//VARIAVEIS GLOBAIS
int mapa1[m][n]; //tabuleiro do jogador 1
int mapa2[m][n]; //tabuleiro do jogador 2

int historicoJ1[m][n];  //Historico de jogadas do jogador 1
int historicoJ2[m][n];  //Historico de jogadas do jogador 2
int rodadas;    //Quantidade de rodadas do jogo

//CONTADORES
    int pontos_j1 = 0;
    int pontos_j2 = 0;
    int tiroFalho_j1 = 0;
    int tiroFalho_j2 = 0;
    int botes_j1 = 0;
    int botes_j2 = 0;
    int navio_j1 = 0;
    int navio_j2 = 0;
    int encouracado_j1 = 0;
    int encouracado_j2 = 0;
    int portaAvioes_j1 = 0;
    int portaAvioes_j2 = 0;

int op = 0;

	//LEGENDA DO MAPA
	int agua = 45; // ~
	int bote = 43;  // +
	int navio = 42; // *
	int encouracado = 64; // @
	int portaAviao = 35; // #
	int localAtingido = 88; // X
    int oculto = 177;   //LOCAIS NAO REVELADOS NO MAPA ATE ENTAO

//FUNCAO MAIN
int main(){
    posicionar_m1(mapa1);
    posicionar_m2(mapa2);
    menu();

return 0;
}

int menu(void){
    titulo();
	int i,j;
	int x = 177;    //Simbolo para agua na tabela ascii (nova)

		int M[10][10];
		for(i=0;i<10;i++){
        	printf("\t\t\t\t");
            	for(j=0;j<10;j++){
                	printf("%c ",x);
            	}
			puts(""); //quebra de linha na matriz
		}
	printf("--------------------------------------------------------------------------------\n");

printf("\t\t\t     ---------[MENU]---------\n\n");
    printf("\t\t\t\t [1] - Jogar\n\n");
    printf("\t\t\t\t [2] - Como jogar?\n\n");
    printf("\t\t\t\t [3] - Sair\n\n");
    printf("\t\t\t     ------------------------\n");
	printf("--------------------------------------------------------------------------------\n");
    scanf("%d",&op);
        switch(op){
            case(1):
                    limpar_tela();
                    jogar(mapa1,mapa2);
                    break;
            case(2):
                    limpar_tela();
                    regras();
                    break;
            case(3):
                    limpar_tela();
                    titulo();
                    printf("\n\n");
                    printf("\t\t\t\t  A T E  L O G O!\n");
                    return 0;
            default:
                    limpar_tela();
                    menu();
        }//FIM SWITCH
}

void regras(void){
    titulo();

    printf("\t\t\t        - REGRAS DO JOGO -\n\n");
    printf("1)O SEU EXERCITO POSSUI UM ARSENAL DE 70/60/40 TIROS DE CANHAO PARA DESTRUIR\n");
    printf("SEU ADVERSARIO.\n");
	printf("2)O VENCEDOR SERA AQUELE QUE DESTRUIR POR COMPLETO AS EMBARCACOES INIMIGAS,\n");
    printf("OU QUEM TIVER A MAIOR PORCENTAGEM DE TIROS CERTEIROS AO FINAL DO JOGO.\n");
    printf("\n");
    printf("\t\t\tEMBARCACOES DISPONIVEIS NO JOGO:\n");
    printf("\t\t\t\t4 BOTES (+)\n");
    printf("\t\t\t\t3 NAVIOS (**)\n");
    printf("\t\t\t\t2 ENCOURACADOS (####)\n");
    printf("\t\t\t\t1 PORTA-AVIAO (@@@@@)\n");
    printf("\n");
	printf("\nOBS: Os barcos estao posicionados na VERTICAL ou HORIZONTAL representado\n");
	printf("por coordenadas (i,j)(i = linha e j = coluna). O tabuleiro tem o tamanho 10x10,\n");
    printf("logo i e j vao de ZERO a NOVE (0-9).\n");
    printf("\n\n");
    printf("\t\t\t    [ENTER] - Voltar ao menu\n");
	printf("--------------------------------------------------------------------------------\n");
    getchar();
    getchar();
    limpar_tela();
    menu();
}

void posicionar_m1(int mapa1[m][n]){
//1 PORTA AVIAO;
    int p1i,p1j;

    //RANDOMIZA A PRIMEIRA PARTE DO PORTA AVIAO
    srand(time(NULL));
    p1i = rand() % 10;
    p1j = rand() % 10;

    //NAO DEIXAR O PORTA AVIAO FICAR EM LINHAS DIFERENTES LIMITANDO OS EXTREMOS DAS COLUNAS (2 a 7)
    while(p1j > 7 || p1j < 2){
        p1j = rand() % 10;
    }

    //ANEXANDO O PORTA-AVIAO (HORIZONTAL)
    mapa1[p1i][p1j-2] = 5;
    mapa1[p1i][p1j-1] = 5;
    mapa1[p1i][p1j] = 5;
    mapa1[p1i][p1j+1] = 5;
    mapa1[p1i][p1j+2] = 5;

//2 ENCOURACADOS
    int e1i,e1j,e2i,e2j;

    //RANDOMIZA A PRIMEIRA PARTE DOS ENCOURACADOS
        srand(time(NULL));
        e1i = rand() % 10;
        e1j = rand() % 10;
        e2i = rand() % 10;
        e2j = rand() % 10;

    //LIMITE DE EXTREMO VERTICAL(0 a 6) E CHECAGEM DA VIZINHANCA VERTICAL DA PRIMEIRA PARTE(*) DO ENCOURACADO 1 (* - - -)
        while(e1i > 6 || (mapa1[e1i][e1j] || mapa1[e1i+1][e1j] || mapa1[e1i+2][e1j] || mapa1[e1i+3][e1j]) != 0){
            e1i = rand() % 10;
            e1j = rand() % 10;
        }
    //ANEXANDO ENCOURACADO 1 (VERTICAL)
    mapa1[e1i][e1j] = 4;
    mapa1[e1i+1][e1j] = 4;
    mapa1[e1i+2][e1j] = 4;
    mapa1[e1i+3][e1j] = 4;

    //LIMITE DE EXTREMO HORIZONTAL(0 a 6) E CHECAGEM DA VIZINHANCA VERTICAL DA PRIMEIRA PARTE(*) DO ENCOURACADO 2 (* - - -)
    while(e2j > 6 || (mapa1[e2i][e2j] || mapa1[e2i][e2j+1] || mapa1[e2i][e2j+2] || mapa1[e2i][e2j+3]) != 0){
        e2i = rand() % 10;
        e2j = rand() % 10;
    }
    //ANEXANDO ENCOURACADO 2 (HORIZONTAL)
    mapa1[e2i][e2j] = 4;
    mapa1[e2i][e2j+1] = 4;
    mapa1[e2i][e2j+2] = 4;
    mapa1[e2i][e2j+3] = 4;

//3 NAVIOS
    int n1i,n1j,n2i,n2j,n3i,n3j;

    //RANDOMIZA AS PRIMEIRAS PARTES DOS NAVIOS
        srand(time(NULL));
        n1i = rand() % 10;
        n1j = rand() % 10;
        n2i = rand() % 10;
        n2j = rand() % 10;
        n3i = rand() % 10;
        n3j = rand() % 10;

    //NAO DEIXAR O NAVIO FICAR EM LINHAS DIFERENTES LIMITANDO OS EXTREMOS DAS COLUNAS (0 a 8) E CHECAGEM DE VIZINHANCA
    while(n1j == 9 || (mapa1[n1i][n1j] || mapa1[n1i][n1j+1]) != 0){
        n1i = rand() % 10;
        n1j = rand() % 10;
    }
    //ANEXANDO NAVIO 1 (HORIZONTAL)
    mapa1[n1i][n1j] = 2;
    mapa1[n1i][n1j+1] = 2;

    //NAO DEIXAR O NAVIO FICAR EM LINHAS DIFERENTES LIMITANDO OS EXTREMOS DAS COLUNAS (0 a 8) E CHECAGEM DE VIZINHANCA
    while(n2j == 9 || (mapa1[n2i][n2j] || mapa1[n2i][n2j+1]) != 0){
        n2i = rand() % 10;
        n2j = rand() % 10;
    }
    //ANEXANDO NAVIO 2 (HORIZONTAL)
    mapa1[n2i][n2j] = 2;
    mapa1[n2i][n2j+1] = 2;

    //NAO DEIXAR O NAVIO FICAR EM LINHAS DIFERENTES LIMITANDO OS EXTREMOS DAS LINHAS (0 a 8) E CHECAGEM DE VIZINHANCA
    while(n3i == 9 || (mapa1[n3i][n3j] || mapa1[n3i+1][n3j]) != 0){
        n3i = rand() % 10;
        n3j = rand() % 10;
    }
    //ANEXANDO NAVIO 3 (VERTICAL)
    mapa1[n3i][n3j] = 2;
    mapa1[n3i+1][n3j] = 2;

    // 4 BOTES
	int b1i,b2i,b3i,b4i;
	int b1j,b2j,b3j,b4j;
	srand (time(NULL));
    b1i = rand() % 10;
    b1j = rand() % 10;
	b2i = rand() % 10;
	b2j = rand() % 10;
	b3i = rand() % 10;
	b3j = rand() % 10;
	b4i = rand() % 10;
	b4j = rand() % 10;

    //CHECAGEM DE VIZINHANCA DO BOTE 1
    while(mapa1[b1i][b1j] != 0){
        b1i= rand() % 10;
        b1j= rand() % 10;
    }
    //ANEXANDO BOTE 1
    mapa1[b1i][b1j] = 1;

    //CHECAGEM DE VIZINHANCA DO BOTE 2
    while(mapa1[b2i][b2j] != 0){
        b2i= rand() % 10;
        b2j= rand() % 10;
    }
    //ANEXANDO BOTE 2
	mapa1[b2i][b2j] = 1;

    //CHECAGEM DE VIZINHANCA DO BOTE 3
    while(mapa1[b3i][b3j] != 0){
        b3i= rand() % 10;
        b3j= rand() % 10;
    }
    //ANEXANDO BOTE 3
	mapa1[b3i][b3j] = 1;

    //CHECAGEM DE VIZINHANCA DO BOTE 4
    while(mapa1[b4i][b4j] != 0){
        b4i= rand() % 10;
        b4j= rand() % 10;
    }
    //ANEXANDO BOTE 4
	mapa1[b4i][b4j] = 1;

}

void posicionar_m2(int mapa2[m][n]){
//1 PORTA AVIAO;
    int p1i,p1j;

    //RANDOMIZA A PRIMEIRA PARTE DO PORTA AVIAO
    //srand(time(NULL));
    p1i = rand() % 10;
    p1j = rand() % 10;

    //NAO DEIXAR O PORTA AVIAO FICAR EM LINHAS DIFERENTES LIMITANDO OS EXTREMOS DAS COLUNAS (2 a 7)
    while(p1j > 7 || p1j < 2){
        p1j = rand() % 10;
    }

    //ANEXANDO O PORTA-AVIAO (HORIZONTAL)
    mapa2[p1i][p1j-2] = 5;
    mapa2[p1i][p1j-1] = 5;
    mapa2[p1i][p1j] = 5;
    mapa2[p1i][p1j+1] = 5;
    mapa2[p1i][p1j+2] = 5;

//2 ENCOURACADOS
    int e1i,e1j,e2i,e2j;

    //RANDOMIZA A PRIMEIRA PARTE DOS ENCOURACADOS
        //srand(time(NULL));
        e1i = rand() % 10;
        e1j = rand() % 10;
        e2i = rand() % 10;
        e2j = rand() % 10;

    //LIMITE DE EXTREMO VERTICAL(0 a 6) E CHECAGEM DA VIZINHANCA VERTICAL DA PRIMEIRA PARTE(*) DO ENCOURACADO 1 (* - - -)
        while(e1i > 6 || (mapa2[e1i][e1j] || mapa2[e1i+1][e1j] || mapa2[e1i+2][e1j] || mapa2[e1i+3][e1j]) != 0){
            e1i = rand() % 10;
            e1j = rand() % 10;
        }
    //ANEXANDO ENCOURACADO 1 (VERTICAL)
    mapa2[e1i][e1j] = 4;
    mapa2[e1i+1][e1j] = 4;
    mapa2[e1i+2][e1j] = 4;
    mapa2[e1i+3][e1j] = 4;

    //LIMITE DE EXTREMO HORIZONTAL(0 a 6) E CHECAGEM DA VIZINHANCA VERTICAL DA PRIMEIRA PARTE(*) DO ENCOURACADO 2 (* - - -)
    while(e2j > 6 || (mapa2[e2i][e2j] || mapa2[e2i][e2j+1] || mapa2[e2i][e2j+2] || mapa2[e2i][e2j+3]) != 0){
        e2i = rand() % 10;
        e2j = rand() % 10;
    }
    //ANEXANDO ENCOURACADO 2 (HORIZONTAL)
    mapa2[e2i][e2j] = 4;
    mapa2[e2i][e2j+1] = 4;
    mapa2[e2i][e2j+2] = 4;
    mapa2[e2i][e2j+3] = 4;

//3 NAVIOS
    int n1i,n1j,n2i,n2j,n3i,n3j;

    //RANDOMIZA AS PRIMEIRAS PARTES DOS NAVIOS
        //srand(time(NULL));
        n1i = rand() % 10;
        n1j = rand() % 10;
        n2i = rand() % 10;
        n2j = rand() % 10;
        n3i = rand() % 10;
        n3j = rand() % 10;

    //NAO DEIXAR O NAVIO FICAR EM LINHAS DIFERENTES LIMITANDO OS EXTREMOS DAS COLUNAS (0 a 8) E CHECAGEM DE VIZINHANCA
    while(n1j == 9 || (mapa2[n1i][n1j] || mapa2[n1i][n1j+1]) != 0){
        n1i = rand() % 10;
        n1j = rand() % 10;
    }
    //ANEXANDO NAVIO 1 (HORIZONTAL)
    mapa2[n1i][n1j] = 2;
    mapa2[n1i][n1j+1] = 2;

    //NAO DEIXAR O NAVIO FICAR EM LINHAS DIFERENTES LIMITANDO OS EXTREMOS DAS COLUNAS (0 a 8) E CHECAGEM DE VIZINHANCA
    while(n2j == 9 || (mapa2[n2i][n2j] || mapa2[n2i][n2j+1]) != 0){
        n2i = rand() % 10;
        n2j = rand() % 10;
    }
    //ANEXANDO NAVIO 2 (HORIZONTAL)
    mapa2[n2i][n2j] = 2;
    mapa2[n2i][n2j+1] = 2;

    //NAO DEIXAR O NAVIO FICAR EM LINHAS DIFERENTES LIMITANDO OS EXTREMOS DAS LINHAS (0 a 8) E CHECAGEM DE VIZINHANCA
    while(n3i == 9 || (mapa2[n3i][n3j] || mapa2[n3i+1][n3j]) != 0){
        n3i = rand() % 10;
        n3j = rand() % 10;
    }
    //ANEXANDO NAVIO 3 (VERTICAL)
    mapa2[n3i][n3j] = 2;
    mapa2[n3i+1][n3j] = 2;

    // 4 BOTES
	int b1i,b2i,b3i,b4i;
	int b1j,b2j,b3j,b4j;
	//srand (time(NULL));
    b1i = rand() % 10;
    b1j = rand() % 10;
	b2i = rand() % 10;
	b2j = rand() % 10;
	b3i = rand() % 10;
	b3j = rand() % 10;
	b4i = rand() % 10;
	b4j = rand() % 10;

    //CHECAGEM DE VIZINHANCA DO BOTE 1
    while(mapa2[b1i][b1j] != 0){
        b1i= rand() % 10;
        b1j= rand() % 10;
    }
    //ANEXANDO BOTE 1
    mapa2[b1i][b1j] = 1;

    //CHECAGEM DE VIZINHANCA DO BOTE 2
    while(mapa2[b2i][b2j] != 0){
        b2i= rand() % 10;
        b2j= rand() % 10;
    }
    //ANEXANDO BOTE 2
	mapa2[b2i][b2j] = 1;

    //CHECAGEM DE VIZINHANCA DO BOTE 3
    while(mapa2[b3i][b3j] != 0){
        b3i= rand() % 10;
        b3j= rand() % 10;
    }
    //ANEXANDO BOTE 3
	mapa2[b3i][b3j] = 1;

    //CHECAGEM DE VIZINHANCA DO BOTE 4
    while(mapa2[b4i][b4j] != 0){
        b4i= rand() % 10;
        b4j= rand() % 10;
    }
    //ANEXANDO BOTE 4
	mapa2[b4i][b4j] = 1;

}

void imprimeTabuleiro1(int mapa1[m][n]){
	int i,j,k;

	printf("\t\t\t\t    Tabuleiro 1: \n");
        printf("\t\t\t\t");
        printf("  ");
        for(k=0;k<10;k++){
            printf("%d ",k);
        }
            printf("\n");
			for(i=0;i<10;i++){
        	printf("\t\t\t\t");
        	printf("%d ",i);
            	for(j=0;j<10;j++){
                        if(mapa1[i][j] == 0){
                            printf("%c ",agua);
                        }
                        if(mapa1[i][j] == 1){
                            printf("%c ",bote);
                        }
                        if(mapa1[i][j] == 2){
                            printf("%c ",navio);
                        }
                        if(mapa1[i][j] == 4){
                            printf("%c ",encouracado);
                        }
                        if(mapa1[i][j] == 5){
                            printf("%c ",portaAviao);
                        }
                        if(mapa1[i][j] == 9){
                            printf("%c ",localAtingido);
                        }
            	}
                puts(""); //quebra de linha na matriz
            }
}

void imprimeTabuleiro2(int mapa2[m][n]){
	int i,j,k;

	printf("\t\t\t\t    Tabuleiro 2: \n");
        printf("\t\t\t\t");
        printf("  ");
        for(k=0;k<10;k++){
            printf("%d ",k);
        }
        printf("\n");
			for(i=0;i<10;i++){
        	printf("\t\t\t\t");
        	printf("%d ",i);
            	for(j=0;j<10;j++){
                        if(mapa2[i][j] == 0){
                            printf("%c ",agua);
                        }
                        if(mapa2[i][j] == 1){
                            printf("%c ",bote);
                        }
                        if(mapa2[i][j] == 2){
                            printf("%c ",navio);
                        }
                        if(mapa2[i][j] == 4){
                            printf("%c ",encouracado);
                        }
                        if(mapa2[i][j] == 5){
                            printf("%c ",portaAviao);
                        }
                        if(mapa2[i][j] == 9){
                            printf("%c ",localAtingido);
                        }
            	}
                puts(""); //quebra de linha na matriz
            }
}

void titulo(void){
	printf("--------------------------------------------------------------------------------\n");
    printf("\t\t\t     B A T A L H A - N A V A L\n");
	printf("--------------------------------------------------------------------------------\n");
}

void jogar(int mapa1[m][n],int mapa2[m][n]){
    int op = 0;
    titulo();
    printf("\t\t\t     ---------[JOGAR]---------\n\n");
    printf("\t\t\t     [1] - Facil    (70 tiros)\n\n");
    printf("\t\t\t     [2] - Medio    (60 tiros)\n\n");
    printf("\t\t\t     [3] - Dificil  (40 tiros)\n\n");
    printf("\t\t\t     ------------------------\n");
	printf("--------------------------------------------------------------------------------\n");
    printf("DIFICULDADE: ");
    scanf("%d",&op);
    limpar_tela();
    titulo();
        switch(op){
            case(1):
                    rodadas = 70;
                    break;
            case(2):
                    rodadas = 60;
                    break;
            case(3):
                    rodadas = 40;
                    break;
            default:
                    limpar_tela();
                    jogar(mapa1,mapa2);
        }
    getchar();
        char nome[20];   //nome do jogador 1
        char nome2[20];  //nome do jogador 2
        char caractere;

        //STRINGS DE MENSAGENS
        char msg[100] = {"VOCE ATINGIU A AGUA!"};
        char msg2[100] = {"VOCE DESTRUIU UM BOTE!"};
        char msg3[100] = {"VOCE DESTRUIU PARTE DE UM NAVIO!"};
        char msg4[100] = {"VOCE DESTRUIU PARTE DE UM ENCOURACADO!"};
        char msg5[100] = {"VOCE DESTRUIU PARTE DE UM PORTA-AVIAO!"};
        char msg6[100] = {"ESTE LOCAL JA FOI ATINGIDO, ESCOLHA OUTRO."};

        //NOME DO JOGADOR 1
        printf("NOME DO JOGADOR 1: ");
        int i = 0;
        do{
            caractere = getchar();
            nome[i] = caractere;
            ++i;
        }while(caractere != '\n');
        nome[i-1] = '\0';

        //NOME DO JOGADOR 2
        printf("NOME DO JOGADOR 2: ");
        int j = 0;

        do{
            caractere = getchar();
            nome2[j] = caractere;
            ++j;
        }while(caractere != '\n');
        nome2[j-1] = '\0';

    //LACO ONDE O JOGO SE DESENVOLVE
        limpar_tela();
        titulo();

    //LINHA E COLUNA DO TIRO
    int l;  //linha
    int c;  //coluna

    int k; //VARIAVEL PARA O LACO
    for(k=1;k<=rodadas;k++){
        printf("\t\t\t    --------- RODADA %d ---------\n",k);
        printf("JOGADOR 1: %s \n",nome);
        printf("PONTOS: %d\n",pontos_j1);
        printf("TIROS:(%d/%d)\n",k,rodadas);

                //MOSTRA AS POSICOES JA ACERTADAS
                historico1(historicoJ1);
                legendaMapa();

        printf("\n");
        printf("INFORME A COORDENADA (i,j) DO TIRO: ");
        scanf("%d %d",&l,&c);
            while(l > 9 || c > 9){
                printf("\a COORDENADA INVALIDA, DIGITE NOVAMENTE(0-9): ");
                scanf("%d %d",&l,&c);
            }
        printf("ALVO ESCOLHIDO: (%d,%d)\n",l,c);
            //ANALISE DO TIRO EFETUADO
            switch(mapa2[l][c]){
                case(0)://AGUA
                        printf("%s \n",msg);
                        tiroFalho_j1++;
                        mapa2[l][c] = 9; //9 é o numero escolhido para representar um local atingido no mapa
                        historicoJ1[l][c] = 10; //VALOR ESCOLHIDO PARA CONVERTER EM SIMBOLO ASCII NA FUNCAO DE HISTORICO
                        break;

                case(1)://BOTE
                        printf("%s \n",msg2);
                        pontos_j1++;
                        botes_j1++;
                        mapa2[l][c] = 9; //9 é o numero escolhido para representar um local atingido no mapa
                        historicoJ1[l][c] = 1; //VALOR ESCOLHIDO PARA CONVERTER EM SIMBOLO ASCII NA FUNCAO DE HISTORICO
                        break;

                case(2)://NAVIO
                        printf("%s \n",msg3);
                        pontos_j1++;
                        navio_j1++;
                        mapa2[l][c] = 9; //9 é o numero escolhido para representar um local atingido no mapa
                        historicoJ1[l][c] = 2; //VALOR ESCOLHIDO PARA CONVERTER EM SIMBOLO ASCII NA FUNCAO DE HISTORICO
                        break;

                case(4)://ENCOURACADO
                        printf("%s \n",msg4);
                        pontos_j1++;
                        encouracado_j1++;
                        mapa2[l][c] = 9; //9 é o numero escolhido para representar um local atingido no mapa
                        historicoJ1[l][c] = 4; //VALOR ESCOLHIDO PARA CONVERTER EM SIMBOLO ASCII NA FUNCAO DE HISTORICO
                        break;

                case(5)://PORTA-AVIAO
                        printf("%s \n",msg5);
                        pontos_j1++;
                        portaAvioes_j1++;
                        mapa2[l][c] = 9; //9 é o numero escolhido para representar um local atingido no mapa
                        historicoJ1[l][c] = 5; //VALOR ESCOLHIDO PARA CONVERTER EM SIMBOLO ASCII NA FUNCAO DE HISTORICO
                        break;

                case(9)://LOCAL JA ATINGIDO
                        printf("%s \n",msg6);
                            printf("\nINFORME A COORDENADA (i,j) DO TIRO: ");
                            scanf("%d %d",&l,&c);
                                while(mapa2[l][c] == 9 || l > 9 || c > 9){
                                    printf("\a COORDENADA INVALIDA, DIGITE NOVAMENTE(0-9): ");
                                    scanf("%d %d",&l,&c);
                                }
                                if(mapa2[l][c] == 0){
                                    printf("%s \n",msg);
                                    tiroFalho_j1++;
                                    mapa2[l][c] = 9; //9 é o numero escolhido para representar um local atingido no mapa
                                    historicoJ1[l][c] = 10; //VALOR ESCOLHIDO PARA CONVERTER EM SIMBOLO ASCII NA FUNCAO DE HISTORICO
                                }
                                if(mapa2[l][c] == 1){
                                    printf("%s \n",msg2);
                                    pontos_j1++;
                                    botes_j1++;
                                    mapa2[l][c] = 9; //9 é o numero escolhido para representar um local atingido no mapa
                                    historicoJ1[l][c] = 1; //VALOR ESCOLHIDO PARA CONVERTER EM SIMBOLO ASCII NA FUNCAO DE HISTORICO
                                }
                                if(mapa2[l][c] == 2){
                                    printf("%s \n",msg3);
                                    pontos_j1++;
                                    navio_j1++;
                                    mapa2[l][c] = 9; //9 é o numero escolhido para representar um local atingido no mapa
                                    historicoJ1[l][c] = 2; //VALOR ESCOLHIDO PARA CONVERTER EM SIMBOLO ASCII NA FUNCAO DE HISTORICO
                                }
                                if(mapa2[l][c] == 4){
                                    printf("%s \n",msg4);
                                    pontos_j1++;
                                    encouracado_j1++;
                                    mapa2[l][c] = 9; //9 é o numero escolhido para representar um local atingido no mapa
                                    historicoJ1[l][c] = 4; //VALOR ESCOLHIDO PARA CONVERTER EM SIMBOLO ASCII NA FUNCAO DE HISTORICO
                                }
                                if(mapa2[l][c] == 5){
                                    printf("%s \n",msg5);
                                    pontos_j1++;
                                    portaAvioes_j1++;
                                    mapa2[l][c] = 9; //9 é o numero escolhido para representar um local atingido no mapa
                                    historicoJ1[l][c] = 5; //VALOR ESCOLHIDO PARA CONVERTER EM SIMBOLO ASCII NA FUNCAO DE HISTORICO
                                }
                        break;
            }
        printf("\n");
        printf("********************************************************************************\n");
        printf("JOGADOR 2: %s \n",nome2);
        printf("PONTOS: %d\n",pontos_j2);
        printf("TIROS:(%d/%d)\n",k,rodadas);

                //MOSTRA AS POSICOES JA ACERTADAS
                historico2(historicoJ2);
                legendaMapa();

        printf("\n");
        printf("INFORME A COORDENADA (i,j) DO TIRO: ");
        scanf("%d %d",&l,&c);
            while(l > 9 || c > 9){
                printf("\a COORDENADA INVALIDA, DIGITE NOVAMENTE(0-9): ");
                scanf("%d %d",&l,&c);
            }
        printf("ALVO ESCOLHIDO: (%d,%d)\n",l,c);
            //ANALISE DO TIRO EFETUADO
            switch(mapa1[l][c]){
                case(0)://AGUA
                        printf("%s \n",msg);
                        tiroFalho_j2++;
                        mapa1[l][c] = 9; //9 é o numero escolhido para representar um local atingido no mapa
                        historicoJ2[l][c] = 10; //VALOR ESCOLHIDO PARA CONVERTER EM SIMBOLO ASCII NA FUNCAO DE HISTORICO
                        break;

                case(1)://BOTE
                        printf("%s \n",msg2);
                        pontos_j2++;
                        botes_j2++;
                        mapa1[l][c] = 9; //9 é o numero escolhido para representar um local atingido no mapa
                        historicoJ2[l][c] = 1; //VALOR ESCOLHIDO PARA CONVERTER EM SIMBOLO ASCII NA FUNCAO DE HISTORICO
                        break;

                case(2)://NAVIO
                        printf("%s \n",msg3);
                        pontos_j2++;
                        navio_j2++;
                        mapa1[l][c] = 9; //9 é o numero escolhido para representar um local atingido no mapa
                        historicoJ2[l][c] = 2; //VALOR ESCOLHIDO PARA CONVERTER EM SIMBOLO ASCII NA FUNCAO DE HISTORICO
                        break;

                case(4)://ENCOURACADO
                        printf("%s \n",msg4);
                        pontos_j2++;
                        encouracado_j2++;
                        mapa1[l][c] = 9; //9 é o numero escolhido para representar um local atingido no mapa
                        historicoJ2[l][c] = 4; //VALOR ESCOLHIDO PARA CONVERTER EM SIMBOLO ASCII NA FUNCAO DE HISTORICO
                        break;

                case(5)://PORTA-AVIAO
                        printf("%s \n",msg5);
                        pontos_j2++;
                        portaAvioes_j2++;
                        mapa1[l][c] = 9; //9 é o numero escolhido para representar um local atingido no mapa
                        historicoJ2[l][c] = 5; //VALOR ESCOLHIDO PARA CONVERTER EM SIMBOLO ASCII NA FUNCAO DE HISTORICO
                        break;

                case(9)://LOCAL JA ATINGIDO
                        printf("%s \n",msg6);
                            printf("\nINFORME A COORDENADA (i,j) DO TIRO: ");
                            scanf("%d %d",&l,&c);
                                while(mapa1[l][c] == 9 || l > 9 || c > 9){
                                    printf("\a COORDENADA INVALIDA, DIGITE NOVAMENTE(0-9): ");
                                    scanf("%d %d",&l,&c);
                                }
                                if(mapa1[l][c] == 0){
                                    printf("%s \n",msg);
                                    tiroFalho_j2++;
                                    mapa1[l][c] = 9; //9 é o numero escolhido para representar um local atingido no mapa
                                    historicoJ2[l][c] = 10; //VALOR ESCOLHIDO PARA CONVERTER EM SIMBOLO ASCII NA FUNCAO DE HISTORICO
                                }
                                if(mapa1[l][c] == 1){
                                    printf("%s \n",msg2);
                                    pontos_j2++;
                                    botes_j2++;
                                    mapa1[l][c] = 9; //9 é o numero escolhido para representar um local atingido no mapa
                                    historicoJ2[l][c] = 1; //VALOR ESCOLHIDO PARA CONVERTER EM SIMBOLO ASCII NA FUNCAO DE HISTORICO
                                }
                                if(mapa1[l][c] == 2){
                                    printf("%s \n",msg3);
                                    pontos_j2++;
                                    navio_j2++;
                                    mapa1[l][c] = 9; //9 é o numero escolhido para representar um local atingido no mapa
                                    historicoJ2[l][c] = 2; //VALOR ESCOLHIDO PARA CONVERTER EM SIMBOLO ASCII NA FUNCAO DE HISTORICO
                                }
                                if(mapa1[l][c] == 4){
                                    printf("%s \n",msg4);
                                    pontos_j2++;
                                    encouracado_j2++;
                                    mapa1[l][c] = 9; //9 é o numero escolhido para representar um local atingido no mapa
                                    historicoJ2[l][c] = 4; //VALOR ESCOLHIDO PARA CONVERTER EM SIMBOLO ASCII NA FUNCAO DE HISTORICO
                                }
                                if(mapa1[l][c] == 5){
                                    printf("%s \n",msg5);
                                    pontos_j2++;
                                    portaAvioes_j2++;
                                    mapa1[l][c] = 9; //9 é o numero escolhido para representar um local atingido no mapa
                                    historicoJ2[l][c] = 5; //VALOR ESCOLHIDO PARA CONVERTER EM SIMBOLO ASCII NA FUNCAO DE HISTORICO
                                }
                        break;
            }//FIM SWITCH(mapa1[l][c])

        printf("\n\n");
        printf("--------------------------------------------------------------------------------\n");
        printf("\t\t  Tecle [ENTER] para ir para a proxima rodada.\n");
        printf("--------------------------------------------------------------------------------\n");
        getchar();
        getchar();
        limpar_tela();
        titulo();

        //CHECAGEM PARA VER SE ALGUEM DESTRUIU TODO O EXERCITO INIMIGO ANTES DA ULTIMA RODADA.
        if(pontos_j1 == 23 && pontos_j2 < 23){
            k = rodadas;    //forca o fim do laco
        }
            if(pontos_j2 == 23 && pontos_j1 < 23){
                k = rodadas;    //forca o fim do laco
            }
    }//FIM WHILE

        //PORCENTAGEM DE ACERTO DOS JOGADORES   //TA BUGADO
        float porcentagem_j1 = 100*(float)(pontos_j1)/23;  //23 é o total de alvos no jogo
        float porcentagem_j2 = 100*(float)(pontos_j2)/23;  //23 é o total de alvos no jogo

            //DETERMINA O VENCEDOR E O PERDEDOR AO FINAL DE TODAS AS RODADAS
                if(pontos_j1 > pontos_j2 || porcentagem_j1 > porcentagem_j2){
                    printf("%s VENCEU A BATALHA!!!\n",nome);
                }
                if(pontos_j2 > pontos_j1 || porcentagem_j2 > porcentagem_j1){
                    printf("%s VENCEU A BATALHA!!!\n",nome2);
                }
                    //DETERMINA O VENCEDOR E O PERDEDOR POR DESEMPATE
                        if(pontos_j1 == pontos_j2 && porcentagem_j1 > porcentagem_j2){
                            printf("%s VENCEU A BATALHA!!!\n",nome);
                        }
                        if(pontos_j2 == pontos_j1 && porcentagem_j2 > porcentagem_j1){
                            printf("%s VENCEU A BATALHA!!!\n",nome2);
                        }
                        if(pontos_j2 == pontos_j1 && porcentagem_j2 == porcentagem_j1){
                            printf("EMPATE!\n");
                        }
        printf("\n\n");
        printf("********************************************************************************\n");
        imprimeTabuleiro2(mapa2);
        legendaMapa();
        printf("\t\t\t\t[x] - MARCA DOS TIROS\n");
        printf("--------------------------------------------------------------------------------\n");
        printf("RELACAO FINAL\n");
        printf("JOGADOR 1: %s\n",nome);
        printf("TOTAL DE PONTOS: %d \n",pontos_j1);
        printf("PORCENTAGEM DE ACERTO: %.2f %\n",porcentagem_j1);
        printf("TOTAL DE TIROS FALHOS: %d\n",tiroFalho_j1);
        printf("BOTES DESTRUIDOS: %d\n",botes_j1);
        printf("PARTE DE NAVIO DESTRUIDO: %d\n",navio_j1);
        printf("PARTE DE ENCOURACADO DESTRUIDO: %d\n",encouracado_j1);
        printf("PARTE DO PORTA-AVIAO DESTRUIDO: %d\n",portaAvioes_j1);
        printf("\n");
        printf("********************************************************************************\n");

        imprimeTabuleiro1(mapa1);
        legendaMapa();
        printf("\t\t\t\t[x] - MARCA DOS TIROS\n");
        printf("--------------------------------------------------------------------------------\n");
        printf("RELACAO FINAL\n");
        printf("JOGADOR 2: %s\n",nome2);
        printf("TOTAL DE PONTOS: %d \n",pontos_j2);
        printf("PORCENTAGEM DE ACERTO: %.2f %\n",porcentagem_j2);
        printf("TOTAL DE TIROS FALHOS: %d \n",tiroFalho_j2);
        printf("BOTES DESTRUIDOS: %d\n",botes_j2);
        printf("PARTE DE NAVIO DESTRUIDO: %d\n",navio_j2);
        printf("PARTE DE ENCOURACADO DESTRUIDO: %d\n",encouracado_j2);
        printf("PARTE DO PORTA-AVIAO DESTRUIDO: %d\n",portaAvioes_j2);
        printf("\n");
        printf("********************************************************************************\n");
        getchar();
        getchar();
}

void historico1(int historicoJ1[m][n]){
    int i,j,k;

        printf("\t\t\t\t     JOGADOR 1\n");
        printf("\t\t\t\tLOCAIS JA JOGADOS: \n");
            printf("\t\t\t\t");
            printf("  ");
            for(k=0;k<10;k++){
                printf("%d ",k);
            }
            printf("\n");
            for(i=0;i<10;i++){
                printf("\t\t\t\t");
                printf("%d ",i);
                    for(j=0;j<10;j++){
                        if(historicoJ1[i][j] == 0){
                            printf("%c ",oculto);
                        }
                        if(historicoJ1[i][j] == 10){
                            printf("%c ",agua);
                        }
                        if(historicoJ1[i][j] == 1){
                            printf("%c ",bote);
                        }
                        if(historicoJ1[i][j] == 2){
                            printf("%c ",navio);
                        }
                        if(historicoJ1[i][j] == 4){
                            printf("%c ",encouracado);
                        }
                        if(historicoJ1[i][j] == 5){
                            printf("%c ",portaAviao);
                        }
                    }
                printf("\n");
            }

}

void historico2(int historicoJ2[m][n]){
    int i,j,k;

        printf("\t\t\t\t     JOGADOR 2\n");
        printf("\t\t\t\tLOCAIS JA JOGADOS: \n");
                printf("\t\t\t\t");
        printf("  ");
        for(k=0;k<10;k++){
            printf("%d ",k);
        }
        printf("\n");
            for(i=0;i<10;i++){
                printf("\t\t\t\t");
                printf("%d ",i);
                    for(j=0;j<10;j++){
                        if(historicoJ2[i][j] == 0){
                            printf("%c ",oculto);
                        }
                        if(historicoJ2[i][j] == 10){
                            printf("%c ",agua);
                        }
                        if(historicoJ2[i][j] == 1){
                            printf("%c ",bote);
                        }
                        if(historicoJ2[i][j] == 2){
                            printf("%c ",navio);
                        }
                        if(historicoJ2[i][j] == 4){
                            printf("%c ",encouracado);
                        }
                        if(historicoJ2[i][j] == 5){
                            printf("%c ",portaAviao);
                        }
                    }
                printf("\n");
            }

}

void legendaMapa(void){
            printf("\n");
            printf("\t\t\t\t[-] - AGUA\n");
            printf("\t\t\t\t[+] - BOTE\n");
            printf("\t\t\t\t[*] - PARTE DE UM NAVIO\n");
            printf("\t\t\t\t[@] - PARTE DE UM ENCOURACADO\n");
            printf("\t\t\t\t[#] - PARTE DO PORTA AVIAO\n");
}

