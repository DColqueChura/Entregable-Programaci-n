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

    char *categorias2[] = {
        "aves.txt", 
        "mamiferos.txt", 
        "peces.txt", 
        "reptiles.txt"
    };
    
    //1.1 Elegir el tipo de categoria para trabajar 
    int tipo_categoria;
    printf("\n ****Seleccione tipo de categoria****\n");
    printf("\n0 -> Categoria Astronomica: planetas, estrellas, cometas.txt, satelites");
    printf("\n1 -> Categoria Animales: aves, mamiferos, peces, reptiles");
    printf("\nCategoria: ");
    scanf("%d", &tipo_categoria);

    //2. Declarar un array de punteros a archivo
    FILE *archivo[CANT_ARCHIVOS];

    //3. Abrir los archivos de la categoria elegida (de forma segura)
    if (tipo_categoria)
        abrirArchivos(categorias2, archivo);
    else if (tipo_categoria == 0)
        abrirArchivos(categorias, archivo);
    else {
        fprintf(stderr, "Opción inválida: %d\n", tipo_categoria);
        exit(EXIT_FAILURE);
    }
    
    //4. Declarar una lista de punteros a lista: para los archivos
    Lista_T *lista_categorias[CANT_ARCHIVOS];
    listaPunteros(lista_categorias);
   
    //5. Guarda los elementos de cada archivo a la lista. Los archivos son 4.
    llenarListas(archivo, lista_categorias);

    //6. Ordenar los elementos de cada lista
    ordenarListaConQuickSort(lista_categorias);
    
    //7. Experiencia de USUARIO
    int opcion, cantidad;
    printf("\nQue lista desea recorrer?\n");
    if(tipo_categoria)
        printf(" 0: Aves \n 1: Mamiferos \n 2: Peces \n 3: Reptiles\n");
    else
        printf(" 0: Planetas \n 1: Estrellas \n 2: Cometas \n 3: Satelites\n");
    printf("Opcion: ");
    scanf("%d", &opcion);

    int longitud = longitudLista(opcion, lista_categorias);
    if(tipo_categoria)
        printf("\nTotal de Elementos de %s -> %d\n", categorias2[opcion], longitud);
    else
        printf("\nTotal de Elementos de %s -> %d\n", categorias[opcion], longitud);
    RecorrerLista(lista_categorias[opcion]);
    
    printf("\nCuantos elementos imprimir?: \n");
    scanf("%d", &cantidad);
    if(cantidad > longitud){
        printf("La cantidad ingresada EXCEDE los elementos de la lista\n\n");  exit(-1); }

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
