#include <stdio.h>

void separar(float num, float *inteiro, float *decimal)
{
    *inteiro = (int)num;
    *decimal = num - *inteiro;
}

int main()
{
    float num, inteiro, decimal;

    printf("Digite um numero: ");
    scanf("%f", &num);

    separar(num, &inteiro, &decimal);

    printf("Parte inteira: %.0f\n", inteiro);
    printf("Parte decimal: %.2f\n", decimal);

    return 0;
}