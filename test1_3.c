#include<stdio.h>
int main()
{
    void hanio(int n,char x,char y,char z);
    int n;
    printf("������A�����ж��ٸ���:\n");
    scanf("%d",&n);
    hanio(n,'A','B','C');
    return 0;
}
void hanio(int n,char x,char y,char z)//��n���̴�x������y���Ƶ�z��
{
    if(n==1)
        printf("%c-->%c\n",x,z);//����ֱ�Ӵ�x�����Ƶ�z����
    else
    {
        hanio(n-1,x,z,y);//�Ƚ�����n-1��x������z���Ƶ�y��
        printf("%c-->%c\n",x,z);//��x����ʣ���һ����ֱ�ӷŵ�z����
        hanio(n-1,y,x,z);//��y���ϵ�n-1���̽���x���Ƶ�z����
    }
}