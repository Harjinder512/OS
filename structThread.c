#include<stdio.h>
#include<pthread.h>
struct A
{
    int a;
    int b;
    int c;
};
void *show(struct A *n)
{
    //struct A *n=n1;
    printf("%d\n",n->b);
}
int main()
{
    pthread_t p1;
    struct A p2={1,2,3};
    pthread_create(&p1,NULL,&show,&p2);
    pthread_join(p1,NULL);
    return 0;
}