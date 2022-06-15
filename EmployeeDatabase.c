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
FILE *fp, *cpy, *id, *tempID;
struct emp e;
long int size = sizeof(e);
int Idno;
char again;
void addrcrd()
{
    system("cls");
    id = fopen("id.txt", "rb+");
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
            printf("ID exists!!\n!!Enter a unique id while adding new data!!\n");
            rewind(id);
            printf("Enter ID of the employee:");
            fflush(stdin);
            scanf("%d", &e.empID);
            continue;
        }
    }
    printf("Enter the name of the employee:");
    fflush(stdin);
    gets(e.name);
    printf("Enter salary of the employee:");
    fflush(stdin);
    scanf("%f", &e.salary);
    while (1)
    {
        int flag = 0;
        printf("Enter mobile number of the employee:");

        fflush(stdin);
        scanf("%s", e.ph_no);
        for (int i = 0; i < 10; i++)
        {
            if (e.ph_no[i] < '0' || e.ph_no[i] > '9')
                flag++;
        }
        if (strlen(e.ph_no) == 10 && flag == 0)
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
    fprintf(id, "%d ", e.empID);
    fclose(id);
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
    id = fopen("id.txt", "rb+");
    int c, run = 0, mark = 0, Idno;
    while (mark == 0)
    {
        rewind(id);
        printf("Enter ID of the employee to modify:");
        fflush(stdin);
        scanf("%d", &Idno);
        while (feof(id) == 0)
        {
            fscanf(id, "%d", &c);
            if (c == Idno)
                run++;
        }
        if (run != 0)
        {
            tempID = fopen("temp.txt", "rb+");
            rewind(fp);
            while (fread(&e, size, 1, fp) == 1)
            {
                if (e.empID == Idno)
                {
                    rewind(id);
                    while (feof(id) == 0)
                    {
                        fscanf(id, "%d", &c);
                        if (c != Idno)
                            fprintf(tempID, "%d ", c);
                    }
                    printf("Enter the new ID of the employee:");
                    fflush(stdin);
                    scanf("%d", &e.empID);
                    fprintf(tempID, "%d", e.empID);
                    printf("Enter the name of the employee:");
                    fflush(stdin);
                    gets(e.name);
                    printf("Enter salary of the employee:");
                    fflush(stdin);
                    scanf("%f", &e.salary);
                    while (1)
                    {
                        int flag = 0;
                        printf("Enter mobile number of the employee:");

                        fflush(stdin);
                        scanf("%s", e.ph_no);
                        for (int i = 0; i < 10; i++)
                        {
                            if (e.ph_no[i] < '0' || e.ph_no[i] > '9')
                                flag++;
                        }
                        if (strlen(e.ph_no) == 10 && flag == 0)
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
                    fseek(fp, -size, SEEK_CUR);
                    fwrite(&e, size, 1, fp);
                    fclose(id);
                    fclose(tempID);
                    remove("id.txt");
                    rename("temp.txt", "id.txt");
                    tempID = fopen("temp.txt", "ab+");
                    fclose(tempID);
                    break;
                }
            }
            mark++;
        }
        else if (run == 0)
        {
            printf("Entered ID does not exist!!\n");
            continue;
        }
    }
}
void dltrcrd()
{
    system("cls");
    id = fopen("id.txt", "rb+");
    int c, run = 0, mark = 0, Idno;
    while (mark == 0)
    {
        rewind(id);
        printf("Enter the employee ID to delete:");
        fflush(stdin);
        scanf("%d", &Idno);
        while (feof(id) == 0)
        {
            fscanf(id, "%d", &c);
            if (c == Idno)
                run++;
        }
        if (run != 0)
        {
            rewind(fp);
            tempID = fopen("temp.txt", "rb+");
            cpy = fopen("cpyEmp.txt", "rb+");
            while (fread(&e, size, 1, fp) == 1)
            {
                if (e.empID != Idno)
                {
                    fwrite(&e, size, 1, cpy);
                    fprintf(tempID, "%d ", e.empID);
                }
            }
            fclose(fp);
            fclose(cpy);
            fclose(tempID);
            fclose(id);
            remove("employee.txt");
            rename("cpyEmp.txt", "employee.txt");
            cpy = fopen("cpyEmp.txt", "ab+");
            fclose(cpy);
            remove("id.txt");
            rename("temp.txt", "id.txt");
            tempID = fopen("temp.txt", "ab+");
            fclose(tempID);
            fp = fopen("employee.txt", "rb+");
            mark++;
        }
        else if (run == 0)
        {
            printf("Entered ID does not exist!!\n");
            continue;
        }
    }
}

int main()
{
    system("cls");
    int opt;
    fp = fopen("employee.txt", "rb+");
    printf("WELCOME TO EMPLOYEE DATABASE\n");
    system("pause");
    printf("Enter any key to continue.....");
    system("cls");
    printf("1.Add new records\n");
    printf("2.View records\n");
    printf("3.Modify records\n");
    printf("4.Delete records\n");
    printf("5.Exit\n");
    printf("\n");
    printf("Enter your choice:");
    scanf("%d", &opt);

    switch (opt)
    {
    case 1:
        system("cls");
        again = 'y';
        while (again == 'y')
        {
            fseek(fp, 0, SEEK_END);
            addrcrd();
            printf("Do you want to add another data ?(y/n)\n");
            again = getche();
        }
        break;

    case 2:
        system("cls");
            readrcrd();
        break;

    case 3:
        system("cls");
        again = 'y';
        while (again == 'y')
        {
            modrcrd();
            printf("Do you want to add another data ?(y/n)\n");
            again = getche();
        }
        break;

    case 4:
        system("cls");
        again = 'y';
        while (again == 'y')
        {
            dltrcrd();
            printf("Do you want to add another data ?(y/n)\n");
            again = getche();
        }
        break;

    case 5:
        break;

    default:
        printf("Invalid input!!");
        break;
    }
    return 0;
}
