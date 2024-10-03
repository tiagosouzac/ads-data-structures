#include <stdio.h>

void encontrarMinMax(int *elementos, int tamanho, int *min, int *max)
{
    *min = elementos[0];
    *max = elementos[0];

    for (int i = 1; i < tamanho; i++)
    {
        if (elementos[i] < *min)
        {
            *min = elementos[i];
        }

        if (elementos[i] > *max)
        {
            *max = elementos[i];
        }
    }
}

int main()
{
    int tamanho;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int elementos[tamanho], min, max;

    for (int i = 0; i < tamanho; i++)
    {
        printf("Digite o %d elemento: ", i + 1);
        scanf("%d", &elementos[i]);
    }

    encontrarMinMax(elementos, tamanho, &min, &max);

    printf("Menor elemento: %d\n", min);
    printf("Maior elemento: %d\n", max);

    return 0;
}
