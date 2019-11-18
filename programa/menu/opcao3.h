//
// Created by HamonRa on 17/11/2019.
//

#ifndef V6_OPCAO3_H
#define V6_OPCAO3_H

void opcao3(pListaVoo lista) {
    char opcao[10];
    bool subMenu = true;

    subMenu3();
    printf("\n");
    printf("Digite uma das opcoes a cima: ");
    fflush(stdin);
    gets(opcao);

    // OPÇÃO 1
    if (strcmp("1", opcao) == 0) {
        printf("|| --                   RESERVA DE PASSAGEM                   -- ||\n");
        printf("\n");
        int nVoo = criaNvoo();
        pVoo voo = procurarVoo(*lista, nVoo);
        if (voo) {
            while (subMenu) {
                if (adicionarPassageiroLista(voo)) {
                    printf("Passageiro adicionado com sucesso.\n");
                }
                else {
                    printf("Nao pode adicionar o passageiro.\n");
                }
                printf("Deseja continuar? s/n: ");
                fflush(stdin);
                gets(opcao);
                if (strcmp("n", opcao) == 0) {
                    subMenu = false;
                }
            }
        }
        else {
            printf("Numero do Voo '%i' nao existe.\n", nVoo);
        }
    }
        // OPÇÃO 2
    else if (strcmp("2", opcao) == 0) {
        int nVoo = 0;
        long long int cpf = 0;
        char buscaNome[MAX_ARRAY_VALUE];
        int error = 0;

        printf("|| --                  DESISTENCIA PASSAGEIRO                 -- ||\n");

        pPassageiro passageiro = NULL;
        nVoo = criaNvoo();
        pVoo voo = procurarVoo(*lista, nVoo);
        if (voo) {
            if (!listaVaziaPassageiro(*voo->listaPassageiros)) {
                //printPassageiro(*voo->listaPassageiros->primeiro->proximo->item);
                cpf = criaCpf();
                // Se o cpf digitado existe ou na lista ou na fila
                bool checkLista = checkCpfListaPassageiro(*voo->listaPassageiros, cpf);
                bool checkFila = checkCpfFilaPassageiro(*voo->filaPassageiros, cpf);
                if (checkLista || checkFila) {

                    if (checkFila) {
                        passageiro = procurarPassageiroFila(*voo->filaPassageiros, cpf, "a", true);
                        int pos = posFilaPassageiro(*voo->filaPassageiros, cpf);
                        printf("Passageiro %s nao pode ser tirado da Fila de espera.\n", passageiro->nome);
                        printf("Passageiro %s esta na posicao %i na Fila de espera.\n", passageiro->nome, pos);
                    }
                    else {
                        passageiro = procurarPassageiroLista(*voo->listaPassageiros, cpf, "a", true);
                        //printPassageiro(*passageiro);
                        if (passageiro) {
                            if (retirarPassageiro(voo->listaPassageiros, passageiro->cpf)) {
                                printf("Passageiro retirado da Lista com sucesso.\n");
                            }
                            else {
                                printf("Nao pode retirar o passageiro da lista. AAA\n");
                            }
                        }
                    }
                }
                else {
                    printf("Passageiro com o cpf %lli nao encontrado.\n", cpf);
                }
            }
            else {
                printf("\nNao pode retirar passageiro. Lista vazia.\n\n");
            }
        }
        else {
            printf("Nao pode encontrar o Voo com o numero %i. Voo nao existe.\n", nVoo);
        }
    }
        // OPÇÃO 3
    else if (strcmp("3", opcao) == 0) {

        int nVoo = criaNvoo();
        pVoo voo = procurarVoo(*lista, nVoo);
        if(voo) {
            int qtdLista = qtdListaPassageiro(*voo->listaPassageiros);
            if (qtdLista < voo->qtdMaximaLista) {
                while (qtdLista < voo->qtdMaximaLista) {
                    pPassageiro passageiro = primeiroFilaPassageiro(voo->filaPassageiros);
                    if(!filaVaziaPassageiro(*voo->filaPassageiros)) {
                        if (passageiro) {
                            printf("Deseja adicionar passageiro %s na lista? s/n: ", passageiro->nome);
                            fflush(stdin);
                            gets(opcao);
                            if (strcmp("s", opcao) == 0) {
                                inserirUltimoListaPassageiro(voo->listaPassageiros, passageiro);
                                desenfileirar(voo->filaPassageiros,
                                              false); // false para nao apagar a memoria. Item movido.
                            }
                            else {
                                desenfileirar(voo->filaPassageiros, true); // true para limpar a memoria.
                                break;
                            }
                        }
                    }
                    else {
                        printf("Nao pode adicionar mais passageiros. Fila vazia.\n");
                        break;
                    }
                }
                /*if(qtdLista < voo->qtdMaximaLista) {
                    pPassageiro passageiro = primeiroFilaPassageiro(voo->filaPassageiros);
                    if(passageiro) {
                        inserirUltimoListaPassageiro(voo->listaPassageiros, passageiro);
                        desenfileirar(voo->filaPassageiros, false); // false para nao apagar a memoria. Item movido.
                    }
                }*/
            }
            else {
                printf("\nNao pode mover passageiro da lista de espera. Lista cheia.\n\n");
            }
        }
        else {
            printf("Numero do Voo '%i' nao encontrado.\n");
        }
    }
        // OPÇÃO 4
    else if (strcmp("4", opcao) == 0) {
        printf("|| --           MOSTRAR INFORMACOES DOS PASSAGEIROS           -- ||\n");
        int nVoo = 0;
        nVoo = criaNvoo();
        pVoo voo = procurarVoo(*lista, nVoo);

        pListaPassageiro passageiros = criaListaPassageiro();
        if (!listaVaziaPassageiro(*voo->listaPassageiros)) {
            passageiros = criaListaPassageiro();
            pCelulaPassageiro q = voo->listaPassageiros->primeiro->proximo;
            while (q != NULL) {
                pPassageiro aux = q->item;
                inserirPassageiro(passageiros, aux);

                q = q->proximo;
            }
        }
        else {
            printf("Nao pode mostrar os passageiros. Lista de passageiros vazia.\n");
        }
        if (passageiros) {
            printPassageiros(*passageiros);
            freeCelulaPassageiro(passageiros->primeiro); // Liberando a celula do sentinela criado.
            free(passageiros); // liberando a memoria da lista criada.
            //freeListaPassageiro(passageiros);
        }
    }
        // OPÇÃO 5
    else if (strcmp("5", opcao) == 0) {
        printf("\n");
        int nVoo = criaNvoo();
        pVoo voo = procurarVoo(*lista, nVoo);
        if (voo) {
            mostrarOrdem(*voo);
        }
        else {
            printf("Nao pode encontrar o Voo %i. Numero do Voo nao existe.\n");
        }
    }
    else {
        printf("Opcao '%s' invalida. Digite novamente.\n");
    }
}

#endif //V6_OPCAO3_H
