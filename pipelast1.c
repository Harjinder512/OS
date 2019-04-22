#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    int fd[2];
    char reader[10],reader1[10];
    int rt=pipe(fd);
    
    if(rt==-1) exit(-1);

    //reading from screen
    read(0,reader,sizeof(reader));

    //writing into pipe
    write(fd[1],reader,sizeof(reader));

    //reading from pipe
    read(fd[0],reader1,sizeof(reader1));

    //writing on screen
    write(1,reader1,sizeof(reader1));

    
    return 0;
}