#include<stdio.h>
int main()
{
    int arr[]={1,2,3,4};
    int *p=&arr[1];
    printf("%d\n",*p);
    p+=1;
    printf("%d",*p);

}