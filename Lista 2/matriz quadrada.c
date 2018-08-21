/*
 * matriz quadrada.c
 * 
 * Copyright 2018 Johnson <johnson@inspiron-5468>
 * 
 */
#include <stdio.h>
 
int main()
{
    int a,b,c,j=1,p,q,N,meio,i,l;
    
	do {
        scanf("%d", &N); // valor M[n][n]
		if(N==0) break;
		
		j=1, p=0, q=0;	// j valor referencia, p e q indices
		int matriz[N][N];
		i=N;

		// meio par
		if(N%2==0) meio=N/2;
		
		// meio impar
		else if(N%2==1) meio=(N/2)+1;
		
		for(c=0; c<meio; c++){
			for(a=p; a<i; a++){
				for(b=q; b<i; b++) matriz[a][b]=j;
			}
			j++;
			p++; q++; i--;
		}
		// FORMATAÇAO + IMPRESSÃO //
		for(l=0; l<N; l++) {
			for(c=0; c<N; c++) {
				if(c==0) printf("%3d",matriz[l][c]);
				else printf(" %3d",matriz[l][c]);
			}
			printf("\n");
		}
		printf("\n");
	} while(N != 0);
	
    return 0;
}
