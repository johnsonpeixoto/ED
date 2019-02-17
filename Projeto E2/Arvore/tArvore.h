typedef struct tItem {
  int chave;
} tipoItem;

typedef struct no *pNo; // define o tipo "apontador" como sendo o
						// endereço de um "no" ou "vertice"
struct no {
  tipoItem item;
  pNo esq;
  pNo dir;
};
