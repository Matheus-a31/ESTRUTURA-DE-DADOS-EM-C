#include<stdio.h>
#include<stdlib.h>

typedef struct pizzaria{
    int valor;
    char tamanho;
    char* recheio;
    char* nome_cliente;
    struct pizzaria *prox;
} PIZZARIA;

PIZZARIA *inicio = NULL;
PIZZARIA *fim = NULL;
int tam2 = 0;

void add_pizza(char *recheio, char tamanho, char *nome_cliente, int valor){
    
    PIZZARIA *pedido_novo = malloc(sizeof(PIZZARIA));
    pedido_novo->recheio = recheio;
    pedido_novo->tamanho = tamanho;
    pedido_novo->nome_cliente = nome_cliente;
    pedido_novo->valor = valor;
    pedido_novo->prox = NULL;
    //sem nenhum pedido 
    if(inicio == NULL){
        inicio = pedido_novo;
        fim = pedido_novo;
    } else { //com pelos menos 1 pedido adiciona no fim
        fim->prox = pedido_novo;
        fim = pedido_novo;
    }
    tam2++;
}

PIZZARIA* remover_pizza(){
    if(inicio != NULL){
        PIZZARIA *lixo = inicio;
        inicio = inicio->prox;
        tam2--;

        // Imprime as informações da pizza removida
        printf("Removido: Recheio: %s, Tamanho: %c, Nome cliente: %s, Valor: %d\n\n", lixo->recheio, lixo->tamanho, lixo->nome_cliente, lixo->valor);
        
        // Libera a memória da pizza removida
        free(lixo);
        
        return NULL; // Retorna NULL para indicar que pizza foi removida
    } else {
        printf("Fila vazia :'( ...\n");
        return NULL;
    }
}

void imprimir_pizza(){
    PIZZARIA *aux = inicio;
    for(int i = 0; i < tam2; i++){
        printf("Recheio: %s, Tamanho: %c, Nome cliente: %s, valor: %d\n\n", aux->recheio, aux->tamanho, aux->nome_cliente, aux->valor);
        aux = aux->prox;
    }
}

int main(){
 
    add_pizza("4 queijos", 'G', "Matheus", 40);
    add_pizza("Marguerita", 'M', "Joao", 30);
    add_pizza("Frango", 'G', "Ana", 40);
    
    imprimir_pizza();
    printf("TAMANHO DA FILA: %d\n\n",tam2);
    
    remover_pizza();
    printf("-------NOVA FILA--------\n\n");
    imprimir_pizza();
    printf("TAMANHO DA FILA: %d",tam2);
    
    return 0;
}