#define MAXTAM 5

typedef struct TItemEst {
    int ID; //cada processo é representado por um registro composto por um número identificador do processo
} TItem;

typedef struct TCelulaEst {
    TItem item;
    struct TCelulaEst* pProx;
} TCelula;

typedef struct TfilaEst {
    TCelula* pFrente;
    TCelula* pTras;
    int qtd;
} TFila;

void FFVazia (TFila* pFila);

int FVazia (TFila* pFila);

int Enfileira (TFila *pFila, TItem* pItem);

int Desenfileira (TFila* pFila, TItem* pItem);

void ImprimeFila(TFila *pFila);

int ImprimeQTD(TFila* pFila);
