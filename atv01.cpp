#include <stdio.h>

struct Data
{
    int dia;
    int mes;
    int ano;

    void ler()
    {
        printf("Dia: ");
        scanf("%d%*c", &dia);

        printf("Mes: ");
        scanf("%d%*c", &mes);

        printf("Ano: ");
        scanf("%d%*c", &ano);
    }
};

struct Cliente
{
    char nome[100];
    Data dataNascimento;
    int idade;
    char sexo;

    void ler()
    {
        printf("Nome: ");
        scanf("%[^\n]%*c", nome);

        printf("Data de nascimento\n");
        dataNascimento.ler();
        calcularIdade();

        printf("Sexo (M ou F): ");
        scanf("%c%*c", &sexo);

        printf("\n");
    }

    void calcularIdade()
    {
        idade = 2024 - dataNascimento.ano;
    }

    void imprimir()
    {
        printf("\n");
        printf("Nome: %s\n", nome);
        printf("Data de nascimento: %d/%d/%d\n", dataNascimento.dia, dataNascimento.mes, dataNascimento.ano);
        printf("Idade: %d\n", idade);
        printf("Sexo: %c\n", sexo);
    }
};

struct Clientes
{
    Cliente clientes[50];
    int totalClientes = 0;

    void cadastrar()
    {
        if (totalClientes == 50)
        {
            printf("Limite de 50 usuarios cadastrados atingido");
            return;
        }

        clientes[totalClientes].ler();
        totalClientes++;
    }

    void imprimir()
    {
        if (totalClientes > 0)
        {
            printf("\nUsuarios cadastrados:\n");

            for (int i = 0; i < totalClientes; i++)
            {
                clientes[i].imprimir();
            }

            printf("\n");
        }
        else
        {
            printf("Nenhum usuario cadastrado!\n\n");
        }
    }
};

struct Menu
{
    Clientes clientes;

    void executar()
    {
        int opcao;

        do
        {
            printf("1. Cadastrar cliente\n");
            printf("2. Listar clientes\n");

            scanf("%d%*c", &opcao);

            printf("\n");

            switch (opcao)
            {
            case 1:
                clientes.cadastrar();
                break;

            case 2:
                clientes.imprimir();
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