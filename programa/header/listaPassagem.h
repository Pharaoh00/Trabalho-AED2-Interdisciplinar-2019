//
// Created by HamonRa on 17/11/2019.
//

#ifndef V6_LISTAPASSAGEM_H
#define V6_LISTAPASSAGEM_H

typedef struct Passagem {
    int *nVoo; // numero do voo
    long long int *cpf; // cpf do passageiro
    int nPoltrona;
    int *hPartida;
    int *hChegada;
} Passagem, *pPassagem;

typedef struct CelulaPassagem {
    pPassagem item;
    struct CelulaPassagem *proximo;
} CelulaPassagem, *pCelulaPassagem;

typedef struct ListaPassagem {
    pCelulaPassagem primeiro;
    pCelulaPassagem ultimo;
} ListaPassagem, *pListaPassagem;

pPassagem criaPassagem(int *nVoo, long long int *cpf, int nPoltrona, int *hPartida, int *hChegada) {
    pPassagem aux = (pPassagem) malloc(sizeof(Passagem)); // MARCA PARA FREE

    aux->nVoo = nVoo;
    aux->cpf = cpf;
    aux->nPoltrona = nPoltrona;
    aux->hPartida = hPartida;
    aux->hChegada = hChegada;

    return aux;
}

pCelulaPassagem criaCelulaPassagem(pPassagem item) {
    if (item) {
        pCelulaPassagem aux = (pCelulaPassagem) malloc(sizeof(CelulaPassagem)); // MARACA PARA FREE
        aux->item = item;
        aux->proximo = NULL;

        return aux;
    }
    else {
        printf("Nao pode criar a celula. Pasagem invalida.\n");
        return NULL;
    }
}

pListaPassagem criaListaPassagem() {
    int nVoo = 00;
    long long int cpf = 00;
    int nPoltrona = 00;
    int hChegada = 00;
    int hPartida = 00;
    pPassagem item = criaPassagem(&nVoo, &cpf, nPoltrona, &hPartida, &hChegada);
    pCelulaPassagem sentinela = criaCelulaPassagem(item);

    // Se for dar free na lista inteira, nao esquecer de dar free no sentinela
    pListaPassagem lista = (pListaPassagem) malloc(sizeof(ListaPassagem));
    lista->primeiro = sentinela;
    lista->ultimo = sentinela;

    return lista;
}

bool listaVaziaPassagem(ListaPassagem lista) {
    if (lista.primeiro == lista.ultimo) {
        return true;
    }
    else {
        return false;
    }
}

pPassagem procurarPassagem(ListaPassagem lista, int nVoo) {
    if (!listaVaziaPassagem(lista)) {
        pCelulaPassagem q = lista.primeiro->proximo;
        while(q != NULL) {
            if(*q->item->nVoo == nVoo) {
                return q->item;
            }
            else if(q->proximo == NULL && *q->item->nVoo != nVoo) {
                return NULL;
            }

            q = q->proximo;
        }
    }
    else {
        return NULL;
    }
}

void inserirPassagem(pListaPassagem lista, pPassagem item) {
    if (lista && item) {
        pCelulaPassagem aux = criaCelulaPassagem(item);
        lista->ultimo->proximo = aux;
        lista->ultimo = aux;
    }
    else {
        printf("Nao pode inserir a Passagem. Lista ou Passagem invalida.\n");
        return;
    }
}

void printPassagem(Passagem passagem) {
    printf("|| -------------------------- Lista de Passagens -------------------------- ||\n");
    if (passagem.nVoo == NULL) {
        printf("O numero do voo e: NULL.\n");
    }
    else {
        printf("O numero do voo e: %i\n", *passagem.nVoo);
    }
    if (passagem.cpf == NULL) {
        printf("O cpf do passageiro e: NULL.\n");
    }
    else {
        printf("O cpf do passageiro e: %lli\n", *passagem.cpf);
    }
    printf("O numero da poltrona e: %i\n", passagem.nPoltrona);
    printf("O horario de partida e: %i\n", *passagem.hPartida);
    printf("O horario de cheagada e: %i\n", *passagem.hChegada);
    //printf("|| ------------------------------------------------------------------------ ||\n");
}

void printPassagens(ListaPassagem lista) {
    if (!listaVaziaPassagem(lista)) {
        pCelulaPassagem q = lista.primeiro->proximo;
        while (q != NULL) {
            printPassagem(*q->item);
            q = q->proximo;
        }
    }
    else {
        printf("Lista de passagens vazia.\n");
    }
}

void freePassagem(pPassagem passagem) {
    // Dando free no malloc() do criaPassagem()
    if (passagem) {
        free(passagem);
    }
}

void freeCelulaPassagem(pCelulaPassagem passagem) {
    if (passagem) {
        // Dando free no malloc() do criaPassagem()
        if (passagem->item) {
            freePassagem(passagem->item);
        }

        // Dando free no malloc do criaCelulaPassagem()
        passagem->proximo = NULL; // apontando proximo para NULL
        free(passagem);
    }
}

void freeListaPassagem(pListaPassagem listaPassagem) {
    if (listaPassagem) {
        pCelulaPassagem q = listaPassagem->primeiro->proximo;
        if (!listaVaziaPassagem(*listaPassagem)) {
            while (q != NULL) {
                freeCelulaPassagem(q);
                q = q->proximo;
            }
        }
        else {
            listaPassagem->primeiro->proximo = NULL; // apontando sentinela para NULL
            freeCelulaPassagem(listaPassagem->primeiro); // FREE NO SENTINELA
            // Dando free no malloc() do criaListaPassagem()
            free(listaPassagem);
        }
    }
}

#endif //V6_LISTAPASSAGEM_H
