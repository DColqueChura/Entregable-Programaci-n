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
    
    // 2) Crear un array de punteros a Lista_T y reservar memoria para cada lista
    Lista_T *catego[CANT_ARCHIVOS];
    for (int i = 0; i < CANT_ARCHIVOS; i++) {
        catego[i] = malloc(sizeof *catego[i]);
        if (!catego[i]) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        CrearLista(catego[i]);    // inicializa la lista vacía
    }

    int opcion = 0;

    //Llena las 1 listas por cada archivo. Los archivos son 4.
    function(archivo, catego);

    //Imprime la lista, dada una elección de la categoría = opcion
    RecorrerLista(catego[opcion]);

    
    
    //Bucle para cerrar los archivos
    for(int i = 0; i<CANT_ARCHIVOS; i++){
        free(catego[i]);
        fclose(archivo[i]);
    }
    return 0;
}
