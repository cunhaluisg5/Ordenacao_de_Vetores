#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int *alocar(int n);
void inserir(int *v, int n);
int *liberar(int *v);
void imprimir(int *v, int n);
void peneira(int *v, int raiz, int fundo);
void heapsort(int *v, int n);
void selecao(int *v, int n);
void insercao(int *v, int n);
void shellsort(int *v, int n);
void quicksort(int *v, int n);
void merge(int *v, int inicio, int meio, int fim);
void mergeSort(int *v, int inicio, int fim);
void metodo(FILE *arquivo);
void asteriscos();
FILE* abreArquivo(char modo, char caminho[30]);
void fecharArquivo(FILE *arquivo);
void imprimeVetorArquivo(int *v, int n, FILE *arquivo);
void asteriscosArquivo(FILE *arquivo);

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

void selecao(int *v, int n){
	int i, j, min, x;
	for(i = 0; i < n-1; ++i) {
		min = i;
		for(j = i+1; j < n; ++j){
			comparacoes++;
			if(v[j] < v[min]){
				min = j;
			}
		}
		movimentacoes++;
		x = v[i]; 
		v[i] = v[min]; 
		v[min] = x;
	}
}

void insercao(int *v, int n){
	int i, j, x;
	for(j = 1; j < n; ++j) {
		x = v[j];
		comparacoes++;
		for(i = j-1; i >= 0 && v[i] > x; --i){
			comparacoes++;
			movimentacoes++;
			v[i + 1] = v[i];
		}
		movimentacoes++;
		v[i + 1] = x;
	}
}

void shellsort(int *v, int n){
	int i, j, k, span, y, incr[3] = {5, 3, 1};
	for(i = 0; i < sizeof(incr); i++){
		span = incr[i];
		for(j = span; j < n; j++){
			y = v[j];
			comparacoes++;
			for(k = j - span; k >= 0 && y < v[k]; k -= span){
				comparacoes++;
				movimentacoes++;
				v[k + span] = v[k];
			}
			movimentacoes++;
			v[k + span] = y;
		}
	}
}

void quicksort(int *v, int n){
	comparacoes++;
	if(n <= 1){
		return;
	}
	int x = v[0];
	int a = 1;
	int b = n - 1;
	int temp;
	do{
		while(a < n && v[a] <= x){
			a++;
		}
		while(v[b] > x){
			b--;
		}
		comparacoes++;
		if(a < b){
			movimentacoes++;
			temp = v[a];
			v[a] = v[b];
			v[b] = temp;
			a++;
			b--;
		}
	}while(a <= b);
	movimentacoes++;
	v[0] = v[b];
	v[b] = x;
	quicksort(v, b);
	quicksort(&v[a], n - a);
}

