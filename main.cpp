#include <iostream>
#include <cstdlib>

using namespace std;

int* resize(int* list, int newSize, int sizeFree);
void add(int *list, int value, int &sizeFree, int &size);
void listElements(int *list, int sizeFree, int sizeReal);
void del(int *list, float &percent25, int &sizeFree, int &sizeReal);


int main()
{
    int sizeReal = 50;
    int sizeFree = sizeReal;
    float percent25 = (sizeReal * 25) / 100;
    int *list = (int *)malloc(sizeReal * sizeof(int));

    cout << endl << "----------------- INÍCIO DOS TESTES -----------------" << endl << endl;

    for (int i = 1; i <= 50; i++)
    {
        add(list, i, sizeFree, sizeReal);
    }
    cout << endl << "Lista com 50 elementos:" << endl;
    listElements(list, sizeFree, sizeReal);
    
    cout << endl << "Teste de adição de elementos:" << endl;
    for (int i = 1; i <= 20; i++)
    {
        add(list, i, sizeFree, sizeReal);
    }
    cout << endl << "Lista com tamanho dobrado:" << endl;
    listElements(list, sizeFree, sizeReal);

    cout << endl << "Teste de remoção de elementos:" << endl;
    for (int i = 0; i < 55; i++)
    {
        del(list, percent25, sizeFree, sizeReal);
    }
    cout << endl << "Lista com tamanho reduzido pela metade:" << endl;
    listElements(list, sizeFree, sizeReal);

    free(list);
    cout << endl <<  "----------------- FIM DOS TESTES -----------------" << endl << endl;

    return 0;
}

int* resize(int* list, int newSize, int sizeFree)
{
    int* vetor = (int*)realloc(list, newSize * sizeof(int));
    
    for(int i = newSize; i < newSize - sizeFree; i--)
    {
        vetor[i] = 0;
    }
    
    return vetor;
}

void add(int *list, int value, int &sizeFree, int &size)
{

    if (sizeFree - 1 == 0)
    {
        size = size * 2;
        sizeFree = size / 2;

        list = resize(list, size, sizeFree);
        cout << endl
             << "***************** Lista dobrou de tamanho! *****************" << endl
             << endl;
    }
    else
    {
        sizeFree--;
    }

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

void del(int *list, float &percent25, int &sizeFree, int &sizeReal)
{
    if (sizeFree < sizeReal)
    {
        sizeFree++;

        for (int i = sizeReal; i >= 0; i--)
        {
            if (list[i] != 0)
            {
                list[i] = 0;
                break;
            }
        }

        int occupied = sizeReal - sizeFree;

        if (occupied <= percent25)
        {
            sizeReal = sizeReal / 2;
            sizeFree = sizeReal - occupied;

            list = resize(list, sizeReal, sizeFree);
            cout << endl
                 << "************ Tamanho da lista diminuiu para metade! ************" << endl
                 << endl;
        }
    }
    else
    {
        cout << endl
             << "************ NÃO EXISTEM ITENS PARA REMOVER! ************" << endl
             << endl;
    }
}