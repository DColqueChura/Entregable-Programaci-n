#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define CANT_ARCHIVOS 4

int main(){
    char *categorias[] = {
        "planetas.txt", 
        "estrellas.txt", 
        "cometas.txt", 
        "satelites.txt"
    };
    
    //Declara un array de 4 punteros (desde archivos[0] a archivos[3]) a FILE
    FILE *archivo[CANT_ARCHIVOS];

    //Bucle para abrir cada archivo
    for(int i = 0; i<CANT_ARCHIVOS; i++){
        archivo[i] = fopen(categorias[i], "r");
        
        //Manejo de errores
        if(!archivo[i]){
            //Imprime en stderr un mensaje de error.
            perror(categorias[i]);   //Ej. <nombre del archivo> “No such file or directory”
            
            //Termina inmediatamente el programa con un código de error.
            exit(EXIT_FAILURE);
        }
    }
    
    Lista_T *catego[CANT_ARCHIVOS];
    arrayPunteros(catego);
   
    //Llena las 1 listas por cada archivo. Los archivos son 4.
    archivo_A_lista(archivo, catego);

    int opcion;
    printf("\nQue categoria desea recorrer?\n");
    printf(" 0: Planetas \n 1: Estrellas \n 2: Cometas \n 3: Satelites\n");
    printf("Opcion: ");
    scanf("%d", &opcion);

    //Imprime la lista, dada una elección de la categoría = opcion
    RecorrerLista(catego[opcion]);

    
    //Bucle para cerrar los archivos
    for(int i = 0; i<CANT_ARCHIVOS; i++){
        free(catego[i]);
        fclose(archivo[i]);
    }
    return 0;
}
