#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

/* Crea una lista vacia*/
void CrearLista(Lista_T *l){
    l->primerNodo = NULL;
    l->n = 0;
}

/*  En ASCII:
*   Las letras mayúsculas van de 65 (‘A’) a 90 (‘Z’).
*   Las minúsculas van de 97 (‘a’) a 122 (‘z’).

char a_minuscula(char letra){
    if(letra >= 'A' && letra <= 'Z'){
        return( letra + ('a' - 'A'));    //97-65 = 32
    }
    return letra;
}
*/

/* Convierte en sitio toda una cadena a minúsculas */
void cadena_a_minusculas(char *s) {
    for (; *s != '\0'; ++s) {
        if (*s >= 'A' && *s <= 'Z') {
            *s += ('a' - 'A');
        }
    }
}

int rellenar_lista(Lista_T *lista, Lista_T *aux, int cantidad){
    int i, j = 0;
    char *palabra; 
    char letra;
    char letra_minuscula;

    while(cantidad-- >0){   //la primera vez verifica cantidad y en la siguiente vez resta 1
        // Leer una línea de entrada de forma segura
        if (fgets(palabra, CANT_LETRAS, stdin) == NULL) {
            break; // fin de entrada o error

        while(gets(letra) != "\0"){
            letra_minuscula = a_minuscula(letra);
            palabra[i] = letra_minuscula;

            if(i==0){
                InsertarUltimo(aux, (char *)letra_minuscula);
            }
            i++;
        }
        InsertarUltimo(lista, palabra);
        cantidad--;
    }
    return 0;
}

/*
 Inserta el dato x como último elemento de la lista l
*/
int InsertarUltimo(Lista_T *l, char *x){
    //puntero auxiliar   
    struct Nodo *p;

    //creacion del Nodo con el nuevo elemento
    struct Nodo *nuevo;      
    nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));

    if (nuevo == NULL) {
        printf("No aloca memoria \n");
        exit (-1);
    } 

    //actualizar los campos de "nuevo"   
    nuevo->dato = x;
    nuevo->sig = NULL;  // será el último Nodo de la lista!

    if (! EstaVacia(*l)){
        //puntero auxiliar apunta a la cabeza de la lista
        p = l->primerNodo;

        while (p->sig != NULL)
        {
        // mover el puntero p al próximo Nodo
    
        p = p->sig;
        }
        // p está en el ultimo Nodo, se actualiza su campo siguiente para que apunte a "nuevo"
        p->sig = nuevo;
    }
    else
        l->primerNodo = nuevo;
    //actualizacion de la cantidad de datos de la lista 
    l->n = l->n+1;

    return 0;
}
//*/

/* Retorna True = 1 si la lista está vacia, FALSE = 0 caso contrario*/
int EstaVacia(Lista_T l){
    return(l.primerNodo == NULL); 
}