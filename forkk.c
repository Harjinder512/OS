#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
	int i=0;
	if(fork())
	{
	for(i=0;i<10;i++)
	{
		printf("child %d\n",i);
	}
	}
	else
	{
		for(i=0;i<10;i++)
			printf("parent %d\n",i);
	}
	return 0;
}