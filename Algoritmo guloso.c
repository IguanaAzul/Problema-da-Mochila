#include<stdio.h>
#include<time.h>

void selection(float cb[], int p[], int v[], int n[], int q) {
    int i, j, min, aux; float faux;
    for (i = 0; i < (q-1); i++){
        min = i;
        for (j = (i+1); j < q; j++) {
            if(cb[j] < cb[min])
            min = j;
        }
        if (cb[i] != cb[min]) {
            faux = cb[i];
            cb[i] = cb[min];
            cb[min] = faux;
            aux = v[i];
            v[i] = v[min];
            v[min] = aux;
            aux = p[i];
            p[i] = p[min];
            p[min] = aux;
            aux = n[i];
            n[i] = n[min];
            n[min] = aux;
        }
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
    float cb[qProdutos];
    int i;
    for(i=0; i<qProdutos; i++){
        fscanf(arqin, "%d", &peso[i]);
        fscanf(arqin, "%d", &valor[i]);
        nItem[i] = i+1;
    }
    fclose(arqin);
    for(i=0; i<qProdutos; i++){
        cb[i] = (float)valor[i]/(float)peso[i];
    }

    /*for(i=0; i<qProdutos; i++){
        printf("Peso item %d:    %d\nPreço item %d:    %d\nCusto/Beneficio item %d:    %.2f\n", nItem[i], peso[i], nItem[i], valor[i], nItem[i], cb[i]);
    }
    printf("\n");*/

    selection(cb, peso, valor, nItem, qProdutos);
    FILE *arqout;
    arqout = fopen("Out.txt", "w");

    /*for(i=0; i<qProdutos; i++){
        fprintf(arqout, "Peso item %d:    %d\nPreço item %d:    %d\nCusto/Beneficio item %d:    %.2f\n", nItem[i], peso[i], nItem[i], valor[i], nItem[i], cb[i]);
    }*/

    int pesoTotal, valorTotal;
    for(i=qProdutos-1, pesoTotal=0;i>=0; i--){
     	pesoTotal+=peso[i];
		valorTotal+=valor[i];
		if(pesoTotal<tMochila){
			fprintf(arqout, "Peso item %d:    %d\nPreço item %d:    %d\nCusto/Beneficio item %d:    %.2f\n\n", nItem[i], peso[i], nItem[i], valor[i], nItem[i], cb[i]);
		}
		else{
			pesoTotal-=peso[i];
			valorTotal-=valor[i];
			break;
		}
    }
    fprintf(arqout, "Peso total colocado na mochila: %d\nValor total arrecadado: %d\n", pesoTotal, valorTotal);
    fclose(arqout);
    tempo[1] = clock();
    double Tempo = (tempo[1] - tempo[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo gasto: %g ms.\n", Tempo);
    return 0;
}
