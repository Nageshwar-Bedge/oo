// a.out
#include <stdio.h>

int main(int argc, char *argv[]) 
{
    if (argc < 2) 
	{
        fprintf(stderr, "Usage: %s <element1> <element2> ... <elementN>\n", argv[0]);
        return 1;
    }
    for (int i = 1; i < argc; i++) 
	{
        printf("Element %d: %s\n", i, argv[i]);
    }
    return 0;
}