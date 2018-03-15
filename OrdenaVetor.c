#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int *alocar(int n);

int main()
{
	
}

int *alocar(int n)
{
	int *v;
	if(n < 1){
    	printf("** Erro: Parametro invalido **\n");
    	return(NULL);
 	}
  	v = (int *) malloc (n * sizeof(int));
	if(v == NULL){
    	printf("** Erro: Memoria Insuficiente **");
    	return(NULL);
	}     
	return(v);
}
