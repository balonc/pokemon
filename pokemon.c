#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "pokedex.h"
#include "algorithms.h"

int main(int argc, char **argv)
{

	int c;
	char *options = "-avzb:";
	
	int selectedV = 0;
	int selectedZ = 0;

	// optind, opterr, optopt, optopt, optarg
	//c = getopt(argc, argv, options);
	
	while ((c = getopt (argc, argv, options)) != -1)
	//while(c != -1) 
	{
		switch(c) 
		{
            case 'v':
                selectedV = 1;
                break;
            case 'z':
                selectedZ = 1;
                break;
            case 'b':
                printf("selected b with %s\n", optarg);
                break;
		}

		if (optarg && (strcmp(optarg,"abc") == 0))
		{
			printf("ok\n");
		}

		//c = getopt(argc, argv, options);
	}

	printf("%d - %d\n", selectedV, selectedZ);
	
    return 0;
}