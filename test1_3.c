#include<stdio.h>
int main()
{
    void hanio(int n,char x,char y,char z);
    int n;
    printf("请输入A座上有多少个盘:\n");
    scanf("%d",&n);
    hanio(n,'A','B','C');
    return 0;
}
void hanio(int n,char x,char y,char z)//将n个盘从x座借助y座移到z座
{
    if(n==1)
        printf("%c-->%c\n",x,z);//将盘直接从x座上移到z座上
    else
    {
        hanio(n-1,x,z,y);//先将上面n-1从x座借助z座移到y座
        printf("%c-->%c\n",x,z);//将x座上剩余的一个盘直接放到z座上
        hanio(n-1,y,x,z);//将y座上的n-1个盘借助x座移到z座上
    }
}