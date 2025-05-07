#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT_LETRAS 20
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

void CrearLista(Lista_T *lista);

//char a_minuscula(char letra);
void cadenaAminusculas(char *s);

int EstaVacia(Lista_T lista);

int InsertarUltimo(Lista_T *l, tipoDato x);
void function(FILE *archivo[CANT_ARCHIVOS], Lista_T *lista[]);

int RecorrerLista(Lista_T *l);
