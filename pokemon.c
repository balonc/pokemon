#include <stdio.h>
#include <stdlib.h>

int calculaPS(int base, int iv, int ev, int nivel)
{
    int ps;

    ps = (((2 * base) + iv + (ev / 4)) * nivel) / 100 + nivel + 10;

    return ps;
}

int calculaStat(int base, int iv, int ev, int nivel, float nature)
{
    int stat;

    stat = (((((2 * base) + iv + (ev / 4)) * nivel) / 100) + 5) * nature;

    return stat;
}

int main(int argc, char **argv)
{
    int ps = calculaPS(25,20,0,50);
    int ata = calculaStat(20,0,0,50,1.1);

    printf("%d,%d",ps,ata);

    return 0;
}