#include <stdio.h>

struct Livro
{
    char titulo[100];
    char autor[100];
    int numeroPaginas;

    void ler()
    {
        printf("Qual o nome do livro? ");
        scanf("%[^\n]%*c", titulo);
        printf("Qual o nome do autor do livro? ");
        scanf("%[^\n]%*c", autor);
        printf("Qual o numero de paginas do livro? ");
        scanf("%d%*c", &numeroPaginas);

        printf("\n");
    }

    void imprimir()
    {
        printf("\n");
        printf("Titulo: %s\n", titulo);
        printf("Autor: %s\n", autor);
        printf("Numero de paginas %d\n", numeroPaginas);
    }
};

struct Biblioteca
{

    Livro livros[10];
    int totalLivros = 0;

    void cadastrarLivro()
    {
        if (totalLivros == 10)
        {
            printf("Limite de 10 livros atingido.");
        }

        livros[totalLivros].ler();
        totalLivros++;
    }

    void imprimirLivros()
    {
        if (totalLivros > 0)
        {
            printf("Livros cadastrados:\n");

            for (int i = 0; i < totalLivros; i++)
            {
                livros[i].imprimir();
            }

            printf("\n");
        }
        else
        {
            printf("Nao ha livros cadastrados!\n\n");
        }
    }

    void imprimirMaiorLivro()
    {
        if (totalLivros > 0)
        {
            Livro maiorLivro = livros[0];

            for (int i = 1; i < totalLivros; i++)
            {
                if (livros[i].numeroPaginas > maiorLivro.numeroPaginas)
                {
                    maiorLivro = livros[i];
                }
            }

            maiorLivro.imprimir();
        }
        else
        {
            printf("Nao ha livros cadastrados!\n\n");
        }
    }
};

struct Menu
{
    Biblioteca biblioteca;

    void executar()
    {
        int opcao;

        do
        {
            printf("1. Cadastrar livro\n");
            printf("2. Listar livros\n");
            printf("3. Mostrar maior livro\n");

            scanf("%d%*c", &opcao);

            printf("\n");

            switch (opcao)
            {
            case 1:
                biblioteca.cadastrarLivro();
                break;

            case 2:
                biblioteca.imprimirLivros();
                break;

            case 3:
                biblioteca.imprimirMaiorLivro();
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