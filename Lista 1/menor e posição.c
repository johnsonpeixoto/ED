/*
 * menor e posição.c
 * 
 * Copyright 2018 Johnson <johnson@inspiron-5468>
 * 
 * Faça um programa que leia um valor N. Este N será o tamanho de um vetor X[N]
 * A seguir, leia cada um dos valores de X, encontre o menor elemento deste vetor
 * e a sua posição dentro do vetor, mostrando esta informação. * 
 * 
 */

#include <stdio.h>

#include <string.h>			// strtok()
#include <stdlib.h>			// atoi()

int main()
{
	
	int n, menor, pos;
	scanf("%d\n", &n);	// define o tamanho do vetor X[n]
	int x[n];
		
	char entrada[100];
	scanf("%[^\n]s", entrada);

	const char d[2] = " ";				// delimitador
	char *ptr;
	
	// ETAPA DE TRATAMENTO
	int i = 0;
	ptr = strtok(entrada, d);			//	encontra o primero espaço
	while(ptr != NULL) {			  // percorre a string novamente
		x[i] = atoi(ptr);
		ptr = strtok(NULL, d);		// altera o ponteiro e NULL mantem a entrada
		i++;
	}
	

	//	ETAPA DE BUSCA
	menor = x[0]; pos = 0;			
	for(i=1; i<n; i++){
		if(x[i] <= menor){
			menor = x[i];
			pos = i;
				//printf("%d | %d\n", menor, pos);
		}
	}
	
	printf("Menor valor: %d\nPosicao: %d", menor, pos);
	
	return 0;
}
