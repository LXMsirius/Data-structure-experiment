#include<stdio.h>

typedef struct score_grade
{
    int score;
    char grade;
} student;

void input_Score(int n,student stu[]){
    int i;
    for(i=0;i<n;i++){
        printf("�������%d��ѧ���ķ�����0-100����\n",i+1);
        scanf("%d",&stu[i].score);
        while (stu[i].score<0||stu[i].score>100)
        {
            printf("�����������%d��ѧ���ķ�����0-100����\n",i+1);
            scanf("%d",&stu[i].score);
        }
        
    }
}

void Score_Grade(int n,student stu[]){
    int i;
    for(i=0;i<n;i++){
        switch (stu[i].score/10)
        {
        case 10:
        case 9:stu[i].grade='A';break;
        case 8:
        case 7:stu[i].grade='B';break;
        case 6:stu[i].grade='C';break;
        default:stu[i].grade='D';break;
        }
    }
}

void Output_Score_Grade(int n,student stu[]){
        int i;
        student *p;
        printf("����ѧ���ķ�����ȼ����£�\n");
        for(i=0,p=stu;i<n;i++,p++){
            printf("��%d��ѧ��:\t����Ϊ%d\t�ȼ�Ϊ%c\n",i+1,p->score,p->grade);
        }
}

int main(){
    student stu[5];
    input_Score(5,stu);
    Score_Grade(5,stu);
    Output_Score_Grade(5,stu);
}
