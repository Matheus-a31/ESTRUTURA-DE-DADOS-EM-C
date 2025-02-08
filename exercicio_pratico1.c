#include<stdio.h>
#include<stdlib.h>

/*ATENCAO: COPIE E COLE ESSE CODIGO EM SUA IDE DE PREFERENCIA. EXECUTE E COMPREENDA O QUE ESTA IMPLEMENTADO PRIMEIRO, SOMENTE DEPOIS FAÇA OS EXERCICIOS*/

/* 1- Crie uma TAD para representar uma pessoa que ira ser cadastrado em um sistema de academia.
Dados necessarios: nome, matricula, idade, peso, altura*/

typedef struct Pessoa{
    char *nome;
    int matricula;
    int idade;
    float peso;
    float altura;
}aluno;


/* 2- Crie uma funcao que recebe os dados de um aluno da academia pelo terminal, salva esses dados 
em uma tad e apresenta no terminal seu nome e IMC */

void cria_tad_aluno(){
    
    aluno p1; 
    char nome[100];
    printf("Digite o nome do aluno: \n");
    scanf("%s", nome);
    p1.nome = nome;
    printf("Digite a matricula do aluno: \n");
    scanf("%d", &p1.matricula);
    printf("Digite a idade do aluno: \n");  
    scanf("%d", &p1.idade);
    printf("Digite a peso do aluno: \n"); 
    scanf("%f", &p1.peso);
    printf("Digite a altura do aluno: \n");
    scanf("%f", &p1.altura);
    
    float imc = p1.peso/(p1.altura*p1.altura);

    printf("O aluno %s tem o imc = %.2f.\n", p1.nome, imc);
    system("PAUSE");
}

/* 3 - Crie uma TAD para representar um produto que ira ser cadastrado em um sistema de supermecado.
Dados necessarios: nome do produto, codigo de barra, preco, dia, mes e ano de validade*/

typedef struct Produto{
   //coloque aqui os dados do produto
   char *nomedoProduto;
   int codigodeBarra;
   float preco;
   int dia;
   int mes;
   int ano_de_validade;
   float precoDesconto;
}produto;


/* 4 - Crie uma funcao que recebe os dados de um produto pelo terminal, salva esses dados 
em uma tad, verifica se ele esta dentro da validade, se sim apresenta no terminal seu nome 
e seu preco com desconto de 20%.
Se o produto esta fora da validade apenas apresenta seu nome e a informacao: fora da validade!*/

//Dica:
void cria_tad_produto(){
    //declare a varivel do tipo produto;
    //coloque o printf e o scanf para carregar cada um dos dados:
    //coloque separado o dia, mes e ano, uma variavel inteira para cada valor.
    //faca um conjunto de ifs para comparar o dia, mes e ano, com o dia atual:
    //use o dia da aula pratica como dia atual.
    //caso o produto esteja dentro da validade faca o calculo do desconto (0.2*preco do produto);
    //coloque um printf com o nome do produto e o valor deste calculo.
    //caso nao esteja dentro da validade basta colocar um printf com o nome do produto e a frase "fora da validade".

    produto pd1;
    char nomedoProduto[100];
    printf("\nDigite o nome do produto : \n");
    scanf("%s", nomedoProduto);

    pd1.nomedoProduto = nomedoProduto;

    printf("Digite o codigo de barra: \n");
    scanf("%d",&pd1.codigodeBarra);
    printf("Digite o preco: \n");
    scanf("%f",&pd1.preco);
    printf("Digite o dia: \n");
    scanf("%d",&pd1.dia);
    printf("Digite o mes: \n");
    scanf("%d",&pd1.mes);
    printf("Digite o ano: \n");
    scanf("%d",&pd1.ano_de_validade);

    float precoDesconto = pd1.preco * 0.8;


    if (pd1.ano_de_validade >= 2024 && pd1.mes >= 3 && pd1.dia >= 12) {
        printf("Nome do produto: %s\nPreco com desconto: R$%.2f", pd1.nomedoProduto, precoDesconto);
        system("PAUSE");
    } else {
        printf("O produto esta fora da validade desde %i/%i/%i", pd1.dia, pd1.mes, pd1.ano_de_validade);
        system("PAUSE");
    }
}

/*5 - Crie um TAD para representar um aluno da disciplina de ED que ira ser cadastrado em um sistema no sigaa
Dados necessarios: nome, matricula, nota da avaliacao teorica, nota do trabalho de ordenacao, nota dos exercicios praticos*/

typedef struct Alunoed{
   char *nome_do_aluno;
   int matricula_do_aluno;
   float nota_avaliacao_teorica;
   float nota_trabalho_de_ordenacao;
   float nota_dos_exercicios_praticos;
}alunoed;

//agora não temos mais dicas e com vocês! :D 

/*6 - Crie uma funcao que recebe os dados do aluno por terminal, salva esses dados 
em uma tad e aresenta no terminal o nome do aluno e se ele esta aprovado, 
reprovado ou de final na disciplina*/

void aluno_de_estrutura_de_dados(){

    alunoed al1;
    char nome_do_aluno[100];
    float media;

    printf("\nDigite o nome do aluno de ED: \n");
    scanf("%s", nome_do_aluno);
    al1.nome_do_aluno=nome_do_aluno;
    printf("Digite a matricula do respectivo aluno: \n");
    scanf("%d",&al1.matricula_do_aluno);
    printf("Digite a nota da avaliacao de ED: \n");
    scanf("%f",&al1.nota_avaliacao_teorica);
    printf("Digite a nota do trabalho de ordenacao: \n");
    scanf("%f",&al1.nota_trabalho_de_ordenacao);
    printf("Digite a nota dos exercicios praticos: \n"); 
    scanf("%f",&al1.nota_dos_exercicios_praticos);

    media = (al1.nota_avaliacao_teorica+al1.nota_trabalho_de_ordenacao+al1.nota_dos_exercicios_praticos)/3;

    if(media>=7.0){
        printf("O aluno de ED: %s foi aprovado !!! com nota: %.2f",al1.nome_do_aluno,media);
        system("PAUSE");
    }else if(media>=4.0 && media<7.0){
        printf("O aluno de ED: %s foi para prova final !!! com nota: %.2f",al1.nome_do_aluno,media);
        system("PAUSE");
    }else {
        printf("O aluno de ED: %s foi reprovado !!! com nota: %.2f",al1.nome_do_aluno,media);
        system("PAUSE");
    }


}
//agora não temos mais dicas e com vocês! :D 

int main(){
    cria_tad_aluno();
    cria_tad_produto();
    aluno_de_estrutura_de_dados();
   //colocar aqui a chamda da funcao criada na questao 6.
    return 0;
}




