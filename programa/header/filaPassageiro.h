//
// Created by HamonRa on 17/11/2019.
//

#ifndef V6_FILAPASSAGEIRO_H
#define V6_FILAPASSAGEIRO_H

typedef struct FilaPassageiro {
    pCelulaPassageiro frente;
    pCelulaPassageiro tras;
} FilaPassageiro, *pFilaPassageiro;

pFilaPassageiro criaFilaPassageiro() {
    pListaPassagem passagem = criaListaPassagem();
    pFilaPassageiro fila = (pFilaPassageiro) malloc(sizeof(Passageiro));
    pCelulaPassageiro sentinela;

    pPassageiro item = criaPassageiro("^", 00, "^", 00, passagem);
    sentinela = criaCelulaPassageiro(item);

    fila->frente = sentinela;
    fila->tras = sentinela;

    return fila;
}

void enfileirarPassageiro(pFilaPassageiro fila, pPassageiro item) {
    if (fila && item) {
        pCelulaPassageiro novaCelula = criaCelulaPassageiro(item);
        fila->tras->proximo = novaCelula;
        fila->tras = novaCelula;
    }
    else {
        printf("Nao pode inserir o passageiro. Fila ou Passageiro invalido\n");
        return;
    }
}

bool filaVaziaPassageiro(FilaPassageiro fila) {
    if (fila.frente == fila.tras) {
        return true;
    }
    else {
        return false;
    }
}

pPassageiro procurarPassageiroFila(FilaPassageiro fila, long long int cpf, char *nome, bool flag) {
    // Se flag for igual a true, print as mensagens de erro.
    // Se flag for igual a false, print as mensagens sem erro.
    if (!filaVaziaPassageiro(fila)) {
        pCelulaPassageiro q = fila.frente->proximo;
        while (q != NULL) {
            if (q->item->cpf == cpf || strcmp(q->item->nome, nome) == 0) {
                if (flag) {
                    printf("Passageiro encontrado.\n");
                    return q->item; // Encontrou o passageiro.
                }
            }
            else if (q->proximo == NULL) {
                // q->proximo == NULL, quer dizer que 'q' é o ultimo.
                // Como na checagem anterior, o ultimo nao é o pasageiro desejado.
                if (flag) {
                    printf("Passageiro nao encontrado.\n");
                }
                return NULL; // Nao encontrou o passsageiro.
            }

            q = q->proximo;
        }
    }
    else {
        if (flag) {
            printf("Nao pode encontrar o passageiro. Fila vazia.\n");
        }
        return NULL;
    }

}

void printFilaPassageiros(FilaPassageiro fila) {
    if (!filaVaziaPassageiro(fila)) {
        pCelulaPassageiro q = fila.frente->proximo;
        while (q != NULL) {
            printPassageiro(*q->item);
            q = q->proximo;
        }
    }
    else {
        printf("Fila de passageiros vazia.\n");
    }
}

bool checkCpfFilaPassageiro(FilaPassageiro fila, long long int cpf) {
    // return true Se tiver um cpf igual
    // return false se nao tiver um cpf igual
    pCelulaPassageiro q = fila.frente->proximo;
    if (!filaVaziaPassageiro(fila)) {
        while (q != NULL) {
            if (q->item->cpf == cpf) {
                return true;
            }
            if (q->proximo == NULL && q->item->cpf != cpf) {
                return false;
            }
            else {
                q = q->proximo;
            }
        }
    }
    else {
        return false;
    }
}

// ERRADO
void freeFilaPassageiro(pFilaPassageiro fila) {
    if (fila) {
        pCelulaPassageiro q = fila->frente->proximo;
        if (!filaVaziaPassageiro(*fila)) {
            while (q->proximo != NULL) {
                freeCelulaPassageiro(q);
                q = q->proximo;
            }
        }
        else {
            fila->frente->proximo = NULL; // Apontando o sentinela para NULL
            freeCelulaPassageiro(fila->frente); // FREE NO SENTINELA
            // Dando free no malloc() do criaFilaPassageiro()
            free(fila);
        }
    }
}

pPassageiro primeiroFilaPassageiro(pFilaPassageiro fila) {
    if (fila) {
        if (!filaVaziaPassageiro(*fila)) {
            return fila->frente->proximo->item;
        }
        else {
            printf("Nao pode retonar o primeiro da fila. Fila vazia.\n");
            return NULL;
        }
    }
    else {
        printf("Nao pode retonar o primeiro da fila. Fila invalida.\n");
        return NULL;
    }
}

pPassageiro UltimoFilaPassageiro(pFilaPassageiro fila) {
    if (fila) {
        if (!filaVaziaPassageiro(*fila)) {
            return fila->tras->item;
        }
        else {
            printf("Nao pode retonar o ultimo da fila. Fila vazia.\n");
            return NULL;
        }
    }
    else {
        printf("Nao pode retonar o ultimo da fila. Fila invalda.\n");
        return NULL;
    }
}

bool desenfileirar(pFilaPassageiro fila, bool flag) {
    // Se flag for igual a true, a mememoria do passageiro sera apagada.
    // Se flag for igual a false, a memoria nao é apagada.
    // Serve para mover passageiro de uma estrutura para outro
    if (fila) {
        if (!filaVaziaPassageiro(*fila)) {
            pCelulaPassageiro q = fila->frente->proximo;
            fila->frente->proximo = q->proximo;

            if(q == fila->tras) {
                fila->frente = fila->tras;
            }
            if(flag) {
                freeCelulaPassageiro(q);
            }
            return true;
        }
        else {
            printf("Nao pode desenfileirar. Fila vazia.\n");
            return false;
        }
    }
    else {
        printf("Nao pode desenfileirar. Fila invalida.\n");
        return false;
    }
}

int qtdFilaPassageiro(FilaPassageiro fila) {
    int qtd = 0;
    if (!filaVaziaPassageiro(fila)) {
        pCelulaPassageiro q = fila.frente->proximo;
        while (q != NULL) {
            qtd++;
            q = q->proximo;
        }
    }
    else {
        return 0;
    }

    return qtd;
}

int posFilaPassageiro(FilaPassageiro fila, long long int cpf) {
    int pos = 0;
    if (!filaVaziaPassageiro(fila)) {
        pCelulaPassageiro q = fila.frente->proximo;
        while(q != NULL) {
            if(q->item->cpf == cpf) {
                return pos;
            }
            pos++;
            q = q->proximo;
        }
    }
    else {
        return 0;
    }

    return pos;
}

#endif //V6_FILAPASSAGEIRO_H
