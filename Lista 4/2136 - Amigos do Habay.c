#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ordenamos com um bubblesort básico
void OrdenaNomes(char nomes[][110], int numNomes) {
	int i;
	char strAux[100];
	int fim = 0, count;
	for(count = 0; count < numNomes-1; count++) {
		for(i=0;i<numNomes - 1 - fim;i++) {

			if(strcmp(nomes[i], nomes[i+1]) > 0) {
				strcpy(strAux, nomes[i]);
				strcpy(nomes[i], nomes[i+1]);
				strcpy(nomes[i+1], strAux);
			}
		}
		fim++;
	}
}

int main() {
	char linha[110];
	char amigosHabay[1000][110];
	char InimigosHabay[1000][110];
	int numAmigos = 0, numInimigos = 0;
	while(1) {
		scanf("%[^\n]", &linha);
		// Paramos o while quando lermos FIM
		if(strcmp(linha, "FIM") == 0)
			break;
		
		int contador = 0;
		char aux[100];
		// Guardamos a palavra no aux
		while(linha[contador] != ' ' && linha[contador] != '\0') {
			aux[contador] = linha[contador];
			contador++;
		}
		aux[contador] = '\0';
		// Se for YES, é guardado no amigosHabay
		if(linha[contador+1] == 'Y') {
			strcpy(amigosHabay[numAmigos], aux);
			
			// Precisamos checar se o nome ja é repetido
			if(numAmigos > 0) {
				int count = numAmigos - 1;
				while(count >= 0) {
					// Se for repetido, diminuímos o numero de amigos
					if(strcmp(amigosHabay[numAmigos], amigosHabay[count]) == 0) {
						numAmigos--;
						break;
					}
					count--;
				}
			}

			numAmigos++;
		}
		else {
			strcpy(InimigosHabay[numInimigos], aux);
			//	Apesar de desnecessário, checamos se existem repetidos:
			if(numInimigos > 0) {
				int count = numInimigos - 1;
				while(count >= 0) {
					// Se for repetido, diminuímos o numero de inimigos
					if(strcmp(InimigosHabay[numInimigos], InimigosHabay[count]) == 0) {
						numInimigos--;
						break;
					}
					count--;
				}
			}
			numInimigos++;
		}

	getchar();
	}

	// Definimos o vencedor:
	int vencedor = 0, i;
	for(i=0;i<numAmigos-1;i++) {
		// Vencedor é definido pelo tamanho do nome e ordem de chegada
		if(strlen(amigosHabay[vencedor]) < strlen(amigosHabay[i+1])){
			vencedor = i+1;
		}
	}
	
	char vencedorFinal[100];
	strcpy(vencedorFinal, amigosHabay[vencedor]);
	OrdenaNomes(amigosHabay, numAmigos);
	OrdenaNomes(InimigosHabay, numInimigos);

	for(i=0;i<numAmigos;i++)
		printf("%s\n", amigosHabay[i]);
	
	for(i=0;i<numInimigos;i++)
		printf("%s\n", InimigosHabay[i]);

	if(numAmigos > 0){
		printf("\nAmigo do Habay:\n%s\n",vencedorFinal);
	}

	return 0;
}
