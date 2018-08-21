/*
 * Fila do Recreio.c
 * 
 * Copyright 2018 Johnson <johnson@inspiron-5468>
 * 
 * Para cada caso de teste imprima uma linha,
 * contendo um inteiro, indicando o número de
 * alunos que não precisaram trocar de lugar
 * mesmo após a fila ser reordenada.
 * 
 */

#include <stdio.h>

struct Aluno {
	int lugarInicial;
	int nota;	
};

int main()
{
	int N, M, i;
	scanf("%d", &N); // número de testes
	int teste[N], n = N;
	while(n != 0){
		scanf("%d", &M); // número de alunos - 1 <= M <= 1000
		struct Aluno P[M]; // vetor de registros
		for(i=0; i<M; i++){
			P[i].lugarInicial = i;
			scanf("%d", &P[i].nota); // notas dos alunos - 1 <= P <= 1000
		}
		// BUBLLE SORT
		struct Aluno swap;
		int ordenado = 1;
		while(ordenado != 0){
			ordenado = 0;
			for(i=0; i<M-1; i++){
				if(P[i].nota < P[i+1].nota){
					swap = P[i+1];
					P[i+1] = P[i];
					P[i] = swap;
					ordenado = 1;
				}
			}
		}
		// CHECKIN
		int naomudaram = 0;
		for(i=0; i<M; i++){
			if(i == P[i].lugarInicial)
				naomudaram++;
		}
		teste[n-1] = naomudaram;
		n--;
	}
	// SAIDA DE CADA TESTE
	for(i=N-1; i>=0; i--){
		printf("%d\n", teste[i]);
	}
	return 0;
}

