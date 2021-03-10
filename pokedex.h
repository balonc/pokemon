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
	char name[7];
	double ataque;
	double defensa;
	double ataqueesp;
	double defensaesp;
	double velocidad;
} Nature;


static Pokemon pokemons[] = {
	/*id	nombre          ps  ata def asp dsp vel*/
	{ 1,	"Bulbasaur",	45,	49,	49, 65, 65, 45 },
	{ 2,	"Ivysaur",		60,	62,	63, 80, 80, 60 },
	{ 3,	"Venusaur",		80,	82,	83, 100,100,80 },
	{ 4,	"Charmander",	39,	52,	43, 60, 50, 65 },
	{ 5,	"Charmeleon",	58,	64,	58, 80, 65, 80 },
	{ 6,	"Charizard",	78,	84,	78, 109,85, 100 },
	{ 7,	"Squirtle",		44,	48,	65, 50, 64, 43 },
	{ 8,	"Wartortle",	59,	63,	80,	65, 80, 58 },
	{ 9,	"Blastoise",	79,	83,	100,85,	105,78 },
};

static Nature natures[] = {
	/*id	name		ata 	def 	asp 	dsp 	vel*/
	{ 1,	"fuerte",	1.0, 	1.0, 	1.0, 	1.0, 	1.0 },
	{ 2,	"osada",	0.9, 	1.1, 	1.0, 	1.0, 	1.0 },
	{ 3,	"miedosa",	0.9, 	1.0, 	1.0, 	1.0, 	1.1 },
	{ 4,	"modesta",	0.9, 	1.0, 	1.1, 	1.0, 	1.0 },
	{ 5,	"serena",	0.9, 	1.0, 	1.0, 	1.1, 	1.0 },
	{ 6,	"huraña",	1.1, 	0.9, 	1.0, 	1.0, 	1.0 },
	{ 7,	"docil",	1.0, 	1.0, 	1.0, 	1.0, 	1.0 },
	{ 8,	"activa",	1.0, 	0.9, 	1.0, 	1.0, 	1.1 },
	{ 9,	"afable",	1.0, 	0.9, 	1.1, 	1.0, 	1.0 },
	{ 10,	"amable",	1.0, 	0.9, 	1.0, 	1.1, 	1.0 },
	{ 11,	"audaz",	1.1, 	1.0, 	1.0, 	1.0, 	0.9 },
	{ 12,	"placida",	1.0, 	1.1, 	1.0, 	1.0, 	0.9 },
	{ 13,	"seria",	1.0, 	1.0, 	1.0, 	1.0, 	1.0 },
	{ 14,	"mansa",	1.0, 	1.0, 	1.1, 	1.0, 	0.9 },
	{ 15,	"grosera",	1.0, 	1.0, 	1.0, 	1.1, 	0.9 },
	{ 16,	"firme",	1.1, 	1.0, 	0.9, 	1.0, 	1.0 },
	{ 17,	"agitada",	1.0, 	1.1, 	0.9, 	1.0, 	1.0 },
	{ 18,	"alegre",	1.0, 	1.0, 	0.9, 	1.0, 	1.1 },
	{ 19,	"timida",	1.0, 	1.0, 	1.0, 	1.0, 	1.0 },
	{ 20,	"cauta",	1.0, 	1.0, 	0.9, 	1.1, 	1.0 },
	{ 21,	"picara",	1.1, 	1.0, 	1.0, 	0.9, 	1.0 },
	{ 22,	"floja",	1.0, 	1.1, 	1.0, 	0.9, 	1.0 },
	{ 23,	"ingenua",	1.0, 	1.0, 	1.0, 	0.9, 	1.1 },
	{ 24,	"alocada",	1.0, 	1.0, 	1.1, 	0.9, 	1.0 },
	{ 25,	"rara",		1.0, 	1.0, 	1.0, 	1.0, 	1.0 },
};


#endif