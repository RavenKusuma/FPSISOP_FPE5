#include "types.h"
#include "stat.h"
#include "user.h" //ada di user
#include "fcntl.h"
#include "fs.h"

int main(int argc, char *argv[])
{
	int fd;
	if((fd = open(argv[1], 0)) < 0){
    		printf(2, "cd: cannot open %s\n", argv[1]);
		exit();
	}
	chdir(argv[1]);
	exit();
}
