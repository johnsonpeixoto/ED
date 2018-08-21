/*
 * marmore.c
 * 
 * Copyright 2018 Johnson <johnson@inspiron-5468>
 * 
 */

#include <stdio.h>

void swap(int *a, int *b) { // permutar
    int t = *a;
    *a = *b;
    *b = t;
}

int particionar (int arr[], int low, int high)
{
    int piv = arr[high];    // obtem o pivor
    int j, i = (low - 1);  // i é o menor valor
	
    for (j = low; j <= high - 1; j++) {
        // Se o elemento for menor/igual o pivor
        if (arr[j] <= piv) {
            i++;    // incremente o indice do menor elemento
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        int piv = particionar(arr, low, high);
        quickSort(arr, low, piv - 1);
        quickSort(arr, piv + 1, high);
    }
}

int encontrar(int arr[], int len, int key){
    int k;
    for(k=0; k<len; k++){
		if(arr[k] == key){
			return k+1;
		}
	}
    return 0;
}

int main()
{
	int N,Q,x;
	int caso = 1;
	while(1){	
		scanf("%d %d", &N, &Q);
		if(N == 0 && Q == 0) break;
		
		int vet[N+1], chaves[Q];
		for(x=0; x<N; x++){
			scanf("%d", &vet[x]);
		}
		
		quickSort(vet, 0, N-1);

		for(x=0; x<Q; x++)
			scanf("%d", &chaves[x]);

		printf("CASE# %d:\n", caso);
		for(x=0; x<Q; x++){
			int m = encontrar(vet, N, chaves[x]);
			if(m != 0) printf("%d found at %d\n", chaves[x], m);
			else printf("%d not found\n", chaves[x]);
		}
		caso++;
	}
	
	return 0;
}

