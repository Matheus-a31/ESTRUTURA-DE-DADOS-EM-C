#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    char *cidade;
    double toneladas_cab;
    struct no *prox;
} NO;

NO *inicio = NULL;
NO *fim = NULL;
int tam = 0;


void adicionar(char *cidade, float toneladas_cab) {
    NO *novo = malloc(sizeof(NO));
    novo->cidade = cidade;  
    novo->toneladas_cab = toneladas_cab;
    novo->prox = NULL;

    if (inicio == NULL) {  // constante nao tem que percorer a lista.
        inicio = novo;
        fim = novo;
    } else {
        if (novo->toneladas_cab > inicio->toneladas_cab) { // constante nao tem que percorer a lista.
            novo->prox = inicio;
            inicio = novo;
        } else {
            NO *aux = inicio;
            NO *ant = NULL;
              // linear possui um loop, no caso o while, o que torna a velocidade e a complexidade lineares, pois depende bastante do tamanho da lista.
            while (aux->toneladas_cab >= novo->toneladas_cab) {
                ant = aux;
                aux = aux->prox;
            }
            if (aux == NULL) {  //constante, nao tem que percorer a lista
                fim->prox = novo;
                fim = novo;
            } else {  //constante nao tem que percorer a lista.
                ant->prox = novo;
                novo->prox = aux;
            }
        }
    }
    tam++;
}

char *remover() {
    char *cidade = "Sem opcoes!"; 
    if (inicio != NULL) {// constante nao tem que percorer a lista, só é removido o 1 elemento, igual uma pilha.
        NO *lixo = inicio;
        cidade = inicio->cidade;
        inicio = inicio->prox;     
        free(lixo);
        tam--;
    }
    return cidade;
}

void imprimir() {
    NO *aux = inicio; 
    while (aux != NULL) {  
        printf("\nCidade: %s\n", aux->cidade);
        printf("Toneladas de Carb.: %.2f\n", aux->toneladas_cab);  
        aux = aux->prox;
    }
    
}

int main() {
    adicionar("Rio de Janeiro", 13.8);
    adicionar("Russas",40.3);
    adicionar("Sao Paulo", 16.6);
    adicionar("Porto Velho", 23.3);
    adicionar("Altamira", 35.2);
    adicionar("Sao Felix do Xingu", 28.9);

    printf("Municipios e emissoes de gases do efeito estufa(dados em milhoes de toneladas de C02e): \n");
    imprimir();
    
    printf("\nCidade com maior qtd de GEE: %s.\n", remover());
    imprimir();
    system("PAUSE");
    return 0;
}