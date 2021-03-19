#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>

#include "pokedex.h"
#include "algorithms.h"

void nature(char *n, char *f, char *u, char **argv)
{
	if (n)
	{
		char *fav = 0;
		char *unfav = 0;
		for (int i = 0; i < 25; i++) 
		{
			if (strcmp(natures[i].name,n) == 0)
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
	else if (f && u)
	{
		printf("asdasd\n");
	}	 
	else if (f)
	{
		for (int i = 0; i < 25; i++) 
		{
			if (strcmp(f,"ataque") == 0) 
			{
				if (natures[i].ataque == 1.1) printf("%s\n",natures[i].name);
			}
			else if (strcmp(f,"ataqueesp") == 0) 
			{
				if (natures[i].ataqueesp == 1.1) printf("%s\n",natures[i].name);
			}
			else if (strcmp(f,"defensa") == 0) 
			{
				if (natures[i].defensa == 1.1) printf("%s\n",natures[i].name);
			}
			else if (strcmp(f,"defensaesp") == 0) 
			{
				if (natures[i].defensaesp == 1.1) printf("%s\n",natures[i].name);
			}
			else if (strcmp(f,"velocidad") == 0) 
			{
				if (natures[i].velocidad == 1.1) printf("%s\n",natures[i].name);
			}
		}
	}
	else if (u) 
	{
		for (int i = 0; i < 25; i++) 
		{
			if (strcmp(u,"ataque") == 0) 
			{
				if (natures[i].ataque == 0.9) printf("%s\n",natures[i].name);
			}
			else if (strcmp(u,"ataqueesp") == 0) 
			{
				if (natures[i].ataqueesp == 0.9) printf("%s\n",natures[i].name);
			}
			else if (strcmp(u,"defensa") == 0) 
			{
				if (natures[i].defensa == 0.9) printf("%s\n",natures[i].name);
			}
			else if (strcmp(u,"defensaesp") == 0) 
			{
				if (natures[i].defensaesp == 0.9) printf("%s\n",natures[i].name);
			}
			else if (strcmp(u,"velocidad") == 0) 
			{
				if (natures[i].velocidad == 0.9) printf("%s\n",natures[i].name);
			}
		}

	}
	else 
	{
		if (argv[2]) 
		{
			char *fav = 0;
			char *unfav = 0;
			for (int i = 0; i < 25; i++) 
			{
				if (strcmp(natures[i].name,argv[2]) == 0)
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
		else printf("Error.\n");
	}
}

void pokedex(char *p, int id)
{
	if (p)
	{
		for (int i = 0; i < 10; i++)
			if (strcmp(lowerCase(pokemons[i].name),lowerCase(p)) == 0) 
				printPokemon(pokemons[i]);
	}
	else if (id)
	{
		for (int i = 0; i < 10; i++)
			if (pokemons[i].id == id) 
				printPokemon(pokemons[i]);
	}
}

void type(char **argv)
{
	double ef;
	int x = getIdByType(argv[2]);
	int y = getIdByType(argv[3]);
	int z = 0;
	
	if (argv[2] && argv[3]) ef = efficacy(x,y);
	if (argv[4]) 
	{
		z = getIdByType(argv[4]);
		ef = ef * efficacy(x,z);
	}

	if (ef == 0) printf("No afecta.\n");
	else if (ef == 0.5) printf("Po.\n");
	else if (ef == 1.0) printf("Ta.\n");
	else if (ef == 2.0) printf("Taratatás.\n");
	else if (ef > 2.0) printf("Tatara-tatara-tatara-tás.\n");
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
			case 'n': naturename = optarg; break;
			case 'f': statisticfavorable = optarg; break;
			case 'u': statisticunfavorable = optarg; break;
			case 'p':
				if (isNumber(optarg)) pokemonid = atoi(optarg);
				else pokemonname = optarg;
		}

		if (optarg && (strcmp(optarg,"naturaleza") == 0)) mode = 1;
		else if (optarg && (strcmp(optarg,"pokedex") == 0)) mode = 2;
		else if (optarg && (strcmp(optarg,"tipo") == 0)) mode = 3;

	}

	if (mode == 1) nature(naturename, statisticfavorable, statisticunfavorable, argv);
	else if (mode == 2) pokedex(pokemonname, pokemonid);
	else if (mode == 3) type(argv);
	
    return 0;
}