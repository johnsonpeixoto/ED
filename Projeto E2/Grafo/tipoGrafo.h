typedef struct tipoVertice *pTipoVertice;
typedef struct tipoAresta *pTipoAresta;

struct tipoVertice {
	int vertice;
	int grau;
	int visitado;
	pTipoVertice proximoVertice;
	pTipoAresta primeiraAresta;
	pTipoAresta ultimaAresta;
};

struct tipoAresta {
	int vertice;
	int distancia;
	pTipoAresta proximaAresta;
};

typedef struct tGrafo {
	int vertices;
	pTipoVertice primeiroVertice;
	pTipoVertice ultimoVertice;
} tipoGrafo;
