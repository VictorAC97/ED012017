#include <stdio.h>
#define n 12

int main(){

int i;
int j;
int vetor[n];
int matriz[3][4];

  //armazenamento de dados no vetor

    printf("Exercicio 1\n");
  for(i=0;i<n;i++){
    printf("Insira o valor %d: ",i);
    scanf("%d",&vetor[i]);
  }

  printf("O vetor e: ");
    for(i=0;i<n;i++){
      printf("%d,",vetor[i]);
    }
//--------------------------------------------
  puts("");
    printf("Exercicio 2\n");

  printf("\n A matriz e:\n");

  for(i=0;i<3;i++){
      for(j=0;j<4;j++){
        printf("Insira o valor %d,%d : ",i,j);
        scanf("%d",&matriz[i][j]);
      }
  }

  //imprimindo a matriz
  puts("");
  for(i=0;i<3;i++){
      for(j=0;j<4;j++){
        printf("%d",matriz[i][j]);
      }
  puts(""); //quebra de linha
  }

  return 0;
}
