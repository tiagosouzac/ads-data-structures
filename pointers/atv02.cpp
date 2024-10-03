#include <stdio.h>

int main()
{
    float elementos[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < 10; i++)
    {
        printf("Endereco do elemento %d: %p\n", i, &elementos[i]);
    }

    return 0;
}