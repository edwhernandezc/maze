# Laberinto - Edwin Hernández Cabrera - 20152020013

## Representacion de datos:

Usamos una lista de listas de caracteres para representar un laberinto
Dicha matriz puede contener:
    
    "1": que representa una pared
    "2": que representa la salida
    "0": que representa un espacio en blanco
    "3": que representa una ubicacion ya visitada

## Usamos enteros para representar coordenadas, que son la posicion en el laberinto (int,int)

#### Ejemplo: 
    
    laberinto 5x5 con 5 obstaculos y salida en (3,4)
       00000
       10000
       00010
       11002
       00010

## Laberinto 

Podemos generar el laberinto con el archivo "generador.c"
en caso contrario podemos modificar el archivo directamente en laberintogenerado.txt

Asumimos que las coordenadas a colocar coinciden con las de una matriz (desde el 0 hasta el (tamaño de la matriz)-1 )
El archivo de entrada que recibe el generador se llama "parametrosLab.txt", el cual tiene la siguiente forma:
Linea 1: alto y ancho del laberinto, separados por un espacio
Linea 2: ubicacion de la salida (coordenadas x e y, separadas por un espacio)
Linea 3: cantidad de paredes a colocar
En el resto de las lineas hasta el fin del archivo se colocan (linea por linea) las coordenadas de las paredes (x e y), 
separadas por un espacio.
Se asume que el inicio se encuentra en la coordenada (0,0), por lo cual no se espera que se coloque un obstaculo alli.
Luego, el laberinto generado se guarda en el archivo "laberintogenerado.txt", en el cual cada linea
es una fila del laberinto, donde todas tienen un caracter \n al final de la linea.
Se adjunta un archivo de muestra, que genera un laberinto de tamaño 6x7 con salida en la coordenada (4,6) y 7 obstaculos
 en las posiciones (0,1),(0,5),(4,0),(4,1),(4,2),(4,3),(5,5)
 
## Función 
buscarSalida: list(list(char)) int int list() -> Bool
buscarSalida recibe un laberinto, una coordenada x, una coordenada y, y una lista vacia 
Devuelve verdadero si se encontro la salida, falso en caso contrario
Comienza buscando los casos base: Si encuentra una pared devuelve False, si enceuntra la salida devuelve True
y si encuentra una ubicacion ya visitada devuelve False
Si no sucede nada de eso, marca la ubicacion actual como visitada y comienza a buscar en otra casilla posible
en este orden: abajo-derecha-izquierda-arriba
Si encuentra la salida en alguna rama aniade la posicion actual (en forma de tupla) a la lista de posiciones
y devuelve True
Sino, busca en otra rama De no encontrar salida, devuelve False 
