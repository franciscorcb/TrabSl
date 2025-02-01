# Trabalho de Estrutura de Dados 1

## Informações Gerais

- **Nome:** Francisco Roberto  
- **Professor:** Anselmo Cardoso de Paiva  
- **Instituição:** UFMA - Universidade Federal do Maranhão  

Este projeto é um trabalho desenvolvido para a disciplina de Estrutura de Dados 1, ministrada pelo professor Anselmo Cardoso. O objetivo é implementar um TAD (Tipo Abstrato de Dados) para manipulação de listas simplesmente encadeadas.

---

## Informações Técnicas

- **Sistema Operacional:** Windows 11.
- **Compilador:** GCC.
- **Linguagem:** C.
- **IDE:** Visual Studio Code. 

### Como Compilar e Executar

1. Abra o terminal no Visual Studio Code.  
2. Execute o seguinte comando para compilar o programa:  
   ```bash
   gcc progsl.c cofosl.c cofosl.h -o teste.exe
   ```
3. Após a compilação, execute o programa gerado:  
   ```bash
   .\"teste.exe"
   ```

---

## Sobre o Código

### Arquivo `progsl.c`
Este arquivo contém a função principal do programa. É nele onde as funções são chamadas e onde o usuario pode interagir

### Arquivo `cofosl.h`
Este arquivo contém as especificações do TAD. Nele estão definidos:
- As estruturas.
- As funções do arquivo cofosl.c.
- E as macros e contantes utilizadas.

### Arquivo `cofosl.c`
Aqui estão as **implementações** das funções declaradas no arquivo `cofosl.h`. Este arquivo contém a lógica para manipulação da lista simplesmente encadeada, incluindo:
- Criação e destruição da lista.
- Inserção e remoção de elementos.
- Contagem de elementos.

---
Mais detalhes em cada arquivo.