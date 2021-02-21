typedef struct pokemon {
	int id;
	char nombre[10];
    int bps;
    int bataque;
    int bdefensa;
    int bataqueesp;
    int bdefensaesp;
    int bvelocidad;
	int peexperienciabase;
    int pepsBase;
    int peataque;
    int pedefensa;
    int pevelocidad;
    int peataqueesp;
    int pedefensaesp;
    struct pokemon* izquierdo;
    struct pokemon* derecho;
} Pokemon;

static Pokemon pokemons[150] = {
{ 1,"Bulbasaur",45,49,49,65,65,45,64,0,0,0,0,1,0 },
{ 2,"Ivysaur",60,62,63,80,80,60,141,0,0,0,0,1,1 },
{ 3,"Venusaur",80,82,83,100,100,80,208,0,0,0,0,2,1 },
{ 4,"Charmander",39,52,43,60,50,65,65,0,0,0,1,0,0 },
{ 5,"Charmeleon",58,64,58,80,65,80,142,0,0,0,1,1,0 },
{ 6,"Charizard",78,84,78,109,85,100,209,0,0,0,0,3,0 },
{ 7,"Squirtle",44,48,65,50,64,43,66,0,0,1,0,0,0 },
{ 8,"Wartortle",59,63,80,65,80,58,143,0,0,1,0,0,1 },
{ 9,"Blastoise",79,83,100,85,105,78,210,0,0,0,0,0,3 },
// { 10,"Caterpie",53,1,0,0,0,0,0 },
// { 11,"Metapod",72,0,0,2,0,0,0 },
// { 12,"Butterfree",160,0,0,0,0,2,1 },
// { 13,"Weedle",52,0,0,0,1,0,0 },
// { 14,"Kakuna",71,0,0,2,0,0,0 },
// { 15,"Beedrill",159,0,2,0,0,0,1 },
// { 16,"Pidgey",55,0,0,0,1,0,0 },
// { 17,"Pidgeotto",113,0,0,0,2,0,0 },
// { 18,"Pidgeot",172,0,0,0,3,0,0 },
// { 19,"Rattata",57,0,0,0,1,0,0 },
// { 20,"Raticate",116,0,0,0,2,0,0 },
// { 21,"Spearow",58,0,0,0,1,0,0 },
// { 22,"Fearow",162,0,0,0,2,0,0 },
// { 23,"Ekans",62,0,1,0,0,0,0 },
// { 24,"Arbok",147,0,2,0,0,0,0 },
// { 25,"Pikachu",82,0,0,0,2,0,0 },
// { 26,"Raichu",122,0,0,0,3,0,0 },
// { 27,"Sandshrew",93,0,0,1,0,0,0 },
// { 28,"Sandslash",163,0,0,2,0,0,0 },
// { 29,"Nidoran",59,1,0,0,0,0,0 },
// { 30,"Nidorina",117,2,0,0,0,0,0 },
// { 31,"Nidoqueen",194,3,0,0,0,0,0 },
// { 32,"Nidoran",60,0,1,0,0,0,0 },
// { 33,"Nidorino",118,0,2,0,0,0,0 },
// { 34,"Nidoking",195,0,3,0,0,0,0 },
// { 35,"Clefairy",68,2,0,0,0,0,0 },
// { 36,"Clefable",129,3,0,0,0,0,0 },
// { 37,"Vulpix",63,0,0,0,1,0,0 },
// { 38,"Ninetales",178,0,0,0,1,0,1 },
// { 39,"Jigglypuff",76,2,0,0,0,0,0 },
// { 40,"Wigglytuff",109,3,0,0,0,0,0 },
// { 41,"Zubat",54,0,0,0,1,0,0 },
// { 42,"Golbat",171,0,0,0,2,0,0 },
// { 43,"Oddish",78,0,0,0,0,1,0 },
// { 44,"Gloom",132,0,0,0,0,2,0 },
// { 45,"Vileplume",184,0,0,0,0,3,0 },
// { 46,"Paras",70,0,1,0,0,0,0 },
// { 47,"Parasect",128,0,2,1,0,0,0 },
// { 48,"Venonat",75,0,0,0,0,0,1 },
// { 49,"Venomoth",138,0,0,0,1,1,0 },
// { 50,"Diglett",81,0,0,0,1,0,0 },
// { 51,"Dugtrio",153,0,0,0,2,0,0 },
// { 52,"Meowth",69,0,0,0,1,0,0 },
// { 53,"Persian",148,0,0,0,2,0,0 },
// { 54,"Psyduck",80,0,0,0,0,1,0 },
// { 55,"Golduck",174,0,0,0,0,2,0 },
// { 56,"Mankey",74,0,1,0,0,0,0 },
// { 57,"Primeape",149,0,2,0,0,0,0 },
// { 58,"Growlithe",91,0,1,0,0,0,0 },
// { 59,"Arcanine",213,0,2,0,0,0,0 },
// { 60,"Poliwag",77,0,0,0,1,0,0 },
// { 61,"Poliwhirl",131,0,0,0,2,0,0 },
// { 62,"Poliwrath",185,0,0,3,0,0,0 },
// { 63,"Abra",75,0,0,0,0,1,0 },
// { 64,"Kadabra",145,0,0,0,0,2,0 },
// { 65,"Alakazam",186,0,0,0,0,3,0 },
// { 66,"Machop",75,0,1,0,0,0,0 },
// { 67,"Machoke",146,0,2,0,0,0,0 },
// { 68,"Machamp",193,0,3,0,0,0,0 },
// { 69,"Bellsprout",84,0,1,0,0,0,0 },
// { 70,"Weepinbell",151,0,2,0,0,0,0  },
};

