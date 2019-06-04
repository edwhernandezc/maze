#include <string.h>
#include <stdio.h>
//Representacion de datos:
//Usamos una matriz bidimensional de enteros para representar un laberinto
//Dicha matriz puede contener:
//1: que representa una pared
//2: que representa la salida
//0: que representa un espacio en blanco
//Usamos enteros para representar coordenadas, que son la posicion en la matriz (int,int)
//Ejemplo de laberinto generado:
//  000
//  011
//  020
//La "entrada" se ubica en la esquina superior izquierda
//la salida, en la ubicacion [2][1]
//Las paredes en las ubicaciones [1][1] y [1][2]
//La informacion de la ubicacion de las paredes y el objetivo se reciben de un archivo, de la manera indicada en
//"readme.txt"

//main: NONE -> int
//Lee de un archivo llamado "parametrosLab.txt" los parametros necesarios para generar el laberinto
//Almacena las cantidad de paredes pedidas en las coordenadas indicadas en el archivo
//Genera un laberinto sin paredes y las agrega si se encuentran dentro de los limites
//Coloca la salida si se encuentra dentro de las dimensiones del laberinto, caso contrario avisa su falla y genera
//un laberinto sin salida
//Escribe la matriz en el archivo "laberintogenerado.txt"
int main(){
  FILE *archivo;
  if(!(fopen("parametrosLab.txt","r")==NULL)){ //revisa si existe el archivo a leer
    int alto, ancho,finalx,finaly,cantparedes;
    archivo = fopen("parametrosLab.txt","r");
    fscanf(archivo, "%d %d", &alto, &ancho);
    fscanf(archivo, "%d %d", &finalx,&finaly);
    fscanf(archivo, "%d", &cantparedes);
    int obstaculos[alto*ancho][2];
    int paredesleidas=0;
    while (paredesleidas<cantparedes){
      fscanf(archivo, "%d %d", &obstaculos[paredesleidas][0], &obstaculos[paredesleidas][1]);
      paredesleidas++;
    }
    fclose(archivo);
    int laberinto[alto][ancho];
    for (int i=0;i<alto;i++){
      for (int j=0;j<ancho;j++){
        laberinto[i][j]=0;
      }
    }
    int x,y;
    for (int i=0;i<cantparedes;i++){
      x=obstaculos[i][0];
      y=obstaculos[i][1];
      if (x>=alto || y>=ancho){
        printf("No se pudo colocar el obstaculo en x:%d y:%d \n",x,y);
      }
      else{
        laberinto[x][y]=1;
      }
    }
    if(finalx>=alto || finaly>=ancho){
      printf("Ubicacion de la salida no valida, se genero un laberinto sin salida");
    }
    else{
      laberinto[finalx][finaly] = 2;
    }
    FILE *archivoescritura;
    archivoescritura = fopen("laberintogenerado.txt", "w+");
    for (int i=0; i<alto; i++){
      for (int j=0;j<ancho;j++){
        fprintf(archivoescritura, "%d", laberinto[i][j]);
      }
      fputs("\n",archivoescritura);
    }
    fclose(archivoescritura);
    printf("Laberinto generado con exito \n");
  }
  else{
    printf("No existe el archivo parametrosLab.txt, imposible generar el laberinto \n");
   }
  return 0;
}
