'''
Irvin Eduardo Zavala Roman 1270771 gpo: 551
Búsqueda	Binaria
Este	método	requiere	que	el	arreglo	este	previamente	ordenado. La	búsqueda	binaria	funciona	de	la	siguiente manera:
1. Calcular	el	centro	de	la	lista,	con	la	fórmula	(izquierdo+derecho)/2.	Izquierdo	y	derecho	son	las	
posiciones	del	elemento	menor	y	mayor	del	vector.
2. Encontrar	el	elemento	central	del	arreglo,	la	llave	se	compara	con	el	centro	si	es	igual	aquí	termina	la búsqueda.
3. Si	no	es	igual	determinar	si	la	llave	se	encuentra	en	el	lado	izquierdo	o	derecho	de	la lista.
4. Redefinir	el	inicio	o	el	final	según	donde	ese	haya	ubicado	la	llave.	Si	la	llave	es	mayor	que	el	centro	entonces	izquierdo=centro+1.	Si	la	llave	es	menor	que	el	centro	entonces	derecho=derecho-1
5. Repetir	desde	el	primer	paso	hasta	encontrar	el	dato	o	hasta	que	ya	no	sea	posible	dividir	más.
6. Si la	llave	no	fue	encontrada	regresar	-1.
Implemente	la	búsqueda	binaria	recursiva	e	iterativa
'''
import math
import time
def busqueda_binaria_recursiva(arreglo, li, ls, iteraciones, valor_buscado):
    iteraciones+=1
    pos_mitad = math.floor((li+ls)/2) #Redondea hacia abajo
    if(li > ls):
        print("No esta ",valor_buscado," en el arreglo :(, se hicieron ",iteraciones," iteraciones")
        return -1
    print("|li = ",li,"|mitad =",pos_mitad,"|ls = ",ls,"|")
    if(arreglo[pos_mitad] < valor_buscado):
        li = pos_mitad + 1
        print("Del indice ",pos_mitad," pa abajo no esta")
    if(arreglo[pos_mitad] > valor_buscado):
        ls = pos_mitad - 1
        print("Del indice ",pos_mitad," pa arriba no esta")
    if(arreglo[pos_mitad] == valor_buscado):
        print("Se encontro! El valor ",valor_buscado," esta en el indice ",pos_mitad," en un total de ",iteraciones," iteraciones!")
        return pos_mitad

    return busqueda_binaria_recursiva(arreglo,li,ls,iteraciones,valor_buscado)


def busqueda_binaria_iterativa(arreglo, valor_buscado):
    li = 0
    ls = len(arreglo)-1
    iteraciones = 0
    while(True):
        iteraciones+=1
        pos_mitad = math.floor((li+ls)/2) #Redondea hacia abajo
        print("|li = ",li,"|mitad =",pos_mitad,"|ls = ",ls,"|")
        if(li > ls):
            print("No esta ",valor_buscado," en el arreglo :(, se hicieron ",iteraciones," iteraciones")
            return -1
        if(arreglo[pos_mitad] < valor_buscado):
            li = pos_mitad + 1
            print("Del indice ",pos_mitad," pa abajo no esta")
        if(arreglo[pos_mitad] > valor_buscado):
            ls = pos_mitad - 1
            print("Del indice ",pos_mitad," pa arriba no esta")
        if(arreglo[pos_mitad] == valor_buscado):
            print("Se encontro! El valor ",valor_buscado," esta en el indice ",pos_mitad," en un total de ",iteraciones," iteraciones!")
            return pos_mitad

    


arreglo=["11111111",'12221222','13331333','14441444','15551555','16661666','17771777','18881888','19991999','20002000','21002100','23002300']

valor_buscado = input("Cual valor busca?: ")
li = 0
ls = len(arreglo)-1
iteraciones = 0

print("-------Busqueda recursiva---------")
inicio_recursivo = time.time()
indice = busqueda_binaria_recursiva(arreglo,li,ls, iteraciones, valor_buscado)
fin_recursivo = time.time()
tiempo_ejecucion_recursivo = fin_recursivo-inicio_recursivo  
print("La funcion recursiva se ejecuto en ",tiempo_ejecucion_recursivo*1000," ms")

print("--------Busqueda iterativa-------")
inicio_iterativo = time.time()
indice = busqueda_binaria_iterativa(arreglo, valor_buscado)
fin_iterativo = time.time()
tiempo_ejecucion_iterativo = fin_iterativo-inicio_iterativo  

print("La funcion iterativa se ejecuto en ",tiempo_ejecucion_iterativo*1000," ms")
