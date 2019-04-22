#include<stdio.h>
#include<pthread.h>
int x=10;
pthread_attr_t tattr;
void *show(void *ptr)
{
    x--;
}
void *show2(void *ptr)
{
    x*=x;
}
int main()
{
    pthread_t t1,t2;
    int i=0;
    for(i=0;i<2;i++)
    {
    pthread_create(&t1,&tattr,show,NULL);
    pthread_create(&t2,&tattr,show2,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
}

    printf("value of shared is %d\n",x);
    printf("value of x is %d",x);
    return 0;
}