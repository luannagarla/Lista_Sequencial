#include <iostream>
#include <cstdlib>

using namespace std;

void resize(int** list, int newSize);
void add(int* list, int value, int& sizeFree, int& size);
void listElements(int* list, int sizeFree, int sizeReal);
void del(int* list, float& percent25, int& sizeFree, int& sizeReal);

int main()
{
    int sizeReal = 8; //Capacidade inial de 50  -- alterar após os testes
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
                cout << "Opção inválida! Tente novamente." << endl;
            }
                
        }

    }while( choice != 3 );

    free(list);
    return 0;
}

void resize(int** list, int newSize) {
  
    int* temp = (int*)realloc(*list, newSize * sizeof(int));
    *list = temp; 
    //parce que toda vez que faço isso ele preenche tudo com lixo
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
    
    list[sizeFree] = value; //Queria adicionar no inicio da lista
}

void listElements(int* list, int sizeFree, int sizeReal){
    
    for(int i = 0; i < sizeReal; i++){
        cout << i+1 << "° elemento: " << list[i] << endl;
    }
    
}

void del(int* list, float& percent25, int& sizeFree, int& sizeReal){
    if(sizeFree < sizeReal){
        sizeFree++;
        list[sizeReal] = 0;
        
        int ocupped = sizeReal - sizeFree;
        
        if(ocupped == percent25){
            sizeReal = sizeReal / 2;
            sizeFree = sizeReal - ocupped;
            
            resize(&list, sizeReal);
            cout << endl << "************ Tamanho da lista diminuiu para metade! ************" << endl << endl;
        }  
    }
    else{
            cout << endl << "************ NÃO EXISTEM ITENS PARA REMOVER! ************" << endl << endl;
    }
    
}