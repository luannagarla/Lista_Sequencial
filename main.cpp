#include <iostream>
#include <cstdlib>

using namespace std;

void resize(int** list, int newSize);
void add(int* list, int value, int& sizeFree, int& size);
void listElements(int* list, int sizeFree, int sizeReal);
void del(int* list);

int main()
{
    int sizeReal = 5; //Capacidade inial de 50 
    int sizeFree = sizeReal;
    int* list = (int*)malloc(sizeReal * sizeof(int));
    
    cout << "----------------- INÍCIO DO SISTEMA -----------------" << endl;
    
    int choice;
    do {
        cout << "-----------------------------------------------------" << endl;
        cout << "O que você deseja fazer?" << endl << "Digite 1 para adicionar item" << endl << "Digite 2 para excluir último item da lista" 
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
                cout << "Opção 2" << endl;
                break;
            }
            case 3:{
                listElements(list, sizeFree, sizeReal);
                break;
            }
            case 4:{
                cout << "Obrigada por utilizar o sistema!" << endl;
                break;
            }
            default:{
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
    
    list[sizeFree] = value;
}

void listElements(int* list, int sizeFree, int sizeReal){
    
    for(int i = 0; i < sizeReal; i++){
        cout << i+1 << "° elemento: " << list[i] << endl;
    }
    
}

void del(int* list){
    // Se for menor que 25% da capacidade máxima: implemente um mecanismo que reduza a capacidade pela metade (função resize) 
        //Pesquisar se é necessário liberar o espaço alocado anteriormente
}