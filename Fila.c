#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

void FFVazia (TFila* pFila) {
    pFila->pFrente = (TCelula*)malloc(sizeof(TCelula));
    pFila->pTras = pFila->pFrente;
    pFila->pFrente->pProx = NULL;
    pFila->qtd = 0;
}

int FVazia (TFila* pFila) {
    return (pFila->pFrente == pFila->pTras);
}

int Enfileira (TFila *pFila, TItem* pItem) {
    TCelula* pNovo;
    pNovo = (TCelula*) malloc(sizeof(TCelula));
    if(pNovo == NULL) return 0;
    pFila->pTras->pProx = pNovo;
    pFila->pTras = pNovo;
    pNovo->item = *pItem;
    pNovo->pProx = NULL;
    pFila->qtd++;
    return 1;
}

int Desenfileira (TFila* pFila, TItem* pItem) {
    if(FVazia(pFila)){
        printf("Fila vazia.\n\n");
        return 0;
    }
    TCelula* pAux;
    pAux = pFila->pFrente; //auxiliar criado para manter a referencia da celula que retornará o item retirado e sera liberada na memoria.
    pFila->pFrente = pFila->pFrente->pProx; //altera a primeira posicao da fila 
    *pItem = pFila->pFrente->item; //grava o item que foi retirado como backup
    free(pAux);
    pFila->qtd--;
    return 1;
}

void ImprimeFila(TFila *pFila){
    if(FVazia(pFila)) return;
    TCelula *pAux;
    pAux = pFila->pFrente->pProx;
    while(pAux != NULL){  //auxiliar percorre a fila até o último elemento
        printf("%d ", pAux->item.ID);  //imprime cada elemento
        pAux = pAux->pProx; //passa para o proximo elemento
    }
}

int ImprimeQTD(TFila* pFila){
    return (pFila->qtd); //imprime a quantidade no momento
}

