/*
ZAVALA ROMAN IRVIN EDUARDO
Codigo de pila estatica visto en clase el 06/10/2021
*/
#include <stdio.h>
#include <conio.h>
#define max 3
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
int main(void) {
    struct Pila pila={0};
    int num,op;
    do{
        puts("\n1)Meter elemento");
        puts("2)Sacar elemento");
        puts("3)Tamano pila");
        puts("4)Salir");
        printf("Opcion: "); 
        scanf("%d",&op);
        
        switch(op){
            case 1:
                if(!llena(&pila)){
                    printf("\nQue dato desea ingresar: ");
                    scanf("%d",&num);
                    push(&pila,num);
                }
                else{
                    printf("\nPila llena!");
                    getch();
                }
                break;
            case 2:
                if(!vacia(&pila))
                    printf("\nSe elimino el elemento %d",pop(&pila));
                else 
                    printf("\nLa pila esta vacia");
                    getch();
                    break;
            case 3:
                printf("\nHay %d datos",pila.tope);
                getch();
                break;
            case 4:
            	printf("Nos vemos!");
                break;
                
        }
        
    }while(op!=4);
    
    return 0;
}
