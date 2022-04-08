#include <stdio.h>
#include <stdlib.h>

void Arriba();
void Abajo();
void Izquierda();
void Derecha();
void EstadoLapiz();
void Pintar();

void InicializarPlano();
void MostrarPlano();
void GuardarUltimoValor();
void ActualizarPlano();

void MoversePorCoordenada(int x, int y);

int capacidadX = 10;
int capacidadY = 10;
int plano[10][10];
int coordenadaX, coordenadaY = 0;
int ultimoValor = 0;
// 0 = espacio sin pintar.
// 1 = espacio pintado.
// 2 = lugar en donde se encuentra parada la máquina.

int main(int argc, char *argv[]) {
	InicializarPlano();
	MostrarPlano();
	
	Abajo();
	Derecha();
	Arriba();
	Izquierda();
	Derecha();
	Derecha();
	Abajo();
	Abajo();
	return 0;
}

void InicializarPlano(){
	int i, j = 0;
	for(i=0;i<capacidadX;i++){
		for(j=0;j<capacidadY;j++){
			plano[i][j] = 0;
		}
	}
	plano[0][0] = 1;
}

void MostrarPlano(){
	int i, j = 0;
	for(i=0;i<capacidadX;i++){
		printf("\n");
		for(j=0;j<capacidadY;j++){
			printf("|%d|",plano[i][j]);
		}
	}
	printf("\n");
}

void ActualizarPlano(){
	MoversePorCoordenada(coordenadaX, coordenadaY);
	MostrarPlano();
	Sleep(1000);
}

void MoversePorCoordenada(int x, int y){	
		plano[x][y] = 1;		
}

void GuardarUltimoValor(){
	plano[coordenadaX][coordenadaY] = ultimoValor;
	int ultimoValor = plano[coordenadaX][coordenadaY];
}

void Arriba(){
	GuardarUltimoValor();
	coordenadaX--;
	ActualizarPlano();
}

void Abajo(){
	GuardarUltimoValor();
	coordenadaX++;
	ActualizarPlano();	
}

void Izquierda(){
	GuardarUltimoValor();
	coordenadaY--;
	ActualizarPlano();
}

void Derecha(){
	GuardarUltimoValor();
	coordenadaY++;
	ActualizarPlano();
}
