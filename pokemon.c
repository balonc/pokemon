#include <stdio.h>
#include <stdlib.h>
#include "pokemon.h"

int main(int argc, char **argv)
{
    printf("Hola mundo pokemon\n");

    for (int i = 0; i < 150; i++)
    {
        printf("%s\n", pokemons[i].nombre);
    }

    PosOrder(arbol);

    return 0;
}

// Árbol binario de búsqueda
// int main()
// {
//     Arbol *arbol = CrearNodo(10);
//     Insertar(&arbol, 5);
//     Insertar(&arbol, 11);
//     Insertar(&arbol, 50);
//     Insertar(&arbol, 3);
//     Insertar(&arbol, 1);
//     Insertar(&arbol, 17);
//     Insertar(&arbol, 85);
//     Insertar(&arbol, 12);
//     Insertar(&arbol, 4);
//     Insertar(&arbol, 8);

//     DeterminarExistencia(arbol, 3);
//     DeterminarExistencia(arbol, 14);
//     DeterminarExistencia(arbol, 50);

//     PreOrder(arbol);
//     printf("\n");
//     InOrder(arbol);
//     printf("\n");
//     PosOrder(arbol);
//     printf("\n");

//     return 0;
// }
