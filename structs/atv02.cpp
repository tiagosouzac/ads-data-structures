#include <stdio.h>

struct Conjunto
{
    int elementos[20];
    int totalElementos = 0;

    void ler()
    {
        lerTamanho();
        lerElementos();

        printf("\n");
    }

    void lerTamanho()
    {
        do
        {
            printf("Digite o tamanho do conjunto: ");
            scanf("%d", &totalElementos);

            if (totalElementos > 20)
            {
                printf("O número máximo de elementos permitido é 20.\n");
            }
        } while (totalElementos < 0 || totalElementos > 20);
    }

    void lerElementos()
    {
        printf("Digite os elementos do conjunto: ");

        for (int i = 0; i < totalElementos; i++)
        {
            scanf("%d", &elementos[i]);
        }
    }

    bool contem(int elemento)
    {
        for (int i = 0; i < totalElementos; i++)
        {
            if (elementos[i] == elemento)
            {
                return true;
            }
        }
        return false;
    }

    void imprimir()
    {
        printf("{ ");

        for (int i = 0; i < totalElementos; i++)
        {
            printf("%d", elementos[i]);

            if (i < totalElementos - 1)
            {
                printf(", ");
            }
        }

        printf(" }\n");
    }
};

struct Conjuntos
{
    Conjunto conjuntos[10];
    int totalConjuntos = 0;

    void cadastrarConjunto()
    {
        if (totalConjuntos == 10)
        {
            printf("Limite de 10 conjuntos cadastrados atingido");
            return;
        }

        conjuntos[totalConjuntos].ler();
        totalConjuntos++;
    }

    void imprimirConjuntos()
    {
        if (totalConjuntos != 0)
        {
            printf("Conjuntos cadastrados:\n\n");

            for (int i = 0; i < totalConjuntos; i++)
            {
                printf("%d. ", i + 1);
                conjuntos[i].imprimir();
            }

            printf("\n");
        }
    }

    void unirConjuntos()
    {
        int indice1, indice2;

        printf("Indice do primeiro conjunto: ");
        scanf("%d%*c", &indice1);

        printf("Indice do segundo conjunto: ");
        scanf("%d%*c", &indice2);

        Conjunto conjunto1 = conjuntos[indice1 - 1];
        Conjunto conjunto2 = conjuntos[indice2 - 1];

        printf("\nUniao desses conjuntos: { ");

        for (int i = 0; i < conjunto1.totalElementos; i++)
        {
            printf("%d", conjunto1.elementos[i]);

            if (i < conjunto1.totalElementos - 1)
            {
                printf(", ");
            }
        }

        for (int i = 0; i < conjunto2.totalElementos; i++)
        {
            if (!conjunto1.contem(conjunto2.elementos[i]))
            {
                printf(", %d", conjunto2.elementos[i]);
            }
        }

        printf(" }\n\n");
    }

    void intersecao()
    {
        int indice1, indice2;

        printf("Indice do primeiro conjunto: ");
        scanf("%d%*c", &indice1);

        printf("Indice do segundo conjunto: ");
        scanf("%d%*c", &indice2);

        Conjunto conjunto1 = conjuntos[indice1 - 1];
        Conjunto conjunto2 = conjuntos[indice2 - 1];

        printf("\nIntersecao desses conjuntos: { ");

        for (int i = 0; i < conjunto1.totalElementos; i++)
        {
            if (conjunto2.contem(conjunto1.elementos[i]))
            {
                printf("%d", conjunto1.elementos[i]);

                if (i < conjunto2.totalElementos - 1)
                {
                    printf(", ");
                }
            }
        }

        printf(" }\n\n");
    }
};

struct Menu
{
    Conjuntos conjuntos;

    void executar()
    {
        int opcao;

        do
        {
            printf("1. Cadastrar conjunto\n");
            printf("2. Imprimir conjuntos\n");
            printf("3. Unir dois conjuntos\n");
            printf("4. Intersecao de dois conjuntos\n");

            scanf("%d%*c", &opcao);

            printf("\n");

            switch (opcao)
            {
            case 1:
                conjuntos.cadastrarConjunto();
                break;

            case 2:
                conjuntos.imprimirConjuntos();
                break;

            case 3:
                conjuntos.unirConjuntos();
                break;

            case 4:
                conjuntos.intersecao();
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