#include "type.h"
#include "stat.h"
#include "user.h"

void
rmrf(char *x)
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
			`	{
					continue;
				}
				char new[512];
				strcpy(new,x);
				strcat(new,"/");
				strcat(new,p);
				rmrf(new);	
				unlink(nec);
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
