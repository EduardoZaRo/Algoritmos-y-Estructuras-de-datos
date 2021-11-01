/*
ZAVALA ROMAN IRVIN EDUARDO 1270771 551
Un	inode	es	una	estructura	de	datos	para	
archivo	que	contiene	los	metadatos	de	un	 archivo.
Los	 datos	 de	 la	 estructura inode son:	 nombre	 del	
archivo,creador,fecha	de	creación,tamaño,nombre y extensión.	
Diseñe	e	implemente	un	programa	basado	en	listas	
doblemente	enlazadas	para administrar archivos,	
el	programa	debe	contar con	las	siguientes	opciones:	
	1)Registrar archivo
	2)Eliminar por nombre
	3)Mostrar archivos de forma ascendente
	4)Mostrar archivos de forma descendente
	5)Fuga
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define max 64
typedef struct{
	int dia;
	int mes;
	int year;
	int hora;
	int min;
	int sec;
}fecha;
struct nodo{
	char nombre[max];
	char creador[max];
	char extension[max];
	float tamano;
	struct nodo * ant;
	struct nodo * sig;
	fecha fecha_creacion;
};

struct nodo * crearNodo();
void mostrarAscendente(struct nodo *inicio);
void insertar(struct nodo **inicio, struct nodo **fin);
void eliminar(struct nodo **inicio, struct nodo ** fin, char const *buscando);
void mostrarDescendente(struct nodo *fin);



int main(){
	struct nodo *inicio=NULL, *fin=NULL;
 	char opc;

    do{   
    	system("cls");
        printf("1. Registrar archivo\n");
        printf("2. Eliminar archivo por nombre\n");
        printf("3. Imprimir archivos de forma ascendente\n");
        printf("4. Imprimir archivos de forma descendente\n");
        printf("5. Salir\n");
        printf("Opcion: ");
        opc=getchar();
        switch(opc){ 
			case '1': 	system("CLS");
						if(!inicio){
							inicio = crearNodo();
							fin = inicio;
							printf("Primer elemento creado exitosamente!");
							getch();
						}
						else{
							insertar(&inicio,&fin);
						}
	                    break;
	        case '2':
	        			system("cls");
	        			if(!inicio){printf("No hay archivos para borrar!"); getch();}
	        			else{
	        				char buscando[max];
	        				printf("Ingresa el archivo que quieres eliminar: ");
	        				fflush(stdin);
	        				fgets(buscando, max, stdin); strtok(buscando, "\n");
   							printf("Se quiere eliminar el archivo: %s\n", buscando); getch();
	        				eliminar(&inicio, &fin, buscando);
						}
						break;
        	case '3':
        				mostrarAscendente(inicio);
        				break;
        	case '4':
        				mostrarDescendente(fin);
        				break;    	
        	case '5': printf("Nos vemos!"); break;
        }
    }while(opc!='5');
       return 0;
}

struct nodo *  crearNodo(){  
	struct nodo *p;
	p = (struct nodo*)malloc (sizeof (struct nodo));
	int listo = 0;
	do{
		system("cls");
		char aux[max];
		puts("Ingresa el nombre del archivo: ");
		fflush(stdin);
		fgets(aux, max, stdin);  strtok(aux, "\n");//Al usar fgets se anade un "\n" al string ingresado, con strtok lo elimino
		if(aux[0] == '\n'){
			printf("Solo pulsaste enter >:(\n"); getch();
		} 
		else{
			strcpy(p->nombre, aux);
			listo = 1;
		}
	}while(listo == 0);

	puts("Ingresa el nombre del creador: ");
	fflush(stdin);
	fgets(p->creador, max, stdin); strtok(p->creador, "\n");
	puts("Ingresa la extension del archivo: ");
	fflush(stdin);
	fgets(p->extension, max, stdin); strtok(p->extension, "\n");
	puts("Ingresa el tamano del archivo (en KB): ");
	scanf("%f", &p->tamano);
	time_t t = time(NULL);
    struct tm fecha = *localtime(&t); 
    p->fecha_creacion.dia = fecha.tm_mday;
    p->fecha_creacion.mes = fecha.tm_mon+1;
    p->fecha_creacion.year = fecha.tm_year+1900;
    p->fecha_creacion.hora = fecha.tm_hour;
    p->fecha_creacion.min = fecha.tm_min;
    p->fecha_creacion.sec = fecha.tm_sec;
	p->sig=NULL;
	p->ant=NULL;
	return(p);
}

void insertar(struct nodo **inicio, struct nodo **fin){  
	struct nodo *p, *q, *nuevo;
    p=*inicio;
    q=NULL;
    int nombre_distinto = 0;
    do{
    	nuevo = crearNodo();
        do{ 
			if(!strcmp(p->nombre,nuevo->nombre)){
				printf("El nombre de archivo ya existe!\n");
				getch();
				break;
			}
			p=p->sig;
        }while(p != inicio&& p!=NULL);
        if(p == inicio|| p==NULL) nombre_distinto = 1;
	}while(nombre_distinto == 0);	
	p=*inicio;	
	

    while(p!=NULL && strcmp(p->nombre, nuevo->nombre) < 0){ 
		q=p;
        p=p->sig; 
    }
    if (q == NULL){
    	puts("Se inserto al inicio!");
		nuevo->sig = p;
		p->ant = nuevo;
		*inicio = nuevo;

    }
    else{   
		if (p == NULL){ 
			puts("Se inserto al final!");  
			q->sig = nuevo;
            nuevo->ant = q;
            *fin = nuevo;
        }
        else{
        	puts("Se inserto entre 2 nodos!");
	        q->sig = nuevo;
	        nuevo->ant = q;
	        nuevo->sig = p;
	        p->ant = nuevo;
        }
    }
    printf("Elemento agregado!"); getch();
}


void eliminar(struct nodo **inicio, struct nodo ** fin, char const *buscando){  
	struct nodo *q=NULL,*p;
    p=*inicio;

    while(p!=NULL && strcmp(p->nombre,buscando)){
        q=p;
        p=p->sig;
    }
    if (q==NULL){
        if ( *inicio==*fin){ 
			*inicio=NULL;
          	*fin=NULL;
        }
        else{
			*inicio=(*inicio)->sig;    
			(*inicio)->ant=NULL;
			printf("Encontrado al inicio"); getch();
        }
        free(p);
    }
    else{
        if (p!=NULL){
            if(p==*fin){
                printf("Encontrado al final");
                fflush(stdin);
                getch();
                if (!strcmp(p->nombre,buscando)){
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


void mostrarAscendente(struct nodo *inicio){ 
	struct nodo *aux;
	system("cls");
	if(!inicio){
		printf("Esta vacia");
		getch();	
	}
	else{ 
		aux=inicio;
		printf("\nNombre	|Creador	|Extension	|Tamano en KB	|Fecha	");
		do{ 
			printf("\n%s	|%s		|%s		|%f	|%d/%d/%d  %d:%d:%d",aux->nombre,aux->creador,aux->extension,aux->tamano,aux->fecha_creacion.dia,
			aux->fecha_creacion.mes, aux->fecha_creacion.year, aux->fecha_creacion.hora, aux->fecha_creacion.min, aux->fecha_creacion.sec);
			aux=aux->sig;
		}while(aux  != inicio&& aux!=NULL);
	}
	getch();
}
void mostrarDescendente(struct nodo *fin){ 
	struct nodo *aux;
	system("cls");
	if(!fin){
		printf("Esta vacia");
		getch();
	}
	else{ 
		aux=fin;
		printf("\nNombre	|Creador	|Extension	|Tamano en KB	|Fecha	");
		do{   
			printf("\n%s	|%s		|%s		|%f	|%d/%d/%d  %d:%d:%d",aux->nombre,aux->creador,aux->extension,aux->tamano,aux->fecha_creacion.dia,
			aux->fecha_creacion.mes, aux->fecha_creacion.year, aux->fecha_creacion.hora, aux->fecha_creacion.min, aux->fecha_creacion.sec);
			aux=aux->ant;
		}while(aux!=NULL);
	}
	getch();
}
