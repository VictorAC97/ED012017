#include <stdio.h>
//cabecalhos
void layout(void);

int main(){

layout();

return 0;
}

void layout(void){

	printf("--------------------------------------------------------------------------------\n");
    printf("\t\t\t     B A T A L H A - N A V A L\n");
	printf("--------------------------------------------------------------------------------\n");

int i,j = 0;

char M[10][10];
	for(i=0;i<10;i++){
        printf("\t\t\t\t");
            for(j=0;j<10;j++){
                printf("@ ",M[i][j]);
            }
		puts(""); //quebra de linha na matriz
	}
	printf("--------------------------------------------------------------------------------\n");
}
