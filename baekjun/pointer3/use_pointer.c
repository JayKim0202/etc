#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count;
    int a, b;

    scanf_s("%d", &count);

    int* x = (int*)malloc(sizeof(int) * count);

    for (int i = 0; i < count; i++)
    {
        scanf_s("%d %d", &a, &b);
        *x++ = a + b;
    }

    x -= count;

    for (int i = 0; i < count; i++)
        printf("%d\n", *x++);

    return 0;
}