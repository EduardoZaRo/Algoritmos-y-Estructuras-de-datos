/* Pila2.c Pila Implementada sobre una lista con apuntadores dobles*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct nodo{
	int num;
	struct nodo *anterior;
};

int vacia(struct nodo* cima){ return (cima==NULL)? 1:0; }

void push(int dato, struct nodo **cima ){
	struct nodo * tempo;
	tempo= (struct nodo * ) malloc( sizeof(struct nodo) );
	tempo->num=dato;
	if(*cima==NULL) tempo->anterior=NULL;
	else tempo->anterior=*cima;
	*cima=tempo;
}
int pop(struct nodo ** cima){
	struct nodo *tempo;
	int regresa;
	tempo=*cima;
	regresa=(*cima)->num;
	*cima=(*cima)->anterior;
	free(tempo);
	return (regresa);
}
void main(){
	struct nodo * pila=NULL;
	char op;
	int numero;
	do{
		system("cls");
		puts("1) Push");
		puts("2) Pop");
		puts("3) Salida");
		printf("Opcion: ");op=getch();
		switch(op){
			case '1': 
				system("cls");
				printf("Numero: "); scanf("%d",&numero);
				push(numero, &pila);
				break;
			case '2': 
				system("cls");
				if ( vacia(pila) ) printf("No hay datos");
				else{ 
					numero=pop(&pila);
					printf("El numero de la cima es %d ", numero);
				}
				getch();
				break;
			case '3': 
				system("cls");
				puts("Nos vemos");
				break;
		}
	}while (op != '3');
} 
