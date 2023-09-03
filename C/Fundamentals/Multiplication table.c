#include <stdlib.h>
#include <stdio.h>

void print_table(int **table, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", table[i][j]);
        printf("\n");
    }
}

int **multiplication_table(int n)
{
    /* --- Memory allocation --- */
    int **table = (int **)calloc(n, sizeof(int *));
    if (!table)
        return NULL;

    for (int i = 0; i < n; i++)
    {
        table[i] = (int *)calloc(n, sizeof(int));
        if (!table[i])
        {
            for (int j = 0; j < n; j++)
            {
                free(table[j]);
                table[j] = NULL;
            }
            free(table);
            table = NULL;
            return NULL;
        }
    }

    /* --- Filling multiplication table --- */
    for (int i = 0; i < n; i++)
        table[i][0] = table[0][i] = i + 1;

    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
            table[i][j] = table[0][j] * table[i][0];

    print_table(table, n);

    return table;
}

int main()
{
    int **table = multiplication_table(3);

    if (table)
    {
        for (int i = 0; i < 3; i++)
        {
            free(table[i]);
            table[i] = NULL;
        }
        free(table);
        table = NULL;
    }

    return 0;
}
