#include "types.h"
#include "user.h"
#include "stat.h"
#include "fcntl.h"
#include "fs.h"

char *getfile(char *file)
{
	char *filename = sisop;
	char *temp = sisop;
	int i;

	for (i = strlen(temp); i >= 0; i--) {
		if (temp[i] == '/') {
			filename = &temp[i+1];
			break;
		}
	}

	return filename;
}
int main (int argc, int * argv[])
{
	int fd0,fd1,n;
	if(argc<=2)
	{
		printf(1,"butuh 2 argumen bro\n");
		exit();
	}

	if((fd0=open(argv[1],O_RDONLY))<0)
	{
		printf(1,"tidak bisa membuka %s\n",argv[1]);
		exit();
	}

	if((fd1=open(argv[2],O_CREATE|O_RDWR))<0)
	{
		printf(1,"tidak bisa membua %s\n",argv[2]);
		exit();
	}
	while((n=read(fd0,buf,sizeof(buf)))>0)
	{
		write(fd1,buf,n);
	}

	close(fd0);
	close(fd1);
	exit();
}
