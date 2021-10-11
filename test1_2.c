#include<stdio.h>

int main()
{
    int n,k,f_n;
    int Fibonacci(int x,int y);   
    // int *p=a;
    printf("please enter k(1~5) and n(0~30):\n");
    scanf("%d %d",&k,&n);
    // for(i=0;i<k-1;i++)
        // a[i]=0;
    // a[i]=1;
    f_n=Fibonacci(k,n);
    printf("f(n)=%d\n",f_n);
    return 0;
}
// int sum=0;
int Fibonacci(int x,int y)
{
    int i,sum=0;
    if(y<x) return 0;
    else if(y==x) return 1;
    else
        return 2*Fibonacci(x,y-1)-Fibonacci(x,y-x-1);
}