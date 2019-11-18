//
// Created by HamonRa on 17/11/2019.
//

#ifndef V6_OPCAO4_H
#define V6_OPCAO4_H

void opcao4(pListaVoo lista) {

    printf("|| --                     FAZER CHECK-IN                      -- ||\n");
    char opcao[10];
    int nVoo = 0;
    nVoo = criaNvoo();
    pVoo voo = procurarVoo(*lista, nVoo);
    if (voo) {
        // Fazer Check-In:
        // Lista de passageiros tem que estar vazia.
        // Fila de passageiro tem q estar cheia.
        if (filaVaziaPassageiro(*voo->filaPassageiros)) {
            int qtdLista = qtdListaPassageiro(*voo->listaPassageiros);
            if (!listaVaziaPassageiro(*voo->listaPassageiros)) {
                pCelulaPassageiro q = voo->listaPassageiros->primeiro->proximo;
                while (q != NULL) {
                    printPassageiro(*q->item);
                    printf("Fazer o Check-In do passageiro %s? s/n: ", q->item->nome);
                    fflush(stdin);
                    gets(opcao);
                    if (strcmp("s", opcao) == 0) {
                        float peso = randomFloat(MIN_VALUE_PESO_BAGAGEM, MAX_VALUE_PESO_BAGAGEM);
                        pBagagem bagagem = criaBagagem(&voo->nVoo, &q->item->cpf, peso);
                        empilharBagagem(voo->bagagens, bagagem);
                    }
                    else {
                        if (retirarPassageiro(voo->listaPassageiros, q->item->cpf)) {
                            printf("Passageiro retirado com sucesso.\n");
                        }
                    }

                    q = q->proximo;
                }
            }
            else {
                printf("Nao pode fazer Check-In. Lista de passageiros vazia.\n");
                printf("Primeiro mova os passageiro da Fila para a lista.\n");
                printf("Depois faca o Check-In.\n\n");
            }
        }
        else {
            printf("\nAinda existem passageiro na Fila de espera.\n");
            printf("Primeiro mova-os para a lista.\n");
            printf("Depois faca o Check-In.\n\n");
        }
    }
    else {
        printf("Numero do Voo '%i' nao encontrado.\n");
    }
}

#endif //V6_OPCAO4_H
