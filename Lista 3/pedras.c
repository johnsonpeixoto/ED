/*
 * pedras.c
 * 
 * Copyright 2018 Johnson <johnson@inspiron-5468>
 * 
 */

#include <stdlib.h>
#include <stdio.h>

int compare(const void *a, const void *b){
	return (*(int*)a - *(int*)b);
}

int lower(int arr[],int x){
	if(arr[x] != arr[x-1] || x==0)return x;
	else lower(arr,--x);
}

int binarySearch(int arr[], int l, int r, int x)
{
   if (r >= l)
   {
		int mid = l + (r - l)/2;

		// If the element is present at the middle itself
		if (arr[mid] == x)  return lower(arr,mid);

		// If element is smaller than mid, then it can only be present
		// in left subarray
		if (arr[mid] > x) return binarySearch(arr, l, mid-1, x);

		// Else the element can only be present in right subarray
		return binarySearch(arr, mid+1, r, x);
   }

   // We reach here when element is not present in array
   return -1;
}

int main(){
	int i,j,k,n,q,x[100],ct=0;
	while(!EOF){
		scanf("%d",&n);
		scanf("%d",&q);
		if(n!=0 && q!=0){
			for(i=0;i<n;++i)scanf("%d",&x[i]);
			qsort(x,n,sizeof(int),compare);
			printf("CASE# %d:\n",++ct);
			for(i=0;i<q;i++){
				scanf("%d",&k);
				j=binarySearch(x,0,n,k);
				if(j!=-1)printf("%d found at %d\n",k,j+1);
				else printf("%d not found\n",k);
			}
		}
	}
	return 0;
}
