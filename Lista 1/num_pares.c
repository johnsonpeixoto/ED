/*
 * num_pares.c
 * 
 * Copyright 2018 Johnson <johnson@inspiron-5468>
 * 
 * Faça um programa que mostre os números pares entre 1 e 100, inclusive.
 * 
 * Entrada:
 * Neste problema extremamente simples de repetição não há entrada.
 * 
 * Saída:
 * Imprima todos os números pares entre 1 e 100, inclusive se for o caso, um em cada linha.
 * 
 */

#include <stdio.h>


int main()
{
	
	//int vetorSize = 100;
	int vetor[100];
	
	for(int i=1; i<=100; i++){		// preencher o vetor com os valores 1 à 100
		vetor[i-1] = i;
	}
	
	for(int i=1; i<=100; i++){		// percorrer o vetor em busca dos valores pares
		if(i%2 == 0){
			printf("%d\n", i);
		}
	}
	
	return 0;
}

