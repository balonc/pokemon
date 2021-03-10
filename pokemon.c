#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "pokedex.h"
#include "algorithms.h"

void nature(char *n, char *f, char *u)
{
	printf("%s,%s,%s\n",n,f,u);
}

void pokedex(char *p, int id)
{
	printf("%s,%d\n",p,id);
}

int main(int argc, char **argv)
{

	int c;
	char *options = "-an:f:u:p:";
	
	int mode = 0;
	char *naturename;
	char *statisticfavorable;
	char *statisticunfavorable;
	char *pokemonname;
	int pokemonid;
	
	while ((c = getopt (argc, argv, options)) != -1)
	{
		switch(c) 
		{
			case 'n':
				naturename = optarg;
				break;
			case 'f':
				statisticfavorable = optarg;
				break;
			case 'u':
				statisticunfavorable = optarg;
				break;
			case 'p':
				if (isNumber(optarg)) pokemonid = atoi(optarg);
				else pokemonname = optarg;
		}

		if (optarg && (strcmp(optarg,"naturaleza") == 0)) mode = 1;
		else if (optarg && (strcmp(optarg,"pokedex") == 0)) mode = 2;

	}

	if (mode == 1) nature(naturename, statisticfavorable, statisticunfavorable);
	if (mode == 2) pokedex(pokemonname, pokemonid);
	
    return 0;
}