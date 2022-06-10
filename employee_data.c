#include <stdio.h>
#include <conio.h>

typedef struct employee
{
    char name[50], designation[10], address[30], email[20], branch[20];
    int salary, id_no, phone, YY, MM, DD;
} emp;

int main(void)
{
    FILE *ptr;
    emp e[120];
    int i, j, pass, x = 10, k = 0, n;

    while (x != 0)
    {
        printf("\x1b[34m");
        printf("Enter password to edit employee database\n");
        scanf("%d", &pass);

        if (pass == 1234)
        {
            x = 0;

            printf("\x1b[36m");
            printf("Enter how many employee's data you want to enter: ");
            scanf("%d", &n);
            printf("\x1b[32m");
            printf("\t\nEdit Employee details\n");
            printf("Enter any key to proceed.....");
            getch();

            for (int count = 0; count < n; count++)
            {
                ptr = fopen("employee_profile.txt", "a");
                printf("\x1b[35m");
                printf("\nEnter the name of the employee %d-->", count + 1);
                scanf("\n");
                scanf("%[^\n]", e[count].name);

                printf("Enter the branch name of the employee %d-->",count + 1);
                scanf("\n");
                scanf("%[^\n]", e[count].branch);

                printf("Enter the address of the employee %d-->", count + 1);
                scanf("\n");
                scanf("%[^\n]", e[count].address);

                printf("Enter the ID no of the employee %d-->", count + 1);
                scanf("%d", &e[count].id_no);
                fflush(stdin);

                printf("Enter the ctc no of the employee %d-->", count + 1);
                scanf("%d", &e[count].salary);
                fflush(stdin);

                printf("Enter the phone no of the employee %d-->", count + 1);
                scanf("%d", &e[count].phone);
                fflush(stdin);

                printf("Enter the email id. of the employee %d-->", count + 1);
                scanf("%s", &e[count].email);
                fflush(stdin);

                printf("Enter the designation of the employee %d\n", count + 1);
                scanf("%s", &e[count].designation);
                fflush(stdin);

                printf("Enter the joining date of the employee %d in DD/MM/YYYY format\n", count + 1);
                scanf("%d %d %d", &e[count].DD, &e[count].MM, &e[count].YY);
                fflush(stdin);

                fprintf(ptr, "\t\t****Employee profile****\nEmployee  Name:%s\t\t\t\tAddress:%s\nID No.:%d\t\t\t\t\tDesignation:%s\nEmployee's annual salary:%d\n", e[count].name, e[count].address, e[count].id_no, e[count].designation, e[count].salary);
                for (i = 0; i < 9; i++)
                    fprintf(ptr, ".");
                fprintf(ptr, "\n");
                for (i = 0; i < 4; i++)
                {
                    fprintf(ptr, "|\t|");
                    if (i == 0)
                        fprintf(ptr, "\t\t\t\tContact No.: %d\n", e[count].phone);
                    if (i == 1)
                        fprintf(ptr, "\t\t\t\tEmail id: %s\n", e[count].email);
                    if (i == 2)
                        fprintf(ptr, "\t\t\t\tJoining date:%d/%d/%d\n", e[count].DD, e[count].MM, e[count].YY);
                    if (i == 3)
                        fprintf(ptr, "\t\t\t\tBranch:%s\n", e[count].branch);
                }
                for (i = 0; i < 9; i++)
                    fprintf(ptr, ".");
                fprintf(ptr, "\n");
                fprintf(ptr, "Employee photo");
                fprintf(ptr, "\n\n\n");
                fclose(ptr);

                printf("\x1b[0m");
                printf("Process complete by creating a 'employee_profile.txt' on %s\n", e[count].name);
            }
        }

        if (pass != 1234)
        {
            printf("\x1b[31m");
            printf("Wrong password, try another\n");
            printf("\x1b[0m");
            k++;
        }
        if (k > 3)
        {
            printf("\x1b[35m");
            printf("Attempts exceeded\nUnauthorized access\n");
            printf("\x1b[0m");
            break;
        }
    }
    return 0;
}
