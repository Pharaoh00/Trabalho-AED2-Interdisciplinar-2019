//
// Created by HamonRa on 17/11/2019.
//

#ifndef V6_PILHABAGAGEM_H
#define V6_PILHABAGAGEM_H

typedef struct Bagagem {
    int *nVoo;
    long long int *cpf;
    float peso;
} Bagagem, *pBagagem;

typedef struct CelulaBagagem {
    pBagagem item;
    struct CelulaBagagem *proximo;
} CelulaBagagem, *pCelulaBagagem;

typedef struct PilhaBagagem {
    pCelulaBagagem fundo;
    pCelulaBagagem topo;
} PilhaBagagem, *pPilhaBagagem;

pBagagem criaBagagem(int *nVoo, long long int *cpf, float peso) {
    pBagagem aux = (pBagagem) malloc(sizeof(Bagagem)); // MARCA PARA FREE
    aux->nVoo = nVoo;
    aux->cpf = cpf;
    aux->peso = peso;

    return aux;
}

pCelulaBagagem criaCelulaBagagem(pBagagem item) {
    pCelulaBagagem aux = (pCelulaBagagem) malloc(sizeof(CelulaBagagem)); // MARCA PARA FREE
    aux->item = item;
    aux->proximo = NULL;

    return aux;
}

pPilhaBagagem criaPilhaBagagem() {
    pPilhaBagagem pilha = (pPilhaBagagem) malloc(sizeof(PilhaBagagem)); // MARCA PARA FREE
    pCelulaBagagem sentinela;
    pBagagem item;

    item = criaBagagem(NULL, NULL, 00);
    sentinela = criaCelulaBagagem(item);

    pilha->fundo = sentinela;
    pilha->topo = sentinela;

    return pilha;
}

void empilharBagagem(pPilhaBagagem pilha, pBagagem bagagem) {
    pCelulaBagagem novaCelula = criaCelulaBagagem(bagagem);
    novaCelula->proximo = pilha->topo;
    pilha->topo = novaCelula;
}

bool pilhaVaziaBagagem(PilhaBagagem pilha) {
    if (pilha.fundo == pilha.topo) {
        return true;
    }
    else {
        return false;
    }
}

pBagagem procurarBagagem(pPilhaBagagem pilha, long long int cpf) {
    if (pilha) {
        pCelulaBagagem q = pilha->topo;
        if (!pilhaVaziaBagagem(*pilha)) {
            while (q != pilha->fundo) {
                if (*q->item->cpf == cpf) {
                    return q->item;
                }
                else if (q->proximo == NULL && *q->item->cpf != cpf) {
                    printf("Bagagem nao encontrada.\n");
                    return NULL;
                }
                q = q->proximo;
            }
        }
        else {
            printf("Nao pode encontrar bagagem. Pilha vazia.\n");
            return NULL;
        }
    }
    else {
        printf("Nao pode encontrar bagagem. Pilha invalida.\n");
        return NULL;
    }
}

void printBagagem(Bagagem bagagem) {
    printf("|| -------------------------------- Bagagem ------------------------------- ||\n");
    if (bagagem.nVoo == NULL) {
        printf("Numero do voo: NULL\n");
    }
    else {
        printf("Numero do voo: %i\n", *bagagem.nVoo);
    }
    if (bagagem.cpf == NULL) {
        printf("Cpf do passageiro: NULL\n");
    }
    else {
        printf("Cpf do passageiro: %lli\n", *bagagem.cpf);
    }
    printf("Peso da bagagem: %.2f\n", bagagem.peso);
    //printf("|| ------------------------------------------------------------------------ ||\n");
}

void printBagagens(PilhaBagagem pilha) {
    pCelulaBagagem q;
    q = pilha.topo;
    // TODO:
    //      CHECAR SE A PILHA NÃO ESTA VAZIA.
    if (!pilhaVaziaBagagem(pilha)) {
        //while (q->proximo != NULL) {
        while (q != pilha.fundo) {
            printBagagem(*q->item);
            q = q->proximo;
        }
    }
    else {
        printf("Pilha de bagagens vazia.\n");
    }
}

void freeBagagem(pBagagem bagagem) {
    // Dando free no malloc() do criaBagagem()
    if (bagagem) {
        free(bagagem);
    }
}

void freeCelulaBagagem(pCelulaBagagem bagagem) {

    if (bagagem) {
        // Dando free na struct da bagagem
        if (bagagem->item) {
            freeBagagem(bagagem->item);
        }
        // Dando free na celula do passageiro
        bagagem->proximo = NULL;
        free(bagagem);
    }
}

void freePilhaBagagem(pPilhaBagagem pilha) {
    if (pilha) {
        pCelulaBagagem q = pilha->topo;
        if (!pilhaVaziaBagagem(*pilha)) {
            while (q != pilha->fundo) {
                freeCelulaBagagem(q);
                q = q->proximo;
            }
        }
        else {
            pilha->fundo->proximo = NULL; // Apontando o sentinela para NULL
            freeCelulaBagagem(pilha->fundo); // FREE NO SENTINELA
            // Dando free no malloc() do criaPilhaBagagem()
            free(pilha);
        }
    }
}

pBagagem topoPilhaBagagem(pPilhaBagagem pilha) {
    if (pilha) {
        if (!pilhaVaziaBagagem(*pilha)) {
            return pilha->topo->item;
        }
        else {
            printf("Nao pode retornar o topo da pilha de Bagagens. Pilha vazia.\n");
            return NULL;
        }
    }
    else {
        printf("Nao pode retornar o topo da pilha de Bagagens. Pilha invalida.\n");
        return NULL;
    }
}

pBagagem fundoPilhaBagagem(pPilhaBagagem pilha) {
    if (pilha) {
        if (!pilhaVaziaBagagem(*pilha)) {
            return pilha->fundo->proximo->item;
        }
        else {
            printf("Nao pode retornar o fundo da pilha de Bagagens. Pilha vazia.\n");
            return NULL;
        }
    }
    else {
        printf("Nao pode retornar o fundo da pilha de Bagagens. Pilha invalida.\n");
        return NULL;
    }
}

bool desempilhar(pPilhaBagagem pilha) {
    if (pilha) {
        if (!pilhaVaziaBagagem(*pilha)) {
            pCelulaBagagem q = pilha->topo;
            // Um unico item na fila,
            // Quer dizer que o proximo do topo é igual ao fundo.
            if (pilha->topo->proximo == pilha->fundo) {
                pilha->topo->proximo = NULL;
                freeCelulaBagagem(q);
                pilha->fundo = pilha->topo; // requisito para a pilha vazia.
                return true;
            }
            else {
                pilha->topo = q->proximo;
                q->proximo = NULL;
                freeCelulaBagagem(q);
                return true;
            }
        }
        else {
            printf("Nao pode desempilhar. Pilha vazia.\n");
            return false;
        }
    }
    else {
        printf("Nao pode desempilhar. Pilha invalida.\n");
        return false;
    }
}

int qtdPilhaBagagem(PilhaBagagem pilha) {
    int qtd = 0;
    pCelulaBagagem q = pilha.topo;
    if (!pilhaVaziaBagagem(pilha)) {
        //while (q->proximo != NULL) {
        while (q != pilha.fundo) {
            qtd++;
            q = q->proximo;
        }
    }
    else {
        printf("Pilha de bagagens vazia.\n");
        return 0;
    }

    return qtd;
}

#endif //V6_PILHABAGAGEM_H
