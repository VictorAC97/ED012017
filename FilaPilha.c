#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void geraNumeros(void);
void pilha(void);
void push(int x);

    typedef struct pilha{
        int top;
        int s[10];
    }Pilha;

Pilha p;
int num[10];
int x;

int main(){
    geraNumeros();


return 0;
}

void geraNumeros(void){
    int i;
    int num[10];
    srand(time(NULL));

    for(i=0;i<10;i++){
        num[i] = rand() % 100;
        printf("%d ",num[i]);
    }
}

void push(int x){

    p.s[p.top] = x;
    p.top = p.top + 1;

}

void pop(void){
    p.s[p.top] =

}
