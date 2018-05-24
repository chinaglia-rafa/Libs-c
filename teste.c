#include <stdio.h>
#include "colors.h"

int main (void) {
	
	init();
	
	changeColor("red");
	printf("R");
	changeColor("yellow");
	printf("A");
	changeColor("pink");
	printf("I");
	changeColor("blue");
	printf("N");
	changeColor("green");
	printf("B");
	changeColor("cyan");
	printf("O");
	changeColor("purple");
	printf("W");
	printf("\n");
	randomColor();
	printf("Cor aleatoria");
	changeColor("default");
	printf("\n");
	printWarning("Eu sou simples demais :(", 1);
	printf("\n");
	printInfo("Mas eu ja sou mais completo e informativo!", 0);
	printf("\n");
	printWarning("Fique atento agora!", 0);
	printf("\n");	
	printError("Houve um erro aqui!", 0);
	printf("\n");	
	printSuccess("Ufa! Ficou tudo bem! Sorte que o campo se ajusta ne?", 0);
	printf("\n");	
	printWarning("Observe como nao importa o quanto o campo seja longo, a linha horizontal nao se quebra facilmente! Isso e uma otima noticia, ja que seria terrivel ter que ajusta-la toda vez que um novo texto fosse digitado!", 0);
	printf("\n");	
	return (0);
}
