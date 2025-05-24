#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define CANT_ARCHIVOS 4

typedef char * tipoDato;

struct Nodo{
    tipoDato dato;
    struct Nodo *sig;    
};

typedef struct{
    int cantidad;
    struct Nodo *primerNodo;
}Lista_T;

/* Retorna True = 1 si la lista está vacia, FALSE = 0 caso contrario */
int EstaVacia(Lista_T *lista);

/* Inserta el dato x como último elemento de la lista l*/
int InsertarUltimo(Lista_T *l, tipoDato x);

/* Recorre la lista imprimiento por pantalla cada dato */
void RecorrerLista(Lista_T *l);

/* Abre los archivos */
void abrirArchivos(char **categorias, FILE *archivo[CANT_ARCHIVOS]);

/* Crea un array de punteros a Lista_T y reservar memoria para cada lista */
Lista_T listaPunteros(Lista_T **lista);

/* Guarda los elementos en la lista de listas */
void llenarListas(FILE *archivo[CANT_ARCHIVOS], Lista_T **lista);

/* Array con la Longitud de cada lista */
int longitudLista(int indice, Lista_T **lista);

/* Ordenar los elementos de cada lista */
void ordenarListaConQuickSort(Lista_T **lista);

// inicializa elementos en posiciones random en una lista
void lista_rnd(Lista_T *lista, Lista_T *rnd, int total, int cantidad);
