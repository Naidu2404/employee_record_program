#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct employee 
{
    char name[50];
    int SSID;
    float salary;
};
struct employee e;
long int size=sizeof(e);
FILE *fp,*ft;
void add_record()
{
    printf("Enter Name:");
    scanf("%s",e.name);
    printf("Enter unique SSID:");
    scanf("%d",&e.SSID);
    printf("Enter Salary:");
    scanf("%f",&e.salary);
    fwrite(&e,size,1,fp);
}
void delete_record_with_employee_name()
{
    char ename[50];
    printf("Enter employee name to delete record:");
    scanf("%s",ename);
    ft=fopen("temp.txt","wb");
    rewind(fp);
    while(fread(&e,size,1,fp)==1)
    {
        if(strcmp(e.name,ename)!=0)
        {
            fwrite(&e,size,1,ft);
        }
    }
    fclose(fp);
    fclose(ft);
    remove("data.txt");
    rename("temp.txt","data.txt");
    fp=fopen("data.txt","rb+");
}
void display()
{
    printf("\t\t\t\tDetails\t\t\t\t\t\t\n");
    rewind(fp);
    while(fread(&e,size,1,fp)==1)
    {
        printf("%s\t\t\t%d\t\t\t%f\n",e.name,e.SSID,e.salary);
    }
}
void display_record_with_employee_name()
{
    char ename[50];
    rewind(fp);
    printf("Enter employee name to display record:");
    scanf("%s",ename);
    while(fread(&e,size,1,fp)==1)
    {
        if(strcmp(ename,e.name)==0)
        {
            printf("%s\t\t\t%d\t\t\t%f\n",e.name,e.SSID,e.salary);
        }
    }
}
void display_record_with_employee_ID()
{
    int id;
    rewind(fp);
    printf("Enter employee ID to display record:");
    scanf("%d",&id);
    while(fread(&e,size,1,fp)==1)
    {
        if(id==e.SSID)
        {
            printf("%s\t\t\t%d\t\t\t%f\n",e.name,e.SSID,e.salary);
        }
    }
}
void modify_with_employee_name()
{
    char ename[50];
    printf("Enter employee name to modify:");
    scanf("%s",ename);
    rewind(fp);
    while(fread(&e,size,1,fp)==1)
    {
        if(strcmp(ename,e.name)==0)
        {
            printf("Enter modified name:");
            scanf("%s",e.name);
            printf("Enter modified id no:");
            scanf("%d",&e.SSID);
            printf("Enter modified salary");
            scanf("%f",&e.salary);
            fseek(fp, -size, SEEK_CUR);
            fwrite(&e,size,1,fp);
            break;
        }
    }
}
int main()
{
    int c;
    fp=fopen("data.txt","wb+");
    if(fp==NULL)
    {
        printf("Cannot open file");
        exit(1);
    }
    while(1)
    {
        printf("Enter your choice:\n1.Add a record\n2.delete a record\n3.display all data\n4.display data of employee using employee name\n5.display data of employee using id no\n6.modify record using name\n7.exit\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1: add_record();break;
            case 2: delete_record_with_employee_name();break;
            case 3: display();break;
            case 4: display_record_with_employee_name();break;
            case 5: display_record_with_employee_ID();break;
            case 6: modify_with_employee_name();break;
            case 7: exit(0);break;
            default: printf("Invalid option");
        }
    }
}