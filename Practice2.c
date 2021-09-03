#include<stdio.h>
#include <time.h>
/*
Irvin Eduardo Zavala Roman Grupo:551 30/08/2021
Practica 2: Análisis de Algoritmos Empírico.
Una variación de la codificación César consiste en utilizar un
alfabeto diferente, por ejemplo codificando el alfabeto
"abcdefghijklmnopqrstuvxyz" utilizando como codificador el
alfabeto "7#1@ef)h8+kl3924$rs65k^y*" y un desplazamiento de
3. La codificación de “computación” sería: fr4sy^@f1r$
*/
void desplazar(char[],int);
void codificar(char[], char[],char[]);
int main(){
int salir;
char alfabeto[] = "abcdefghijklmnopqrstuvxyz";
char codificador[] = "7#1@ef)h8+kl3924$rs65k^y*";
char input[256] = {0};
int desplazamiento;
clock_t inicio,fin; double total;
do{
printf("Ingresa una cadena a codificar\n");
fgets(input, 256, stdin);
fflush(stdin);
printf("Cuantos espacios desea desplazar?\n");
scanf("%d", &desplazamiento);
printf("La cadena a codificar es %s con un desplazamiento de %d
caracteres\n\n",input, desplazamiento);
inicio = clock();
desplazar(codificador,desplazamiento);
codificar(input,codificador,alfabeto);
fin = clock();
total = (double)(fin-inicio)/(CLOCKS_PER_SEC/1000);
printf("La cadena codificada es:\n");
puts(input);
printf("El tiempo de ejecucion fue de %f milisegundos\n", total);
printf("\nSi quieres repetir presiona 0, sino 1\n");
scanf("%d",&salir);
fflush(stdin);
if(salir == 0){
char alfabeto[] = "abcdefghijklmnopqrstuvxyz";
char codificador[] = "7#1@ef)h8+kl3924$rs65k^y*";
}
}while(salir == 0);
return 0;
}
void desplazar(char* cadena, int desplazamiento){
int i, j;
char a[desplazamiento];//En este char se guardan los valores que se pierden
al desplazar
for(i = 0; i < desplazamiento;i++){
a[i] = cadena[i];
}
for(i = 0; i < strlen(cadena)-1;i++){
cadena[i] = cadena[i+desplazamiento];
if(i == strlen(cadena)-(desplazamiento+1)){
for(j = 0; j < desplazamiento;j++){
cadena[i+j] = a[j];
}
break;
}
}
}
void codificar(char* cadena, char* codificador,char* alfabeto){
int i,j;
puts(cadena);
puts(codificador);
printf("I J Cadena Alfabeto Codificador\n");
for(i = 0; i < strlen(cadena);i++){
for(j = 0; j < strlen(alfabeto);j++){
if(cadena[i] == alfabeto[j]){
printf("%d %d %c %c %c\n", i, j, cadena[i],
alfabeto[j],codificador[j]);
cadena[i] = codificador[j];
break;
}
}
}
}
