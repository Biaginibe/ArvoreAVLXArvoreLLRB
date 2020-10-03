typedef struct NO *ArvAVL;

typedef struct informacao funcionario;

ArvAVL *cria_ArvAVL();

void liberar_ArvAVL(ArvAVL *raiz);

int vazia_ArvAVL(ArvAVL *raiz);

int altura_ArvAVL(ArvAVL *raiz);

int totalNO_ArvAVL(ArvAVL *raiz);

void preOrdem_ArvAVL(ArvAVL *raiz);

void emOrdem_ArvAVL(ArvAVL *raiz);

void posOrdem_ArvAVL(ArvAVL *raiz);

int insere_ArvAVL(ArvAVL *raiz, funcionario inf);

int remove_ArvAVL(ArvAVL *raiz, int valor);

void coleta_dadosAVL(ArvAVL *raiz);

