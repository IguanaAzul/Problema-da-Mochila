/************************************************
LAED1 - Trabalho Pratico 1
Aluno: Ramon Griffo Costa
Matricula: 201622040112
Descricao do programa: Algoritmo tentativa e erro para resolver o problema da mochila usando backtracking implementado com recursividade
Data: 14/09/2017
************************************************/
#include<stdio.h>
#include<time.h>



int backtracking(int n[], int valor[], int peso[], int melhor[], int itens[], int pesoTotal, int valorTotal, int maiorV, int qItensC, int qTotal, int qIdeal, int tMochila){
	*pesoTotal+=peso[i];
	if(*pesoTotal>tMochila){
		
	}
	
}
int main(){
	clock_t tempo[2];
	tempo[0] = clock();
	FILE *arqin;
	arqin = fopen("In.txt", "rt");
	if (arqin == NULL){
		printf("Problemas na CRIACAO do arquivo\n");
		return -1;
	}
	int tMochila, qProdutos;
	fscanf(arqin, "%d", &tMochila);
	fscanf(arqin, "%d", &qProdutos);
	int peso[qProdutos], valor[qProdutos], nItem[qProdutos];
	int i;

	for(i=0; i<qProdutos; i++){
		fscanf(arqin, "%d", &peso[i]);
		fscanf(arqin, "%d", &valor[i]);
		nItem[i] = i+1;
	}

	int pesoTotal = 0, valorTotal = 0, maiorValor = 0, melhorCombinacao[qProdutos], itensColocados[qProdutos], qItensColocados, qIdeal;
	
	backtracking(int nItem, int valor, int peso, int melhorCombinacao, int itensColocados, int &pesoTotal, int &valorTotal, int &maiorValor, int &qItensColocados, int &qProdutos, int &qIdeal, int &tMochila);

	tempo[1] = clock();
	double Tempo = (tempo[1] - tempo[0]) * 1000.0 / CLOCKS_PER_SEC;
	printf("Tempo gasto: %g ms.", Tempo);
	return 0;
}


