#include <stdio.h>
#include <cmath>

void calcular(float raio, float *area, float *volume)
{
    *area = 4.0 * M_PI * pow(raio, 2);
    *volume = (4.0 / 3.0) * M_PI * pow(raio, 3);
}

int main()
{
    float raio, area, volume;

    printf("Digite o raio da esfera: ");
    scanf("%f", &raio);

    calcular(raio, &area, &volume);

    printf("Area da esfera: %.2f\n", area);
    printf("Volume da esfera: %.2f\n", volume);

    return 0;
}