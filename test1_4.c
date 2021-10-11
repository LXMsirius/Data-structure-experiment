#include<stdio.h>

int main()
{
    int i,n,m,sum;
    printf("请输入天数n和剩余桃子数m(n和m间用空格分开):");
    scanf("%d %d",&n,&m);
    sum=m;
    for(i=0;i<n;i++)
        sum=(sum+1)*2;
    printf("刚开始时仓库共有%d个桃子",sum);
    return 0;
}