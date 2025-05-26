#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funciones.h"
#define CANT_ARCHIVOS 4

/* Crea una lista vacia*/
void crearLista(Lista_T *l){
    l->primerNodo = NULL;
    l->cantidad = 0;
}

/*  En ASCII:
*   Las letras mayúsculas van de 65 (‘A’) a 90 (‘Z’).
*   Las minúsculas van de 97 (‘a’) a 122 (‘z’).
*/
// Convierte en sitio toda una cadena a minúsculas 
void cadenaAminusculas(char *s) {
    for (; *s != '\0'; ++s) {
        if (*s >= 'A' && *s <= 'Z') {
            *s += ('a' - 'A');  
        }
    }
}

/********FUNCIONES PRINCIPALES***********/

/* Retorna True = 1 si la lista está vacia, FALSE = 0 caso contrario */
int EstaVacia(Lista_T *lista){
    return(lista->primerNodo == NULL);
}

/* Inserta el dato x como último elemento de la lista l*/
int InsertarUltimo(Lista_T *l, tipoDato x){
    //puntero auxiliar   
    struct Nodo *p;

    //creacion del nodo con el nuevo elemento
    struct Nodo *nuevo;      
    nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) { printf("No aloca memoria");  exit (-1); } 

    nuevo->dato = malloc(strlen(x) + 1);
    if (!nuevo->dato){ perror("malloc");  exit(EXIT_FAILURE);  }

    cadenaAminusculas(x);
    strcpy(nuevo->dato, x); //copia en el nuevo nodo, el dato que queremos ingresar

    nuevo->sig = NULL;  // será el último nodo de la lista!

    if (!EstaVacia(l)){
        //puntero auxiliar apunta a la cabeza de la lista
        p = l->primerNodo;

        while (p->sig != NULL){
            p = p->sig;
        }
        // p está en el ultimo nodo, se actualiza su campo siguiente para que apunte a "nuevo"
        p->sig = nuevo;
    }
    else
        l->primerNodo = nuevo;
    
    l->cantidad++;

    return 0;
}

/* Recorre la lista imprimiento por pantalla cada dato */
void RecorrerLista(Lista_T *l){
    struct Nodo *p;
    int indice = 0;

    if(!EstaVacia(l)){
        // ahora l es puntero a Lista_T
        p = l->primerNodo;  

        while (p != NULL){
            // imprime el dato y mueve el puntero p
            printf("[%d] %s \n",indice, p->dato);
            indice++;
            p = p->sig;
        }
    }
    printf("\n");
}

/* Abre los archivos */
void abrirArchivos(char **categorias, FILE *archivo[CANT_ARCHIVOS]){
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
}

/* Crea un array de punteros a Lista_T y reservar memoria para cada lista */
Lista_T listaPunteros(Lista_T **lista){
    for (int i = 0; i < CANT_ARCHIVOS; i++) {

        Lista_T *aux = malloc(sizeof(Lista_T));
        if (!aux) { perror("malloc");  exit(EXIT_FAILURE); }
        
        crearLista(aux);    // inicializa la lista vacía
        lista[i] = aux;
    }
}

/* Guarda los elementos en la lista de listas */
void llenarListas(FILE *archivo[CANT_ARCHIVOS], Lista_T **lista){
    int i=0;
    int cantidad = 0;
    char cadena[15];

    for(int i=0; i<CANT_ARCHIVOS; i++){
        while(fscanf(archivo[i], "%s", cadena) == 1){
            InsertarUltimo(lista[i], cadena);
            cantidad++;
        }
    }
}

/* Array con la Longitud de cada lista */
int longitudLista(int indice, Lista_T **lista){
    return lista[indice]->cantidad;
}

// Comparador para qsort
static int cmpStrings(const void *a, const void *b) {
    const char * const *pa = a;
    const char * const *pb = b;
    return strcmp(*pa, *pb);
}

/* Ordenar los elementos de cada lista */
void ordenarListaConQuickSort(Lista_T **lista){
    for(int i = 0; i<CANT_ARCHIVOS; i++){   

        // Ordena la lista en orden alfabético completo
        int n = lista[i]->cantidad;
        if (n < 2) return;

        // 1) Volcar punteros a palabra en array
        char **arr = malloc(n * sizeof(char*));
        if (!arr) { perror("malloc"); exit(EXIT_FAILURE); }
        
        struct Nodo *p = lista[i]->primerNodo;
        for (int i = 0; i < n; i++, p = p->sig) {
            arr[i] = p->dato;
        }
        
        // 2) Ordenar el array de char* con qsort + strcmp
        qsort(arr, n, sizeof(char*), cmpStrings);

        // 3) Reasignar los punteros ordenados de vuelta en la lista
        p = lista[i]->primerNodo;
        for (int i = 0; i < n; i++, p = p->sig) {
            p->dato = arr[i];
        }

        free(arr);
        
    }
}

// Baraja un array de punteros a char con Fisher–Yates
static void shuffle(char **arr, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char *tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

// inicializa elementos en posiciones random en una lista
void lista_rnd(Lista_T *lista, Lista_T *rnd, int total, int cantidad) { 
    if (cantidad <= 0)  
        return;

    // 1) Volcar datos en un array
    char **arr = malloc(total * sizeof(char*));
    if (!arr) { perror("malloc"); exit(EXIT_FAILURE); }

    struct Nodo *p = lista->primerNodo;
    for (int i = 0; i < total; i++) {
        arr[i] = p->dato;
        p = p->sig;
    }

    // 2) Barajar el array
    srand((unsigned)time(NULL));
    shuffle(arr, total);

    // 3) Inicializar lista destino y volcar datos barajados
    crearLista(rnd);
    for (int i = 0; i < cantidad; i++) {
        InsertarUltimo(rnd, arr[i]);
    }

    free(arr);
}
