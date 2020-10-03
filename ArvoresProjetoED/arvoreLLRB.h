
typedef struct NO *ArvLLRB;

typedef struct informacao funcionario;

ArvLLRB *cria_ArvLLRB();

void liberar_ArvLLRB(ArvLLRB *raiz);

int vazia_ArvLLRB(ArvLLRB *raiz);

int altura_ArvLLRB(ArvLLRB *raiz);

int totalNO_ArvLLRB(ArvLLRB *raiz);

int consulta_arvLLRB(ArvLLRB *raiz, int valor);

void preOrdem_ArvLLRB(ArvLLRB *raiz);

void emOrdem_ArvLLRB(ArvLLRB *raiz);

void posOrdem_ArvLLRB(ArvLLRB *raiz);

int insere_ArvLLRB(ArvLLRB *raiz, struct informacao inf);

int remove_ArvLLRB(ArvLLRB *raiz, int valor);

void coleta_dadosLLRB(ArvLLRB *raiz, int ordenado);

