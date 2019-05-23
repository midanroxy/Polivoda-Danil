#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter size of matrix:");
    if (scanf("%d", &n) < 1)
    {
        printf("Invalid size of matrix\n");
        return 0;
    }

    int** a = calloc(n, sizeof(int*));

    for(int i = 0; i < n; i++)
    {
        a[i] = calloc(n, sizeof(int));
        a[0][i] = 0;
    }
    a[0][0] = 1;

    for(int i = 1; i < n; i++)
    {
        a[i][0] = 1;
        for(int k = 1; k < n; k++)
        {
            a[i][k] = a[i-1][k] + a[i-1][k-1];
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int k = 0; k < n; k++)
        {
            printf("   %d", a[i][k]);
        }
        printf("\n");
    }

    return 0;
}
