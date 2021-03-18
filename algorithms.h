#ifndef ALGORITHMS_H
#define ALGORITHMS_H

int calculaPS(int base, int iv, int ev, int nivel)
{
    return (((2 * base) + iv + (ev / 4)) * nivel) / 100 + nivel + 10;
}

int calculaStat(int base, int iv, int ev, int nivel, float nature)
{
    return (((((2 * base) + iv + (ev / 4)) * nivel) / 100) + 5) * nature;
}

int calculaTipoPoderOculto(int ivps, int ivata, int ivdef, int ivvel, int ivataesp, int ivdefesp)
{
    int tpo, t;

    if (ivps % 2 != 0) t++;
    if (ivata % 2 != 0) t+=2;
    if (ivdef % 2 != 0) t+=4;
    if (ivvel % 2 != 0) t+=8;
    if (ivataesp % 2 != 0) t+=16;
    if (ivdefesp % 2 != 0) t+=32;

    tpo = (t * 15) / 63;

    return tpo;
}

int calculaPotenciaPoderOculto(int ivps, int ivata, int ivdef, int ivvel, int ivataesp, int ivdefesp)
{
    int ppo, p;

    if (ivps % 4 == 2 || ivps % 4 == 3) p++;
    if (ivata % 4 == 2 || ivps % 4 == 3) p+=2;
    if (ivdef % 4 == 2 || ivps % 4 == 3) p+=4;
    if (ivvel % 4 == 2 || ivps % 4 == 3) p+=8;
    if (ivataesp % 4 == 2 || ivps % 4 == 3) p+=16;
    if (ivdefesp % 4 == 2 || ivps % 4 == 3) p+=32;

    ppo = ((p * 40) / 63) + 30;

    return ppo;
}

int calculaHuida(int a, int b, int c)
{
    /*
        a es la velocidad del pokemon que quiere huir
        b es la velocidad del oponente
        c es la cantidad de veces que el usuario ha intentado huir (comienza en 1), se 
            reinicia al usar el usuario un movimiento
    */
    srand(time(NULL));
    int mod = rand() % 50;
    int f = ((a * 128) / b + 30 * c);

    /* 1 escapa, 0 no escapa */
    if (mod < f) return 1; else return 0;
}

int calculaDamage(int n, int a, int p, int d, float b, float e)
{
    /*
        n es el nivel del atacante
        a es el nivel de ataque / ataque especial del atacante, en función del movimiento usado
        p es la potencia del movimiento
        d es la defensa / defensa especial del defensor
        b es bonificación o stab; si el movimiento es del mismo tipo que el atacante el valor es 1.5; en 
            caso contrario el valor es 1
        e es efectividad, pudiendo ser 0, 0.25, 0.5, 1, 2 y 4
        v es variación, que comprende un valor discreto entre 85 y 100 (ambos incluidos)

        el resultado es un entero que indica el número de PS que pierde el rival
    */
    srand(time(NULL));
    float v = rand() % 15 + 85;
    return 0.01 * b * e * v * ((((0.2 * n + 1) * a * p) / (25 * d)) + 2);
}

int calculaPrecision(float pb, int p, int e)
{
    /*
        pb es la precisión base del movimiento utilizado
        p es la precisión del pokemon al utilizar el movimiento, parte de 0 y se encuentra en el rango [6,-6]
        e es la evasión del rival al utilizar el movimiento, parte de 0 y se encuentra en el rango [6,-6]
    */
	float a, cp, ce;
	pb = pb / 100;

	switch(p) 
    {
		case 6: cp = pb * 3; break;
		case 5: cp = pb * 2.6; break;
		case 4: cp = pb * 2.3; break;
		case 3: cp = pb * 2; break;
		case 2: cp = pb * 1.6; break;
		case 1: cp = pb * 1.3; break;
		case 0: cp = pb * 1; break;
		case -1: cp = pb * 0.75; break;
		case -2: cp = pb * 0.6; break;
		case -3: cp = pb * 0.5; break;
		case -4: cp = pb * 0.4285; break;
		case -5: cp = pb * 0.375; break;
		case -6: cp = pb * 0.3; break;
    }

	switch(e) 
    {
		case 6: ce = pb * 0.3; break;
		case 5: ce = pb * 0.375; break;
		case 4: ce = pb * 0.4285; break;
		case 3: ce = pb * 0.5; break;
		case 2: ce = pb * 0.6; break;
		case 1: ce = pb * 0.75; break;
		case 0: ce = pb * 1; break;
		case -1: ce = pb * 1.3; break;
		case -2: ce = pb * 1.6; break;
		case -3: ce = pb * 2; break;
		case -4: ce = pb * 2.3; break;
		case -5: ce = pb * 2.6; break;
		case -6: ce = pb * 3; break;
    }

    a = pb * (cp / ce);
   
    if (a >= 1) return 1;
    else return 0;
}

int isNumber(char *s)
{
    char *p = s;
    while( *p )
    {
        if(!(*p >= 0x30 && *p <= 0x39 ) ) return 0;
        p++;
    }

    return 1;
}

char *lowerCase(char *s)
{
    for(int i = 0; s[i]; i++) s[i] = tolower(s[i]);
    return s;
}

void printPokemon(Pokemon p) 
{
    printf("(%d) Nombre:%s"
        "\nCaracterísticas base:"
        "\nPS (%d) Ata (%d) Def (%d) AtaEsp (%d) DefEsp (%d) Vel (%d)"
        "\n",
        p.id,
        p.name,
        p.bps,	
        p.bata,	
        p.bdef,	
        p.bataesp,	
        p.bdefesp,	
        p.bvel
        );
}

int getIdByType(char *type)
{
    for (int i = 0; i < 17; i++)
    {
        if (strcmp(types[i].name,type) == 0) return types[i].id;
    }
}

double efficacy(int a, int b)
{
    for (int i = 0; i < 17; i++) 
    {
        if (TypeMatrix[i][0] == a)
        {
            return TypeMatrix[i][b];
        }
    }
}

int calculaPS(int base, int iv, int ev, int nivel);
int calculaStat(int base, int iv, int ev, int nivel, float nature);
int calculaTipoPoderOculto(int ivps, int ivata, int ivdef, int ivvel, int ivataesp, int ivdefesp);
int calculaPotenciaPoderOculto(int ivps, int ivata, int ivdef, int ivvel, int ivataesp, int ivdefesp);
int calculaHuida(int a, int b, int c);
int calculaDamage(int n, int a, int p, int d, float b, float e);
int calculaPrecision(float pb, int p, int e);
int isNumber(char *s);
char *lowerCase(char *s);
void printPokemon(Pokemon p);

#endif