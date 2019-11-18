//
// Created by HamonRa on 17/11/2019.
//

#ifndef V6_LISTAVOO_H
#define V6_LISTAVOO_H

typedef struct Voo {
    int nVoo;
    char *origem;
    char *destino;
    int hPartida;
    int hChegada;
    int qtdMaximaLista;
    int qtdMaximaFila;
    pListaPassageiro listaPassageiros;
    pFilaPassageiro filaPassageiros;
    pPilhaBagagem bagagens;

} Voo, *pVoo;

typedef struct CelulaVoo {
    pVoo item;
    struct CelulaVoo *proximo;
} CelulaVoo, *pCelulaVoo;

typedef struct ListaVoo {
    pCelulaVoo primeiro;
    pCelulaVoo ultimo;
} ListaVoo, *pListaVoo;

pVoo criaVoo(int nVoo, char *origem, char *destino, int hPartida, int hChegada,
             int qtdMaximaLista, int qtdMaximaFila, pListaPassageiro listaPassageiros,
             pPilhaBagagem bagagens, pFilaPassageiro filaPassageiros) {
    if (listaPassageiros && bagagens && filaPassageiros) {
        pVoo aux = (pVoo) malloc(sizeof(Voo)); // MARCA PARA FREE

        aux->nVoo = nVoo;

        aux->origem = (char *) calloc(strlen(origem), sizeof(char)); // MARCA PARA FREE
        snprintf(aux->origem, strlen(origem) + 1, "%s", origem);

        aux->destino = (char *) calloc(strlen(destino), sizeof(char)); // MARCA PARA FREE
        snprintf(aux->destino, strlen(destino) + 1, "%s", destino);

        aux->hPartida = hPartida;
        aux->hChegada = hChegada;
        aux->qtdMaximaLista = qtdMaximaLista;
        aux->qtdMaximaFila = qtdMaximaFila;
        aux->listaPassageiros = listaPassageiros; // MARCA PARA FREE
        aux->bagagens = bagagens; // MARCA PARA FREE
        aux->filaPassageiros = filaPassageiros; // MARCA PARA FREE

        return aux;
    }
    else {
        printf("Nao pode criar o Voo. Lista de Passageiros ou Pilha de Bagagens ou Fila de passageiros invalido.\n");
        return NULL;
    }
}

pCelulaVoo criaCelulaVoo(pVoo item) {
    if (item) {
        pCelulaVoo aux = (pCelulaVoo) malloc(sizeof(Voo)); // MARCA PARA FREE
        aux->item = item;
        aux->proximo = NULL;

        return aux;
    }
    else {
        printf("Nao pode criar a celula. Voo invalido.\n");
        return NULL;
    }
}

pListaVoo criaListaVoo() {
    pListaPassageiro listaPassageiro = criaListaPassageiro();
    pPilhaBagagem bagagem = criaPilhaBagagem();
    pFilaPassageiro filaPassageiro = criaFilaPassageiro();
    pVoo item = criaVoo(00, "^", "^", 00, 00,
                        0, 0, listaPassageiro, bagagem, filaPassageiro);
    pCelulaVoo sentinela = criaCelulaVoo(item);

    pListaVoo lista = (pListaVoo) malloc(sizeof(ListaVoo)); // MARCA PARA FREE
    lista->primeiro = sentinela;
    lista->ultimo = sentinela;

    return lista;

}

void inserirVoo(pListaVoo lista, pVoo item) {
    if (lista && item) {
        pCelulaVoo aux = criaCelulaVoo(item);
        lista->ultimo->proximo = aux;
        lista->ultimo = aux;
    }
    else {
        printf("Nao pode inserir o Voo. Lista ou Voo invalido.\n");
        return;
    }
}

bool listaVaziaVoo(ListaVoo voo) {
    if (voo.primeiro == voo.ultimo) {
        return true;
    }
    else {
        return false;
    }
}

