#include "types.h"
#include "user.h"
#include "stat.h"
#include "fcntl.h"

char buf[512];

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
}
