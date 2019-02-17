#include "tipoGrafo.h"

void fazGrafoVazio(tipoGrafo *grafo, int nVertices) {
	grafo->vertices = nVertices; 
	grafo->primeiroVertice = (pTipoVertice) malloc(sizeof(struct tipoVertice));
	grafo->primeiroVertice->vertice = -1;
	grafo->primeiroVertice->grau = -1;
	grafo->primeiroVertice->proximoVertice = NULL;
	grafo->primeiroVertice->primeiraAresta = NULL;
	grafo->primeiroVertice->ultimaAresta = NULL;
	grafo->ultimoVertice = grafo->primeiroVertice;
}

// verifica se o Grafo está vazio (sem nenhum vértice)
int grafoVazio(tipoGrafo *grafo) {
	return (grafo->primeiroVertice == grafo->ultimoVertice);
}

// retorna o endereço do "vertice" (NULL se o vértice não for localizado)
pTipoVertice localizaVertice(int vertice, tipoGrafo *grafo) {
	pTipoVertice p = grafo->primeiroVertice->proximoVertice;
	while ((p != NULL) && (p->vertice != vertice)) {
		p = p->proximoVertice;
	}
	return(p);
}

void fazListaAdjacenciasVazia(pTipoVertice vertice) {
	vertice->primeiraAresta = (pTipoAresta) malloc(sizeof(struct tipoAresta));
	vertice->primeiraAresta->vertice = -1;
	vertice->primeiraAresta->distancia = -1;
	vertice->primeiraAresta->proximaAresta = NULL;
	vertice->ultimaAresta = vertice->primeiraAresta;
}

// verifica se a lista de adjacências do vértice está vazia
int listaAdjacenciasVazia(pTipoVertice vertice) {
	return (vertice->primeiraAresta == vertice->ultimaAresta);
}

// retorna o endereço da "aresta" na lista de adjacências do vértice (NULL se a aresta
// não for localizada)
pTipoAresta localizaAresta(pTipoVertice vertice, int aresta) {
	pTipoAresta p = vertice->primeiraAresta->proximaAresta;
	while ((p != NULL) && (p->vertice != aresta)) {
		p = p->proximaAresta;
	}
	return(p);
}

void insereVertice(int vertice, tipoGrafo *grafo) {
	grafo->ultimoVertice->proximoVertice = (pTipoVertice) malloc(sizeof(struct tipoVertice));
	grafo->ultimoVertice = grafo->ultimoVertice->proximoVertice;
	grafo->ultimoVertice->vertice = vertice;
	grafo->ultimoVertice->grau = 0;
	grafo->ultimoVertice->proximoVertice = NULL;
	fazListaAdjacenciasVazia(grafo->ultimoVertice);
}

void insereAresta(pTipoVertice verticeOrigem, int verticeDestino, int distancia) {
	verticeOrigem->ultimaAresta->proximaAresta = (pTipoAresta) malloc(sizeof(struct tipoAresta));
	verticeOrigem->ultimaAresta = verticeOrigem->ultimaAresta->proximaAresta;
	verticeOrigem->ultimaAresta->vertice = verticeDestino;
	verticeOrigem->ultimaAresta->distancia = distancia;
	verticeOrigem->ultimaAresta->proximaAresta = NULL;
	verticeOrigem->grau = verticeOrigem->grau + 1;
}

pTipoAresta localizaArestaAnterior(pTipoVertice vertice, int aresta) {
	pTipoAresta pAnt = vertice->primeiraAresta;
	pTipoAresta p = vertice->primeiraAresta->proximaAresta;
	while ((p != NULL) && (p->vertice != aresta)) {
		pAnt = p;
		p = p->proximaAresta;
	}
	return(pAnt);
}

void removeAresta(pTipoAresta p, pTipoVertice pVertice) {
	pTipoAresta q = p->proximaAresta;
	p->proximaAresta = q->proximaAresta;
	// se retirando a última aresta da lista de adjacencias
	if (p->proximaAresta == NULL)
		pVertice->ultimaAresta = p;
	pVertice->grau = pVertice->grau - 1;
	free(q); // libera a memória ocupada pela aresta
}

pTipoVertice localizaVerticeAnterior(int vertice, tipoGrafo *grafo) {
	pTipoVertice pAnt = grafo->primeiroVertice;
	pTipoVertice p = grafo->primeiroVertice->proximoVertice;
	while ((p != NULL) && (p->vertice != vertice)) {
		pAnt = p;
		p = p->proximoVertice;
	}
	return(pAnt);
}

// remove o "próximo" vértice de "p" da lista de vértices do Grafo:
void removeVertice(pTipoVertice p, tipoGrafo *grafo) {
	pTipoVertice verticeDestino, verticeOrigem = p->proximoVertice;
	// processo para remover "todas" as arestas do vértice
	pTipoAresta arestaDois, arestaUm = verticeOrigem->primeiraAresta;
	while (!listaAdjacenciasVazia(verticeOrigem)) {
		verticeDestino = localizaVertice(arestaUm->proximaAresta->vertice, grafo);
		arestaDois = localizaArestaAnterior(verticeDestino, verticeOrigem->vertice);
		removeAresta(arestaUm, verticeOrigem);
		removeAresta(arestaDois, verticeDestino);
	}
	free(verticeOrigem->primeiraAresta); // remove a célula cabeça da lista de adjacências
	p->proximoVertice = verticeOrigem->proximoVertice;
	// verifice se o vértice removido é o último da lista de vértices
	if (p->proximoVertice == NULL)
		grafo->ultimoVertice = p;
	free(verticeOrigem); // libera a memória ocupada pela aresta
}