pVoo procurarVoo(ListaVoo lista, int nVoo) {
    if (lista.primeiro) {
        pCelulaVoo q = lista.primeiro->proximo;
        if (!listaVaziaVoo(lista)) {
            while (q != NULL) {
                if (q->item->nVoo == nVoo) {
                    return q->item;
                }
                else if (q->proximo == NULL && q->item->nVoo != nVoo) {
                    return NULL; // quer dizer que procurou e não achou nada.
                }
                else {
                    q = q->proximo;
                }
            }
        }
        else {
            printf("Lista de voos vazia.\n");
            return NULL;
        }
    }
    else {
        printf("Nao pode printar os voos. Lista invalida.\n");
        return NULL;
    }
}

void printVoo(Voo voo, bool flag) {
    // Flag igual a true printa somente os dados do voo
    // Flag igual a fale printa a lista de passageiros, Fila de passageiros e a pilha de bagagens do voo
    printf("|| --------------------------------- Voo ---------------------------------- ||\n");
    printf("Numero do voo: %i\n", voo.nVoo);
    printf("Voo com origem: %s - com destino: %s\n", voo.origem, voo.destino);
    printf("Horario de saida do voo: %i - com chegada (horario local do destino): %i\n", voo.hPartida,
           voo.hChegada);
    printf("Maximo de passageiros no aviao: %i - maximo passageiros na fila de espera: %i\n",
           voo.qtdMaximaLista, voo.qtdMaximaFila);
    printf("Quantidade de passageiros na lista: %i\n", qtdListaPassageiro(*voo.listaPassageiros));
    printf("Quantidade de passageiros na fila: %i\n", qtdFilaPassageiro(*voo.filaPassageiros));
    if (!flag) {
        printf("|| -------------------------- LISTA PASSAGEIROS --------------------------- ||\n\n");
        printPassageiros(*voo.listaPassageiros);
        printf("|| --------------------------- FILA PASSAGEIROS --------------------------- ||\n\n");
        printFilaPassageiros(*voo.filaPassageiros);
        printf("|| ---------------------------- PILHA BAGAGENS ---------------------------- ||\n\n");
        printBagagens(*voo.bagagens);
        printf("|| ------------------------------------------------------------------------ ||\n\n");
    }
}

void printVoos(ListaVoo lista, bool flag) {
    // Flag igual a true printa somente os dados do voo
    // Flag igual a fale printa a lista de passageiros e a pilha de bagagens do voo
    pCelulaVoo q = lista.primeiro->proximo;
    if (!listaVaziaVoo(lista)) {
        while (q != NULL) {
            if (q->item) {
                printVoo(*q->item, flag);
                q = q->proximo;
            }
        }
    }
    else {
        printf("Lista de Voo vazia.\n");
    }
}

void freeVoo(pVoo voo) {
    if (voo) {
        // Dando free no malloc() do char array origem
        if (voo->origem) {
            free(voo->origem);
        }
        // Dando free no malloc() do char array destino
        if (voo->destino) {
            free(voo->destino);
        }
        if (voo->listaPassageiros) {
            // Dando free na lista interna dos passageiros
            freeListaPassageiro(voo->listaPassageiros);
        }
        if (voo->filaPassageiros) {
            // Dando free na fila interna dos passageiros
            freeFilaPassageiro(voo->filaPassageiros);
        }
        if (voo->bagagens) {
            // Dando free na pilha interna dos passsageiros
            freePilhaBagagem(voo->bagagens);
        }
        // Dando free no malloc() do voo
        free(voo);
    }
}

void freeCelulaVoo(pCelulaVoo voo) {
    if (voo) {
        // Dando free na struct do Voo
        if (voo->item) {
            freeVoo(voo->item);
        }
        // Dando free na celula do passageiro
        voo->proximo = NULL;
        free(voo);
    }
}

void freeListaVoo(pListaVoo listaVoo) {
    if (listaVoo) {
        pCelulaVoo q = listaVoo->primeiro->proximo;
        if (!listaVaziaVoo(*listaVoo)) {
            while (q != NULL) {
                freeCelulaVoo(q);
                q = q->proximo;
            }
        }
        else {
            listaVoo->primeiro->proximo = NULL; // Apontando o sentinela para NULL
            freeCelulaVoo(listaVoo->primeiro); // FREE NO SENTINELA
            // Dando free no malloc() do criaListaVoo()
            free(listaVoo);
        }
    }
}

#endif //V6_LISTAVOO_H
