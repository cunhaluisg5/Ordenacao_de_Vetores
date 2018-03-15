#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int *alocar(int n);
void inserir(int *v, int n);
int *liberar(int *v);
void imprimir(int *v, int n);
void peneira(int *v, int raiz, int fundo);
void heapsort(int *v, int n);

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

void heapsort(int *v, int n) {
	int i, tmp;
	for(i = (n / 2); i >= 0; i--) {
		peneira(v, i, n - 1);
	}
	for(i = n-1; i >= 1; i--) {
		movimentacoes++;
		tmp = v[0];
		v[0] = v[i];
		v[i] = tmp;
		peneira(v, 0, i - 1);
	}
}

void peneira(int *v, int raiz, int fundo) {
	int pronto, filhoMax, tmp;
	pronto = 0;
	while((raiz * 2 <= fundo) && (!pronto)) {
		comparacoes++;
		if(raiz * 2 == fundo) {
			filhoMax = raiz * 2;
		}
		else 
		comparacoes++;
		if(v[raiz * 2] > v[raiz * 2 + 1]) {
			filhoMax = raiz * 2;
		}
		else{
			filhoMax = raiz * 2 + 1;
		}

	comparacoes++;
	if(v[raiz] < v[filhoMax]) {
		movimentacoes++;
		tmp = v[raiz];
		v[raiz] = v[filhoMax];
		v[filhoMax] = tmp;
		raiz = filhoMax;
    }
	else {
      pronto = 1;
	}
  }
}
