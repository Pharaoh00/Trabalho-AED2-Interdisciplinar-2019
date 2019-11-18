//
// Created by HamonRa on 17/11/2019.
//

#ifndef V6_OPCAO2_H
#define V6_OPCAO2_H

void opcao2(ListaVoo lista) {
    if (!listaVaziaVoo(lista)) {
        long long int cpf = 0;
        char buscaNome[MAX_ARRAY_VALUE];
        int error = 0; // erros

        printf("Para a pesquisa do passageiro ira precisar: \n");
        printf("O CPF do passageiro. Caso nao saiba, digite '1'.\n");
        printf("O nome do passageiro. Caso nao saiba, digite 'a'.\n");

        cpf = criaCpf();

        printf("Digite o nome do passageiro: ");
        fflush(stdin);
        gets(buscaNome);
        while (!checkString(buscaNome)) {
            printf("Nome invalido.\n");
            printf("Digite o nome novamente: ");
            fflush(stdin);
            gets(buscaNome);
            error++;
            if (error > 2) {
                printf("Tente digitar somente letras. Sem acentos.\n");
                printf("Tente sem caracteres especiais.\n");
                printf("Por exemplo: 'á' ou 'ô' - '-' ou '*'.\n");
            }
        }
        error = 0; // resetando o erros;

        // Procurar o passageiro em todos os voos
        pCelulaVoo q = lista.primeiro->proximo;
        pPassageiro passageiro = NULL;
        while(q != NULL) {
            passageiro = procurarPassageiroLista(*q->item->listaPassageiros, cpf, buscaNome, false); // sem msg de erro.
            if(passageiro) {
                //printPassageiro(*passageiro);
                break; // achou o passageiro na lista.
            }
            else {
                passageiro = procurarPassageiroFila(*q->item->filaPassageiros, cpf, buscaNome, false); // sem msg de erro.
                if(passageiro) {
                    //printPassageiro(*passageiro);
                    break; // achou o passageiro na fila.
                }
            }

            q = q->proximo;
        }
        if(passageiro) {
            printPassageiro(*passageiro);
        }
        else {
            printf("Passageiro com o CPF: '%lli' ou com o Nom: '%s' nao foi encontrado.\n", cpf, buscaNome);
        }
    }
    else {
        printf("Nao pode procurar um passageiro. Lista de voos vazia.\n");
    }
}

#endif //V6_OPCAO2_H
