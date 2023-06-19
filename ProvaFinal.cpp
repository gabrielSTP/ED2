#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

void gerarVetor(int vetor[], int tamanho)
{
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++)
    {
        vetor[i] = rand() % 100; // Números aleatórios entre 0 e 99
    }
}

void imprimirVetor(int vetor[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        cout << vetor[i] << " ";
    }
    cout << endl;
}

void insertionSort(int vetor[], int tamanho)
{
    int i, chave, j;
    for (i = 1; i < tamanho; i++)
    {
        chave = vetor[i];
        j = i - 1;

        while (j >= 0 && vetor[j] > chave)
        {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }
}

void merge(int vetor[], int inicio, int meio, int fim)
{
    int i, j, k;
    int tamanhoEsquerda = meio - inicio + 1;
    int tamanhoDireita = fim - meio;

    int *esquerda = new int[tamanhoEsquerda];
    int *direita = new int[tamanhoDireita];

    for (i = 0; i < tamanhoEsquerda; i++)
        esquerda[i] = vetor[inicio + i];
    for (j = 0; j < tamanhoDireita; j++)
        direita[j] = vetor[meio + 1 + j];

    i = 0;
    j = 0;
    k = inicio;
    while (i < tamanhoEsquerda && j < tamanhoDireita)
    {
        if (esquerda[i] <= direita[j])
        {
            vetor[k] = esquerda[i];
            i++;
        }
        else
        {
            vetor[k] = direita[j];
            j++;
        }
        k++;
    }

    while (i < tamanhoEsquerda)
    {
        vetor[k] = esquerda[i];
        i++;
        k++;
    }

    while (j < tamanhoDireita)
    {
        vetor[k] = direita[j];
        j++;
        k++;
    }

    delete[] esquerda;
    delete[] direita;
}

void mergeSort(int vetor[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = inicio + (fim - inicio) / 2;

        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);

        merge(vetor, inicio, meio, fim);
    }
}

int buscaSequencial(int vetor[], int tamanho, int valor)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (vetor[i] == valor)
        {
            return i;
        }
    }
    return -1;
}

int buscaBinaria(int vetor[], int tamanho, int valor)
{
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim)
    {
        int meio = inicio + (fim - inicio) / 2;

        if (vetor[meio] == valor)
            return meio;

        if (vetor[meio] < valor)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }

    return -1;
}

int main()
{
    int opcao;
    int tamanho = 0;
    int *vetor = nullptr;
    bool vetorGerado = false;
    bool vetorOrdenado = false;

    while (true)
    {
        cout << "Escolha uma opcao:\n";
        cout << "a. Gerar vetor\n";
        cout << "b. Ordenar vetor\n";
        cout << "c. Busca sequencial\n";
        cout << "d. Busca binaria\n";
        cout << "e. Sair\n";

        cin >> opcao;

        if (opcao == 'e')
        {
            cout << "Encerrando...\n";
            break;
        }

        switch (opcao)
        {
        case 'a':
        {
            if (vetorGerado)
            {
                cout << "O vetor ja foi gerado!\n";
                break;
            }

            cout << "Informe o tamanho do vetor: ";
            cin >> tamanho;

            if (tamanho <= 0)
            {
                cout << "Tamanho invalido!\n";
                break;
            }

            vetor = new int[tamanho];
            gerarVetor(vetor, tamanho);
            vetorGerado = true;
            cout << "Vetor gerado com sucesso!\n";
            break;
        }
        case 'b':
        {
            if (!vetorGerado)
            {
                cout << "E necessario gerar o vetor antes de ordenar!\n";
                break;
            }

            if (vetorOrdenado)
            {
                cout << "O vetor ja esta ordenado!\n";
                break;
            }

            char algoritmo;
            cout << "Escolha o algoritmo de ordenacao:\n";
            cout << "I - Insertion Sort\n";
            cout << "M - Merge Sort\n";
            cin >> algoritmo;

            if (algoritmo == 'I')
            {
                insertionSort(vetor, tamanho);
                cout << "Vetor ordenado usando Insertion Sort.\n";
            }
            else if (algoritmo == 'M')
            {
                mergeSort(vetor, 0, tamanho - 1);
                cout << "Vetor ordenado usando Merge Sort.\n";
            }
            else
            {
                cout << "Opcao invalida!\n";
                break;
            }

            vetorOrdenado = true;
            break;
        }
        case 'c':
        {
            if (!vetorGerado)
            {
                cout << "E necessario gerar o vetor antes de fazer a busca!\n";
                break;
            }

            int valor;
            cout << "Informe o valor a ser buscado: ";
            cin >> valor;

            int posicao = buscaSequencial(vetor, tamanho, valor);
            if (posicao != -1)
            {
                cout << "Valor encontrado na posicao " << posicao << ".\n";
            }
            else
            {
                cout << "Valor nao encontrado no vetor.\n";
            }

            break;
        }
        case 'd':
        {
            if (!vetorGerado)
            {
                cout << "E necessario gerar e ordenar o vetor antes de fazer a busca binaria!\n";
                break;
            }

            if (!vetorOrdenado)
            {
                cout << "E necessario ordenar o vetor antes de fazer a busca binaria!\n";
                break;
            }

            int valor;
            cout << "Informe o valor a ser buscado: ";
            cin >> valor;

            int posicao = buscaBinaria(vetor, tamanho, valor);
            if (posicao != -1)
            {
                cout << "Valor encontrado na posicao " << posicao << ".\n";
            }
            else
            {
                cout << "Valor nao encontrado no vetor.\n";
            }

            break;
        }
        default:
            cout << "Opcao invalida!\n";
            break;
        }

        cout << endl;
    }

    delete[] vetor;

    return 0;
}
