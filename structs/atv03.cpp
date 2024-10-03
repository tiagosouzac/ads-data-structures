#include <stdio.h>

struct Funcionario
{
    char nome[100];
    char cargo[100];
    float salario;
    float beneficios;
    float descontos;

    void ler()
    {
        printf("Nome: ");
        scanf("%[^\n]%*c", nome);

        printf("Cargo: ");
        scanf("%[^\n]%*c", cargo);

        printf("Salario: ");
        scanf("%f%*c", &salario);

        printf("Beneficios: ");
        scanf("%f%*c", &beneficios);

        printf("Descontos: ");
        scanf("%f%*c", &descontos);

        printf("\n");
    }

    void imprimir()
    {
        printf("\n");
        printf("Nome: %s\n", nome);
        printf("Cargo: %s\n", cargo);
        printf("Salario base: R$ %.2f\n", salario);
        printf("Beneficios: %.2f\n", beneficios);
        printf("Descontos: %.2f\n", descontos);
        printf("Salario liquido: R$ %.2f\n", calcularSalarioLiquido());
    }

    float calcularSalarioLiquido()
    {
        return salario + beneficios - descontos;
    }
};

struct Loja
{
    Funcionario funcionarios[10];
    int totalFuncionarios = 0;

    void cadastrarFuncionario()
    {
        if (totalFuncionarios == 10)
        {
            printf("Limite de 10 funcionarios atingido.");
        }

        funcionarios[totalFuncionarios].ler();
        totalFuncionarios++;
    }

    void imprimirFuncionarios()
    {
        if (totalFuncionarios > 0)
        {
            printf("Funcionarios cadastrados:\n");

            for (int i = 0; i < totalFuncionarios; i++)
            {
                funcionarios[i].imprimir();
            }

            printf("\n");
        }
        else
        {
            printf("Nao ha funcionarios cadastrados!\n\n");
        }
    }

    void imprimirMediaSalarial()
    {
        if (totalFuncionarios > 0)
        {
            float totalSalarios = 0;

            for (int i = 0; i < totalFuncionarios; i++)
            {
                totalSalarios += funcionarios[i].salario;
            }

            float media = totalSalarios / totalFuncionarios;

            printf("Média salarial: R$ %.2f\n\n", media);
        }
        else
        {
            printf("Nao ha funcionarios cadastrados!\n\n");
        }
    }

    void imprimirMaiorSalario()
    {
        if (totalFuncionarios > 0)
        {
            float maiorSalario = funcionarios[0].salario;

            for (int i = 1; i < totalFuncionarios; i++)
            {
                if (funcionarios[i].salario > maiorSalario)
                {
                    maiorSalario = funcionarios[i].salario;
                }
            }

            printf("Maior salario: R$ %.2f\n\n", maiorSalario);
        }
        else
        {
            printf("Nao ha funcionarios cadastrados!\n\n");
        }
    }
};

struct Menu
{
    Loja loja;

    void executar()
    {
        int opcao;

        do
        {
            printf("1. Cadastrar funcionario\n");
            printf("2. Listar funcionarios\n");
            printf("3. Mostrar media salarial\n");
            printf("4. Mostrar maior salario\n");

            scanf("%d%*c", &opcao);

            printf("\n");

            switch (opcao)
            {
            case 1:
                loja.cadastrarFuncionario();
                break;

            case 2:
                loja.imprimirFuncionarios();
                break;

            case 3:
                loja.imprimirMediaSalarial();
                break;

            case 4:
                loja.imprimirMaiorSalario();
                break;

            default:
                printf("Opcao invalida!\n");
                break;
            }
        } while (opcao != 0);
    }
};

int main()
{
    Menu menu;

    menu.executar();

    return 0;
}