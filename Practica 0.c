#include<stdio.h>
//Mejorar portada XD
/*
Nombre: Irvin Eduardo Zavala Roman, grupo 551
16/07/2021
Practica 0: Manejo de cadenas
EL	método	de	 transposición	simple	
divide un	mensaje	en	dos	bloques	símbolo	por símbolo, 
si	el	número	de	símbolos	es	impar,	el	primer grupo	de	
símbolos	 tendrá	 un	 elemento	 más	 que	 el	 segundo.
En	 el	 primer	 bloque	 tendremos	 los	 elementos impares			
mientras	en	el	segundo	estarán	los	elementos	pares.	Para
finalizar	se	concatenan	los	bloques	y	así	tendremos	el	
mensaje	en	criptograma.

Ejemplo	1
Si	la	cadena	a	encriptar	es:	Hola	mundo
Bloque1:	 Hlmno
Bloque2:	 oaud
Criptograma:	 Hlmnooaud
*/

void encriptar_cadena(char[],char[]);
void eliminar_espacios(char[], char[]);

int main(void){
	
	char cadena[256] = {0};
	char cadena_sin_espacios[256] = {0};
	char cadena_encriptada[256] = {0};
	
	printf("Ingresa la cadena a encriptar: ");
	fgets(cadena, 256, stdin);
	fflush(stdin);
	

	eliminar_espacios(&cadena, &cadena_sin_espacios);
	
	encriptar_cadena(&cadena_sin_espacios, &cadena_encriptada);
	printf("\n\nLa cadena encriptada es:\n");
	printf(cadena_encriptada);
	return 0;
}

void eliminar_espacios(char* cadena, char* cadena_sin_espacios){
	while(*cadena){
		if(*cadena != ' '){
			*cadena_sin_espacios = *cadena;
			*cadena_sin_espacios++;
		}
		cadena++;
	}
}

void encriptar_cadena(char* cadena, char* cadena_encriptada){
	int longitud_string = strlen(cadena) - 1;
	char pares[128], impares[128];
	int i,j = 0,k=0;
	for(i = 0; i < longitud_string; i++){
		if(i%2 == 0){
			impares[j] = cadena[i];
			j++;
			printf("Par\n");		
		}
		else{
			pares[k] = cadena[i];
			k++;
			printf("Impar\n");
		}	
	}
	printf("\n-------Valores impares---------\n");
	printf(impares);
	printf("\n--------Valores pares--------\n");
	printf(pares);
	//Juntamos los valores impares y pares en cadena_encriptada
	for(i = 0; i < strlen(impares);i++){
		*cadena_encriptada = impares[i];
		*cadena_encriptada++;
	}
	for(i = 0; i < strlen(pares);i++){
		*cadena_encriptada = pares[i];
		*cadena_encriptada++;
	}
}
