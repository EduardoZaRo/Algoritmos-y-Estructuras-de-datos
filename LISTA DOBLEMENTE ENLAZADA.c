// Codigo lista doblemente enlazada, 26/10/2021

#include<stdio.h>
#include <stdlib.h>

struct nodo
{int dato;
 struct nodo * ant;
 struct nodo * sig;
};
struct nodo *  crearNodo(int dato);
void insertar(struct nodo **inicio, struct nodo **fin, int dato);
void mostrarIzqDer(struct nodo *inicio);
void mostrarDerIzq(struct nodo *inicio);
void eliminar(struct nodo **inicio, struct nodo **fin, int);


int main(){
	struct nodo *inicio=NULL, *fin=NULL;
 	char opc;

      	do{   
		  	system("CLS");
            printf("1. Insertar en la lista\n");
            printf("2. Eliminar un elemento\n");
            printf("3. Imprimir izquierda-derecha\n");
            printf("4. Imprimir derecha izquierda \n");
            printf("5. Salir\n");
            printf("Opcion: [  ]\b\b");
            opc=getchar();
            switch(opc){ 
			case '1': 	system("CLS");
						inicio=crearNodo(50);
						fin=inicio;
						insertar(&inicio,&fin, 100);
						insertar(&inicio,&fin, 200);
						insertar(&inicio,&fin, 75);
						insertar(&inicio,&fin, 1000);
                        break;
            case '2':   system("CLS");
                        eliminar(&inicio,&fin,200);
                        break;
            case '3':   mostrarIzqDer(inicio); break;

            case '4':   mostrarDerIzq(fin); break;
            case '5':   break;
        }
    }while(opc!='5');
    return 0;
}

struct nodo *  crearNodo(int dato){  
	struct nodo *p;
	p=(struct nodo*)malloc (sizeof (struct nodo));
	p->dato=dato;
	p->sig=NULL;
	p->ant=NULL;
	return(p);
}

void insertar(struct nodo **inicio, struct nodo **fin, int num){  
	struct nodo *p, *q, *nuevo;
    p=*inicio;
    q=NULL;
    nuevo=crearNodo (num);

    while(p!=NULL && p->dato<num){      
		q=p;
        p=p->sig;
    }

    if (q==NULL){
        nuevo->sig=p;
        p->ant=nuevo;
        *inicio=nuevo;
    }
    else{   
		if (p==NULL){   
			q->sig=nuevo;
            nuevo->ant=q;
            *fin=nuevo;
        }
        else{
	        q->sig=nuevo;
	        nuevo->ant=q;
	        nuevo->sig=p;
	        p->ant=nuevo;
        }

 	}
}


void eliminar(struct nodo **inicio, struct nodo ** fin, int x){  
	struct nodo *q=NULL,*p;
    p=*inicio;
    while(p!=NULL && p->dato!=x){
        q=p;
        p=p->sig;
    }
    if (q==NULL){
        if ( *inicio==*fin){ 
			*inicio=NULL;
          	*fin=NULL;
        }
        else{
			*inicio=(*inicio)->sig;    // si es el primero
			(*inicio)->ant=NULL;
        }
        free(p);
    }
    else{
        if (p!=NULL){
	        if(p==*fin){
	            printf("Encontrado al final");
	            fflush(stdin);
	            getch();
	            if (p->dato==x)
	            {
	                *fin=p->ant;
	                (*fin)->sig=NULL;
	                free(p);
	            }
	        }
	        else{
	            printf("Encontrado entre dos nodos");
	            fflush(stdin);
	            getch();
	            q->sig=p->sig;
	            q->sig->ant = q;
	            free(p);
	        }
        }
        else{
			printf("No encontrado");
			fflush(stdin);
			getch();
        }

    }
 }
void mostrarIzqDer(struct nodo *inicio){ 
	struct nodo *aux;
    system("cls");
    if(!inicio)
    	printf("Esta vacia");
    else{ 
		aux=inicio;
        do{ 
			printf("\n%d",aux->dato);
	        aux=aux->sig;
        }while(aux  != inicio&& aux!=NULL);
    }
	getch();
}
void mostrarDerIzq(struct nodo *fin){ 
	struct nodo *aux;

    system("cls");
    if(!fin)
    	printf("Esta vacia");
    else{ 
		aux=fin;
        do{   
			printf("\n%d",aux->dato);
            aux=aux->ant;
       }while(aux!=NULL);
    }
	getch();
}
