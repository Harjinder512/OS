#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
    int fd[2];
    char reader[20]={"hey i am reader"};
    
    //parent writes into pipe and child reads and prints it on screen [whole process happens for 2 times]
    int rd=pipe(fd);
    int check=fork();
    
        if(check==0)
        {
            printf("\nReading what parent has written\n");
            read(fd[0],reader,sizeof(reader));
            write(1,reader,sizeof(reader));
            printf("\n Reading message 2\n");
            read(fd[0],reader,8);
            write(1,reader,sizeof(reader));
        }
        else
    {
        printf("hey i am parent writing into the pipe");
        write(fd[1],reader,sizeof(reader));
        sleep(5);
        printf("writing again....");
        write(fd[1],"message2",8);
    }

    return 0;
}