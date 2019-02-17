#include <stdio.h>
#include <stdlib.h>

#include "tArvore.h"

void insereRec(tipoItem x, pNo p);
void inserirNos(pNo raiz);

void buscarNo(pNo raiz);

void visitaRaiz(pNo no);
void caminhamentos(pNo raiz, int op);

void antecessor(pNo q, pNo r);
void retira(tipoItem x, pNo p, int *operacao);
void removerNos(pNo raiz);

int main() {
	pNo raiz; raiz = NULL; // inicializa a arvore
	int op;

	do {
		system("clear");
		printf("Pesquisa e Arvore Binaria\n");
		printf("1- Inserir nos na Arvore\n");
		printf("2- Buscar no na Arvore\n");
		printf("3- Remover nos da Arvore\n");
		printf("0- Encerrar o programa\n");
		printf("Opcao desejada: ");

		do {
			scanf("%d", &op);
		} while ((op < 0) || (op > 4));

		switch (op) {
			case 1: inserirNos(raiz); break;
			case 2: buscarNo(raiz); break;
			case 3: removerNos(raiz);
		}

	} while (op != 0);
  
	return 0;
}

void insereRec(tipoItem x, pNo raiz) {
	system("clear");
	if (raiz == NULL) {
		raiz = (pNo) malloc(sizeof(struct no));
		raiz->item = x;
		raiz->esq = NULL;
		raiz->dir = NULL;
		printf("- No %d adicionado -\n", raiz->item.chave);
	}
	else if (x.chave < raiz->item.chave)
		insereRec(x, raiz->esq);
	else insereRec(x, raiz->dir);
}

void buscaRec(int *alvo, pNo raiz) {
	printf("Buscando...\n");
	printf("Em raiz %d...\n", raiz->item.chave);
	if (raiz->item.chave == (int)*alvo) {
		printf("- Valor %d encontrado -\n", (int)*alvo);
	}
	else if ((int)*alvo < raiz->item.chave)
		buscaRec(alvo, raiz->esq);
	else buscaRec(alvo, raiz->dir);

}

void buscarNo(pNo raiz) {
	printf("Informe um item a ser encontrado: ");
	int alvo; scanf("%d", &alvo);
	buscaRec(&alvo, raiz);
}

void inserirNos(pNo raiz) {
	tipoItem x;
	while (1) {
		printf("Informe um item a ser inserido, -1 para encerrar:\n");
		scanf("%d", &x.chave);
		if (x.chave == -1) break;
		insereRec(x, raiz);
	}
}

void visitaRaiz(pNo no) {
	printf("%d ", no->item.chave);
}

void antecessor(pNo q, pNo r) {
  if (r->dir != NULL)
     antecessor(q, r->dir);
  else {
     q->item = r->item;
     q = r;
     r = r->esq;
     free(q);
  }
}

void retira(tipoItem x, pNo p, int *operacao) {
	pNo aux;
	if (p == NULL)
		*operacao = 0;
	else if (x.chave < p->item.chave)
		retira(x, p->esq, operacao);
	else if (x.chave > p->item.chave)
		retira(x, p->dir, operacao);
	else {
		*operacao = 1;
		if (p->dir == NULL) {
			aux = p;
			p = p->esq;
			free(aux);
		}
		else if (p->esq == NULL) {
			aux = p;
			p = p->dir;
			free(aux);
		}
		else antecessor(p, p->esq);
	}
}

void removerNos(pNo raiz) {
	tipoItem x;
	int operacao;
	while (1) {
		system("clear");
		printf("Informe um item a ser removido, -1 para encerrar:\n");
		scanf("%d", &x.chave);
		if (x.chave == -1)
			break;

		retira(x, raiz, &operacao);

		if (operacao == 1)
			printf("\n\nItem removido com sucesso !!!");
		else printf("\n\nErro: Registro nao encontrado.");

		printf("\n\nPressione [algo] para prosseguir.\n");
		system("pause");
	}
}
