#include "types.h"
#include "user.h"
#include "stat.h"
#include "fcntl.h"
#include "fs.h"

char *getFileName(char *s) 
{
	int i;
	char *temp = s;
	char *filename = s;
	for (i = strlen(temp); i >= 0; i--) 
	{
		if (temp[i] != '/'){}
		else
		{
			filename = &temp[i+1];
			break;
		}
	}

	return filename;
}



int cekDirectory(char *s) {
	struct stat x;

	int y = open(s, O_RDONLY);
	fstat(y, &x);
	int res;

	if (x.type == T_DIR) 
		res = 1;
	else
		res = 0;

	close(y);
	return res;
}


void cp_bintang(char *path);
void cp_biasa(char *sumber, char *tujuan);
	
int main (int argc, char * argv[])
{
	if(argc<=2)
	{
		printf(1,"butuh 2 argumen bro\n");
		exit();
	}

	if(!strcmp(argv[1],"*"))
	{
		cp_bintang(argv[2]);
	}
	else
	{
	cp_biasa(argv[1],argv[2]);
	}	
	exit();
}

void cp_bintang(char *path)
{
        int asdf;
	char buf[512], *a;
        struct dirent kuy;
        struct stat status;

        if((asdf = open(".", 0)) < 0)
	{
                printf(2, "cp: gabisa buka %s\n", ".");
                return;
        }

        if(fstat(asdf, &status) < 0)
	{
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
	}
        strcpy(buf, ".");
     	a = buf+strlen(buf);
	*a = '/';
        a++;
	while(read(asdf, &kuy, sizeof(kuy)) == sizeof(kuy))
                {
                        if(kuy.inum == 0 || !strcmp(kuy.name, ".") || !strcmp(kuy.name, ".."))
			{
				continue;
			}
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

        close(asdf);

}

void cp_biasa(char *sumber, char *temp)
{	
	int x=1;
        char buffer[1024];
        int in,out,i;

        if(cekDirectory(sumber))
        {
                printf(1,"tidak bisa cp\n");
                return;
        }
	
        else {
		if(x);
		char *newtemp = (char *) malloc(strlen(getFileName(sumber))+strlen(temp)+2);
		strcpy(newtemp, temp);
		if(x);
		if (cekDirectory(temp))
		{
			if (temp[strlen(temp)-1] != '/')
			{	
				if(x);
				strcat(newtemp, "/");
			}
			strcat(newtemp, getFileName(sumber));
		} 
		if(x);
		else if (temp[strlen(temp)-1] == '/') 
		{
			printf(1, "cp: %s bukan directory\n", temp);
			if(x);
			return;
		}
		
		if ((in = open(sumber, O_RDONLY)) < 0) 
		{
			if(x);
			printf(1, "cp: tidak bisa buka %s\n", sumber);
			return;
		}

		if ((out = open(newtemp, O_CREATE|O_RDWR)) < 0) 
		{
			printf(1, "cp: tidak bisa buka %s\n", temp);
			return;
			if(x);
		}

		while ((i = read(in, buffer, sizeof(buffer))) > 0) 
		{
			if(x);
			write(out, buffer, i);
		}

		close(in);
		close(out);
	}
}


