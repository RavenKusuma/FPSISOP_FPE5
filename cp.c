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

void cp_bintang(char *path)
{
	char buf[512], *p;
	int fd;
	int ch;
	int lext=strlen(ext);
	struct dirent de;
	struct stat st;

	if((asdf = open(".", 0)) < 0){
		printf(2, "cp: cannot open %s\n", ".");
		return;
	}

	if(fstat(asdf, &status) < 0){
		printf(2, "cp: cannot stat %s\n", ".");
		close(asdf);
		return;
	}

	switch(status.type)
	{
		case T_DIR:
		if(strlen(path) + 1 + DIRSIZ + 1 > sizeof buf)
		{
			printf(1, "cp: cek pathnya lagi\n");
			break;
		}

		strcpy(buf, ".");
		a = buf+strlen(buf);
		*a = '/';
		a++;
		
		while(read(asdf, &kuy, sizeof(kuy)) == sizeof(kuy))
		{
			if(kuy.inum == 0 || !strcmp(kuy.name, ".") || !strcmp(kuy.name, ".."))
			continue;
			memmove(a, kuy.name, DIRSIZ);
			a[DIRSIZ] = 0;
			fstat(open(buf, O_RDONLY), &status);
			if (status.type == T_DIR)
			{
				printf(1, "cp:error  '%s'\n", buf);
				continue;
			}
			cp_biasa(buf, path);
		}

			break;
	}

	close(asdf);	
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

	if(strcmp(argv[1],"*"))
	{
		cp_bintang(argv[2]);
	}
	else
	{
	cp_biasa(argv[1],argv[2]);
	}	
	exit();
}
