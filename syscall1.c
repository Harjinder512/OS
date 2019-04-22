#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	int fd;
	int byteR,byteW;
	char *buf=(char *)malloc(10*sizeof(char));
	int a;
	//fd=creat("myfile.txt",O_RDWR|O_EXCL);
	//close(fd);
	fd=open("myfile.txt",O_RDWR);
	byteR=read(fd,buf,10);
	byteW=write(1,buf,10);
	printf("%c",*buf);
	printf("%d  %d  %d ",fd,byteR,byteW);
	a=lseek(fd,1,SEEK_SET);
	byteR=read(fd,buf,10-1);
	byteW=write(1,buf,10-1);
	printf("%d %d ",byteR,byteW);
	printf("%d\n",a);
	return 0;
}