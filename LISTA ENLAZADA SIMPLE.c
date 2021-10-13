/*
ZAVALA ROMAN IRVIN EDUARDO 551 1270771
CODIGO DE LISTA ENLAZADA SIMPLE VISTO EL 12/10/2021


el codigo tiene varias formas de romperse, solo es de ejemplo
bajo un uso ideal
*/
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

struct nodo{
	int dato;
	struct nodo * sig;
};
struct nodo* crearNodo(int dato){
	struct nodo * p;
	p=(struct nodo*) malloc(sizeof (struct nodo) );
	p->dato=dato;
	p->sig=NULL;
	return(p);
}
struct nodo* insertar(struct nodo *inicio, int dato){
	struct nodo * p,* nuevo, *q;
	nuevo=crearNodo(dato);
	p=inicio;
	while(p!=NULL){
		q=p;
		p=p->sig;
	}
	q->sig=nuevo;
	return(inicio);
}
void mostrar(struct nodo* inicio){
	struct nodo *aux;
	system("cls");
	if (!inicio) printf("Vacia");
	else{ 
		aux=inicio;
		do{ 
			printf("\n%d", aux->dato);
			aux=aux->sig;
		}while(aux);
	}
	getch();
}
struct nodo* borrar(struct nodo *inicio,int dato){
	struct nodo *p, *q=NULL;
	p=inicio;
	while(p->dato!=dato && p!=NULL){
		q=p;
		p=p->sig;
	}
	if(q==NULL){ 
		inicio=p->sig;
		free(p);
	}
	else
	if(p!=NULL){ 
		q->sig=p->sig;
		free(p);
	}
	else{ 
		printf("No encontrado"); getch();
	}
	return inicio;
}
void main(){ 
	struct nodo * inicio=NULL;
	char op;
	int x;
	do{ 
		system("cls");
		puts("1)Insertar\n2)Mostrar\n3)Borrar\n4)Salida");
		printf("Opcion:[ ]\b\b"); op=getch();
		switch(op){
			case '1': 
				system("cls"); printf("Dato: "); scanf("%d",&x);
				if(!inicio) inicio=crearNodo(x);
				else inicio=insertar(inicio,x);
				break;
			case '2': 
				system("cls");
				if(!inicio) puts("No hay elementos para mostrar!");
				else{ 
					system("cls"); mostrar(inicio); 
				}
				op=getch();
				break;
			case '3': 
				system("cls");
				if(!inicio) puts("No hay elementos para borrar!");
				else{ 
					system("cls"); printf("Dato: ");scanf("%d",&x);
					inicio=borrar(inicio,x); 
				}
				op=getch();

			break;
		}
	}while(op!='4');
} 
