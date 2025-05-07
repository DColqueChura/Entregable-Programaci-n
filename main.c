#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(){
    char *categorias[] = {
        "planetas.txt", 
        //"estrellas.txt", 
        //"cometas.txt", 
        //"satelites.txt"
    };
    
    //Declara un array de 4 punteros (desde archivos[0] a archivos[3]) a FILE
    FILE *archivo[4];

    //Bucle para abrir cada archivo
    for(int i = 0; i<4; i++){
        archivo[i] = fopen(categorias[i], "r");
        
        //Manejo de errores
        if(!archivo[i]){
            //Imprime en stderr un mensaje de error.
            perror(categorias[i]);   //Ej. <nombre del archivo> “No such file or directory”
            
            //Termina inmediatamente el programa con un código de error.
            exit(EXIT_FAILURE);
        }
    }
    
    /*CODIGO*/
    
    //Bucle para cerrar los archivos
    for(int i = 0; i<4; i++)
        fclose(archivo[i]);
    
    return 0;
}