typedef Pokemon Arbol;

// Nodo* CrearNodo(int id, char nombre[10], int bps, int) {
//     Nodo* n = (Nodo *) malloc(sizeof(Nodo));
//     n->valor = valor;
//     n->derecho = n->izquierdo = NULL;
//     return n;
// }

// void DestruirNodo(Nodo* n) {
//     n->derecho = n->izquierdo = NULL; // Por si acaso
//     free(n);
// }

// void Insertar(Nodo** arbol, int valor) {
//     if (*arbol == NULL) {
//         Nodo* n = CrearNodo(valor);
//         *arbol = n;
//     } else {
//         // Los elementos menores a la izq, los elementos
//         // mayores a la der.
//         int valorRaiz = (*arbol)->valor;
//         if (valor < valorRaiz) {
//             Insertar(&(*arbol)->izquierdo, valor);
//         } else {
//             Insertar(&(*arbol)->derecho, valor);
//         }
//     }
// }

void PreOrder(Pokemon *arbol) {
    if (arbol) {
        printf("%d,", arbol->id);
        PreOrder(arbol->izquierdo);
        PreOrder(arbol->derecho);
    }
}

void InOrder(Pokemon *arbol) {
    if (arbol) {
        InOrder(arbol->izquierdo);
        printf("%d,", arbol->id);
        InOrder(arbol->derecho);
    }
}

void PosOrder(Pokemon *arbol) {
    if (arbol) {
        PosOrder(arbol->derecho);
        PosOrder(arbol->izquierdo);
        printf("%d,", arbol->id);
    }
}

int Existe(Pokemon* arbol, int id) {
    if (!arbol) {
        return 0;
    } else if (arbol->id == id) {
       return 1;
    } else if (id < arbol->id) {
        return Existe(arbol->izquierdo, id);
    } else {
        return Existe(arbol->derecho, id);
    }
}

void DeterminarExistencia(Pokemon* arbol, int id) {
    if (Existe(arbol, id)) {
        printf("El pokemon %d existe. \n", id);
    } else {
        printf("El pokemon %d no existe. \n", id);
    }
}
