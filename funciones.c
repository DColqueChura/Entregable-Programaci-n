#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define CANT_ARCHIVOS 4

/* Crea una lista vacia*/
void CrearLista(Lista_T *l){
    l->primerNodo = NULL;
    l->cantidad = 0;
}

/*  En ASCII:
*   Las letras mayúsculas van de 65 (‘A’) a 90 (‘Z’).
*   Las minúsculas van de 97 (‘a’) a 122 (‘z’).

/* Convierte en sitio toda una cadena a minúsculas 
void cadenaAminusculas(char *s) {
    for (; *s != '\0'; ++s) {
        if (*s >= 'A' && *s <= 'Z') {
            *s += ('a' - 'A');
        }
    }
}
*/

/* Retorna True = 1 si la lista está vacia, FALSE = 0 caso contrario*/
int EstaVacia(Lista_T lista){
    return(lista.primerNodo == NULL);
}

/* Inserta el dato x como último elemento de la lista l*/
int InsertarUltimo(Lista_T *l, tipoDato x){
    //puntero auxiliar   
    struct Nodo *p;

    //creacion del nodo con el nuevo elemento
    struct Nodo *nuevo;      
    nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));

    if (nuevo == NULL) {
        printf("No aloca memoria");
        exit (-1);
    } 

    //actualizar los campos de "nuevo"   
    nuevo->dato = x;
    nuevo->sig = NULL;  // será el último nodo de la lista!

    if (! EstaVacia(*l)){
        //puntero auxiliar apunta a la cabeza de la lista
        p = l->primerNodo;

        while (p->sig != NULL)
        {
        // mover el puntero p al próximo nodo
        p = p->sig;
        }
        // p está en el ultimo nodo, se actualiza su campo siguiente para que apunte a "nuevo"
        p->sig = nuevo;
    }
    else
        l->primerNodo = nuevo;
    //actualizacion de la cantidad de datos de la lista 
    l->cantidad = l->cantidad+1;

    return 0;
}

void function(FILE *archivo[CANT_ARCHIVOS], Lista_T *lista[]){
    int i=0;
    int cantidad = 0;
    char cadena[15];

    for(int i=0; i<CANT_ARCHIVOS; i++){
        while(archivo[i]){
            fscanf(archivo[i], "%s", cadena);
            InsertarUltimo(lista[i], cadena);
            cantidad++;
        }
    }
}

/* Recorre la lista imprimiento por pantalla cada dato */
int RecorrerLista(Lista_T *l){
    struct Nodo *p;

    if(!EstaVacia(*l)){
        // p apunta al primer elemento de la lista
        p = l->primerNodo;

        while (p != NULL){
            // imprime el dato y mueve el puntero p
            printf(" %s ",p->dato);
            p = p->sig;
        }
    }

    printf("\n");
    return 0;
}
