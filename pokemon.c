#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "pokedex.h"
#include "algorithms.h"

void nature(char *n, char *f, char *u)
{
	if (n)
	{
		char *fav = 0;
		char *unfav = 0;
		for (int i = 0; i < 5; i++) 
		{
			if (strcmp(natures[i].esp,n) == 0)
			{
				if (natures[i].ataque == 1.1) fav = "ataque";
				if (natures[i].defensa == 1.1) fav = "defensa";
				if (natures[i].ataqueesp == 1.1) fav = "ataque especial";
				if (natures[i].defensaesp == 1.1) fav = "defensa especial";
				if (natures[i].velocidad == 1.1) fav = "velocidad";
				if (natures[i].ataque == 0.9) unfav = "ataque";
				if (natures[i].defensa == 0.9) unfav = "defensa";
				if (natures[i].ataqueesp == 0.9) unfav = "ataque especial";
				if (natures[i].defensaesp == 0.9) unfav = "defensa especial";
				if (natures[i].velocidad == 0.9) unfav = "velocidad";
			}
		}
		if (fav && unfav) printf("Sube %s y baja %s.\n",fav,unfav);
		else printf("Naturaleza neutra.\n");
	}
	else if (f && u) printf("asdasd\n");	 
	else if (f) printf("asdasd\n");	 
	else if (u) printf("asdasd\n");	 
	else printf("asdasd\n");
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
	char *naturename = 0;
	char *statisticfavorable = 0;
	char *statisticunfavorable = 0;
	char *pokemonname = 0;
	int pokemonid = 0;
	
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