/*
 * diamantes e areia.c
 * 
 * Copyright 2018 Johnson <johnson@inspiron-5468>
 * 
 */

#include <stdio.h>
#include <stdlib.h>

struct Pilha {
	int topo;	// posicao elemento topo
	int tam;	// tamanho da pilha
	char *pElem;	// ponteiro do elemento
};
typedef struct Pilha pilha;

void criarpilha(pilha *p, int c);
int estavazia(pilha *p);
int estacheia (pilha *p );
void empilhar(pilha *p, char v);
float desempilhar (pilha *p);
float retornatopo(pilha *p);

int main(){
	
	return 0;
}

void criarpilha(pilha *p, int c){
   p->topo = -1;
   p->tam = c;
   p->pElem = (char*) malloc(c* sizeof(char));
}

int estavazia(pilha *p){
   if(p->topo == -1 )
      return 1;   // true
   else
      return 0;   // false
}

int estacheia (pilha *p ){
	if (p->topo == p->tam -1)
		return 1;
	else
		return 0;
}

void empilhar(pilha *p, char v){
	p->topo++;
	p->pElem[p->topo] = v;
}

float desempilhar (pilha *p){
   float aux = p->pElem[p->topo];
   p->topo--;
   return aux;
}

float retornatopo(pilha *p){
   return p->pElem[p->topo];
}
