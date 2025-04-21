#include <stdio.h>
#include <stdlib.h>
int main()
{
    // use of malloc
    // int *ptr;
    // ptr = (int *)malloc(3 * sizeof(int));
    // for (int i = 0; i < 3; i++)
    // {
    //     scanf("%d", &ptr[i]);
    // }
    // for (int i = 0; i < 3; i++)
    // {
    //     printf("%d  ", ptr[i]);
    // }
    // use of calloc

    // int *ptr;
    // ptr = (int *)calloc(3, sizeof(int));
    // for (int i = 0; i < 3; i++)
    // {
    //     scanf("%d", &ptr[i]);
    // }
    // for (int i = 0; i < 4; i++)
    // {
    //     printf("%d  ", ptr[i]);
    // }

    // use of realloc

    int *ptr;
    ptr = (int *)realloc(3 * sizeof(int));
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &ptr[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        printf("%d  ", ptr[i]);
    }
}
