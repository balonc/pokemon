#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "pokedex.h"
#include "algorithms.h"

int main(int argc, char **argv)
{
    for (int i = 0; i < 9; i++)
    {
        if (pokemons[i].id)
        printf("%d - %s - %d %d\n", 
            pokemons[i].id, pokemons[i].nombre, 
            calculaPS(pokemons[i].baseps,0,0,100), 
            calculaStat(pokemons[i].baseataque,0,0,100,1.1)
        );
    }

	int b = calculaPrecision(100.0,0,0);
	printf("%d", b);

    return 0;
}