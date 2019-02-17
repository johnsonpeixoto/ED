// percorre a lista de vértice do grafo alterando o status do campo "visitado" do vértice
// para falso (valor inteiro 0)

void DFS(pTipoVertice p, tipoGrafo *grafo) {
	pTipoVertice aux;
	p->visitado = 1; // marca o vértice como "visitado"
	// percorre "todas" as arestas do vértice apontado por "p"
	pTipoAresta aresta = p->primeiraAresta->proximaAresta;
	while (aresta != NULL) {
	// se o vértice ainda não foi visitado aplicar a busca em profundidade no vértice da aresta
		//printf("while\n");
		aux = localizaVertice(aresta->vertice, grafo);
		if (aux->visitado == 0){
			printf("Visitando| v:%d \n", aux->vertice);
			DFS(aux, grafo); // aplica a DFS no vértice da aresta
		}
		else aresta = aresta->proximaAresta;
	}
}

void buscaEmProfundidade(pTipoVertice p, tipoGrafo *grafo) {
	printf("Busca em profundidade...\n");
	pTipoVertice v = grafo->primeiroVertice->proximoVertice;
	while (v != NULL) {
		v->visitado = 0;
		v = v->proximoVertice;
	}
	DFS(p, grafo);
}
