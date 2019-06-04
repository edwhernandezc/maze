def buscarSalida(laberinto,x,y,listapos):
    if laberinto[x][y]=="1": #encontre una pared
        return False
    elif laberinto[x][y]=="2": #encontre la salida
        listapos.append((x,y))
        return True
    elif laberinto[x][y]=="3": #encontre una ubicacion que ya visite
        return False
    laberinto[x][y]="3" #marco la ubicacion como visitada
    if x < len(laberinto)-1:
        if (buscarSalida(laberinto,x+1,y,listapos)):
            listapos.append((x,y))
            return True
    if y < len(laberinto[x])-2: #tomo en cuenta el caracter '\n'
        if (buscarSalida(laberinto,x,y+1,listapos)):
            listapos.append((x,y))
            return True
    if  x > 0:
        if (buscarSalida(laberinto,x-1,y,listapos)):
            listapos.append((x,y))
            return True
    if y > 0:
        if (buscarSalida(laberinto,x,y-1,listapos)):
            listapos.append((x,y))
            return True
    return False

def test_buscarSalida():
    assert buscarSalida([["0","0","1"],["2","1","0"],["1","1","0"]],1,0,[])==True
    assert buscarSalida([["0","0","1"],["2","1","0"],["1","1","0"]],0,2,[])==False
    assert buscarSalida([["0","0","1"],["0","0","2"],["3","1","0"]],1,0,[])==False
    assert buscarSalida([["1","1","1"],["1","0","1"],["1","1","1"]],1,1,[])==False

def main():
    laberinto=[]
    archivo=open("laberintogenerado.txt","r")
    laberinto = archivo.readlines()
    archivo.close()
    for i in range(len(laberinto)):
        # laberinto[i]=laberinto[i][0:100]
        laberinto[i]=list(laberinto[i])
    posiciones=[]
    resolucion = buscarSalida(laberinto,0,0,posiciones)
    posiciones.reverse()
    if (len(posiciones)==0):
        print("No se pudo encontrar el camino hacia el objetivo")
    else:
        print("Posiciones a seguir para resolver el laberinto:\n" + str(posiciones))
main()