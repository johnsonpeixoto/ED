/*
 * diagonal secundaria.c
 * 
 * Copyright 2018 Johnson <johnson@inspiron-5468>
 * 
 */

#include <stdio.h>
int main()
{
    double a = 0.0, M[12][12];
    char T[2];		// var da operação
    int x,y,l,c;	// var auxiliares
    int p = 10; 	// último indice da coluna a cada for
    
    scanf("%s", T);
    
    for(x=0;x<=11;x++){
        for(y=0; y<=11; y++)
			scanf("%lf", &M[x][y]);
    }
    
    for(l=0; l<11; l++){
        for(c=0; c<=p; c++) {
			a+=M[l][c];
			printf("A: %.1lf | l%d c%d\n", a, l, c);
		}
		p--;
    }
    
    if(T[0]=='S')
        printf("%.1lf\n",a);
    else if(T[0]=='M'){
        a=a/66.0;
        printf("%.1lf\n",a);
    }
    
    return 0;
}
