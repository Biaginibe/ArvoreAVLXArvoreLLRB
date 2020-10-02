struct informacao{
    int codigo;
    char nome[100];
    int idade;
    char empresa[30];
    char depto[30];
    float salario;
};

typedef struct NO *ArvAVL;

typedef struct informacao Func;

ArvAVL *cria_ArvAVL();

void coleta_dados(ArvAVL *raiz);

void liberar_ArvAVL(ArvAVL *raiz);

int vazia_ArvAVL(ArvAVL *raiz);

int altura_ArvAVL(ArvAVL *raiz);

int totalNO_ArvAVL(ArvAVL *raiz);

void preOrdem_ArvAVL(ArvAVL *raiz);

void emOrdem_ArvAVL(ArvAVL *raiz);

void posOrdem_ArvAVL(ArvAVL *raiz);

int insere_ArvAVL(ArvAVL *raiz, Func func);

int remove_ArvAVL(ArvAVL *raiz, int valor);
