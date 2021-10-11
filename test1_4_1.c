#include<stdio.h>
int main()
{
    int i,n,m,sum;
    int fun(int n,int m);
    printf("请输入天数n和剩余桃子数m(n和m间用空格分开):");
    scanf("%d %d",&n,&m);
    sum=fun(n,m);
    printf("刚开始时仓库共有%d个桃子",sum);
    return 0;
}

int fun(int n,int m)
{
    if(n==0) return m;
    else return (fun(n-1,m)+1)*2;
}