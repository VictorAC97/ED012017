#include <stdio.h>
#define n 12

int main(){

int i;
int j;
int vetor[n];
int matriz[3][4];

    printf("Exercicio 1\n");
  
   //armazenamento de dados no vetor
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
  
  //armazenamento de dados na matriz
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
