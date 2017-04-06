#include <stdio.h>
#include <stdlib.h>
int main()
{

  int tamanho,indice,resultado = 0;
  float media;

  printf("TAMANHO DO VETOR: ");
  scanf("%d",&tamanho);

  int *vetor = (int*)malloc(tamanho*sizeof(int));

   for (indice=0;indice<tamanho;indice++){
      printf("Digite um valor:");
      scanf("%d",&vetor[indice]);

      resultado=resultado+vetor[indice];
   }
      media=(float)(resultado/tamanho);

      printf("%.2f",media);

      free(vetor);
   return 0;
}
