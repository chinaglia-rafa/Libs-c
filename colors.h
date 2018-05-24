/*
**	Lib helper para controle de cores no console Windows 
**	@author Rafael Chinaglia <chinaglia.rafa@gmail.com>
**
**	TODO: ajustar espacamento esquerdo nas mensagens com icones
**
*/

#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char* BORDER_TYPE = "-"; //	Troque pelo tipo de borda que preferir ["~", "=", "-", "-+-", "~-"]

HANDLE hConsole;
//	Cria uma constante com as informacoes do console
CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
//	Faz um backuop das configuracoes padroes para uso futuro
WORD saved_attributes;
	
/*
**	Essa funcao vai capturar os controles de tela
**	para podermos administrar as cores.
*/
void init () {
	//	Captura o controle de saida
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
}

/*
**	Troca a cor da saida de texto para a cor especificada.
**	@param color String com o nome da cor em ingles
**		- red
**		- blue
**		- green
**		- yellow
**		- purple
**		- pink
**		- white
**		- default
*/

void changeColor(char *color) {
	if (strcmp(color, "red") == 0) {
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	} else if (strcmp(color, "blue") == 0) {
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	} else if (strcmp(color, "green") == 0) {
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	} else if (strcmp(color, "cyan") == 0) {
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	} else if (strcmp(color, "yellow") == 0) {
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	} else if (strcmp(color, "purple") == 0) {
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
	} else if (strcmp(color, "pink") == 0) {
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	} else if (strcmp(color, "white") == 0) {
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	} else if (strcmp(color, "default") == 0) {
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	}
}

/*
**	Retorna a cor ao padrao
**	Similar ao uso de changeColor("default")
*/
void resetColor() {
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

/*
**	Troca a cor do output para uma cor aleatoria
**	da lista de cores suportadas
*/
void randomColor() {
	srand(time(NULL));
	switch (rand() % 7) {
		case 0:
			changeColor("blue");
			break;
		case 1:
			changeColor("green");
			break;
		case 2:
			changeColor("cyan");
			break;
		case 3:
			changeColor("yellow");
			break;
		case 4:
			changeColor("purple");
			break;
		case 5:
			changeColor("pink");
			break;
		case 6:
			changeColor("white");
			break;
		case 7:
			changeColor("default");
			break;
	}
}

/*
**	Responsavel por imprimir uma mensagem ja formatada
**  como um ERRO
**	@param texto String 
*/

void printError(char *texto, short simplify) {
	changeColor("red");
	//	Se simplify for verdadeiro, apenas imprimimos o texto
	if (simplify == 1) {
		printf(texto);
	} else {	
	//	Caso contrario, imprimimos o icone e linhas paralelas
		//	Aqui usamos uma funcao chamada __renderLine para
		//	desenhar a linha com o tamanho exato do texto.
		//	Somamos +4 ao tamanho para comportar tambem o
		//	icone
		__renderLine(strlen(texto)+4);
		printf("\n");
		printf("[x] ");
		printf(texto);
		printf("\n");
		__renderLine(strlen(texto)+4);
		printf("\n");
	}
	changeColor("default");
}


/*
**	Responsavel por imprimir uma mensagem ja formatada
**  como um AVISO
**	@param texto String 
*/

void printWarning(char *texto, short simplify) {
	changeColor("yellow");
	//	Se simplify for verdadeiro, apenas imprimimos o texto
	if (simplify == 1) {
		printf(texto);
	} else {	
	//	Caso contrario, imprimimos o icone e linhas paralelas
		//	Aqui usamos uma funcao chamada __renderLine para
		//	desenhar a linha com o tamanho exato do texto.
		//	Somamos +4 ao tamanho para comportar tambem o
		//	icone
		__renderLine(strlen(texto)+4);
		printf("\n");
		printf("[!] ");
		printf(texto);
		printf("\n");
		__renderLine(strlen(texto)+4);
		printf("\n");
	}
	changeColor("default");
}

/*
**	Responsavel por imprimir uma mensagem ja formatada
**  como um SUCESSO
**	@param texto String 
*/

void printSuccess(char *texto, short simplify) {
	changeColor("green");
	//	Se simplify for verdadeiro, apenas imprimimos o texto
	if (simplify == 1) {
		printf(texto);
	} else {	
	//	Caso contrario, imprimimos o icone e linhas paralelas
		//	Aqui usamos uma funcao chamada __renderLine para
		//	desenhar a linha com o tamanho exato do texto.
		//	Somamos +4 ao tamanho para comportar tambem o
		//	icone
		__renderLine(strlen(texto)+4);
		printf("\n");
		printf("[o] ");
		printf(texto);
		printf("\n");
		__renderLine(strlen(texto)+4);
		printf("\n");
	}
	changeColor("default");
}

/*
**	Responsavel por imprimir uma mensagem ja formatada
**  como um BLOCO INFORMATIVO
**	@param texto String 
*/

void printInfo(char *texto, short simplify) {
	changeColor("cyan");
	//	Se simplify for verdadeiro, apenas imprimimos o texto
	if (simplify == 1) {
		printf(texto);
	} else {	
	//	Caso contrario, imprimimos o icone e linhas paralelas
		//	Aqui usamos uma funcao chamada __renderLine para
		//	desenhar a linha com o tamanho exato do texto.
		//	Somamos +4 ao tamanho para comportar tambem o
		//	icone
		__renderLine(strlen(texto)+4);
		printf("\n");
		printf("[i] ");
		printf(texto);
		printf("\n");
		__renderLine(strlen(texto)+4);
		printf("\n");
	}
	changeColor("default");
}

/*
**	Funcao privada que imprime uma linha
**	de tamanho pre-definido
**	@param size int Tamanho da linha
*/
void __renderLine(int size) {
	int i = 1, lim = ceil((double)size / (strlen(BORDER_TYPE)));
	if (lim > 110) lim = 110;
	for (i = 1; i <= lim; i++) {
		printf(BORDER_TYPE);
	}
}

