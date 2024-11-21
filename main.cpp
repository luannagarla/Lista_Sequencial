#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    //Capacidade inial de 50 
       // loop para o usuario adicionar ou remover itens (ou sair do sistema)
    int* lista = (int*)malloc(50 * sizeof(int));
    
    cout << "----------------- INÍCIO DO SISTEMA -----------------" << endl;
    
    int opcao;
    do {
        cout << "---------------------------------------------------" << endl;
        cout << "O que você deseja fazer?" << endl << "Digite 1 para adicionar item" << endl << "Digite 2 para excluir item" << endl << "Digite 3 para finalizar o sistema" << endl;
        cin >> opcao;

        switch (opcao) {
            case 1: {
                cout << "Opção 1";
                break;
            }
            case 2: {                
                cout << "Opção 2";
                break;
            }
            case 3:
                cout << "Obrigada por utilizar o sistema!" << endl;
                break;
            default:
                cout << "Opção inválida! Tente novamente." << endl;
        }

    }while( opcao != 3 );

    // A cada alteração de elemento conferir o tamanho da lista:
    // Se for maior que 50: a lista deve dobrar de tamanho utilizando alocação dinâmica de memória (função resize)
    // Se for caia para 25% da capacidade máxima: implemente um mecanismo que reduza a capacidade pela metade (função resize) 
        //Pesquisar se é necessário liberar o espaço alocado anteriormente

    //Função realloc para redimensionar o vetor de forma dinâmica sem perder os dados armazenados
    //vetor = realloc(vetor, novo tamanho * sizeof(tipo));
    
    return 0;
}