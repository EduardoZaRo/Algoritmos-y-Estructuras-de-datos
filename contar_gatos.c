/*
ZAVALA ROMAN IRVIN EDUARDO 1270771
Desarrollar	un	programa	basado	en	un	algoritmo	
recursivo	cuya	función	sea	devolver	el	
número	de	#’s	alrededor	de	cada	celda de	
una	matriz	de	5	x	9.
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void llenarGatitos(char matriz[][9]);
void imprimirMatriz(char matriz[][9]);
void contarGatitosAlrededor(char matriz[][9], int filas, int columnas, int i, int j);

int main(){

    /*
	char matriz[5][9]= { //Matriz ejemplo del doc
	{'#','0','#','#','0','0','0','0','#'},
	{'0','0','0','#','0','#','0','#','0'},
	{'0','0','0','0','0','0','0','#','0'},
	{'0','#','0','#','0','#','0','#','#'},
	{'#','0','0','0','0','0','#','0','0'},
	};*/
	char matriz[5][9];
	llenarGatitos((char*)matriz);
	
	printf("\tMatriz original:\n");
	imprimirMatriz((char*)matriz);
	contarGatitosAlrededor(((char*)matriz),5,9,0,0);
	printf("\tMatriz con gatitos contados:\n");
	imprimirMatriz((char*)matriz);

	return 0;
}

void llenarGatitos(char matriz[][9]){
    int i,j,cantidad_gatitos = 0;
    srand(time(NULL));
    for(i = 0;i < 5; i++){
        for(j = 0; j < 9; j++){
			int numero = rand() % 11;	
			if(numero < 5 && cantidad_gatitos < 15){
				matriz[i][j] = '#';
				cantidad_gatitos++;
			}else matriz[i][j] = '0';
			
			numero = 0;
        }
    }
}
void imprimirMatriz(char matriz[][9]){
	int i,j;
	for(i = 0; i < 5;i++){
		for(j = 0; j < 9; j++){
			printf("|%c",matriz[i][j]);
		}

		printf("|\n");
	}
}
void contarGatitosAlrededor(char matriz[][9], int filas, int columnas, int i, int j){
    int contador = 0;
    if(i < filas){
		if(matriz[i][j] == '0'){
			if(i!=0 && j!=0) if(matriz[i-1][j-1] == '#') contador++;
			if(i!=0) if(matriz[i-1][j] == '#') contador++;
			if(j!=0) if(matriz[i][j-1] == '#') contador++;
			if(j!=8) if(matriz[i][j+1] == '#') contador++;
			if(i!=4) if(matriz[i+1][j] == '#') contador++;	
			if(i!=4 && j!=8) if(matriz[i+1][j+1] == '#') contador++;
			if(i!=4 && j!=0) if(matriz[i+1][j-1] == '#') contador++;	
			if(i!=0 && j!=8) if(matriz[i-1][j+1] == '#') contador++;
			matriz[i][j] = contador+'0';
		}
        j++;
        if(j < columnas) contarGatitosAlrededor(matriz, filas,columnas,i,j);
        else{
            i++;
            contarGatitosAlrededor(matriz, filas,columnas,i,0);
        }
    }
}
