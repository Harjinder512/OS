#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
int main()
{
    char *a="Hello 1";
    char *b="Hello 2";
    char *c="Hello 3";
    int rs,i;
    char buff[sizeof(a)];
    int pipefds[2];
    rs=pipe(pipefds);
    if (rs==-1)
    exit(1);
    write(pipefds[1],a,sizeof(a));  
    write(pipefds[1],b,sizeof(b));
    write(pipefds[1],c,sizeof(c));
    for(i=0;i<=2;i++)
    {
        read(pipefds[0],buff,sizeof(a));
        write(2,buff,sizeof(buff));
    }
    return 0;
}