#include<stdio.h>

typedef struct score_grade
{
    int score;
    char grade;
} student;

void input_Score(int n,student stu[]){
    int i;
    for(i=0;i<n;i++){
        printf("请输入第%d个学生的分数（0-100）：\n",i+1);
        scanf("%d",&stu[i].score);
        while (stu[i].score<0||stu[i].score>100)
        {
            printf("请重新输入第%d个学生的分数（0-100）：\n",i+1);
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
        printf("各个学生的分数与等级如下：\n");
        for(i=0,p=stu;i<n;i++,p++){
            printf("第%d个学生:\t分数为%d\t等级为%c\n",i+1,p->score,p->grade);
        }
}

int main(){
    student stu[5];
    input_Score(5,stu);
    Score_Grade(5,stu);
    Output_Score_Grade(5,stu);
}
