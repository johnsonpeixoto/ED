/*
 * coluna na matriz.c
 * 
 * Copyright 2018 Johnson <johnson@inspiron-5468> 
 * 
 */

#include <stdio.h>

int main(){
	int C; scanf("%d", &C); // coluna alvo [0 <= C <= 11]
	char T[2]; scanf("%s", T); // var da operação
	double sum = 0.0, M[12][12]; // tamanho fixo definido pela questão
	
	int l,k;	// auxiliares
	
	for(l=0; l<12; l++){ // preencher a matrix vazia
		for(k=0; k<12; k++){
			scanf("%lf", &M[l][k]);
			if(k==C) sum+=M[l][k];
		}
	}
	
	if(T[0] == 'S')
		printf("%.1lf\n",sum);
	else {
		sum = sum/12.0;
		printf("%.1lf\n",sum);		
	}
	
	return 0;
}

