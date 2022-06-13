#include <stdio.h>

int main()
{
    FILE *fp, *cpy;
    int id, c;
    fp = fopen("test.txt", "r+");
    cpy = fopen("test2.txt", "r+");
    rewind(cpy);
    printf("ENter id:");
    fflush(stdin);
    scanf("%d", &id);
    while (feof(cpy) == 0)
    {
        fscanf(cpy, "%d", &c);
        if (c == id)
        {
            printf("id exists!!Enter a unique id while adding new data!!\n");
            rewind(cpy);
            printf("ENter id:");
            fflush(stdin);
            scanf("%d", &id);
            continue;
        }
    }
    fprintf(cpy, " %d", id);
    return 0;
}