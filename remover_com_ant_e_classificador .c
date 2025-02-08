
#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int valor;
    struct no * prox;
    struct no * ant;
}NO;

NO * inicio = NULL;
NO * fim = NULL;
int tam = 0;

void add(int valor, int pos){

    if(pos >= 0 && pos <= tam){
        //criar o no e seto os valores dele
        NO * novo = malloc(sizeof(NO));
        novo->valor = valor;
        novo->prox = NULL;
        novo->ant = NULL;

        if(inicio == NULL){ //lista vazia!
            inicio = novo;
            fim = novo;
        }else if(pos == 0){ // no inicio da lista
            novo->prox = inicio;
            inicio->ant = novo;
            inicio = novo;
        }else if(pos == tam){ //no fim da lista
            fim->prox = novo;
            novo->ant = fim;
            fim = novo;
        }else{
            // no "meio" da lista
            NO * aux = inicio;
            for(int i = 0; i< pos; i++){
                aux = aux->prox;
            }
            //realizar as operacoes de encaixe!!! :D
            //novo->prox = aux;
            //aux->ant->prox = novo;
            //novo->ant = aux->ant;
            //aux->ant = novo;

            novo->prox = aux;
            novo->ant = aux->ant;
            aux->ant->prox = novo;
            aux->ant = novo;
        }
        tam++;
    }else{
        printf("Insercao nao realizada. Posicao %d eh invalida!\n", pos);
    }
}


int remover(int pos) {
    if (pos >= 0 && pos < tam) { 
        int valor;
        NO *lixo;
        if (pos == 0) { // inicio
            lixo = inicio;
            inicio = inicio->prox;
            if (inicio != NULL) {
                inicio->ant = NULL;
            } else {
                fim = NULL; // Lista ficou vazia
            }
        } else if (pos == tam - 1) { // fim
            lixo = fim;
            fim = fim->ant;
            if (fim != NULL) {
                fim->prox = NULL;
            } else {
                inicio = NULL; // Lista ficou vazia
            }
        } else { // meio
            NO *aux = inicio;
            for (int i = 0; i < pos; i++) {
                aux = aux->prox;
            }
            lixo = aux;
            aux->ant->prox = aux->prox;
            aux->prox->ant = aux->ant;
        }
        valor = lixo->valor;
        free(lixo);
        tam--;
        return valor;
    } else {
        printf("Remocao nao realizada. Posicao %d eh invalida!\n", pos);
        return -1;
    }
}

void verifica_classificacao() {
    NO *atual = inicio;
    while (atual != NULL) {
        int valor_anterior = (atual->ant != NULL) ? atual->ant->valor : atual->valor;
        int valor_proximo = (atual->prox != NULL) ? atual->prox->valor : atual->valor;

        if (atual->valor > valor_anterior && atual->valor > valor_proximo) {
            printf("NO FORTE: %d\n", atual->valor);
        } else if (atual->valor < valor_anterior && atual->valor < valor_proximo ||
                   atual->valor < valor_anterior && atual->valor == valor_proximo||
                   atual->valor == valor_anterior && atual->valor < valor_proximo) {
            printf("NO FRACO: %d\n", atual->valor);
        } else if ((atual->valor < valor_anterior && atual->valor > valor_proximo) ||
                   (atual->valor > valor_anterior && atual->valor < valor_proximo) ||
                   (atual->valor == valor_anterior && atual->valor == valor_proximo)) {
            printf("NO NEUTRO: %d\n", atual->valor);
        } else {
            printf("NO NEUTRO: %d\n", atual->valor);
        }

        atual = atual->prox;
    }
}


void imprimir(){
    NO * aux = fim;
    for(int i = 0; i< tam; i++){
        printf("%d\n", aux->valor);
        aux = aux->ant;
    }
}

int main(){

    add(20,0);
    add(30, 1);
    add(10, 2);
    add(45, 3);
    add(12, 4);
    add(8, 5);
    add(43, 6);
    add(21, 7);
    add(15, 8);
    add(5, 9);
    add(1, 10);
   
    remover(10);
    imprimir();
    
    
    verifica_classificacao();
    system("PAUSE");
    return 0;
}