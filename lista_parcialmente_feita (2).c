#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int valor;
    struct no * prox;
}NO;

typedef struct StructAuxiliar {
    int valor2;
    struct StructAuxiliar * prox2;
}SA;

NO * inicio = NULL;
int tam = 0;


void add(int valor, int pos){

    if(pos >= 0 && pos <= tam){ //posicao valida
    
        //cria o no e seto valores
        NO * novo = malloc(sizeof(NO));
        novo->valor = valor;
        novo->prox = NULL;

        if(inicio == NULL){ //lista vazia!
            inicio = novo;
        }else if (pos == 0){
            //no inicio!
            novo->prox = inicio;
            inicio = novo;
        }else if(pos == tam){
            //no final!

            //caminhar com a aux ate o ultimo elemento
            NO * aux = inicio;
            for (int i = 0; i< tam -1; i++){
                aux = aux->prox;
            }
            aux->prox = novo;
        }else{
            //"meio"
            NO * aux = inicio;
            for (int i = 0; i< pos -1; i++){
                aux = aux->prox;
            }
            novo->prox = aux->prox;
            aux->prox = novo;
        }
        tam++;


        // senao é no "meio" (ABSTRAI!!!)
    }else{ //posicao nao eh valida
        printf("Nao eh possivel adicionar, posicao invalida!\n :'()");
    }
}


int remover(int pos){

   if(pos >= 0 && pos < tam){ //posicao valida
        int valor;

        // inicio
        if(pos == 0){

            NO * lixo = inicio;
            inicio = inicio->prox;
            valor = lixo->valor;
            free(lixo);
            tam--;
        // fim
        }else if (pos == tam -1){
            NO * lixo = inicio;
            NO * aux = inicio;

            for (int i = 0; i < pos; i++) {
                lixo = lixo->prox;
                if (i <= pos - 1) {
                    aux = aux->prox;
                }
            }
            aux->prox = lixo->prox;
            valor = lixo->valor;
            free(lixo);
            tam--;

        // meio
        }else if (pos >= 0 && pos < tam) {
            NO * aux = inicio;
            NO * lixo = inicio;

            for (int i = 0; i < pos-1; i++) 
                aux = aux->prox;
            lixo = aux->prox;
            aux->prox=aux->prox->prox;
            valor = lixo->valor;
            free(lixo);
            tam--;

        }

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

int main(){

    add(10, 0);
    add(21, 1);
    add(32, 2);
    add(43, 3);
    add(54, 4);
    add(65, 5);
    add(76, 6); 
    printf("Valor removido 1 = %i\n", remover(6));
    printf("Tamanho: %i\n", tam);
    imprimir();
    system("PAUSE");
    return 0;
}


