#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "pokedex.h"
#include "algorithms.h"

int main(int argc, char **argv)
{

	int c;
	char *options = "-ab:c:d::";
	
	// optind, opterr, optopt, optopt, optarg
	c = getopt(argc, argv, options);
	
	while(c != -1) 
	{
		switch(c) {

		case 'a'  :
			printf("has seleccionado a\n");
			break;
			
		case 'b'  :
			printf("has seleccionado b con %s\n", optarg);
			break;
		}

		if (strcmp(optarg,"abc") == 0)
		{
			printf("UEEE\n");
		}

		c = getopt(argc, argv, options);
	}
	
    return 0;
}