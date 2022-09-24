#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char** argv)
{
	if(argc < 3)
	{
		printf("too low arguements\n");
		goto funcExit;
	}
	else if (argc > 3)
	{

		printf("too many arguements\n");	
		goto funcExit;
	}

	int result = rename(argv[1], argv[2]);

	if(result == -1)
	{
		switch(errno)
		{
			case ENOENT:
				printf("source file does not exist!!\n");
				break;
			default:
				printf("error number %d occured in moving source file\n", errno);
				break;
		}

	}

funcExit:
	return 0;
}

