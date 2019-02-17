/*
 * 
 * buffer.h
 * 
 */
 
//#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
	char conteudo; // tamanho do char
	struct celula *prox;
} tCelula;

typedef struct fila {
	tCelula *inicio;
	tCelula *fim;
} tFila;


//	METODOS DE FILA

tFila* criarFila(void){
	tFila *fi = (tFila *) malloc(sizeof(tFila));
	fi->inicio = fi->fim = NULL;
	return fi;
}

void enFileira(tFila *fi, char carac){

	tCelula *p = (tCelula *) malloc(sizeof(tCelula));
	p->conteudo = carac;
	p->prox = NULL;

	if (fi->fim != NULL){ // quando fim aponta para algo
		fi->fim->prox = p;
	}
	
	printf("inserindo: %c\n", carac);	
	fi->fim = p;

	if (fi->inicio==NULL)  // caso fila antes vazia 
		fi->inicio = fi->fim;
}

void imprimeFila(tFila* fi){
	tCelula *q;
	q = fi->inicio;
	printf("* Imprimindo...\n");
	for(q=fi->inicio; q!=NULL; q=q->prox)
		printf("%c\n",q->conteudo);
}

int filaVazia(tFila* fi){
	return (fi->inicio==NULL);
}

char desenFileira(tFila* fi){
    if(filaVazia(fi)){ // fila vazia, aborta o programa
		printf("Fila vazia.\n");
		return '\0';
	}

	char v = fi->inicio->conteudo;

	tCelula *p = fi->inicio->prox;
	free(fi->inicio); // fi->inicio == null
	fi->inicio = p;

	if (fi->inicio == NULL)   // fila ficou vazia
		fi->fim = NULL;
	
    return v;
}

void esvaziaFila(tFila *fi){
	tCelula *q;
	for(q=fi->inicio; q!=NULL; q=q->prox)
		free(q);
	fi->inicio = fi->fim = NULL;
}
