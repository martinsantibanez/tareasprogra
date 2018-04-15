#include <stdio.h>
#include <string.h>

#define MAX_X 10
#define MAX_Y 10
#define FALSO 0
#define VERDADERO 1
/*
Tarea 5
Martín Santibáñez
19.525.124-K

*/


void leerMapa(char mapa[MAX_X][MAX_Y],
	      int *x, int *y,
	      int *xEntrada, int *yEntrada,
	      int *xSalida, int *ySalida);


void imprimirMapa(char mapa[MAX_X][MAX_Y], int x, int y);


/* Retorna VERDADERO si existe un camino en el 'mapa'
   desde la posición de entrada (xEntrada, yEntrada) hacia la
   posición de salida (xSalida, ySalida). */
int existeSalida(char mapa[MAX_X][MAX_Y],
		 int mapaX, int mapaY,
		 int xEntrada, int yEntrada,
		 int xSalida, int ySalida);


/* Similar a 'existeSalida', pero esta función realiza
   la búsqueda recursiva de los caminos en el mapa del laberinto. */
int encontrarCamino(int x, int y, char mapa[MAX_X][MAX_Y],
		    int mapaX, int mapaY,
		    int xSalida, int ySalida);


int main() {
  char mapa[MAX_X][MAX_Y];
  int mapaX, mapaY, xEntrada, yEntrada, xSalida, ySalida;

  leerMapa(mapa, &mapaX, &mapaY, &xEntrada, &yEntrada, &xSalida, &ySalida);
  printf("Mapa leído:\n\n");
  imprimirMapa(mapa, mapaX, mapaY);
    //existeSalida(mapa, mapaX, mapaY, xEntrada, yEntrada, xSalida, ySalida);
  if (existeSalida(mapa, mapaX, mapaY, xEntrada, yEntrada, xSalida, ySalida)) {
    imprimirMapa(mapa, mapaX, mapaY);
  } else {
    printf("No hay camino.");
  }

  return 0;
}


void leerMapa(char mapa[MAX_X][MAX_Y],
	      int *x, int *y,
	      int *xEntrada, int *yEntrada,
	      int *xSalida, int *ySalida) {
  int i, j;
  scanf("%d %d\n", x, y);
  for (i = 0; i < *y; i += 1) {
    for (j = 0; j < *x; j += 1) {
      scanf("%c", &mapa[i][j]);

      /* Determinar posición inicial */
      if (mapa[i][j] == 'E') {
	*xEntrada = j;
	*yEntrada = i;
      }

      /* Determinar posición final */
      if (mapa[i][j] == 'S') {
	*xSalida = j;
	*ySalida = i;
      }
    }
    scanf("\n");
  }
}


void imprimirMapa(char mapa[MAX_X][MAX_Y], int x, int y) {
  int i, j;
  for (i = 0; i < y; i += 1) {
    for (j = 0; j < x; j += 1) {
      printf("%c", mapa[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}


int existeSalida(char mapa[MAX_X][MAX_Y],
		 int mapaX, int mapaY,
		 int xEntrada, int yEntrada,
		 int xSalida, int ySalida) {
  printf("Partiendo desde posición inicial (%d, %d)\n", xEntrada, yEntrada);
  return encontrarCamino(yEntrada, xEntrada, mapa, mapaX, mapaY, xSalida, ySalida);
}


/* Búsqueda recursiva de las salidas al laberinto.
Los parámetros 'x' e 'y' indican que el robot hará un movimiento a la casilla (x,y).
Los demás parámetros proporcionan el contexto necesario para tomar decisiones dentro
de la función.

La función debe retornar VERDADERO si el movimiento hacia (x,y) coincide con el movimiento
hacia la salida en la posición (xSalida, ySalida). También debe retornar VERDADERO si este
movimiento es parte de un camino posible, el cual se busca recursivamente.

Si el movimiento hacia (x,y) no lleva a la salida, la función debe retornar FALSO. */
int encontrarCamino(int x, int y, char mapa[MAX_X][MAX_Y],
		    int mapaX, int mapaY,
		    int xSalida, int ySalida) {
    mapa[x][y] = '+';

    if(mapa[x-1][y]=='S') {
        return VERDADERO;
    }
    if(mapa[x+1][y]=='S') {
        return VERDADERO;
    }
    if(mapa[x][y-1]=='S') {
        return VERDADERO;
    }
    if(mapa[x][y+1]=='S') {
        return VERDADERO;
    }


    if(mapa[x-1][y]=='.') {
        if(encontrarCamino(x-1, y, mapa, mapaX, mapaY, xSalida, ySalida)) return VERDADERO;
    }
    if(mapa[x+1][y]=='.') {
        if(encontrarCamino(x+1, y, mapa, mapaX, mapaY, xSalida, ySalida)) return VERDADERO;
    }
    if(mapa[x][y-1]=='.') {
        if(encontrarCamino(x, y-1, mapa, mapaX, mapaY, xSalida, ySalida)) return VERDADERO;
    }
    if(mapa[x][y+1]=='.') {
        if(encontrarCamino(x, y+1, mapa, mapaX, mapaY, xSalida, ySalida)) return VERDADERO;
    }
    return FALSO;
}



