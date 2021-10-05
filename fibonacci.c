#include<stdio.h>
int fibonacci(int n)
{
    if(n==0)
    {
        return 0;
    }
    else if(n==1)
    {
        return 1;
    }
    else
    {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}
int main()
{
    int sum=0;
    int n;
    scanf("%d",&n);
    sum=sum+ fibonacci(n);
    printf("\n%d\n",sum);
    return 0;
}