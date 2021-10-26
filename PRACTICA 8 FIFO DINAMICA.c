/*
ZAVALA ROMAN IRVIN EDUARDO 551 1270771
Un	polinomio	se	puede	representar	con	una	cola.	El	primer	elemento
de	la	cola	representa	el	primer	término	del	polinomio,	el	segundo	
elemento	al	segundo	término	del	polinomio	y	así	 sucesivamente.	 
Cada	 elemento	 tiene	 como	 campos	 el	 coeficiente	 del	 
término	 y el	exponente.	Por	ejemplo,	el	polinomio	3x^4-4x^2+11
se	representa	así: [3|4,-4|2,11|0]
Cada	nodo	está formado	por	el	coeficiente,	el	exponente	y	
la	parte	de	referencia, que	no	se	muestra	en	la	figura.
Desarrolle	un	programa	para	almacenar polinomios	de	x,	
representándolos	con	una	cola.	
El	programa	debe obtener	una	tabla	de	valores	del	polinomio	
para	un	rango	proporcionado	por	el	usuario.	
El	programa	debe	tener	las	siguientes	opciones:	
	1)	Capturar	término.
	2)	Ver	polinomio.
	3)	Generar tabla de valores.	
	4)	Salir
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct nodo{
	int coeficiente;
	int exponente;
	struct nodo * sig;
};
struct nodo* crearNodo(int coeficiente, int exponente);
struct nodo* insertar(struct nodo *inicio, int coeficiente, int exponente);
void mostrar(struct nodo* inicio);
void evaluar_polinomio(struct nodo* inicio, int li, int ls);
void main(){ 
	struct nodo * inicio = NULL;
	char op;
	int coeficiente, exponente;
	do{ 
		system("cls");
		puts("1)Capturar termino\n2)Ver polinomio\n3)Generar tabla\n4)Salir");
		printf("Opcion: "); op=getch();
		switch(op){
			case '1': 
				system("cls"); 
				printf("Coeficiente: "); 
				scanf("%d",&coeficiente);
				printf("Exponente: "); 
				scanf("%d",&exponente);
				if(!inicio) inicio = crearNodo(coeficiente, exponente);
				else inicio = insertar(inicio, coeficiente, exponente);
				break;
			case '2': 
				system("cls");
				if(!inicio) puts("No hay elementos para mostrar!");
				else{ 
					system("cls"); 
					mostrar(inicio); 
				}
				op = getch();
				break;
			case '3':
				system("cls");
				int li, ls,listo = 0; 
		
				if (!inicio){
					printf("Vacia!"); getch();
				} 
				else{
					do{
						printf("Ingresa el limite inferior de la tabla: ");
						scanf("%d",&li);
						printf("Ingresa el limite superior de la tabla: ");
						scanf("%d",&ls);
						if(li >= ls) printf("Los limites no son validos :(\n");
						else listo = 1;	
					}while(listo == 0);
					evaluar_polinomio(inicio,li,ls);
				}
				
				break;
			case '4':
				system("cls");
				puts("Nos vemos!");
				break;
			default:
				system("cls");
				printf("Opcion no disponible!");
				getchar();
		}
	}while(op != '4');
} 


struct nodo* crearNodo(int coeficiente, int exponente){
	struct nodo * p;
	p = (struct nodo*) malloc(sizeof (struct nodo) );
	p->coeficiente = coeficiente;
	p->exponente = exponente;
	p->sig=NULL;
	return(p);
}
struct nodo* insertar(struct nodo *inicio, int coeficiente, int exponente){
	struct nodo * p,* nuevo, *q;
	nuevo = crearNodo(coeficiente, exponente);
	p = inicio;
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
		aux = inicio;
		int contador = 0;
		do{ 
			printf("%dx^%d", aux->coeficiente,aux->exponente);
			aux=aux->sig;
			contador--;
			if(aux != NULL) printf("+");
		}while(aux);
	}
}
void evaluar_polinomio(struct nodo* inicio, int li, int ls){
	int i, yi = 0;
	struct nodo *aux;
	printf("X  |  Y");
	for(i = li;i <= ls; i++){
		aux = inicio;
		int potencia = 0;
		printf("\n");
		printf("\n%d  |  ",i);
		do{
			potencia = pow(i, aux->exponente);
			yi += potencia*aux->coeficiente;
			printf("%d(%d)^%d", aux->coeficiente,i, aux->exponente);
			aux=aux->sig;
			if(aux != NULL) printf("+");
			else printf(" = %d",yi);
			
		}while(aux);
		yi = 0; 
	}
	getch();
}
