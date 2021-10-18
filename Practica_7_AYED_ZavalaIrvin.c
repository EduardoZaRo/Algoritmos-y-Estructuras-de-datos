/*
ZAVALA ROMAN IRVIN EDUARDO 552 1270771
La	conversión	de	un	número	en	base	decimal	a	base	binaria	
se	lleva	a	cabo	dividiendo	el	número	entre	2,	n	veces
hasta	que	ya	no	se	pueda	dividir,	el	número	en	binario	está
formado	por	 todos	 los	 residuos	 de	 las	 divisiones,	 el	
dígito	 más	 significativo	 es	 el último	 residuo obtenido	
mientras	 que	 el	 dígito	menos	 significativo	 es	 el	 residuo	 
de	 la	 primera	 división	realizada. Por	ejemplo,	 
si	el	 usuario	 desea	 convertir	el	 número	 60	 a	 binario,	 
se	 realizan divisiones	sucesivas:
60/2	=30	resta	0
30/2=15	resta	0
15/2=7 resta	1
7/2	=3 resta	1
3/2	=1 resta	1
1
El	primer	0	es	el	último	dígito	del	resultado	mientras	
que	el	residuo	de	la	última	división	es	el	primer	dígito	
del	resultado,	de	manera	que	el	equivalente	en	binario	de	60	es	111100.
Se	pide	que	implemente	un	programa	basado	en	el	principio	LIFO y	
funciones que	lea	un	número	entero	en	base	10	y	lo	convierta	a	
una	cadena	que	contenga	su	equivalente	binario.
*/
#include<stdio.h>
#import<math.h>
#define max 32

struct Pila{
    int tope;
    int dato[max];
};
typedef struct Pila tipoPila;
void push(tipoPila *pila, int x){
    pila->dato[pila->tope++] = x;
}
int pop(struct Pila *pila){
    return(pila->dato[--pila->tope]);
}
int llena(struct Pila *pila){
    if(pila->tope == max) return(1);
    else return(0);
}
int vacia(struct Pila *pila){
    if(pila->tope == 0) return(1);
    else return(0);
}
void intToBin(int entero, tipoPila *pila);
void imprimirPila(tipoPila *pila);
int pilaToString(tipoPila *pila, char* binario);
void desplazar(char* cadena, int desplazamiento);
int main(){
	struct Pila pila = {0};
	int entero;
	char binario[max+1] = "00000000000000000000000000000000"; //El caracter extra es \0
	
	puts("Ingresa un numero decimal para convertir a binario: "); scanf("%d", &entero);
	intToBin(entero, &pila);
	
    int	digitos = pilaToString(&pila, binario);
	desplazar(binario,digitos);
	printf("\nListo! %d decimal en binario es: ",entero);

	
	puts(binario);

	return 0;
}

void intToBin(int entero, tipoPila *pila){
	int listo = 0, resto = 0;
	if(entero >= 0){
		do{
			resto = entero % 2;
			entero /= 2;
			push(pila, resto);
			if(entero <= 1) listo = 1;
		}while(listo == 0);	
		push(pila, entero); 
	}
	else{
		entero = abs(entero);
		entero--;
		while(listo == 0){
		
			resto = entero % 2;
			entero /= 2;
			if(resto == 1) push(pila, 0);
			if(resto == 0) push(pila,1);
			if(entero <= 1) listo = 1;
		}	
		if(entero == 1) push(pila, 0);
		if(entero == 0) push(pila,1);
		while(!llena(pila)) push(pila,1);
	}
}

int pilaToString(tipoPila *pila, char* binario){
	int digitos = 0,i,j;
    while(!vacia(pila)){//Mientras la pila tenga elementos estos se moveran a binario como char
        *binario = pop(pila)+'0';
        binario++; digitos++;
    }
    /*El chiste de saber los digitos del numero es para desplazarlo despues, 
    Por ejemplo si convierto 12 el bucle anterior me guardaria 1100 y los 0 que ya estaban en binario
    Si desplazo la cadena a la izquiera 1100 quedarian al final de la cadena y no cuenta como
    funcion para invertir cadenas(creo)
	*/
    printf("El numero tiene %d digitos",digitos);
    return digitos;
    
}
void desplazar(char* cadena, int desplazamiento){
	int i, j;
	char a[desplazamiento];
	for(i = 0; i < desplazamiento;i++){
		a[i] = cadena[i];
	}
	for(i = 0; i < max-1;i++){
		cadena[i] = cadena[i+desplazamiento];
		if(i == max-(desplazamiento)){
			for(j = 0; j < desplazamiento;j++){
				cadena[i+j] = a[j];
			}
			break;
		}
	}
}






