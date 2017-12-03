#include "type.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
	int i;
	if(argc<2)
	{
		printf(2,"Cara: rm filenya atau rm -r dir\n");
		exit();
	}
	
	if(strcmp(argv[1],"-r")==0 || strcmp(argv[1],"-R")==0)
	{
		if(argc !=3)
		{
			printf(2,"terlalu banyak argumen....\n");
			exit();
		}
		else
		{
			if(remove(argv[2] <0)
			{
				printf(2,"rm: %s gagal mengahpus folder");
				exit();
			}
		}
	}
	else
	{
		int j;
		for(i=0;i<argc;i++)
		{
			if(unlink(argv[i])<0)
			{
				printf(2,"rm:%s failed to delete\n",argv[i]);
				exit();
			}
		}

	}
	
	exit();
}
