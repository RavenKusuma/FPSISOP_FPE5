#include "types.h"
#include "user.h"
#include "stat.h"
#include "fcntl.h"

char buf[512];
void wildcard (char * path)
{
  
  int fd;
  fd =open (path,0);
  if (fd<0)
  {
    printf("cannot open path: %s\n", path);
    return; 
  }
  struct dirent looker;
  char * walker;  
  char buff_src [512];
  while (read(fd, &looker, sizeof(looker)) == sizeof(looker))
  {  
    strcpy(buff_src, path);
    if (strcmp(looker.d_name, ".") ==0 || strcmp(looker.d_name, "..") ==0)
      continue;
    
    // printf("%s %s %s\n",  buff_src, buff_dest, looker.d_name);
  
    walker= buff_src + strlen(buff_src);
    if (*walker != '/') strcat(buff_src, "/");
    // printf("%s %s %s\n",  buff_src, looker.d_name);
    strcat(buff_src, looker.d_name);
    strcat(buff_src, "\0");
    // printf("%s %s %s\n",  buff_src, buff_dest, looker.d_name);
    int test=test_dir (buff_src);
    if (test == 0)
    {
      wildcard(buff_src);
    }
    else if (test == 1)
      removethis(buff_src);
    else 
    {
      printf("rm: cannot open/stat %s\n", buff_src);
      sysexit();
    }
  }
  if(unlink(path) < 0)
  {
    printf("rm: failed to delete directory:%s\n", buff_src);
  }
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
