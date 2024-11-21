#include <iostream>
#include <cstdlib>

using namespace std;

void resize(int** list, int newSize);
void add(int* list, int value, int& sizeFree, int& size);
void listElements(int* list, int sizeFree, int sizeReal);
void del(int* list, float& percent25, int& sizeFree, int& sizeReal);

int main()
{
    int sizeReal = 8; //Capacidade inial de 50  -- eu vou alterar após os testes
    int sizeFree = sizeReal;
    float percent25 = (sizeReal * 25) / 100;
    int* list = (int*)malloc(sizeReal * sizeof(int));
    
    cout << "----------------- INÍCIO DO SISTEMA -----------------" << endl;
    
    int choice;
    do {
        cout << "-----------------------------------------------------" << endl;
        cout << "O que você deseja fazer?" << endl << "Digite 1 para adicionar item" << endl << "Digite 2 para excluir o último item da lista" 
        << endl << "Digite 3 para listar os elementos" << endl << "Digite 4 para finalizar o sistema" << endl << "Resposta: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int val;
                cout << "Digite o valor a ser adicionado: ";
                cin >> val;
                
                add(list, val, sizeFree, sizeReal);
                break;
            }
            case 2: {                
                del(list, percent25, sizeFree, sizeReal);
                break;
            }
            case 3: {
                listElements(list, sizeFree, sizeReal);
                break;
            }
            case 4: {
                cout << "Obrigada por utilizar o sistema!" << endl;
                break;
            }
            default: {
                cout << endl << "***************** Opção inválida! Tente novamente *****************" << endl << endl;
            }
                
        }

    }while( choice != 4 );

    free(list);
    return 0;
}

void resize(int** list, int newSize) {
  
    int* temp = (int*)realloc(*list, newSize * sizeof(int));
    *list = temp; 
    
    //Parece que sobrescreve com lixo
}

void add(int* list, int value, int& sizeFree, int& size){
    
    if(sizeFree - 1 == 0){
        size = size * 2;
        sizeFree = size / 2;
        
        resize(&list, size);
        cout << endl << "***************** Lista dobrou de tamanho! *****************" << endl << endl;
    }
    else{
        sizeFree--;
    }
    
    for (int i = size - sizeFree; i > 0; i--) {
        list[i] = list[i - 1];
    }

    list[0] = value;
}

void listElements(int* list, int sizeFree, int sizeReal) {
    cout << endl << endl << "Elementos da lista:" << endl;
    for (int i = 0; i < sizeReal; i++) {
        cout << i + 1 << "° elemento: " << list[i] << endl;
    }
}

void del(int* list, float& percent25, int& sizeFree, int& sizeReal){
    if(sizeFree < sizeReal){
        sizeFree++;
        list[0] = 0;
        
        int occupied = sizeReal - sizeFree;
        
        if(occupied <= percent25){
            sizeReal = sizeReal / 2;
            sizeFree = sizeReal - occupied;
            
            resize(&list, sizeReal);
            cout << endl << "************ Tamanho da lista diminuiu para metade! ************" << endl << endl;
        }  
    }
    else{
            cout << endl << "************ NÃO EXISTEM ITENS PARA REMOVER! ************" << endl << endl;
    }
    
}