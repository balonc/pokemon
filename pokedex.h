#ifndef POKEDEX_H
#define POKEDEX_H

typedef struct {
	int id;
	char nombre[10];
	int baseps;
	int baseataque;
	int basedefensa;
	int baseataqueesp;
	int basedefensaesp;
	int basevelocidad;
} Pokemon;

typedef struct {
	int id;
	char esp[10];
	char eng[10];
	double ataque;
	double defensa;
	double ataqueesp;
	double defensaesp;
	double velocidad;
} Nature;


static Pokemon pokemons[] = {
	/*id	nombre          ps  ata def asp dsp vel*/
	{ 1,	"Bulbasaur",    45, 49, 49, 65, 65, 45 },
	{ 2,	"Ivysaur",	    60, 62, 63, 80, 80, 60 },
	{ 3,	"Venusaur",	    80, 82, 83, 100,100,80 },
	{ 4,	"Charmander",   39, 52, 43, 60, 50, 65 },
	{ 5,	"Charmeleon",   58, 64, 58, 80, 65, 80 },
	{ 6,	"Charizard",	78, 84, 78, 109,85, 100 },
	{ 7,	"Squirtle",	    44, 48, 65, 50, 64, 43 },
	{ 8,	"Wartortle",	59, 63, 80, 65, 80, 58 },
	{ 9,	"Blastoise",	79, 83, 100,85, 105,78 },
};

static Nature natures[] = {
	/*id	esp			eng  		ata 	def 	asp 	dsp 	vel*/
	{ 1,	"fuerte",	"hardy", 	1.0, 	1.0, 	1.0, 	1.0, 	1.0 },
	{ 2,	"osada",	"bold", 	0.9, 	1.1, 	1.0, 	1.0, 	1.0 },
	{ 3,	"miedosa",	"timid", 	0.9, 	1.0, 	1.1, 	1.0, 	1.0 },
	{ 4,	"modesta",	"modest", 	0.9, 	1.0, 	1.0, 	1.1, 	1.0 },
	{ 5,	"serena",	"calm", 	0.9, 	1.0, 	1.0, 	1.0, 	1.1 },
};


#endif