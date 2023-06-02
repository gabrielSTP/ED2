#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

#define MAX_NOMES 1000
#define MAX_CARACTER 100

void troca(char nomes[][MAX_CARACTER], int i, int j)
{
    char temp[MAX_CARACTER];
    strcpy(temp, nomes[i]);
    strcpy(nomes[i], nomes[j]);
    strcpy(nomes[j], temp);
}

void bubble_sort(char nomes[][MAX_CARACTER], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (strcmp(nomes[j], nomes[j + 1]) > 0)
            {
                troca(nomes, j, j + 1);
            }
        }
    }
}

void selection_sort(char nomes[][MAX_CARACTER], int n)
{
    int i, j, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(nomes[j], nomes[min]) < 0)
            {
                min = j;
            }
        }
        troca(nomes, i, min);
    }
}

void insertion_sort(char nomes[][MAX_CARACTER], int n)
{
    int i, j;
    char chave[MAX_CARACTER];
    for (i = 1; i < n; i++)
    {
        strcpy(chave, nomes[i]);
        j = i - 1;
        while (j >= 0 && strcmp(nomes[j], chave) > 0)
        {
            strcpy(nomes[j + 1], nomes[j]);
            j--;
        }
        strcpy(nomes[j + 1], chave);
    }
}

void merge(char nomes[][MAX_CARACTER], int inicio, int meio, int fim)
{
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    char esquerda[n1][MAX_CARACTER];
    char direita[n2][MAX_CARACTER];

    for (i = 0; i < n1; i++)
    {
        strcpy(esquerda[i], nomes[inicio + i]);
    }
    for (j = 0; j < n2; j++)
    {
        strcpy(direita[j], nomes[meio + 1 + j]);
    }

    i = 0;
    j = 0;
    k = inicio;
    while (i < n1 && j < n2)
    {
        if (strcmp(esquerda[i], direita[j]) <= 0)
        {
            strcpy(nomes[k], esquerda[i]);
            i++;
        }
        else
        {
            strcpy(nomes[k], direita[j]);
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        strcpy(nomes[k], esquerda[i]);
        i++;
        k++;
    }

    while (j < n2)
    {
        strcpy(nomes[k], direita[j]);
        j++;
        k++;
    }
}

void merge_sort(char nomes[][MAX_CARACTER], int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = (inicio + fim) / 2;
        merge_sort(nomes, inicio, meio);
        merge_sort(nomes, meio + 1, fim);
        merge(nomes, inicio, meio, fim);
    }
}

void printNames(char nomes[][MAX_CARACTER], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        cout << nomes[i];
    }
}

int main()
{
    FILE *arquivo;
    int opc;
    int n = 0;
    char nomes[MAX_NOMES][MAX_CARACTER];
    char nome_arquivo[] = "nome2.txt";

    arquivo = fopen("nome2.txt", "r");

    if (arquivo == NULL)
    {
        cout << "Erro ao abrir o arquivo" << nome_arquivo << "\n";
        return -1;
    }

    while (!feof(arquivo))
    {
        fgets(nomes[n], MAX_CARACTER, arquivo);
        n++;
    }

    fclose(arquivo);

    cout << "Escolha qual algoritmo de ordenacao deseja:\n";
    cout << "1 - Bubble Sort\n";
    cout << "2 - Selection Sort\n";
    cout << "3 - Insertion Sort\n";
    cout << "4 - Merge Sort\n";
    cout << "5 - Sair\n";

    cin >> opc;

    switch (opc)
    {
    case 1:
        cout << "Ordernação com Bubble Sort:";
        bubble_sort(nomes, n);
        break;
    case 2:
        cout << "Ordernação com Selection Sort:";
        selection_sort(nomes, n);
        break;
    case 3:
        cout << "Ordernação com Insertion Sort:";
        insertion_sort(nomes, n);
        break;
    case 4:
        cout << "Ordernação com Merge Sort:";
        merge_sort(nomes, 0, n - 1);
        break;
    case 5:
        cout << "Encerrando... \n";
        return 0;
    default:
        cout << "Opcao invalida.\n";
        return -1;
    }

    printNames(nomes, n);
    /*printNames(nomes, n+1)*/
    return 0;
}
