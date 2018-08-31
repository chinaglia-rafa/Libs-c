# Libs em C
Libs em C para colaborar com os alunos da FCT

## COLORS.H

Esta biblioteca usa algumas funções do console **Windows**
para trabalhar com cores.

### Utilização 

Mantenha o arquivo colors-vX.Y.h no mesmo diretório que seus arquivos fontes .c
e inclua a lib usando #include.

```c
#include "colors-vX.Y.h"
```

:information_source: É importante notar que não são utilizados < e >, mas sim aspas duplas.

:information_source: O nome do arquivo deve ser preenchido com a versão da lib (por exemplo **colors-v1.0.h**)


Para iniciar a lib, use o comando abaixo no começo da sua função main

```c
initColors();
```

A colors.h possui as seguintes cores disponíveis:

1. azul (*blue*)
2. verde (*green*)
3. ciano (*cyan*)
4. amarelo (*yellow*)
5. roxo (*purple*)
6. rosa (*pink*)
7. branco (*white*)
8. default (*default*)

Para trocar a cor de saída, use o comando

```c
//	Troca a cor para ciano
changeColor("cyan");
//	Volta à cor original
resetColor();
//	Aplica uma cor aleatória
randomColor();
```

### Mensagens

A biblioteca oferece quatro tipo de caixas de mensagens personalizáveis. O
segundo parâmetro controla o uso de borda e ícone (0 | 1).


```c

printWarning("aviso", 1);

printError("erro", 1);

printSuccess("sucesso", 1);

printInfo("informativo", 1);
```
O arquivo teste.c tem exemplos de uso.

![Image of Yaktocat](https://i.imgur.com/7FDTCCJ.png)

