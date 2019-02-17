#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	char linha[250];
	while(1) {
		// Lemos até quebra de linha
		scanf("%[^\n]%*c",linha);
		// Terminamos o programa quando lemos *
		if(linha[0] == '*')
			break;

		int contador;
		int tamLinha = strlen(linha);
		int compassosCertos = 0;
		for(contador = 1; contador < tamLinha; contador++) {
			float limiteCompasso = 0;

			//	Esse while percorre cada compasso
			while(linha[contador] != '/' && linha[contador] != '\0' && contador < tamLinha) {
				if(linha[contador] == 'W')
					limiteCompasso += 1;
				else if(linha[contador] == 'H')
					limiteCompasso += (float)1/2;
				else if(linha[contador] == 'Q')
					limiteCompasso += (float)1/4;
				else if(linha[contador] == 'E')
					limiteCompasso += (float)1/8;
				else if(linha[contador] == 'S')
					limiteCompasso += (float)1/16;
				else if(linha[contador] == 'T')
					limiteCompasso += (float)1/32;
				else if(linha[contador] == 'X')
					limiteCompasso += (float)1/64;
				
				contador++;
			}
			//	Se for exatamente igual a 1, está certo
			if(limiteCompasso == 1)
				compassosCertos++;

		}
		printf("%d\n",compassosCertos);

	}

	return 0;
}