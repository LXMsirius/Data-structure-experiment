#include<stdio.h>
int main()
{
    int i,j,k,n,a[31];//创建一个数组用于存储裴波那契序列
    printf("please enter k(1~5) and n(0~30):\n");//输入k和n中间用空格分开，否则出错
    scanf("%d %d",&k,&n);
    for(i=0;i<k-1;i++)//先将数组前k项初始化
        a[i]=0;
    a[i]=1;
    for(i=k;i<=n;i++){//使用已初始化的前k项利用规律以此求出剩余项
        a[i]=0;
        for(j=1;j<=k;j++)
            a[i]=a[i]+a[i-j];
    }
    printf("f(n)=%d",a[n]);
    return 0;
}