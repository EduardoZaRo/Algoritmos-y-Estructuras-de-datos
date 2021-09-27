''''
Zavala Roman Irvin Eduardo 1270771 551
Si	los	datos	están	distribuidos	de	 forma	uniforme,	este	método	puede	ser	más	eficiente	que	la	búsqueda	binaria.	Básicamente	el	algoritmo es	el	mismo	que	el	de	la	búsqueda	binaria.	La	diferencia	radica	en	que	en	la	búsqueda	interpolada	no	se	busca	el	dato	en	el	centro	del	arreglo	sino	que	se	calcula	su	posición	aproximada.	
g = i + ((j-i)(x-A[i])/((A[j]-A[i])))
Donde i,j son los extremos
x el valor que se busca
A[] es el arreglo
'''
import math
import time
def busqueda_interpolada_recursiva(arreglo, li, ls, iteraciones, valor_buscado):
    interpolado = math.floor(li + ((ls-li)*(valor_buscado-arreglo[li])/((arreglo[ls]-arreglo[li])))) 
    iteraciones+=1
    if(li > ls or interpolado < li): #Sin (interpolado <= 0 and valor_buscado != arreglo[0]) la funcion puede ejecutarse infinitamente jaja q feo
        print("No esta ",valor_buscado," en el arreglo :(, se hicieron ",iteraciones," iteraciones")
        return -1

    print("|li = ",li,"|interpolado =",interpolado,"|ls = ",ls,"|")
    if(arreglo[interpolado] < valor_buscado):
        li = interpolado + 1
        print("Del indice ",interpolado," pa abajo no esta")
    if(arreglo[interpolado] > valor_buscado):
        ls = interpolado - 1
        print("Del indice ",interpolado," pa arriba no esta")
    if(arreglo[interpolado] == valor_buscado):
        print("Se encontro! El valor ",valor_buscado," esta en el indice ",interpolado," en un total de ",iteraciones," iteraciones!")
        return interpolado
    return busqueda_interpolada_recursiva(arreglo,li,ls,iteraciones,valor_buscado)

arreglo=arreglo=[3,6,9,12,15,18,21,24,27,30,33,36,39,41,45,48]

valor_buscado = float(input("Cual valor busca?: "))
li = 0
ls = len(arreglo)-1
iteraciones = 0

print("-------Busqueda recursiva---------")
inicio_recursivo = time.time()
indice = busqueda_interpolada_recursiva(arreglo,li,ls, iteraciones, valor_buscado)
fin_recursivo = time.time()
tiempo_ejecucion_recursivo = fin_recursivo-inicio_recursivo  
print("La funcion recursiva se ejecuto en ",tiempo_ejecucion_recursivo*1000," ms")
