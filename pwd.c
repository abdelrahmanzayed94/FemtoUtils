#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	if(argc != 1)
	{
		printf("too many arguements\n");
		goto funcExit;
	}

	int initPathLen = 8;

	char* buf = (char *) malloc(initPathLen);
	char* result = NULL;

	while(result == NULL)
	{
		result = getcwd(buf, initPathLen);
	
		if(result == NULL && errno == ERANGE)
		{
			switch(errno)
			{
				case ERANGE:
					//printf("exceeds range \n");
					free(buf);
					initPathLen *= 2;			
					buf = (char *) malloc(initPathLen);
					break;
				case EACCES:
					printf("permission denied\n");
					break;
				default:
					printf("error number %d occured\n", errno);
					break;
			}
		}
		else
		{
			printf("%s\n", buf);
		}
	}

	free(buf);

funcExit:
	return 0;
}

