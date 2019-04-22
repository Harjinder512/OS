#include<stdio.h>
#include<pthread.h>
void *show(int n)
{
    printf("%d\n",n);
}
int main()
{
    int i;
    pthread_t p1;
    for(i=0;i<20;i++)
    {
    pthread_create(&p1,NULL,&show,i);
    }
    pthread_join(p1,NULL);
}