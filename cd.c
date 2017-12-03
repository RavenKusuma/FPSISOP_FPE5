#include "type.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main (int argc, int *argv[])
{
	int coba= chdir(argv[1]);

	if(argc<=1)
	{
		printf(2,"Maaf input belum sesuai kali\n");
		exit();
	}
	
	if(coba==0)
	{
		printf(2,"gagal akses %s\n",argv[1]);
		exit();
	}
	else
		printf(1,"suskses\n");

	exit();
}
