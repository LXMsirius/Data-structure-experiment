#include<stdio.h>

int main()
{
    int i,n,m,sum;
    printf("����������n��ʣ��������m(n��m���ÿո�ֿ�):");
    scanf("%d %d",&n,&m);
    sum=m;
    for(i=0;i<n;i++)
        sum=(sum+1)*2;
    printf("�տ�ʼʱ�ֿ⹲��%d������",sum);
    return 0;
}