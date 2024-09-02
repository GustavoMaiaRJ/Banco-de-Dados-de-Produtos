#include <stdio.h>
#include <string.h>

// definindo as dimensoes

#define MaxProd 100
#define TamProd 20

// Struct para armazenar informacoes do produto.

typedef struct {
    int codigo;
    char  nome[TamProd];
    float preco;
    int quantidade;
}Produto;

// Declarar o array de produtos e o contador de produtos.

Produto produtos[MaxProd];
int contador = 0;

// Declarar as funções. 

void InserirProd();
void ListarProd();
void BuscarProd();
void ExcluirProd();
void Menu();

int main(){
    Menu();
    return 0;
}

// Criar função para inserir um produto novo.

void InserirProd(){
    if (contador >= MaxProd) {
        printf("Limite de produtos atingidos!\n");
        return; // Essa condicao serve para que o limite de produtos nao seja atingido.
    }
    Produto novoProd;
    printf("Digite o codigo do produto:\n ");
    scanf("%d", &novoProd.codigo);
    getchar();

    // Analisar se o codigo ja existe ou nao.
    for (int i = 0; i < contador; i++){
        if (produtos[i].codigo == novoProd.codigo){ // Verificar dentro da array
            printf("Codigo de produto ja existente!\n");
            return;   
        }
    }

    printf("Digite o nome do produto:\n");
    scanf("%[^\n]%*c", &novoProd.nome);
    printf("Digite o preco do produto:\n");
    scanf("%f", &novoProd.preco);
    getchar();
    printf("Digite a quantidade em estoque:\n");
    scanf("%d", &novoProd.quantidade);
    getchar();
    // Adicionar ao contador de produtos o novo produto adicionado
    produtos[contador] = novoProd;
    contador++;
    printf("Produto adicionado com sucesso!");
}

// Criar função para listar os produtos cadastrados

void ListarProd(){
    if(contador == 0){
        printf("Nenhum produto registrado!\n");
        return; // caso nao tenha nenhum produto no array, e consequentemente no contador aparecera essa mensagem.
    }

    printf("Lista de Produtos\n");
    for (int i = 0; i < contador; i++){
        printf("Codigo: %d | Nome: %s | Preco: %.2f | Quantidade: %d\n", produtos[i].codigo, produtos[i].nome, produtos[i].preco, produtos[i].quantidade);
    }
    return;

    
}

// Criar função para buscar um produto pelo nome

void BuscarProd(){
    char nomeBusca[TamProd];
    printf("Digite o nome do produto para a busca:\n");
    scanf("%[^\n]%*c",nomeBusca);

    for (int i = 0; i < contador; i++){
        if (strcmp(produtos[i].nome, nomeBusca) == 0){ // o for percorre o array e compara cada posicao com o produto digitado ate achar o igual.
            printf("Produto encontrado!\n");
            printf("Codigo: %d | Nome: %s | Preco: %.2f | Quantidade: %d\n", produtos[i].codigo, produtos[i].nome, produtos[i].preco, produtos[i].quantidade);
            return;
        }
    }
    printf("Produto nao encontrado!\n");
}

// Criar a função para excluir produtos pelo nome

void ExcluirProd(){
    char nomeExcluir[TamProd];
    printf("Digite o nome do produto que deseja excluir:\n ");
    scanf("%[^\n]%*c", &nomeExcluir);

    for (int i = 0; i < contador; i++) {
        if (strcmp(produtos[i].nome, nomeExcluir) == 0){
            for (int j = i; j < contador - 1; j++) {
                produtos[j] = produtos[j + 1];
            }
            contador --; // o for vai percorrer a array e vai achar o produto igual ao que digitado e remove-lo e logo apos ajusta-los para a posicao nova.
            printf("Produto excluido com sucesso! \n");
            return;
        }
    }
    printf("Produto nao encontrado!\n");
}

//Criar a função para mostrar o menu de opcoes

void Menu(){
    int opcao;

    do{
        printf("\n=== MENU ===\n1. Inserir produto\n2. Listar todos os produtos\n3. Buscar produto por nome\n4. Excluir produto por nome\n5. Sair\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) { // o switch foi usado para poder selecionar cada opcao que tem no menu, sendo cada case as funcoes que a gente criou.
            case 1:
                InserirProd();
                break;
            case 2:
                ListarProd();
                break;
            case 3:
                BuscarProd();
                break;
            case 4:
                ExcluirProd();
                break;
            case 5:
                printf("Saindo do programa.\n");
                break;
            default:
            printf("Opção invalida. Tente novamente.\n");
        }
    }while (opcao != 5); // encerrar o loop while quando digitado a opcao 5 de sair do progama.
}
