#include<stdio.h>
#define max 3
/*
ZAVALA ROMAN IRVIN EDUARDO
CODIGO COLA ESTATICA VISTO EN CLASE EL 07/10/2021
*/
struct cola{
	int datos[max];
	int final, inicio;
};
void crearCola(struct cola* q){
	q->inicio = 1;
	q->final = 0;
}
int llena(struct cola q){
	if(q.final == max) return(1);
	return(0);
}
int vacia(struct cola q){
	if(q.final == 0) return(1);
	return(0);
}
void insertar(struct cola *q, int dato){
	q->datos[q->final++] = dato;
	//No necesario por el ++ en el indice de q->datos: q->final++;
}
int remover(struct cola *q){
	int x,i;
	x = q->datos[0]; //Guardamos el primer elemento en una variable aux
	for(i = 0;i < q->final-1;i++) //Se recorren los elementos
		q->datos[i] = q->datos[i+1];
	q->final--;//Se recorre el indice final
	return(x);
}

int main(){
	struct cola C;
	int num, opc;
	crearCola(&C);
	do{
		puts("1)Agregar a la cola");
		puts("2)Remover de la cola");
		puts("3)Salir");
		scanf("%d",&opc);
		
		switch(opc){
			case 1:
				if(!llena(C)){
					puts("Cual elemento quieres agregar?");
					scanf("%d",&num);
					insertar(&C,num);
					puts("Listo!");
				}
				else
					puts("La cola ya esta llena :(");
				break;
			case 2:
				if(!vacia(C)){
					printf("Listo!, se removio %d\n", remover(&C));	
				}
				else{
					puts("No quedan elementos en la cola que eliminar!");
				}
				break;
			case 3:
				puts("Nos vemos!");
				break;
		}
	}while(opc != 3);
	
}

