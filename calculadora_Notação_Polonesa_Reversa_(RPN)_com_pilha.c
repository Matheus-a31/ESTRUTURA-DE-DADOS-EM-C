#include<stdio.h>
#include<stdlib.h>

//1)questao
typedef struct calculadora {
    char valor;
    struct calculadora *prox;
} CALCULADORA;

CALCULADORA *topo = NULL; 
int tam = 0;

void remover(){
    CALCULADORA *temp = topo;
    topo = topo->prox;
    tam -= 1;

    free(temp);
}

void add_calculadora(char valor) {
    CALCULADORA *nova_conta = (CALCULADORA *)malloc(sizeof(CALCULADORA));
    nova_conta->valor = valor;
    nova_conta->prox = topo;
    topo = nova_conta;
    tam++;

    if (valor == '+' || valor == '-' || valor == '*' || valor == '/') {
        if (tam < 3) {
            printf("Expressão inválida!\n");
            return;
        }

        int v1 = topo->prox->prox->valor - '0'; // Pega o segundo valor da pilha
        int v2 = topo->prox->valor - '0'; // Pega o primeiro valor da pilha
        float resultado;

        switch (valor) {
            case '+':
                resultado = v1 + v2;
                break;
            case '-':
                resultado = v1 - v2;
                break;
            case '*':
                resultado = v1 * v2;
                break;
            case '/':
                resultado = (float)v1 / v2;
                break;
        }

        // Remover os 3 últimos elementos da pilha
        remover();
        remover();
        remover();

        // Empilhar o resultado
        add_calculadora(resultado + '0');
    }
}

void imprimir_calculadora() {
    CALCULADORA *aux = topo;
    while (aux != NULL) {
        printf("%c\n", aux->valor);
        aux = aux->prox;
    }
}

int main(){
    
    add_calculadora('2');
    add_calculadora('1');
    add_calculadora('-');
    add_calculadora('4');
    add_calculadora('5');
    add_calculadora('+');
    add_calculadora('*');
    imprimir_calculadora();
    
    printf("\n");
    
    return 0;
}