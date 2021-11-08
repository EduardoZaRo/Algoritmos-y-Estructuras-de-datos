/*
ZAVALA ROMAN IRVIN EDUARDO 1270771 551
Hacer un programa para administrar listas de reproducción de 
canciones, permite que una persona pueda tener 3 listas de 
reproducción para diferentes estados de ánimo, por ejemplo: 
triste, feliz y trabajando. Se desea que la aplicación cuente 
con las siguientes opciones:
	1) Agregar una canción a una lista
	2) Borrar canción
	3) Reproducir lista
	4) Salida
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include<math.h>
#define max 256
struct nodo{
	char titulo[max];
	char interprete[max];
	float duracion;
	struct nodo * sig;
};

struct nodo *  crearNodo();
void insertar(struct nodo **inicio,struct nodo **fin);
void reproducirLista(struct nodo *inicio);
void eliminar(struct nodo **inicio, struct nodo** fin, char const *buscando);
int elegirLista();
void insertarLista(struct nodo **inicio, struct nodo **fin);

int main(){
	struct nodo *inicio_triste=NULL;
	struct nodo  *fin_triste=NULL;
	struct nodo *inicio_feliz=NULL;
	struct nodo  *fin_feliz=NULL;
	struct nodo *inicio_trabajo=NULL;
	struct nodo  *fin_trabajo=NULL;	
	int num;
	char opc;

    do{   
		system("cls");
        printf("1. Agregar cancion a una lista\n");
        printf("2. Borrar cancion\n");
        printf("3. Reproducir lista\n");
        printf("4. Salir\n");
        printf("Opcion:[ ]\b\b");
        opc=getchar();

        switch(opc){ 
			case '1':
				system("cls");
				printf("En cual lista quieres agregar la cancion?:");
				int opc;
				opc = elegirLista();
				switch(opc){
					case 1:
						insertarLista(&inicio_triste, &fin_triste);
						break;
					case 2:
						insertarLista(&inicio_feliz, &fin_feliz);
						break;
					case 3:
						insertarLista(&inicio_trabajo, &fin_trabajo);
						break;
				}
				getch();
	            break;
            case '2':    
           		system("cls");
				printf("En cual lista quieres eliminar la cancion?:");
				int opc_1;
				opc_1 = elegirLista();
				char buscando[max];
				printf("Cual cancion quieres eliminar?: ");
				fflush(stdin);
				fgets(buscando, max, stdin); strtok(buscando, "\n"); 
				switch(opc_1){
					case 1:
						if(inicio_triste == NULL) printf("No hay elementos para borrar");
						else eliminar(&inicio_triste,&fin_triste, buscando);
						break;
					case 2:
						if(inicio_feliz == NULL) printf("No hay elementos para borrar");
						else eliminar(&inicio_feliz,&fin_feliz, buscando);
						break;
					case 3:
						if(inicio_trabajo == NULL) printf("No hay elementos para borrar");
						else eliminar(&inicio_trabajo,&fin_trabajo, buscando);
						break;
				}
				getch();
                break;
            case '3':  
		   		system("cls");  
		   		printf("Cual lista quieres reproducir?\n");
		   		int opc_2;
		   		opc_2 = elegirLista();
		   		switch(opc_2){
					case 1:
		           		if(inicio_triste == NULL){
		           			printf("No hay nada que mostrar"); getch();
						} 
					    else reproducirLista(inicio_triste); 
						break;
					case 2:
		           		if(inicio_feliz == NULL){
		           			printf("No hay nada que mostrar"); getch();
						} 
					    else reproducirLista(inicio_feliz); 
						break;
					case 3:
		           		if(inicio_trabajo == NULL){
		           			printf("No hay nada que mostrar"); getch();
						} 
					    else reproducirLista(inicio_trabajo);
						break;	
				}
			    break;
			case '4':
				printf("Nos vemos!"); break;
        }
    }while(opc!='4');
       return 0;
}
void insertarLista(struct nodo **inicio, struct nodo **fin){
	if(*inicio == NULL){
		*inicio = crearNodo();
        *fin=*inicio;
        (*inicio)->sig=*fin;
       

        (*fin)->sig=*inicio;
		printf("Primer nodo de lista creado!");
		getch();
	}
	else{
		insertar(&(*inicio), &(*fin));
	}
}
int elegirLista(){
	int opc_correcta = 0, opc;
	do{
		
		printf("\n1. Triste :(\n2. Feliz :)\n3. Trabajando\n");
		scanf("%d", &opc);
		if(opc < 1 || opc > 3){
			printf("Lista no disponible"); getch();
		} 
		else opc_correcta = 1;
		system("cls");
	}while(opc_correcta == 0);	
	return opc;
}
struct nodo *  crearNodo(){  
	struct nodo *p;
    p=(struct nodo*)malloc (sizeof (struct nodo));
	puts("Ingresa el nombre de la cancion: ");
	fflush(stdin);
	fgets(p->titulo, max, stdin); strtok(p->titulo, "\n");
	puts("Ingresa el nombre del interprete: ");
	fflush(stdin);
	fgets(p->interprete, max, stdin); strtok(p->interprete, "\n");
	puts("Cuantos segundos dura la cancion?: ");
	scanf("%f", &p->duracion);
	p->sig=NULL;
  	return(p);
}

void insertar(struct nodo **inicio, struct nodo **fin){  
	int valido = 0,opc;
	do{
		system("cls");
		printf("Donde quieres agregar el nodo? \n1.Al principio\n2.Al final\n"); 
		
		scanf("%d", &opc);
		if(opc < 1 || opc > 2){
			 printf("\nOpcion no valida!"); getch();
		}
		else valido = 1;
	}while(valido == 0);
	
	struct nodo *nuevo;
	nuevo=crearNodo();
	nuevo->sig = *inicio;
	(*fin)->sig=nuevo;
	if(opc == 1)	*inicio=nuevo;
	if(opc == 2)	*fin=nuevo;
	

	printf("Nodo agregado!");
}
void eliminar(struct nodo **inicio, struct nodo** fin, char const *buscando){  
	struct nodo *q=NULL,*p;
    p=*inicio;
    int principio = 0,encontrado = 0;
    while(q!=*fin){
        q=p;
        p=p->sig;
        if(p == *inicio && !strcmp(p->titulo,buscando)){
        	encontrado = 1;
        	break;
		} 
		if(!strcmp(p->titulo,buscando)){
			encontrado = 1;
			break;
		}
    }
    
	if(p == *inicio && encontrado == 1){
	    if (*inicio==*fin){
	       *inicio=NULL;
	       *fin=NULL;
	    }
	    else{
	        (*inicio)=(*inicio)->sig;
	        (*fin)->sig=*inicio;
	    }
	    printf("Encontrado al inicio!");
	    getch();
	    free(p);
	}
    else{
        if (p!=NULL && encontrado == 1){
            if(p==*fin){
                printf("Encontrado al final");
                fflush(stdin);
                getch();
                if (!strcmp(p->titulo,buscando)){
                    *fin=q;
                    (*fin)->sig=*inicio;
                    free(p);
                }
            }
            else{
                printf("Encontrado entre dos nodos");
                fflush(stdin);
                getch();
                q->sig=p->sig;
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
void reproducirLista(struct nodo *inicio){   
	struct nodo *aux;
    aux=inicio; 
	int salir;
    do{
		
		int i,j;
		char progreso[100];
		int barras = round(100/aux->duracion);
		char simbolo = '|';
		int segundos_barra = 0;
		for(i = 0;i < aux->duracion+1;i++){
			system("cls");
			printf("\nCancion: %s\n",aux->titulo);
			printf("\Autor: %s\n",aux->interprete);
			printf("[%-100s] Seg: %d", progreso, segundos_barra);
			for(j = 0;j < barras;j++){
				strncat(progreso, &simbolo, 1);
			}
			segundos_barra++;
			sleep(1);
		}
		progreso[0] = '\0';
		aux=aux->sig;
		system("cls");
		printf("Siguiente cancion: %s ...\nSi quiere salir presione 1:\n",aux->titulo);
		
		scanf("%d",&salir);
		if(salir == 1)printf("Saliendo...");
		else printf("Continuando...")	;	
		sleep(2);
    }while(salir != 1); 
}
