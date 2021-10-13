#include<stdio.h>
#include<stdlib.h>

typedef struct Num_score//������һ���ṹ�����ڴ���ÿ��ѧ����ѧ�š����Ƴɼ����ܷ֡���Ȩƽ���֣���ȡ��һ������student
{
    int Num;
    int score[3];
    int sum;
    float aver;
} student;

void Input_score(int *p,student *stu){//��������ѧ����Ϣ
    int i;
    for(i=0;i<*p;i++){
        printf("�����������%d��ѧ����ѧ�ţ����ģ���ѧ��Ӣ��ɼ����ÿո�ֿ�����",i+1);
        scanf("%d %d %d %d",&(stu+i)->Num,&(stu+i)->score[0],&(stu+i)->score[1],&(stu+i)->score[2]);
        while ((stu+i)->score[0]>100||(stu+i)->score[0]<0||(stu+i)->score[1]>100||(stu+i)->score[1]<0||(stu+i)->score[2]>100||(stu+i)->score[2]<0)
        {
            printf("�����������%d��ѧ������Ϣ��",i+1);
            scanf("%d %d %d",&(stu+i)->score[0],&(stu+i)->score[1],&(stu+i)->score[2]);
        }
        stu[i].sum=stu[i].score[0]+stu[i].score[1]+stu[i].score[2];
        stu[i].aver=stu[i].score[0]*0.3+stu[i].score[1]*0.5+stu[i].score[2]*0.2;
    }
}

void Output_Grade(int *p,student *stu){//����Ѵ����ѧ����Ϣ
    int i;
    printf("��ѧ���ɼ����£�\n");
    for ( i = 0; i < *p; i++)
    {
        printf("�ڸ�%dѧ������ϢΪ��\tѧ��%d\t����%d\t��ѧ%d\tӢ��%d\t�ܷ�%d\t��Ȩƽ����%.2f\t\n",i+1,stu[i].Num,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].sum,stu[i].aver);
    }
}

void Add_score(int *p,student *stu){//���ѧ����Ϣ
    // student *p;
    stu=(student*)realloc(stu,(*p+1)*sizeof(student));
    if(!stu) exit(0);
    printf("�����������¼���ѧ���ɼ���\n");
    scanf("%d %d %d %d",&stu[*p].Num,&stu[*p].score[0],&stu[*p].score[1],&stu[*p].score[2]);
    while (stu[*p].score[0]<0||stu[*p].score[0]>100||stu[*p].score[1]<0||stu[*p].score[1]>100||stu[*p].score[2]<0||stu[*p].score[2]>100)
    {
        printf("���������������¼���ѧ���ɼ���\n");
        scanf("%d %d %d %d",&stu[*p].Num,&stu[*p].score[0],&stu[*p].score[1],&stu[*p].score[2]);
    }
    stu[*p].sum=stu[*p].score[0]+stu[*p].score[1]+stu[*p].score[2];
    stu[*p].aver=stu[*p].score[0]*0.3+stu[*p].score[1]*0.5+stu[*p].score[2]*0.2;
    *p=*p+1;
    Output_Grade(p,stu);
    // return stu;
}

void Delete_score_Num(int *p,student *stu){
    int i,j,Num;
    printf("������Ҫɾ��ѧ����Ϣ��ѧ�ţ�");
    scanf("%d",&Num);
    for(i=0;i<*p;i++){
        if(stu[i].Num==Num){
            for(j=i;j<*p;j++) stu[j]=stu[j+1];
        *p-=1;i--;
        }
    }
    Output_Grade(p,stu);
}

void Sort_Score_Num(int *p,student *stu){//����ѧ����������
    int i,j,k;
    student temp;
    for(i=0;i<*p-1;i++){
        k=i;
        for(j=i+1;j<*p;j++){
            if (stu[k].Num>stu[j].Num) k=j;
        }
        temp=stu[i];stu[i]=stu[k];stu[k]=temp;
    }
    printf("����ѧ���������£�\n");
    Output_Grade(p,stu);
}

void Sort_Score_Sum(int *p,student *stu){//�����ܷ���������
    int i,j,k;
    student temp;
    for(i=0;i<*p-1;i++){
        k=i;
        for(j=i;j<*p;j++){
            if(stu[k].sum>stu[j].sum) k=j;
        }
        temp=stu[i];stu[i]=stu[k];stu[k]=temp;
    }
    printf("�����ܳɼ��������£�\n");
    Output_Grade(p,stu);
}

int main(){
    int n,Num,c,*p;
    p=&n;
    student *stu;
    printf("�����������Сn��1-100����");
    scanf("%d",p);
    while (n<0||n>100)
    {
        printf("���������������С��1-100����");
        scanf("%d",p);
    }
    stu=(student*)malloc(n*sizeof(student));
    if(!stu) exit(0);
    Input_score(p,stu);
    // Sort_Score_Num(n,stu);
    Output_Grade(p,stu);
    printf("ִ������ѧ����Ϣ������1����ѧ������������2�����ܳɼ���������3��ɾ��ѧ����Ϣ������4���˳�������0��");//�ٳ�ʼ��ѧ����Ϣ��ѡ��Ҫ���еĲ���
    scanf("%d",&c);
    while (c)
    {
        if(c==1)
            Add_score(p,stu);
        else if (c==2)
            Sort_Score_Num(p,stu);
        else if(c==3)
            Sort_Score_Sum(p,stu);
        else if(c==4)
            Delete_score_Num(p,stu);
        else printf("�����������������룡\n");
        printf("ִ������ѧ����Ϣ������1����ѧ������������2�����ܳɼ���������3��ɾ��ѧ����Ϣ������4���˳�������0��");
        scanf("%d",&c);
    }
    free(stu);
}
