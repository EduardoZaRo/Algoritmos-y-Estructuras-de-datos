#include<stdio.h>
/*
Irvin Eduardo Zavala Roman Grupo:551 23/08/2021

Practica 1: Manejo de funciones y cadenas ADN

Se pide implementar una función que reciba dos cadenas de ADN y 
devuelva si las dos cadenas de ADN coinciden.
La secuencia de ADN es cíclica, por lo que puede comenzar en 
cualquier posición. Por ejemplo, las
dos secuencias siguientes coinciden:
A T G C G T A T A T G C G T A T
A T A T G C G T
*/


void input_cadena(char[]);
void comprobar_ciclico(char[],char[]);
void rotar(char[]);
int main(){
	int salir;
	char primera_cadena[] = "ATGCGTATATGCGTAT";
	char segunda_cadena[256] = {0};
	printf("La cadena ya ingresada es %s\n",primera_cadena);
	
	do{
		char primera_cadena[] = "ATGCGTATATGCGTAT";
		char segunda_cadena[256] = {0};
		printf("Bienvenido, se va a comparar una cadena de ADN con una ya registrada\n");
	
		input_cadena(segunda_cadena);
		printf("La cadena a comprobar es:\n");
		puts(segunda_cadena);
		comprobar_ciclico(primera_cadena, segunda_cadena);
		

		printf("\nSi quieres repetir presiona 0, sino 1\n");
		scanf("%d",&salir);
		fflush(stdin);
	}while(salir == 0);
	return 0;
}
void input_cadena(char* segunda_cadena){
	int condicion = 0, longitud = 0, i = 0;
	char caracteres_validos[4] = "ATGC";
	do{
		printf("Ingresa una cadena con solo caracteres ATGC y de minimo 8 caracteres: ");
		fgets(segunda_cadena, 256, stdin);
		fflush(stdin);

	    longitud = strlen(segunda_cadena);
		if(longitud > 8){
			for(i = 0; i < (longitud-1);i++){
				if(segunda_cadena[i] == caracteres_validos[0]||segunda_cadena[i] == caracteres_validos[1]||
				segunda_cadena[i] == caracteres_validos[2]||segunda_cadena[i] == caracteres_validos[3]){
					condicion = 1;
				}
				else{
					printf("No se cumplen las condiciones\n");	
					condicion = 0;
					break; //Con una letra que con coincide rompemos el bucle
				}
			}
		}
		else{
			printf("No se cumplen las condiciones\n");
		}
		
		
	}while(condicion==0);

}

void comprobar_ciclico(char* primera_cadena, char* segunda_cadena){
	int i = 0,j = 0,k = 0; //i es para los indices de las cadenas, j para la cantidad de rotaciones y k para la cantidad de coincidencias
	int size_1 = strlen(primera_cadena),size_2 = strlen(segunda_cadena);
	int size_mayor = (size_1 > size_2) ? size_1 : size_2;
	int size_menor = (size_1 < size_2) ? size_1 : size_2;

	int condiciones = 0;
	do{
		if(primera_cadena[i] == segunda_cadena[i]){
			i++;
			if(i == size_menor-1){//Las veces que encaja el array mas pequeno en el mas grande
				printf("\nA encajado una vez!\n");
				i = 0;
			} 
			k++;
			if(k == size_mayor){//Si el numero de coincidencias es el mismo tamano del array mas grande, coinciden
				condiciones =1;
				printf("\nLas 2 secuencias coinciden!\n");
			}
		
		}
		else{
			j++;
			k = 0;
			rotar(segunda_cadena);
			i = 0;
			if(j == size_menor){
				condiciones = 1;
				if(condiciones == 1) printf("\nLas 2 secuencias no coinciden\n");
			} 
		}
	}while(condiciones == 0);

	
}

void rotar(char* cadena){
	int a = cadena[0],i;

	for(i = 0; i < strlen(cadena)-1;i++){
		
		cadena[i] = cadena[i+1];
		if(i == strlen(cadena)-2) {
			cadena[i] =a;
			break;
		}
	}
}
