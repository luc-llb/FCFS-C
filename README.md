# 🧮 First Come, First Serve (FCFS) em C

Implementação do algoritmo de escalonamento **First Come, First Serve (FCFS)** de forma **não-preemptiva**, utilizando a linguagem **C**.

Desenvolvido como projeto da disciplina **ECOS11A - Laboratório de Sistemas Operacionais** do curso de **Engenharia da Computação** da **Universidade Federal de Itajubá (UNIFEI)**.

## 🧾 Descrição

O código simula o ambiente de um sistema operacional, no qual os processos são:

* Lidos a partir de um arquivo de entrada [`stdin.txt`](./stdin.txt)
* Criados dinamicamente
* Adicionados a uma **fila de execução**, obedecendo a ordem de chegada (FCFS)

A simulação mostra como o escalonador FCFS atua no gerenciamento de processos, sem interrupções até a finalização de cada um.

## 📂 Arquivos

* [`ProjCodificacao.c`](./ProjCodificacao.c): implementação principal da lógica de escalonamento.
* [`stdin.txt`](./stdin.txt): arquivo de entrada contendo a lista de processos com seus respectivos tempos de chegada e durações.

## ▶️ Como Compilar e Executar

### Requisitos

* Compilador **C** (ex: `gcc`, `clang`)
* Terminal compatível (Linux, macOS ou Windows com terminal)

### Passos:

```bash
# Compilar o programa
gcc -o fcfs ProjCodificacao.c

# Executar
./fcfs
```

## 📚 Conceitos Envolvidos

* Escalonamento de processos (FCFS)
* Simulação de ambiente de sistema operacional
* Manipulação de arquivos em C
* Estruturas de dados (filas)

## 🎓 Sobre

Este projeto foi desenvolvido como atividade da disciplina **ECOS11A - Laboratório de Sistemas Operacionais**, ofertada pela **Universidade Federal de Itajubá (UNIFEI)** para o curso de **Engenharia da Computação**.

