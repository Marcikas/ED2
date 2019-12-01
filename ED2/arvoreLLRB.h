typedef struct NO *arvoreLLRB;

arvoreLLRB *cria_arvoreLLRB();

void preOrdem_arvLLRB(arvoreLLRB *raiz);

void emOrdem_arvLLRB(arvoreLLRB *raiz);

void posOrdem_arvLLRB(arvoreLLRB *raiz);

int consulta_arvoreLLRB(arvoreLLRB *raiz, int valor);

int insere_arvoreLLRB(arvoreLLRB *raiz, int valor);

int remove_arvoreLLRB(arvoreLLRB *raiz, int valor);
