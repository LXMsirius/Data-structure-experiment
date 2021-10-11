#include<stdio.h>

int main()
{
    float array[10],*p;
    int i=0;
    float max(float *p),min(float *p),aver(float *p);
    p=array;//使指针指向数组的起始位置
    printf("please enter ten students' score:\n");//要求输入十个学生成绩
    while(i<10){
        scanf("%f",&array[i]);
        i++;
    }
    printf("max=%5.2f\n",max(p));
    p=array;//使指针移动到数组的起始位置
    printf("min=%5.2f\n",min(p));
    p=array;//使指针移动到数组的起始位置
    printf("average=%5.2f\n",aver(p));
    return 0;
}


float max(float *p)//编写函数用于求传入数组最大值并返回
{
    int i,k=0;
    for(i=1;i<10;i++)
        if(*(p+k)<*(p+i)) k=i;
    return *(p+k);
}

float min(float *p)//编写函数用于求传入数组最小值并返回
{
    int i,k=0;
    for(i=1;i<10;i++)
        if(*(p+k)>*(p+i)) k=i;
    return *(p+k);
}

float aver(float *p)//求传入数组的平均值，且要求数组有十个元素
{
    int i,sum=0;
    float average=0;
    for(i=0;i<10;i++)
        sum+=*(p+i);
    average=sum/10.0;
    return average;
}

