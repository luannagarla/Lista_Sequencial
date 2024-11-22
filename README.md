# Lista com Redimensionamento Dinâmico

Projeto desenvolvido como parte da disciplina de Estrutura de Dados do curso de Ciência de Dados e Inteligência Artificial na Universidade Estadual de Londrina (UEL). O objetivo é consolidar conceitos fundamentais da disciplina como estruturas de listas, lógica de programação, alocação dinâmica de memória, ponteiros, versionamento de código, tipos de dados e outros tópicos essenciais em estruturas de dados.


---


**:dart: Objetivo** 

Desenvolver uma lista sequencial ordenada em C/C++ que permita redimensionamento dinâmico. A estrutura deve expandir ou reduzir sua capacidade automaticamente com base no número de elementos inseridos ou removidos.

**:clipboard: Especificações**

- [X]   A capacidade inicial da lista é de 50 elementos.
- [X]   Ao atingir sua capacidade máxima (50 elementos), a lista dobra de tamanho utilizando alocação dinâmica de memória.
- [X]   Para evitar desperdício de memória, foi implementado um mecanismo que reduza a capacidade pela metade caso o número de elementos caia para 25% da capacidade total.


---


**:question: Sobre o código** 

*   O arquivo [main.cpp](https://github.com/luannagarla/Lista_Sequencial/blob/main/main.cpp) implementa um teste automatizado de uma lista com redimensionamento dinâmico, permitindo observar seu funcionamento com apenas um clique.
*   Já o arquivo [crud.cpp](https://github.com/luannagarla/Lista_Sequencial/blob/main/ComCrud/crud.cpp) apresenta uma implementação de CRUD, onde é possível adicionar itens manualmente, acompanhar as operações realizadas e imprimir a lista após cada inserção ou remoção, facilitando o entendimento detalhado do código.