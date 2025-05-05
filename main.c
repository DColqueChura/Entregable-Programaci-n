#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main(){
    char palabra[]="HOLA!";
    printf("%s\n", palabra);
    cadena_a_minusculas(palabra);
    printf("%s\n", palabra);

    return 0;
}