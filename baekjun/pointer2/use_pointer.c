#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count;
    int* a, * b, * c;

    scanf_s("%d", &count);

    a = (int*)malloc(sizeof(int) * count);
    b = (int*)malloc(sizeof(int) * count);
    c = (int*)malloc(sizeof(int) * count);

    for (int i = 0; i < count; i++)
    {
        scanf_s("%d %d", &*a, &*b);
        *c++ = *a++ + *b++;
    }

    a -= count;
    b -= count;
    c -= count;

    for (int i = 1; i <= count; i++)
        printf("Case #%d: %d + %d = %d\n", i, *a++, *b++, *c++);

    return 0;
}