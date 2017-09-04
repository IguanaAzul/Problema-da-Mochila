#include<stdio.h>
#include<time.h>



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
    for(i=0; i<qProdutos; i++){
        printf("Peso item %d:    %d\nPreço item %d:    %d\n", nItem[i], peso[i], nItem[i], valor[i]);
    }
    tempo[1] = clock();
    double Tempo = (tempo[1] - tempo[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo gasto: %g ms.", Tempo);
    return 0;
}


