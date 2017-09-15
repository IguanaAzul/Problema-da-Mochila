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
	int i, pesoAtual=0, valorAtual=0;
	for(i=0; i<qProdutos; i++){
		v[i]=0;
	}
	while(testaFinal(v, qProdutos)==0){
		for(i=0, pesoAtual=0, valorAtual=0; i<qProdutos; i++){
			if(v[i] == 1){
				pesoAtual+=itens[i].peso;
				valorAtual+=itens[i].valor;
				if(pesoAtual>tMochila) break;
				else if(mV<valorAtual){
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
	clock_t tempos[4];		 									//variáveis usadas para armazenar e medir o tempo gasto
	tempos[0] = clock();										//armazenando tempo inicial
	FILE *arqin, *arqout;//, *arqaux; 							//arquivos a serem manipulados
	int arq;
	printf("Digite o número da entrada a ser aberta (1 a 10): \n");
	scanf("%d", &arq);
	switch(arq){
		case 1:
			arqin = fopen("In1.txt", "rt");						//abre o arquivo de entrada 1 (mochila com capacidade 100 e 15 produtos disponíveis)
			break;
		case 2:
			arqin = fopen("In2.txt", "rt");						//abre o arquivo de entrada 2 (mochila com capacidade 300 e 40 produtos disponíveis)
			break;
		case 3:
			arqin = fopen("In3.txt", "rt");						//abre o arquivo de entrada 3 (mochila com capacidade 200 e 500 produtos disponíveis)
			break;
		case 4:
			arqin = fopen("In4.txt", "rt");						//abre o arquivo de entrada 4 (mochila com capacidade 200 e 500 produtos disponíveis)
			break;
		case 5:
			arqin = fopen("In5.txt", "rt");						//abre o arquivo de entrada 5 (mochila com capacidade 300 e 500 produtos disponíveis)
			break;
		case 6:
			arqin = fopen("In6.txt", "rt");						//abre o arquivo de entrada 6 (mochila com capacidade 100 e 1500 produtos disponíveis)
			break;
		case 7:
			arqin = fopen("In7.txt", "rt");						//abre o arquivo de entrada 7 (mochila com capacidade 400 e 600 produtos disponíveis)
			break;
		case 8:
			arqin = fopen("In8.txt", "rt");						//abre o arquivo de entrada 8 (mochila com capacidade 100 e 5000 produtos disponíveis)
			break;
		case 9:
			arqin = fopen("In9.txt", "rt");						//abre o arquivo de entrada 8 (mochila com capacidade 50 e 20 produtos disponíveis)
			break;
		case 10:
			arqin = fopen("In10.txt", "rt");					//abre o arquivo de entrada 8 (mochila com capacidade 50 e 20 produtos disponíveis)
			break;
		default: printf("Erro na criação do arquivo\n"); break;
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
	tempos[1] = clock();
	int maiorValor = 0, melhorCombinacao[qProdutos], vetorCombinacao[qProdutos];
	
	maiorValor = tentativaerro(itens, vetorCombinacao, melhorCombinacao, tMochila, qProdutos, maiorValor);
	tempos[2] = clock();
	arqout = fopen("Out.txt", "w");	
	fprintf(arqout, "Capacidade da mochila: %d\nQuantidade de produtos disponíveis: %d\n\nItens colocados na mochila:\n\n", tMochila, qProdutos);
	int pesoTotal=0, valorTotal=0;
	for(i=0;i<qProdutos; i++){
			if(melhorCombinacao[i]==1){
				fprintf(arqout, "Peso item %d:    %d\nPreço item %d:    %d\n\n", itens[i].n, itens[i].peso, itens[i].n, itens[i].valor);
				pesoTotal+=itens[i].peso;
				valorTotal+=itens[i].valor;
			}
	}
	fprintf(arqout, "Peso total colocado na mochila: %d\nValor total arrecadado: %d\n", pesoTotal, valorTotal);
	fclose(arqout);
	tempos[3] = clock();
	double Tempo12 = (tempos[1] - tempos[0]) * 1000.0 / CLOCKS_PER_SEC;
	double Tempo23 = (tempos[2] - tempos[1]) * 1000.0 / CLOCKS_PER_SEC;
	double Tempo34 = (tempos[3] - tempos[2]) * 1000.0 / CLOCKS_PER_SEC;
	double Tempo14 = (tempos[3] - tempos[0]) * 1000.0 / CLOCKS_PER_SEC;
	double Tempo13 = (tempos[2] - tempos[0]) * 1000.0 / CLOCKS_PER_SEC;
	printf("Tempo de leitura de arquivos e calculo do custo benefício: %g ms.\nTempo de ordenação dos produtos: %g ms.\nTempo de escrita de arquivos: %g ms.\nTempo total: %g ms.\nTempo total sem escrita de arquivos: %g ms.\n", Tempo12, Tempo23, Tempo34, Tempo14, Tempo13);
	return 0;
}

