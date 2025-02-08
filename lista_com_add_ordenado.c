#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int valor;
    struct no * prox;
}NO;

NO * inicio = NULL;
NO * fim = NULL;
int tam = 0;
int tam_ordenado = 0;

void add(int valor, int pos){

    if(pos >= 0 && pos <= tam){ //posicao valida

        //cria o no e seto valores
        NO * novo = malloc(sizeof(NO));
        novo->valor = valor;
        novo->prox = NULL;

        if(inicio == NULL){ //lista vazia! - constante
            inicio = novo;
            fim = novo;
        }else if (pos == 0){ //add no inicio! - constante
            novo->prox = inicio;
            inicio = novo;
        }else if(pos == tam){//add no fim! - constante
            fim->prox = novo;
        }else{//add no "meio" - linear
            NO * aux = inicio;
            for (int i = 0; i< pos -1; i++){
                aux = aux->prox;
            }
            novo->prox = aux->prox;
            aux->prox = novo;
        }
        tam++;
    }else{ //posicao nao eh valida
        printf("Nao eh possivel adicionar, posicao invalida!\n :'()");
    }
}

void add_ordenado (int valor){

    NO * novo = malloc(sizeof(NO));
    novo->valor = valor;
    novo->prox = NULL;

    if (inicio == NULL) { //lista vazia
        inicio = novo;
        fim = novo;
        tam_ordenado++;
    } else if (valor <= inicio->valor) { //lista não vazia antes
        novo->prox = inicio;
        inicio = novo;
        tam_ordenado++;
    } else { // lista não vazia depois
        NO * aux = inicio;
        while (aux->prox != NULL && valor > aux->prox->valor) {
            aux = aux->prox;
        }
        novo->prox = aux->prox;
        aux->prox = novo;
        tam_ordenado++;
    }
}


int remover_ordenado(int valor) {
    NO *aux = inicio;
    NO *ant = NULL;

    while (aux != NULL) {
        if (aux->valor == valor) {
            if (ant == NULL) { // o nó a ser removido é o primeiro nó
                inicio = aux->prox;
            } else {
                ant->prox = aux->prox;
            }

            if (aux == fim) { // o nó a ser removido é o último nó
                fim = ant;
            }

            free(aux);
            tam_ordenado--;
            return 1; 
        }
        ant = aux;
        aux = aux->prox;
    }

    return 0; // valor não encontrado
}



int remover(int pos){

   if(pos >= 0 && pos < tam){ //posicao valida
        int valor;
        NO *lixo;
        if(pos == 0){ //remover no inicio - constante

            lixo = inicio;
            inicio = inicio->prox;
            valor = lixo->valor;

            //ATENCAO: é necessario criar um tratamento
            // para o caso da lista ter apenas um
            // unico elemento

            if(tam == 1){
                fim = NULL;
            }

        }else if (pos == tam -1){ //remover no fim - linear
            NO * aux = inicio;
            for(int i = 0; i < pos-1; i++){
                aux = aux->prox;
            }

            lixo = aux->prox;
            aux->prox = NULL;
            valor = lixo->valor;

            //ATENCAO: eh necessario atualizar o ponteiro fim
            fim = aux;

        }else{ //remover no "meio" - linear
            NO * aux = inicio;
            for(int i = 0; i < pos-1; i++){
                aux = aux->prox;
            }

            lixo = aux->prox;
            aux->prox = lixo->prox;
            valor = lixo->valor;
        }
        free(lixo);
        tam--;
        return valor;
   }else{
     printf("Nao eh possivel remover, posicao invalida!\n :'()");
     return -1;
   }
}

void imprimir(){
    NO * aux = inicio;

    for (int i = 0; i< tam; i++){
        printf("%d\n", aux->valor);
        aux = aux->prox;
    }

}

void imprimir_ordenada(){
    NO * aux = inicio;

    for (int i = 0; i< tam_ordenado; i++){
        printf("%d\n", aux->valor);
        aux = aux->prox;
    }

}


int main(){

    // add(19, 0); //lista vazia
    // add(10, 0); //add no inicio
    // add(7, 2);  //add no fim
    // add(2, 2);  //add no meio
    // printf("valor removido= %d\n", remover(3));
    // add(5, 2);  //add no meio
    add_ordenado(9);
    add_ordenado(5);
    add_ordenado(7);
    add_ordenado(3);
    add_ordenado(6);
    remover_ordenado(3);
    imprimir_ordenada();
    system("PAUSE");

    return 0;
}
