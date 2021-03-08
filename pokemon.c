#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "pokedex.h"
#include "algorithms.h"

int main(int argc, char **argv)
{

	int aflag = 0;
	int bflag = 0;
	char *cvalue = NULL;
	int index;
	int c;

	opterr = 0;

	while ((c = getopt (argc, argv, "abc:")) != -1)
		switch (c)
		{
			case 'a':
				aflag = 1;
				break;
			case 'b':
				bflag = 1;
				break;
			case 'c':
				cvalue = optarg;
				break;
			case '?':
				if (optopt == 'c')
					fprintf (stderr, "Option -%c requires an argument.\n", optopt);
				else if (isprint (optopt))
					fprintf (stderr, "Unknown option `-%c'.\n", optopt);
				else
					fprintf (stderr,
					"Unknown option character `\\x%x'.\n",
					optopt);
				return 1;
			default:
		abort ();
	}

	printf ("aflag = %d, bflag = %d, cvalue = %s\n",
		aflag, bflag, cvalue);

	for (index = optind; index < argc; index++)
		printf ("Non-option argument %s\n", argv[index]);

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