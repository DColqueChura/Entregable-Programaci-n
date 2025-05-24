#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funciones.h"
#define CANT_ARCHIVOS 4

int main(){
    //1. Definir los archivos
    char *categorias[] = {
        "planetas.txt", 
        "estrellas.txt", 
        "cometas.txt", 
        "satelites.txt"
    };
    
    //2. Declarar un array de punteros a archivo
    FILE *archivo[CANT_ARCHIVOS];

    //3. Abrir todos los archivos (de forma segura)
    abrirArchivos(categorias, archivo);
    
    //4. Declarar una lista de punteros a lista: para los archivos
    Lista_T *lista_categorias[CANT_ARCHIVOS];
    listaPunteros(lista_categorias);
   
    //5. Guarda los elementos de cada archivo a la lista. Los archivos son 4.
    llenarListas(archivo, lista_categorias);
    
    //6. Ordenar los elementos de cada lista
    ordenarListaConQuickSort(lista_categorias);

    //7. Experiencia de USUARIO
    int opcion, cantidad;
    printf("\nQue categoria desea recorrer?\n");
    printf(" 0: Planetas \n 1: Estrellas \n 2: Cometas \n 3: Satelites\n");
    printf("Opcion: ");
    scanf("%d", &opcion);

    int longitud = longitudLista(opcion, lista_categorias);
    printf("\nTotal de Elementos de %s -> %d\n", categorias[opcion], longitud);
    printf("\nCuantos elementos imprimir?: \n");
    scanf("%d", &cantidad);

    Lista_T rnd;
    lista_rnd(lista_categorias[opcion], &rnd, longitud, cantidad);
    RecorrerLista(&rnd);

    //Bucle para cerrar los archivos
    for(int i = 0; i<CANT_ARCHIVOS; i++){
        free(lista_categorias[i]);
        fclose(archivo[i]);
    }

    return 0;
}
