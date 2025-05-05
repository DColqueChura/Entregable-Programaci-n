#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT_LETRAS 20

typedef char * tipoDato;

struct Nodo{
    tipoDato dato;
    struct Nodo *sig;    
};

typedef struct{
    int n;
    struct Nodo *primerNodo;
}Lista_T;

void CrearLista(Lista_T *l);

//char a_minuscula(char letra);
void cadena_a_minusculas(char *s);

int InsertarUltimo(Lista_T *l, tipoDato x);
int EstaVacia(Lista_T l);


