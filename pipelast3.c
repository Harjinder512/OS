#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
    char reader[20];
    int res=mkfifo("fifo1",0777);   //pipe with fifo1 name created
    if(res==0)
    {
    printf("pipe created");
    //printf("\n %d res val",res);
    }
    else printf("pipe already exists");
    //pipe has been created now anyone can write and read into the file
    res=open("fifo1",O_WRONLY);
    printf("\n The file discriptor is: %d\n",res);
    write(res,"clear",5);
    printf("File Written\t The Process Id is %d\n",getpid());
    //close(res);
    res=open("fifo1",O_RDONLY);
    read(res,reader,5);
    write(1,reader,5);

    return 0;
}