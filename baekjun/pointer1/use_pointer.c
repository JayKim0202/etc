#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, x;
    int* a;

    scanf_s("%d %d", &n, &x);
    a = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        scanf_s("%d", a++);
    }

    a -= n;

    for (int i = 0; i < n; i++)
    {
        if (*a < x)
            printf("%d ", *a);
        a++;
    }

    return 0;
}