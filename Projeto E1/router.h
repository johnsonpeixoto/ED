/*
 * 
 * router.h
 * 
 */

//#include <stdio.h>
#include <string.h>
#include "buffer.h"

#define MSG_SIZE 100  //tamanho máximo da msg a ser enviada

int i;

tFila *bufferA;
tFila *bufferB;

typedef struct {
	char corpo[MSG_SIZE];
	int dest;
} tMsg;

void criarRoteador(void){ // inicia um roteador com 2 portas
	printf("* Iniciando o roteador...\n");
	bufferA = criarFila();
	bufferB = criarFila();
}

void limpaRoteador(void){ // reinicia o roteador
	printf("* Esvaziando a memória...\n");
	esvaziaFila(bufferA);
	esvaziaFila(bufferB);
}

void enviarpct(tMsg *pct){ // enfileirar
	tFila *fi;
	if(pct->dest == 1) fi = bufferB;
	else if(pct->dest == 2) fi = bufferA;
	printf("> enviando pacote...\n");
	for(i=0; i<strlen(pct->corpo); i++){
		enFileira(fi, pct->corpo[i]);
	}
}

void lerpct(int term){ // desenfileirar
	tFila* fi; char* p;
	if(term == 1) fi = bufferA;
	else if(term == 2) fi = bufferB;
	
	if(filaVazia(fi)){
		printf("< Nada por aqui.\n");
	}else{
		p = (char *) malloc(sizeof(char)*20);
		i=0;
		while(filaVazia(fi) != 1){
			*p = desenFileira(fi);
			printf("< lendo pacotes: %s\n", p);
			p++; i++;
		}
		p -= i;
		printf("< pacote completo recebido: %s\n", p);
	}
}

int novasMsg(int term){
	tFila* fi;
	if(term == 1) fi = bufferA;
	else if(term == 2) fi = bufferB;
	
	return (filaVazia(fi) == 0);

}
