#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int *alocar(int n);
void inserir(int *v, int n);
int *liberar(int *v);
void imprimir(int *v, int n);

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

void inserir(int *v, int n){
	int i;
	for(i=0; i<n; i++){
		v[i] = rand() % 100;
	}
}

int *liberar(int *v)
{
	if(v == NULL) return(NULL);
	free(v); 
	return(NULL); 
}

void imprimir(int *v, int n){
	int i;
	for(i=0; i<n; i++){
		printf("V[%2d] = %2d\t", i + 1, v[i]);
	}
}
