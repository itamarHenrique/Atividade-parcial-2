#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  setlocale(LC_ALL, "");

  char produtoValido[100][50];
  float valorPreco[5] = {};
  int quantidadeProdutos;

  typedef struct {

    char codigo[7];
    char nome[50];
    float preco;
  } Produto;

  typedef struct {

    Produto produto;
    int quantidade;
  } itemCarrinho;

  Produto Produto1, Produto2, Produto3, Produto4, Produto5;

  strcpy(Produto1.nome, "Feijão Carioquinha");
  strcpy(Produto1.codigo, "ABC123");
  Produto1.preco = 9.59;

  strcpy(Produto2.nome, "Arroz Branco");
  strcpy(Produto2.codigo, "ZPK305");
  Produto2.preco = 7.23;

  strcpy(Produto3.nome, "Farinha");
  strcpy(Produto3.codigo, "ZPY452");
  Produto3.preco = 12.9;

  strcpy(Produto4.nome, "Café Santa Clara");
  strcpy(Produto4.codigo, "DJK325");
  Produto4.preco = 7.6;

  strcpy(Produto5.nome, "Açucar Cristal");
  strcpy(Produto5.codigo, "UMD916");
  Produto5.preco = 3.8;

  Produto produtos[5] = {Produto1, Produto2, Produto3, Produto4, Produto5};

  itemCarrinho itensCarrinho[5] = {};




    do{
        printf("Quantos produtos serão adicionados ao carrinho:");
        scanf("%d", &quantidadeProdutos);

        if(quantidadeProdutos <1 || quantidadeProdutos > 5){
            printf("A quantidade que você inseriu no produto não condiz com a quantidade de produtos que temos.\n");
        }
    }while(quantidadeProdutos < 1 || quantidadeProdutos > 5);

      for(int i = 0; i < 5; i++){
        printf("Os produtos tem esses codigos %s e nome %s\n", produtos[i].codigo, produtos[i].nome);
      }

      for (int i = 0; i < quantidadeProdutos; i++) {
        printf("Qual o código do produto %d: ", i + 1);
        scanf("%s", itensCarrinho[i].produto.codigo);

        int codigoValido = 0;
        for (int j = 0; j < 5; j++) {
          if (strcmp(itensCarrinho[i].produto.codigo, produtos[j].codigo) == 0) {
            strcpy(produtoValido[i], produtos[j].nome);
            valorPreco[i] = produtos[j].preco;

            codigoValido = 1;
            break;
          }
        }
        if (!codigoValido) {
          printf("Código de produto inválido. Por favor, insira um codigo valido.\n");
          i--;
        } else {
          printf("Qual a quantidade do produto atual:");
          scanf("%d", &itensCarrinho[i].quantidade);
        }
      }



    float subTotal = 0;
    float total = 0;


     printf("%-25s%-20s%-20s%-20s\n", "Produto", "Quantidade", "Preco Unitario", "Subtotal");
        for (int i = 0; i < quantidadeProdutos; i++) {
            subTotal = valorPreco[i] * itensCarrinho[i].quantidade;
            total+=subTotal;
            printf("%-25s%-20d%-20.2f%-20.2f\n", produtoValido[i], itensCarrinho[i].quantidade, valorPreco[i], subTotal);
        }


      printf("===========================================================================================\n");
      printf("\t\t\t\t\t\t\t\t\tTotal: R$%.2f", total);
      return 0;
}
