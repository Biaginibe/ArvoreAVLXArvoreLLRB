typedef struct NO *ArvAVL;

typedef struct informacao func;

ArvAVL *cria_ArvAVL();

void coleta_dados(ArvAVL *raiz);

void liberar_ArvAVL(ArvAVL *raiz);

int vazia_ArvAVL(ArvAVL *raiz);

int altura_ArvAVL(ArvAVL *raiz);

int totalNO_ArvAVL(ArvAVL *raiz);

void preOrdem_ArvAVL(ArvAVL *raiz);

void emOrdem_ArvAVL(ArvAVL *raiz);

void posOrdem_ArvAVL(ArvAVL *raiz);

int insere_ArvAVL(ArvAVL *raiz, int valor);

int remove_ArvAVL(ArvAVL *raiz, int valor);
