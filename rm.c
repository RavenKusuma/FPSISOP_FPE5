#include "types.h"
#include "user.h"
#include "fcntl.h"
#include "stat.h"
#include "fs.h"


char go[512];

char* fmtname(char *path)
{
	static char buf[DIRSIZ+1];
	char *p;

	for(p=path+strlen(path); p >= path && *p != '/'; p--);
	p++;
	if(strlen(p) >= DIRSIZ)
  	return p;
	memmove(buf, p, strlen(p));
	memset(buf+strlen(p), ' ', DIRSIZ-strlen(p));
	return buf;
}


void rmrf(char *x)
{
	char buf[512], *p;
	int fd;
	struct dirent de;
	struct stat st;
	stat(x,&st);
	fd=open(x,O_RDONLY);
	if(st.type==T_FILE)
	{
		unlink(x);  
 	}

    	else if(st.type==T_DIR)
 	{
    		strcpy(buf, x);
    		p = buf+strlen(buf);
    		*p++ = '/';
   		while(read(fd, &de, sizeof(de)) == sizeof(de))
		{
      			if(de.inum == 0)
			{
       				 continue;
			}
      			memmove(p, de.name, DIRSIZ);
     			p[DIRSIZ] = 0;
      			if(stat(buf,&st)<0)
			{
				printf(1,"rm -R: file cannot be stats\n");
				continue;	
			}
      			if(st.type==1)
			{
		        	if(fmtname(buf)[0]=='.')
				{
					continue;
				}
				char new[512];
				strcpy(new,x);
				strcat(new,"/");
				strcat(new,p);
				rmrf(new);	
				unlink(new);
			}
		       	else
			{        
				char new[512];
			        strcpy(new,x);
			        strcat(new,"/");
				strcat(new,p);
			        unlink(new);
			}
		}
	}	
	close(fd);
}	



int
main(int argc, char *argv[])
{
  int i;

  if(argc < 2){
    printf(2, "Usage: rm files...\n");
    exit();
  }

  if (argc==3 && argv[1][0]=='-' && argv[1][1]=='r' && argv[1][2]=='f'){
	int fd;
	fd=open(argv[2],O_WRONLY);
	if(fd>=0){
		printf(1,"%s is a file\n", argv[3]);
		exit();	
	}
	close(fd);
	rmrf(argv[2]);
	unlink(argv[2]);
	exit();	
}
  for(i = 1; i < argc; i++){
    if(unlink(argv[i]) < 0){
      printf(2, "rm: %s failed to delete\n", argv[i]);
      break;
    }
  }

  exit();
}
