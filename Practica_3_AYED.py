import time
'''
Zavala Roman Irvin Eduardo gpo 551 06/09/2021
Diseñe e       implemente      un      algoritmo basado        en      funciones que elimine
todos   los     elementos       repetidos       de      un      arreglo de      N       elementos      
y solo  deje    el      que     aparece primero.
'''
def eliminar_repetidos(array,final):
    contador = 0
    iteraciones = 0
    for elemento in array: #Recorro el array
        iteraciones+=1
        print("Iteracion for + 1")
        print("array[",contador,"] = ",elemento)
        if elemento not in final: #Si el elemento del arreglo no esta en final no esta repetido
            iteraciones+=1
            print("Iteracion if + 1")
            print("Procesos +1 if")
            print(array[contador], " es un elemento original")
            final.append(elemento)
        else: 
            iteraciones+=1
            print("Iteracion else + 1")
            print(array[contador], " es un elemento repetido") 
            print("Procesos +1 else")
        contador+=1
    print("En total se hicieron ",iteraciones," iteraciones")
array = ["Irvin","Eduardo","Zavala","Roman","Roman","Irvin","Irvin","Irvin","Eduardo","Amarillo"]
final = []
inicio = time.time()
eliminar_repetidos(array,final)
fin = time.time()
tiempo_ejecucion = fin-inicio    
print("El array sin valores repetidos queda:",final)
print("El tiempo de ejecucion fue de: ",tiempo_ejecucion*1000," milisegundos")
