#include<stdio.h>
int main()
{
    int i,n,m,sum;
    int fun(int n,int m);
    printf("����������n��ʣ��������m(n��m���ÿո�ֿ�):");
    scanf("%d %d",&n,&m);
    sum=fun(n,m);
    printf("�տ�ʼʱ�ֿ⹲��%d������",sum);
    return 0;
}

int fun(int n,int m)
{
    if(n==0) return m;
    else return (fun(n-1,m)+1)*2;
}