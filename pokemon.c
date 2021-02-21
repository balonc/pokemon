#include <stdio.h>
#include "pokemon.h"

int main(int argc, char **argv)
{
    printf("Hola mundo pokemon\n");

    for (int i = 0; i < 150; i++)
    {
        printf("%s\n", pokemons[i].nombre);
    }

    return 0;
}