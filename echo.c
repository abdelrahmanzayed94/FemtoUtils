#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	for(int i = 1; i < argc; i++)
	{
		printf("%s ", argv[i]);
	}

	printf("\n");

	return 0;
}

