#include <stdio.h>
#include <time.h>
int maiorValor(int tMochila, int qProdutos, int peso[], int valor[])
{
	int V[qProdutos + 1][tMochila + 1];

	for(int w = 0; w <= tMochila; w++)
		V[0][tMochila] = 0;
	for(int i = 1; i <= qProdutos; i++)
		V[i][0] = 0;

	for(int i = 1; i <= qProdutos; i++){
		for(int w = 1; w <= tMochila; w++){	
			if(peso[i - 1] <= w){
				if((valor[i - 1] + V[i - 1][w - peso[i - 1]]) > V[i - 1][w])
					V[i][w] = valor[i - 1] + V[i - 1][w - peso[i - 1]];
				else
					V[i][w] = V[i - 1][w];
			}
			else
				V[i][w] = V[i - 1][w];
		}
	}
	return V[qProdutos][tMochila];
}

int main(){
	clock_t tempo[2];
	tempo[0] = clock();
	FILE *arqin;
	arqin = fopen("In8.txt", "rt");
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

	int maiorValor = maiorValor(tMochila, qProdutos, peso, valor);

	printf("%d\n", maiorValor);

	tempo[1] = clock();
	double Tempo = (tempo[1] - tempo[0]) * 1000.0 / CLOCKS_PER_SEC;
	printf("Tempo gasto: %g ms.", Tempo);

	return 0;
}
