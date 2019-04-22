#include <stdio.h>
#include<stdlib.h>
#include <pthread.h>

void *compute(void *str)
{
	char *ptr;
	int c;
	setbuf(stdout, NULL);
	for (ptr = str; c = *ptr++; )
		putc(c, stdout);
}

int main(int argc, char *argv[]) 
{
	pthread_t thread1, thread2;

	pthread_create(&thread1, NULL, compute, "Output from thread1");
	pthread_create(&thread2, NULL, compute, "Output from thread2");

   	pthread_join( thread1, NULL);
   	pthread_join( thread2, NULL);

	exit(0);
}