/************************************************
LAED1 - Trabalho Pratico 1
Aluno: Ramon Griffo Costa
Matricula: 201622040112
Descricao do programa: Algoritmo tentativa e erro para resolver o problema da mochila usando backtracking implementado com recursividade
Data: 14/09/2017
************************************************/
#include<stdio.h>
#include<time.h>

typedef struct item{
int n;
int peso;
int valor;
}Item;

void soma1bin(int v[], int tam){
	int i, c=1;
	for (i=0;i<tam;i++){
		if(c==1){
			if(v[i]==0){
				v[i]+=c;
				c=0;
			}else if(v[i]==1){
				v[i]=0;
			}
		}
	}
}
int testaFinal(int v[], int tam){
	int i;
	for(i=0; i<tam; i++){
		if(v[i]==0){
			return 0;
		}
	}
	return 1;
}
void insereVetor(int v[], int u[], int tam){
	int i;
	for(i=0; i<tam; i++){
		u[i] = v[i];
	}
}

int tentativaerro(Item itens[], int v[], int mc[], int tMochila, int qProdutos, int mV){
	int i, pesoAtual, valorAtual;
	for(i=0; i<qProdutos; i++){
		v[i]=0;
	}
	while(testaFinal(v, qProdutos)==0){
		pesoAtual=0; valorAtual=0;
		for(i=0; i<qProdutos; i++){
			if(v[i] == 1){
				pesoAtual+=itens[i].peso;
				valorAtual+=itens[i].valor;
				if(pesoAtual>tMochila) break;
				if(mV<valorAtual){
					mV=valorAtual;
					insereVetor(v, mc, qProdutos);
				}
			}
		}
		soma1bin(v, qProdutos);
	}
	return mV;
}
int main(){
	clock_t tempo[2];
	tempo[0] = clock();
	FILE *arqin;
	arqin = fopen("In2.txt", "rt");
	if (arqin == NULL){
		printf("Problemas na CRIACAO do arquivo\n");
		return -1;
	}
	int tMochila, qProdutos;
	fscanf(arqin, "%d", &tMochila);
	fscanf(arqin, "%d", &qProdutos);
	Item itens[qProdutos];
	int i;

	for(i=0; i<qProdutos; i++){
		fscanf(arqin, "%d", &(itens[i].peso));
		fscanf(arqin, "%d", &(itens[i].valor));
		itens[i].n = i+1;
	}

	int maiorValor = 0, melhorCombinacao[qProdutos], vetorCombinacao[qProdutos];
	
	maiorValor = tentativaerro(itens, vetorCombinacao, melhorCombinacao, tMochila, qProdutos, maiorValor);
	printf("%d", maiorValor);
	tempo[1] = clock();
	double Tempo = (tempo[1] - tempo[0]) * 1000.0 / CLOCKS_PER_SEC;
	printf("Tempo gasto: %g ms.", Tempo);
	return 0;
}

