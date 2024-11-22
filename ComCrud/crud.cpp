#include <iostream>
#include <cstdlib>

using namespace std;

int* resize(int* &list, int newSize, int sizeFree);
void add(int* &list, int value, int &sizeFree, int &size);
void listElements(int *list, int sizeFree, int sizeReal);
void del(int* &list, float &percent25, int &sizeFree, int &sizeReal);

int main()
{
    int sizeReal = 8; // Capacidade inial de 50  -- eu vou alterar após os testes
    int sizeFree = sizeReal;
    float percent25 = (sizeReal * 25) / 100;
    int *list = (int *)malloc(sizeReal * sizeof(int));

    cout << "----------------- INÍCIO DO SISTEMA -----------------" << endl;

    int choice;
    do
    {
        cout << "-----------------------------------------------------" << endl;
        cout << "O que você deseja fazer?" << endl
             << "Digite 1 para adicionar item" << endl
             << "Digite 2 para excluir o último item da lista"
             << endl
             << "Digite 3 para listar os elementos" << endl
             << "Digite 4 para finalizar o sistema" << endl
             << "Resposta: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int val;
            cout << "Digite o valor a ser adicionado: ";
            cin >> val;

            add(list, val, sizeFree, sizeReal);
            break;
        }
        case 2:
        {
            del(list, percent25, sizeFree, sizeReal);
            break;
        }
        case 3:
        {
            listElements(list, sizeFree, sizeReal);
            break;
        }
        case 4:
        {
            cout << "Obrigada por utilizar o sistema!" << endl;
            break;
        }
        default:
        {
            cout << endl
                 << "***************** Opção inválida! Tente novamente *****************" << endl
                 << endl;
        }
        }

    } while (choice != 4);

    free(list);
    return 0;
}

int* resize(int* &list, int newSize, int sizeFree)
{
    int* vetor = (int*)realloc(list, newSize * sizeof(int));

    for (int i = newSize - sizeFree; i < newSize; i++)
    {
        vetor[i] = 0;
    }

    return vetor;
}

void add(int* &list, int value, int &sizeFree, int &size)
{
    if (sizeFree == 0)
    {
        size *= 2;
        sizeFree = size / 2;

        list = resize(list, size, sizeFree);
        cout << endl
             << "***************** Lista dobrou de tamanho! *****************" << endl;
    }

    sizeFree--;
    for (int i = 0; i < size; i++)
    {
        if (list[i] == 0)
        {
            list[i] = value;
            break;
        }
    }
}

void listElements(int *list, int sizeFree, int sizeReal)
{
    for (int i = 0; i < sizeReal; i++)
    {
        cout << i + 1 << "° elemento: " << list[i] << endl;
    }
}

void del(int* &list, float &percent25, int &sizeFree, int &sizeReal)
{
    if (sizeFree < sizeReal)
    {
        for (int i = sizeReal - 1; i >= 0; i--)
        {
            if (list[i] != 0)
            {
                list[i] = 0;
                sizeFree++;
                break;
            }
        }

        int occupied = sizeReal - sizeFree;

        if (occupied <= percent25 && sizeReal > 1)
        {
            sizeReal /= 2;
            sizeFree = sizeReal - occupied;

            list = resize(list, sizeReal, sizeFree);
            cout << endl
                 << "************ Tamanho da lista diminuiu para metade! ************" << endl;
        }
    }
    else
    {
        cout << "************ NÃO EXISTEM ITENS PARA REMOVER! ************" << endl;
    }
}
