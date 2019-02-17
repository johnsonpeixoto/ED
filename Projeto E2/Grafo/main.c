/*
 * mian.c
 * 
 * Copyright 2018 Johnson <johnson@inspiron-5468>
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "opGrafo.h"
#include "buscaDFS.h"

int listaA[20][3] = {
	{1,2,3}, {1,3,7},
	{2,1,3}, {2,5,2},
	{3,1,7},
	{3,4,5}, {3,5,6},
	{4,3,5}, {4,6,8},
	{5,2,2}, {5,3,6}, {5,6,15}, {5,7,9},
	{6,4,8}, {6,5,15}, {6,8,10},
	{7,5,9}, {7,8,7},
	{8,9,7},
	{9,8,7}
};


int main(){
	int i, origem, nVertices;
	nVertices = 9;
	
	tipoGrafo graph;
	fazGrafoVazio(&graph, nVertices);
	
	for(i=1; i<=nVertices; i++){
		insereVertice(i, &graph);
	} // cria os vertices 1 a 9

	for(i=0; i<20; i++){
		pTipoVertice v = localizaVertice(listaA[i][0], &graph);
		insereAresta(v, listaA[i][1], listaA[i][2]);
	} // carrega a lista de adjacencias

	if(grafoVazio(&graph) == 0){
		printf("Escolha a origem: "); scanf("%d", &origem);
		pTipoVertice vv = localizaVertice(origem, &graph);
		printf("%d com grau %d\n", vv->vertice, vv->grau);
		buscaEmProfundidade(vv, &graph);
	}
	else
		printf("Grafo vazio.\n");
		
	return 0;
}

