/*
ECOS11A - Laboratorio de Sistemas Operacionais - T01
Prof Otavio de Souza Martins Gomes

Algoritmo de Escalonamento Fist Come, Fist Serve (FCFS)

por: Brenno de Oliveira da Rosa, 2021029935 e
    Lucas Luan Belarmino Barbosa, 2021017872
*/

#include <stdio.h>
#include <stdlib.h>

typedef enum{false, true}bool;

//variaveis globais
int nProcess;
int currentTime;
float waitingTime;
float runtime;
FILE* out;

//dados dos processos, são a representação dos processos
typedef struct no{
    int req, duracao, prio, numProc;
    struct no* prox;
}process;

process* list; //lista de processos que atuará como fila

//insere ordenando pelo tempo de requisição (req)
bool insert(int _req, int _duracao, int _prio){
    process* atual;
    process* ant;
    process* aux;

    //alocando processo
    aux = malloc(sizeof(process));
    aux->req=_req;
    aux->duracao=_duracao;
    aux->prio=_prio;
    aux->numProc=nProcess; 
    aux->prox=NULL;

    //iniciando as variaveis de controle
    atual = list;
    ant = NULL;

    while(atual!=NULL){
        if(atual->req > aux->req){
            aux->prox=atual;
            if(ant!=NULL){ //inserindo no meio da fila
                ant->prox=aux;
                return true;
            }
            list = aux;
            return true;
        }
        ant = atual;
        atual = atual->prox;
    }

   if(ant!=NULL){ 
        ant->prox=aux; //inserindo no final da fila
        return true;
    }else{
        list = aux; //primeiro elemento a ser inserido na fila
        return true;
    }

    return false;
}

void imprime(process* elem){
    fprintf(out,"\t\t\tID Processo: %d\n", elem->numProc);
    fprintf(out,"\t\t\t  Momento de inicio: %d\n", currentTime);
    waitingTime+=(float)(currentTime-elem->req);
    currentTime+=elem->duracao;
    runtime+=(float)(currentTime-elem->req);
    fprintf(out,"\t\t\t    Momento de fim: %d\n", currentTime);
    fprintf(out,"========================================================\n");
}
    
void pull_first(){

    process *aux;

    //retira o primeiro processo da fila
    aux = list;
    list = list->prox;
    
    if(aux!=NULL){
        if(currentTime<aux->req){
        /*obs.: Esse if serve para "pular" o tempo que o processador deveria 
          esperar parado, apenas pra otimização deste código. Caso queira-se
          uma maior semelhança com a realidade basta substituir este if por:

          while(currentTime<aux->req){currentTime++;}
        */
           currentTime=aux->req;
        }
        imprime(aux);
    }
    
    free(aux);
}

int main(){
    FILE* arq;
    int flagEOF;
    int duracao, req, prio;
    bool capError;

    //iniciando as variaveis
    list = NULL;
    nProcess = 0;
    currentTime= 0;
    runtime = 0;
    waitingTime = 0;
    capError = true;

    printf("Abrindo o arquivo...\n\n");

    //No arquivo txt, os dados de cada linha representam respectivamente a requisição, o tempo de execução e a prioridade
    //O ID Processo eh referencia da linha a qual foram lidos aqueles dados do processo (Ex.: linha 3 contem os dados do processo 3)
    arq = fopen("stdin.txt", "r");

    printf("Lendo o arquivo de input...\n\n");

    flagEOF = fscanf(arq, "%d %d %d", &req, &duracao, &prio);

    while(flagEOF!=EOF && capError){
        nProcess++;
        capError = insert(req, duracao, prio);
        flagEOF = fscanf(arq, "%d %d %d", &req, &duracao, &prio);
    }

    if(!capError){
        printf("[Ocorreu um erro ao realizar a leitura do arquivo!]\n\n");
        fclose(arq);
        printf("Arquivo de input fechado.\n\n");
        return 0;
    }

    fclose(arq);
    printf("Arquivo de input fechado.\n\n");
    printf("Criando/abrindo o arquivo output.txt...\n\n");
    out = fopen("stdout.txt", "w");

    printf("Escrevendo no arquivo...\n\n");
    fprintf(out,"\t\tALGORITMO FCFS (First Come First Serve)\n");
    fprintf(out,"========================================================\n");
    while(list != NULL){
        pull_first();
    }
    fprintf(out,"\t\t\tTempo Médio de Espera: %.2f\n\t\t\t Tempo Médio de Vida: %.2f",waitingTime/nProcess,runtime/nProcess);
    fprintf(out,"\n========================================================\n");
    fprintf(out,"\nby Brenno de Oliveira da Rosa & Lucas Luan Belarmino Barbosa\n\n");
    fclose(out);
    printf("[As operacoes foram concluidas com exito!]\n\n");
    printf("~fim do programa~\n");

    
    return 0;
}
