#include<stdio.h>
#include<pthread.h>
pthread_mutex_t l;

void *show(char *a)
{
    int i;
    pthread_mutex_lock(&l);
    for(i=0;i<17;i++)
    {
    printf("%c",*a);
    a++;
    }
    pthread_mutex_unlock(&l);
}
void *show1(char *b)
{
    pthread_mutex_lock(&l);
    int i;
    for(i=0;i<17;i++)
    {
    printf("%c",*b);
    b++;
    }
    pthread_mutex_unlock(&l);
    }
int main()
{
    pthread_mutex_init(&l,NULL);
    pthread_t t1,t2;
    pthread_create(&t1,NULL,show,"this is char abcd");
    pthread_create(&t2,NULL,show1,"Second file output");
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    return 0; 
}