#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

struct emp
{
    int empID;
    char name[20];
    float salary;
    char ph_no[10];
    int age;
};
FILE *fp, *cpy, *id;
struct emp e;
long int size = sizeof(e);
int Idno;
char again;
void addrcrd()
{
    system("cls");
    id = fopen("id.txt", "rb+");    //id.txt
        int c;
        rewind(id);
    printf("Enter ID of the employee:");
    fflush(stdin);
    scanf("%d", &e.empID);
    while (feof(id) == 0)
    {
        fscanf(id, "%d", &c);
        if (c == e.empID)
        {
            printf("ID exists!!\nEnter a unique id while adding new data!!\n");
            rewind(id);
            printf("Enter ID of the employee:");
            fflush(stdin);
            scanf("%d", &e.empID);
            continue;
        }
    }
    fprintf(id," %d",e.empID);
    fclose(id);
    printf("Enter the name of the employee:");
    fflush(stdin);
    gets(e.name);
    printf("Enter salary of the employee:");
    fflush(stdin);
    scanf("%f", &e.salary);
    while (1)
    {
        printf("Enter mobile number of the employee:");
        fflush(stdin);
        scanf("%s",e.ph_no);
        if (strlen(e.ph_no) == 10)
            break;
        else
        {
            printf("Enter valid mobile number!!\n");
            continue;
        }
    }
    printf("Enter age of the employee:");
    fflush(stdin);
    scanf("%d", &e.age);
    fwrite(&e, size, 1, fp);
}
void readrcrd()
{
    rewind(fp);
    system("cls");
    printf("EMPLOYEE ID\tEMPLOYEE NAME\tEMPLOYEE SALARY\tMOBILE NUMBER\tAGE\n");
    printf("-----------\t-------------\t---------------\t-------------\t---\n");
    printf("\n");
    while (fread(&e, size, 1, fp) == 1)
        printf("%4d\t\t%s\t\t%.2f\t%s\t%d\n", e.empID, e.name, e.salary, e.ph_no, e.age);
}
void modrcrd()
{
    system("cls");
    printf("Enter the employee ID to modify:");
    fflush(stdin);
    scanf("%d", &Idno);
    rewind(fp);
    while (fread(&e, size, 1, fp) == 1)
    {
        if (e.empID == Idno)
        {
            printf("Enter the ID of the employee:");
            fflush(stdin);
            scanf("%d",&e.empID);
            printf("Enter the name of the employee:");
            fflush(stdin);
            gets(e.name);
            printf("Enter salary of the employee:");
            fflush(stdin);
            scanf("%f", &e.salary);
            while (1)
            {
                printf("Enter mobile number of the employee:");
                fflush(stdin); 
                gets(e.ph_no);
                if (strlen(e.ph_no) == 10)
                    break;
                else
                {
                    printf("Enter valid mobile number!!\n");
                    continue;
                }
            }
            printf("Enter age of the employee:");
            fflush(stdin);
            scanf("%d", &e.age);
            fseek(fp,-size,SEEK_CUR);
            fwrite(&e,size,1,fp);
            break;
        }
    }
}
void dltrcrd()
{
    system("cls");
    FILE *tempID;
    printf("Enter the employee ID to delete:");
    fflush(stdin);
    scanf("%d",&Idno);
    rewind(fp);
    tempID = fopen("temp.txt","rb+");    //temp.txt
    cpy = fopen("cpyEmp.txt","rb+");    //cpyEmp.txt
    while(fread(&e,size,1,fp)==1)
    {
        if(e.empID != Idno)
        {
            fwrite(&e,size,1,cpy);
            fprintf(tempID,"%d ",e.empID);
        }
    }
    fclose(fp);
    fclose(cpy);
    fclose(tempID);
    remove("employee.txt");
    rename("cpyEmp.txt","employee.txt");
    cpy = fopen("cpyEmp.txt","ab+");
    fclose(cpy);
    remove("id.txt");
    rename("temp.txt","id.txt");
    tempID = fopen("temp.txt","ab+");
    fclose(tempID);
    fp = fopen("employee.txt","rb+");
}

int main()
{
    system("cls");
    //int pass;
    int opt;
    fp = fopen("employee.txt","rb+");   //employee.txt
    printf("WELCOME TO EMPLOYEE DATABASE\n");
    system("pause");
    printf("Enter any key to continue.....");
    system("cls");
    //printf("Enter password to access the database:");
    //scanf("%d",&pass);
    printf("1.Add records\n");
    printf("2.View records\n");
    printf("3.Modify records\n");
    printf("4.Delete records\n");
    printf("5.Exit\n");
    printf("\n");
    printf("Enter your choice:");
    scanf("%d",&opt);

    switch (opt)
    {
    case 1:
        system("cls");
        fseek(fp,0,SEEK_END);
        addrcrd();
        break;
   
    case 2:
        system("cls");
        readrcrd();
        break;
    
    case 3:
        system("cls");
        modrcrd();
        break;

    case 4:
        system("cls");
        dltrcrd();
        break;

    case 5:
        break;

    default:
        printf("Invalid input!!");
        break;
    }
    return 0;
}
