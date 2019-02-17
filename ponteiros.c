#include <stdio.h>

#define troca(X, Y) {int t = X; X = Y; Y = t;}

void hm(int mnts, int *h, int *m){
	if(mnts < 60){
		*h = 0;
		*m = mnts; 
	}else{
		float hem = mnts/60;
		*h = (int) hem;
		*m = mnts - (*h * 60);
	}
}

int main (void) {

	int horas;
	int minutos = 5;
	
	hm(minutos, &horas, &minutos);
	printf("%dh e %dmin\n", horas, minutos);
	
	return 0;
}
