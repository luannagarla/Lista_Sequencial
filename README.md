# Lista com Redimensionamento Dinâmico

Projeto desenvolvido como parte da disciplina de Estrutura de Dados do curso de Ciência de Dados e Inteligência Artificial na Universidade Estadual de Londrina (UEL). O objetivo é consolidar conceitos fundamentais da disciplina como estruturas de listas, lógica de programação, alocação dinâmica de memória, ponteiros, versionamento de código, tipos de dados e outros tópicos essenciais em estruturas de dados.


---


**:dart: Objetivo** 

Desenvolver uma lista sequencial ordenada em C/C++ que permita redimensionamento dinâmico. A estrutura deve expandir ou reduzir sua capacidade automaticamente com base no número de elementos inseridos ou removidos.

**:clipboard: Especificações**

*   A capacidade inicial da lista será de 50 elementos.
*   Ao atingir sua capacidade máxima (50 elementos), a lista deve dobrar de tamanho utilizando alocação dinâmica de memória.
*   Para evitar desperdício de memória, implemente um mecanismo que reduza a capacidade pela metade caso o número de elementos caia para 25% da capacidade total.