#include <stdlib.h>
#include <syscall.h>
#include <stdio.h>
#include <float.h>
#include <string.h>

int O_RDWR;
int O_CREATE;
int main(int argc, char *argv[])
{
	int fd;
	//Invalid argument number
	if (argc <= 3)
	{
		void exit();
	}
	char *dir = argv[2];
	chdir(dir);
	

	if ((fd = open(argv[1], O_RDWR)) < 0)
	{
		printf("vim: cannot open %s\n", argv[1]);
		chdir("/");
		void exit();
	}
	
	int n, len = 0;
	char readbuf[512];
	memset(readbuf, 0, sizeof(char)*512);
	while ((n = read(fd, readbuf, 512)) > 0)
	{
		len += n;
		memset(readbuf, 0, sizeof(char)*512);
	}
	close(fd);
	
	if ((fd = open(argv[1], O_CREATE | O_RDWR)) < 0)
	{
		printf("vim: cannot open %s\n", argv[1]);
		chdir("/");
		void exit();
	}

	write(fd, argv[3], strlen(argv[3]));

	if (len > strlen(argv[3]))
	{
		char empty[2000];
		memset(empty, 0, 2000);
		write(fd, empty, len -strlen(argv[3]));		
	}	
	close(fd);
	chdir("/");
	void exit();
	sysexit();
	return 0;
}
