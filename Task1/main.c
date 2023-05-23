#include <stdio.h>
#include <string.h>
struct student
{
    int rollno;
    int fees;
    int marks;
    char name[20];
    int id;
};
struct student s[100];
int option;
int rand_id;
FILE* fp;
int main()
{
//    fp=fopen("C:/Users/manoj/OneDrive/Desktop/Training/Pointers in C/Tasks/Task1/student_details.txt","a+");
    while(1)
    {
        printf("1.add student details\n");
        printf("2.display student details\n");
        printf("3.update student details\n");
        printf("4.delete student details\n");
        printf("5.exit\n");
        printf("enter your option:");
        scanf("%d",&option);
        switch(option)
        {
           case 1:add_details(fp);
                  break;
           case 2:dis_stud_details(fp);
                  break;
           case 3:update(s);
                break;
           case 4:delete_stud_record(s);
                break;
           case 5:exit(0);
                break;
           default:printf("sorry invalid options...\n");
        }
    }
    fclose(fp);
    return 0;
}
void add_details(FILE *fp)
{
    fp=fopen("C:/Users/manoj/OneDrive/Desktop/Training/Pointers in C/Tasks/Task1/student_details.txt","a+");
    printf("file opened...\n");
    printf("enter the rollno:");
    scanf("%d",&s->rollno);
    fprintf(fp,"%d\t",s->rollno);

    printf("enter the name:");
    scanf("%s",&s->name);
    fprintf(fp,"%s\t",s->name);

    printf("enter the fees:");
    scanf("%d",&s->fees);
    fprintf(fp,"%d\t",s->fees);

    printf("marks:");
    scanf("%d",&s->marks);
    fprintf(fp,"%d\t",s->marks);
    rand_id=rand();
    s->id=rand_id;
    fprintf(fp,"%d\n",s->id);
    fclose(fp);
}
void dis_stud_details(FILE *fp)
{
    fp=fopen("C:/Users/manoj/OneDrive/Desktop/Training/Pointers in C/Tasks/Task1/student_details.txt","a+");
    rewind(fp);
    while(fscanf(fp,"%d\t%s\t%d\t%d\t%d\n",&s->rollno,&s->name,&s->fees,&s->marks,&s->id)!=EOF)
    {
        printf("rollno=%d\tname=%s\tfees=%d\tmarks=%d\tid=%d\n",s->rollno,s->name,s->fees,s->marks,s->id);
    }
    fclose(fp);
//    char str[60];
//    while(fgets(str,59,fp)!=NULL)
//    {
//        puts(str);
//    }
}
void update(struct student* s)
{
    int stud_id=0;
    FILE* fp, *fp1;

    fp=fopen("C:/Users/manoj/OneDrive/Desktop/Training/Pointers in C/Tasks/Task1/student_details.txt","r+");
    fp1=fopen("C:/Users/manoj/OneDrive/Desktop/Training/Pointers in C/Tasks/Task1/update.txt","w+");

    printf("enter the student id you want to update the details:");
    scanf("%d",&stud_id);
    if(fp1==NULL)
    {
        printf("error!\n");
        exit(0);
    }
    else
    {
        printf("file opened!!\n");
    }
    while(fscanf(fp,"%d\t%s\t%d\t%d\t%d\n",&s->rollno,&s->name,&s->fees,&s->marks,&s->id)!=EOF)
    {
        if(s->id==stud_id)
        {
            printf("enter the rollno:");
            scanf("%d",&s->rollno);

            printf("enter the name:");
            scanf("%s",&s->name);

            printf("enter the fees:");
            scanf("%d",&s->fees);

            printf("enter the marks:");
            scanf("%d",&s->marks);
        }
        fprintf(fp1,"%d\t%s\t%d\t%d\t%d\n",s->rollno,s->name,s->fees,s->marks,s->id);
    }
    printf("record updated!!!\n");
    rewind(fp1);
    rewind(fp);
    while(fscanf(fp1,"%d\t%s\t%d\t%d\t%d\n",&s->rollno,&s->name,&s->fees,&s->marks,&s->id)!=EOF)
    {
        fprintf(fp,"%d\t",s->rollno);
        fprintf(fp,"%s\t",s->name);
        fprintf(fp,"%d\t",s->fees);
        fprintf(fp,"%d\t",s->marks);
        fprintf(fp,"%d\n",s->id);
    }
    fclose(fp);
    fclose(fp1);
    remove("C:/Users/manoj/OneDrive/Desktop/Training/Pointers in C/Tasks/Task1/update.txt");
}
void delete_stud_record(struct student * s)
{
    int std_id=0;
    FILE* fp, *fp2;

    fp=fopen("C:/Users/manoj/OneDrive/Desktop/Training/Pointers in C/Tasks/Task1/student_details.txt","r+");
    fp2=fopen("C:/Users/manoj/OneDrive/Desktop/Training/Pointers in C/Tasks/Task1/delete.txt","w+");

    printf("enter the student id you want to delete the details:");
    scanf("%d",&std_id);
    if(fp==NULL)
    {
        printf("error!\n");
        exit(0);
    }
   else
    {
        printf("file opened!!\n");
    }
    while(fscanf(fp,"%d\t%s\t%d\t%d\t%d\n",&s->rollno,s->name,&s->fees,&s->marks,&s->id)!=EOF)
    {
        if( s->id!=std_id )
        {
            fprintf(fp2,"%d\t%s\t%d\t%d\t%d\n",s->rollno,s->name,s->fees,s->marks,s->id);
        }
    }
    printf("record deleted!!!\n");
    fclose(fp2);
    fclose(fp);
    remove("C:/Users/manoj/OneDrive/Desktop/Training/Pointers in C/Tasks/Task1/student_details.txt");
    rename("C:/Users/manoj/OneDrive/Desktop/Training/Pointers in C/Tasks/Task1/delete.txt","C:/Users/manoj/OneDrive/Desktop/Training/Pointers in C/Tasks/Task1/student_details.txt");
}




