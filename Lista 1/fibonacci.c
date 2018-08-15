/*
 * fibonacci.c
 * 
 * Copyright 2018 Johnson <johnson@inspiron-5468>
 * 
 * Fib(N) = X
 * 
 */

#include <stdio.h>

int main()
{
	int i, n, j;
	scanf("%d", &n);

	double seq[61], temp;
	seq[0] = 0;
	seq[1] = 1;
	
	for (i=2; i<=60; i++){
		temp = seq[i-1] + seq[i-2];
		seq[i] = temp;
	}	
	
	int indices[n];
	for (i=0; i<n; i++){
		scanf("%d", &indices[i]);
	}

	for (i=0; i<n; i++){
		printf("Fib(%d) = %.0f\n", indices[i], seq[indices[i]]);
	}
	return 0;
}

