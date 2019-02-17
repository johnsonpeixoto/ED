/*
 * main.c
 * 
 * Copyright 2018 Johnson <johnson@inspiron-5468>
 *
 */

#include <stdio.h>
#include "router.h"

int main(void)
{
	int term, op;
	criarRoteador();  // iniciar as filas
	while(1)
	{
		printf("\n\t[[MENU ROTEADOR]]\n\n[1] Computador 1\n[2] Computador 2\n[4] Reinicia tudo\n[5] Sair\nOpção: ");
		scanf("%d", &term);
		if(term == 5) // fim do programa
			exit(1);
		else if(term == 4) // esvazia as filas
			limpaRoteador();
		system("clear");
		if(term == 1 || term == 2)	{
			while(1)
			{
				if(novasMsg(term)) printf("\t\t** Você possue novas mensagens...\n");
				printf("\t[MENU Computador %d]\n\n[1] Enviar pacote\n[2] Ler pacotes\n[5] Voltar\nEscolhar uma Operação: ", term);
				scanf("%d", &op);
				if(op == 5) { system("clear"); break; }
				if(op == 1){ // enviar pacote
					tMsg pacote;
					scanf("%s", pacote.corpo); // define o conteudo do pacote
					pacote.dest = term; // define o destino do pacote
					enviarpct(&pacote); // envia o pacote
				}else if(op == 2) { // ler pacote
					lerpct(term);
				}
				else printf("* Operação inválida\n");
			}
		}
		else printf("* Operação inválida\n");
	}
	return 0;
}
