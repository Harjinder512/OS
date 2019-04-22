#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
int main()
{
    pid_t fd[2];
    int buff;
    pipe(fd);
    if(fork()==0)
    {
        char *a="Hello";
        char *b="I am child process";
        char *c="Bye\n";
        write(fd[1],a,10);
        write(fd[1],b,10);
        write(fd[1],c,10);
    }
    else
    {
        int i;
        char buff[10];
        for(i=0;i<3;i++)
        {
            read(fd[0],buff,10);
            write(2,buff,10);
        }
        close(fd[0]);
    }
    return 0;
}