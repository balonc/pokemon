#include <stdio.h>
#include <stdlib.h>

int calculaPS(int base, int iv, int ev, int nivel)
{
    return (((2 * base) + iv + (ev / 4)) * nivel) / 100 + nivel + 10;
}

int calculaStat(int base, int iv, int ev, int nivel, float nature)
{
    return (((((2 * base) + iv + (ev / 4)) * nivel) / 100) + 5) * nature;
}

int calculaHuida(int a, int b, int c)
{
    /*
        a es la velocidad del pokemon que quiere huir
        b es la velocidad del oponente
        c es la cantidad de veces que el usuario ha intentado huir (comienza en 1), se 
            reinicia al usar el usuario un movimiento
    */
    time_t t;
    srand((unsigned) time(&t));
    int mod = rand() % 50;
    int f = ((a * 128) / b + 30 * c);

    /* 1 escapa, 0 no escapa */
    if (mod < f) 
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(int argc, char **argv)
{
    int ps = calculaPS(25,20,0,50);
    int ata = calculaStat(105,5,252,100,0.9);

    printf("%d,%d\n",ps,ata);

    if (calculaHuida(10, 100, 1))
    {
        printf("Huye\n");
    }
    else 
    {
        printf("No huye\n");
    }

    return 0;
}