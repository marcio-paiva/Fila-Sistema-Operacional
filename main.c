#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

int main(){
    TFila x;
    int opcao;
    TItem a, k; //variaveis temporarias para enfileirar e desenfileirar.

    FFVazia(&x);

    do{
        printf("Escolha a opcao desejada: \n\n\t1 - Incluir novos processos na fila de processos. \n\t2 - Retirar da fila o processo com o maior tempo de espera \n\t3 - Imprimir o conteudo da lista de processo. \n\t4 - Imprimir o numero de processos da fila. \n\t0 - Sair.\n");
        scanf("%d", &opcao);
        switch (opcao){
            case 1:
                printf("\nInforme o ID do processo: ");
                scanf("%d", &a.ID);
                Enfileira (&x, &a);
                printf("\n");
                break;
            case 2:
                if(Desenfileira(&x, &k)){ //se a fila nao estiver vazia, retornará 1, e o valor retirado será impresso
                    printf("\nProcesso retirado. ID: %d\n", k);
                }
                break;
            case 3:
                printf("\nLista de processos:\n");
                ImprimeFila(&x);
                printf("\n\n");
                break;
            case 4:
                printf("\nQuantidade de processos na fila: %d\n\n", ImprimeQTD(&x));
                break;
            default:
                break;
        }
    }while(opcao != 0);

    system("pause");
    return 0;
}
