#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    srand(time(NULL));
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

    int dano = calculaDamage(100,410,150,450,1.5,0.5);
    printf("%d\n", dano);

    return 0;
}