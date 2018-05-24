# Libs-c
Libs em C para colaborar com os alunos da FCT

## COLORS.H

Esta biblioteca usa algumas funções do console **Windows**
para trabalhar com cores.

### Utilização 

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
