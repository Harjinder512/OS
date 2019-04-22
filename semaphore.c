#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
int a=99;
sem_t s;
void *show1(void *pt)
{
    sem_wait(&s);
    a++;
    sleep(1);
    printf("%d\n",a);
    sem_post(&s);

}
void *show2(void *b)
{
    sem_wait(&s);
    a--;
    printf("%d",a);
    sem_post(&s);
}
int main()
{
    pthread_t p1,p2;
    sem_init(&s,1,1);
    pthread_create(&p1,NULL,show1,NULL);
    pthread_create(&p2,NULL,show2,NULL);
    pthread_join(p1,NULL);
    pthread_join(p2,NULL);
    return 0;
}