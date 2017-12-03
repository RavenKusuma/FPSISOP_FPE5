#include "user.h"
#include "stat.h"
#include "types.h"
#include "fcntl.h"


int main (int argc, int *argv[])
{
	int touch;
	if(argc<=1)
	{
		printf(2,"argumen kurang kakak\n");
		exit();
	}
	
	int i;
	for(i=0;i<argc;i++)
	{
		if(touch=open(argv[i],O_CREATE|O_RDWR))<0)
		{
			printf(2,"tidak bisa membuat %s\n",argv[1]);
			exit();
		}
	}

	exit();
}
