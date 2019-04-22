#include<stdio.h>
#include<pthread.h>
typedef struct Total
{
    float obtained;
    float total;
};
float *show(struct Total *n)
{
    float a=n->obtained;
    float b=n->total;
    float c=(a/b)*9.5;
    printf("%f",c);
    //return c;
    
}
int main()
{
    float k;
    struct Total val={90,100};
    pthread_t p1;
    pthread_create(&p1,NULL,&show,&val);
    pthread_join(p1,NULL);
    return 0;
}