#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <ctype.h>

#define MAX_ARRAY_VALUE 99 // valor maximo para um array qualquer
#define MAX_VALUE_PESO_BAGAGEM 40 // valor maximo para o peso da bagagem
#define MIN_VALUE_PESO_BAGAGEM 10 // valor minimo para o peso da bagagem
#define MAX_VALUE_POLTRONA 9999 // valor maximo para o numero da poltrona
#define MIN_VALUE_POLTRONA 1000 // valor minimo para o numero da poltrona
#define MAX_VALUE_QTD_LISTA_PASSAGEIRO 3 // valor maximo para a quantidade de passageiros na lista do voo
#define MAX_VALUE_QTD_FILA_PASSAGEIRO 5 // valor maximo para a quantidade de passageiros na lista de espera do voo

#include "header/listaPassagem.h"
#include "header/listaPassageiro.h"
#include "header/filaPassageiro.h"
#include "header/pilhaBagagem.h"
#include "header/listaVoo.h"

// Arquivos de auxilio
#include "tools/gerenciamento.h"
#include "tools/tools.h"
#include "tools/criaCpf.h"
#include "tools/criaTelefone.h"
#include "tools/criaNvoo.h"
#include "tools/adicionarPassageiroLista.h"
#include "tools/adicionarPassageiroLista_v2.h"

// Opções do menu
#include "menu/menu.h" // Opcoes do menu
#include "menu/opcao1.h"
#include "menu/opcao2.h"
#include "menu/opcao3.h"
#include "menu/opcao4.h"
#include "menu/opcao5.h"

#include "test/test.h" // incluir sempre o test.h por ultimo

/*
 * NOTAS:
 *      Pela natureza de como a Pilha funciona, uma vez o passageiro adicionado a lista do voo,
 *      e sua bagagem adicionada a pilha do voo, a bagagem nao pode ser retirada enquanto a lista
 *      nao for esvaziada.
 *
 *      CHECAGENS:
 *              input do usuario, tanto para numeros tanto para strings, exemplo:
 *                      Se o dado for um char array, faz-se a checagem se o input foram todas letras, ou o que for checado.
 *              Se o cpf ja existe, tanto na LISTA de passageiros e na FILA de passageiros.
 *              Checagem para se o usuario errar mais de 2 vezes, mensagem de ajuda.
 *
 *      MECANICAS:
 *              O numero da poltrona e o peso da pagagem sao gerados automaticamente.
 *              O valor estao definidos no topo do arquivo.
 * */

/*
 * KNOW BUGS:
 *          Telefone e CPF, como são inteiros, é somente feito a checagem se eles realmente sao inteiros, exemplo:
 *              long long int cpf = 131313139;
 *              cpf é um inteiro.
 *              long long int cpf = "a", no scanf() qualquer letra é igual a 0.
 *              Então cpf = 0;
 *              Mas a condição da checagem é maior que zero, então cpf nao é um numero.
 *              Se caso, no scanf() digitar 13131313-9 o numero vai passar, mas será 13131313 sem o 9 no final.
 *              A mesma coisa se da com o telefone.
 *
 *              Nem o Telfone e nem o CPF podem começar com 0.
 * */

int main() {

    pListaVoo voos = criaListaVoo(); // Inicializar a lista dos voos
    voosPadrao(voos);
    //testCriaPassageiros(voos);
    //testEnfileirarPassageiro(voos);
    bool running = true;

    // programa principal
    while (running) {
        menu();
        char opcao[10];
        printf("\n");
        printf("Digite uma das opcoes a cima: ");
        fflush(stdin);
        gets(opcao);

        // opcoes
        if (strcmp("1", opcao) == 0) {
            opcao1(*voos);
        }
        else if (strcmp("2", opcao) == 0) {
            opcao2(*voos);
        }
        else if (strcmp("3", opcao) == 0) {
            // opções "avançadas"
            opcao3(voos);
        }
        else if (strcmp("4", opcao) == 0) {
            opcao4(voos);
        }
        else if (strcmp("5", opcao) == 0) {
            opcao5(voos);
        }
        else if(strcmp("test", opcao) == 0) {
            //printVoos(*voos, false);
            pVoo voo = procurarVoo(*voos, 5050);
            printVoo(*voo, false);
        }
        else {
            printf("Opcao '%s' invalida. Digite novamente.\n");
        }
    }

    return 0;
}
