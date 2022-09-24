#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define READ_BUFF_SIZE	1024

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

	int srcFD = open(argv[1], O_RDONLY);

	if(srcFD == -1)
	{
		switch(errno)
		{
			case ENOENT:
				printf("source file does not exist!!\n");
				break;
			default:
				printf("error number %d occured in opening source file\n", errno);
				break;
		}

		goto funcExit;
	}

	int destFD = open(argv[2], O_CREAT|O_WRONLY, 0644);

	if(destFD == -1)
	{
		printf("error number %d occured in opening or creating destination file\n", errno);
		goto funcExit;
	}


	char buf[READ_BUFF_SIZE];
	int rdCount = -1, wrCount;

	while(rdCount)
	{
		rdCount = read(srcFD, buf, READ_BUFF_SIZE);
		if(rdCount == -1)
		{
			printf("error number %d occured in reading from source file\n", errno);
			goto funcExit;
		}
		
		wrCount = write(destFD, buf, rdCount);

		if(wrCount == -1)
		{
			printf("error number %d occured in writing to destination file\n", errno);
			goto funcExit;
		}
	}

funcExit:
	return 0;
}

