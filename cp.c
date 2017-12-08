#include "types.h"
#include "user.h"
#include "stat.h"
#include "fcntl.h"
#include "fs.h"

char *getfile(char *sisop)
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

void cp_biasa(char *sumber, char *tujuan)
{
	int in,out,i,n;
	char buffer[1024];
	char *filename=getfile(sumber);

	if((in=open(sumber,O_CREATE|O_RDWR))<0)
	{
		printf(1,"tidak bisa cp\n");
		exit();
	}
		
	if((out = open(tujuan,O_CREATE|O_RDWR)) < 0)
        {
                int p_tujuan = strlen(tujuan);
                int p_file=strlen(filename);

                char *point=(char*)malloc(p_tujuan+p_file+2);
                for(i=0;i<p_tujuan;i++)
                {
                        point[i]=tujuan[i];
                }
		if(point[p_tujuan-1] !='/')
		{
			point[p_tujuan]='/';
			p_tujuan++;
		}
                if ((out = open(point, O_CREATE|O_RDWR)) < 0)
                {
                        printf(1, "cp tidak bisa\n", tujuan);
                        return;
                }
        }
	
	while ((n = read(in, buffer, sizeof(buffer))) > 0)
        {
                write(out, buffer, n);
        }

        close(in);
        close(out);

}
	
int main (int argc, char * argv[])
{
	if(argc<=2)
	{
		printf(1,"butuh 2 argumen bro\n");
		exit();
	}


	cp_biasa(argv[1],argv[2]);
	exit();
}