void merge(int *v, int inicio, int meio, int fim)
{
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 =  fim - meio;
    int L[n1], R[n2];    
    for(i = 0; i < n1; i++)
        L[i] = v[inicio + i];
    for(j = 0; j < n2; j++)
        R[j] = v[meio + 1 + j]; 
    i = 0; 
    j = 0;
    k = inicio; 
    while(i < n1 && j < n2)
    {
    	comparacoes++;
        if(L[i] <= R[j])
        {
        	movimentacoes++;
            v[k] = L[i];
            i++;
        }
        else
        {
        	movimentacoes++;
            v[k] = R[j];
            j++;
        }
        k++;
    } 
    while(i < n1)
    {
    	movimentacoes++;
        v[k] = L[i];
        i++;
        k++;
    } 
    while(j < n2)
    {
    	movimentacoes++;
        v[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *v, int inicio, int fim) {
	comparacoes++;
	if(inicio < fim) {
		int meio = (inicio + fim) / 2;
		mergeSort(v, inicio, meio);
		mergeSort(v, meio + 1, fim);
		merge(v, inicio, meio, fim);
	}
}

void metodo(FILE *arquivo){
	int j, *c, q, *v;
	char opcao = 's';
	
	while(opcao == 's' || opcao == 'S'){
		printf("Informe o tamanho do vetor:\n");
		scanf("%d", &q);
		v = alocar(q);
		printf("\n\tOs dados a seguir serao gravados no arquivo \"dados.txt\"\t\t\n\n");
		sleep(3);
		printf("Vetor de %d posicoes:\n\n", q);  
		fprintf(arquivo, "Vetor de %d posicoes:\n\n", q); 
		inserir(v, q);
		imprimir(v,  q);
		imprimeVetorArquivo(v, q, arquivo);
		c = v;
		printf("\n\n");
		fprintf(arquivo, "\n\n"); 
		asteriscos();
		asteriscosArquivo(arquivo);
			
		for(j=0; j<6; j++)
		{
			comparacoes = 0;
			movimentacoes = 0;
			v = c;
			switch(j){
				case 0: {
					printf("\n\nVetor de %d posicoes ordenado por Selecao:\n\n", q);
					fprintf(arquivo, "\n\nVetor de %d posicoes ordenado por Selecao:\n\n", q);		
					selecao(v, q);
					break;
				}
				case 1: {
					printf("\n\nVetor de %d posicoes ordenado por Insercao:\n\n", q);
					fprintf(arquivo, "\n\nVetor de %d posicoes ordenado por Insercao:\n\n", q);
					insercao(v, q);
					break;
				}
				case 2: {
					printf("\n\nVetor de %d posicoes ordenado por ShellSort:\n\n", q);
					fprintf(arquivo, "\n\nVetor de %d posicoes ordenado por ShellSort:\n\n", q);
					shellsort(v, q);
					break;
				}
				case 3: {
					printf("\n\nVetor de %d posicoes ordenado por QuickSort:\n\n", q);
					fprintf(arquivo, "\n\nVetor de %d posicoes ordenado por QuickSort:\n\n", q);
					quicksort(v, q);
					break;
				}
				case 4: {
					printf("\n\nVetor de %d posicoes ordenado por MergeSort:\n\n", q);
					fprintf(arquivo, "\n\nVetor de %d posicoes ordenado por MergeSort:\n\n", q);
					mergeSort(v, 0, q-1);
					break;
				}
				case 5: {
					printf("\n\nVetor de %d posicoes ordenado por HeapSort:\n\n", q);
					fprintf(arquivo, "\n\nVetor de %d posicoes ordenado por HeapSort:\n\n", q);
					heapsort(v, q);
					break;
				}
			}
			imprimir(v, q);
			imprimeVetorArquivo(v, q, arquivo);
			printf("\n\nPossui %d comparacoes e %d movimentacoes\n", comparacoes, movimentacoes);
			fprintf(arquivo, "\nPossui %d comparacoes e %d movimentacoes\n", comparacoes, movimentacoes);
			printf("\n");
			fprintf(arquivo, "\n");
			asteriscos();
			asteriscosArquivo(arquivo);
		}
		printf("\n");
		fprintf(arquivo, "\n");
		opcao = 'a';
		while(opcao != 's' && opcao != 'S' && opcao != 'n' && opcao != 'N'){
			printf("\n\nDeseja ordenar mais algum vetor (S)im ou (N)ao ?))");
			fflush(stdin);
			scanf("%c", &opcao);
		}
		system("cls");
		liberar(v);
	}
}

void asteriscos(){
	int i;
	for(i=0; i<76; i++){
		printf("*");
	}
}

FILE* abreArquivo(char modo, char caminho[30]){
    FILE *arquivo;
    switch(modo){
        case 'g':
            arquivo = fopen(caminho,"wt"); 
            break;
        case 'l':
            arquivo = fopen(caminho,"rt"); 
            break;
        case 'a':
            arquivo = fopen(caminho,"a"); 
            break;
    }
    if(arquivo==NULL){ 
        printf("Não foi possível abrir o arquivo");
        exit(0);
    }
    return arquivo;
}

void fecharArquivo(FILE *arquivo){
    fclose(arquivo);
}

void imprimeVetorArquivo(int *v, int n, FILE *arquivo){
	int i;
	for(i=0; i<n; i++){
		if(i % 5 == 0){
			fprintf(arquivo, "\n");
		}
		fprintf(arquivo, "V[%2d] = %2d\t", i + 1, v[i]);
	}
	fprintf(arquivo, "\n", i + 1, v[i]);
}

void asteriscosArquivo(FILE *arquivo){
	int i;
	for(i=0; i<76; i++){
		fprintf(arquivo, "*");
	}
}
