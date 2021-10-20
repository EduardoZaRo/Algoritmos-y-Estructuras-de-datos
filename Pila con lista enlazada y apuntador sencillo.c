#include<stdio.h>
#include<stdlib.h>
struct nodo{
	int dato;
	struct nodo * ant;
};

int vacia(struct nodo *tope) { return (!tope)? 1:0; }

struct nodo * crearnodo(int dato){ 
	struct nodo* p;
	p = (struct nodo*)malloc(sizeof(p));
	p->dato=dato;
	p->ant=NULL;
	return(p);
}

struct nodo* push(struct nodo * tope,int dato){ 
	struct nodo *aux;
	aux=crearnodo(dato);
	aux->ant=tope;
	tope=aux;
	return(tope);
}
void mostrar(struct nodo *tope){ 
	struct nodo *aux;
	system("cls");
	if(!tope) printf("Esta vacia");
	else{ 
		aux=tope;
		do{
			printf("\n%d",aux->dato);
			aux=aux->ant;
		}while(aux!= NULL);
	}
	getch();
} 
struct nodo* pop(struct nodo *tope,int* valor){ 
	struct nodo *aux;
	int dato;
	aux=tope;
	*valor=tope->dato;
	tope = tope->ant;
	free(aux);
	return(tope);
}
void main(){
	struct nodo *tope = NULL;
	char opc;
	int dato,ban;
	do{ 
		system("cls");
		printf("1. Push\n2. Pop\n3. Mostrar pila\n4. Salir\nOpcion:[ ]\b\b");

		opc = getche();
		switch(opc){ 
			case '1':
				system("cls");
				printf("Escribe dato: ");
				scanf("%d",&dato);
				if(tope==NULL) tope=crearnodo(dato);
				else tope=push(tope,dato);
				break;
			case '2': 
				system("cls");
				if(!vacia(tope)) {
					tope = pop(tope,&dato);
					printf("El dato en la cima es: %d",dato);
				}
				else printf("Pila Vacia");
				getch(); 
				break;
			case '3': 
				system("cls");
				if (!vacia(tope)) mostrar(tope);
				else printf("Pila Vacia");
				getch();
				break;
			case '4': 
				system("cls");
				puts("Nos vemos");
				break;
		}
	}while(opc != '4');
} 
