#include <iostream>
using namespace std;

int main()
{
    //Capacidade inial de 50 

    //A cada adição de elemento conferir o tamanho da lista:
    // Se for maior que 50: a lista deve dobrar de tamanho utilizando alocação dinâmica de memória (função resize)
    // Se for caia para 25% da capacidade máxima: implemente um mecanismo que reduza a capacidade pela metade (função resize)

    //Utilize a função realloc para redimensionar o vetor de forma dinâmica sem perder os dados armazenados
    //vetor = realloc(vetor, novo tamanho * sizeof(tipo));

    return 0;
}

