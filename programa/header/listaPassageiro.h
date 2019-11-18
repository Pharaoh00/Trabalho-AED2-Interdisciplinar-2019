//
// Created by HamonRa on 17/11/2019.
//

#ifndef V6_LISTAPASSAGEIRO_H
#define V6_LISTAPASSAGEIRO_H

typedef struct Passageiro {
    char *nome;
    long long int cpf;
    char *endereco;
    long long int telefone;
    pListaPassagem passagens;
} Passageiro, *pPassageiro;

typedef struct CelulaPassageiro {
    pPassageiro item;
    struct CelulaPassageiro *proximo;
} CelulaPassageiro, *pCelulaPassageiro;

typedef struct ListaPassageiro {
    pCelulaPassageiro primeiro;
    pCelulaPassageiro ultimo;
} ListaPassageiro, *pListaPassageiro;

pPassageiro criaPassageiro(char *nome, long long int cpf, char *endereco,
                           long long int telefone, pListaPassagem passagem) {
    if (passagem) {
        pPassageiro aux = (pPassageiro) malloc(sizeof(Passageiro)); // MARCA PARA FREE

        // inicializando a memoria na stack // MARCA PARA FREE
        aux->nome = (char *) calloc(strlen(nome) + 1, sizeof(char));
        snprintf(aux->nome, strlen(nome) + 1, "%s", nome); // copiar as memorias sem problemas

        aux->cpf = cpf;

        // NOTA:
        //      Por alguma razão, quando vai alocar memoria para o endereço é necessario strlen(endereco)+1
        aux->endereco = (char *) calloc(strlen(endereco) + 1, sizeof(char)); // MARCA PARA FREE
        snprintf(aux->endereco, strlen(endereco) + 1, "%s", endereco);

        aux->telefone = telefone;

        aux->passagens = passagem;

        return aux;
    }
    else {
        printf("Lista de pasagens invalida.\n");
        return NULL;
    }
}

pCelulaPassageiro criaCelulaPassageiro(pPassageiro item) {
    if (item) {
        pCelulaPassageiro aux = (pCelulaPassageiro) malloc(sizeof(Passageiro)); // MARCA PARA FREE
        aux->item = item;
        aux->proximo = NULL;

        return aux;
    }
    else {
        printf("Passageiro passado invalido.\n");
        return NULL;
    }
}

pListaPassageiro criaListaPassageiro() {
    pListaPassagem passagem = criaListaPassagem();
    pPassageiro item = criaPassageiro("^", 00, "^", 00, passagem);
    pCelulaPassageiro sentinela = criaCelulaPassageiro(item);

    pListaPassageiro lista = (pListaPassageiro) malloc(sizeof(ListaPassageiro)); // MARCA PARA FREE
    lista->primeiro = sentinela;
    lista->ultimo = sentinela;

    return lista;
}

bool listaVaziaPassageiro(ListaPassageiro passageiro) {
    if (passageiro.primeiro == passageiro.ultimo) {
        return true;
    }
    else {
        return false;
    }
}

/*void inserirPassageiro(pListaPassageiro lista, pPassageiro item) {
    pCelulaPassageiro aux = criaCelulaPassageiro(item);
    lista->ultimo->proximo = aux;
    lista->ultimo = aux;
}*/

pPassageiro procurarPassageiroLista(ListaPassageiro lista, long long int cpf, char *nome, bool flag) {
    // Se flag for igual a true, print as mensagens de erro.
    // Se flag for igual a false, print as mensagens sem erro.
    pCelulaPassageiro q = lista.primeiro->proximo;
    if (!listaVaziaPassageiro(lista)) {
        while (q != NULL) {
            if (q->item->cpf == cpf || strcmp(q->item->nome, nome) == 0) {
                return q->item;
            }
            else if (q->proximo == NULL && (q->item->cpf != cpf || strcmp(q->item->nome, nome) != 0)) {
                if (flag) {
                    printf("Passageiro nao encontrado.\n");
                }
                return NULL;
            }
            else {
                q = q->proximo;
            }
        }
    }
    else {
        if (flag) {
            printf("Nao pode encontrar passageiro. Lista vazia.\n");
        }
        return NULL;
    }
}

void inserirPassageiro(pListaPassageiro lista, pPassageiro item) {
    // Se o nome do item passado for NULL
    // Nem comece a procurar
    if (lista && item && item->nome != NULL) {
        pCelulaPassageiro q = lista->primeiro->proximo;
        pCelulaPassageiro anterior = lista->primeiro;
        pCelulaPassageiro novaCelula = criaCelulaPassageiro(item);
        if (!listaVaziaPassageiro(*lista)) {
            while (q != NULL) {
                if (q->item->nome != NULL) { // Deu cagada
                    // OPÇÃO CASO FOR O ULTIMO
                    // HÁ À NECESSIDADE DESSA OPÇÃO SER A PRIMEIRA.
                    // TERÁ QUE VERIFICAR SE O q->proximo É NULL ou lista->ultimo == q
                    // SABE-SE QUE O q EM QUESTÃO É O ULTIMO ITEM DA LISTA E SE FOR NECESSARIO A INSERCÃO DEPOIS DO q,
                    // A LISTA TEM QUE SER ATUALIZA.
                    if (q->proximo == NULL && strcmp(novaCelula->item->nome, q->item->nome) == 1) {
                        novaCelula->proximo = q->proximo; // == NULL
                        q->proximo = novaCelula;
                        lista->ultimo = novaCelula; // ultimo atualizado.
                        break; // pare de procurar.
                    }
                        // OPÇÃO PARA INSERIR ANTES DO q E DEPOIS DO anterior.
                        //
                        // NÃO TEM QUE CHECAR SE REALMENTE É DEPOIS DO ANTERIOR.
                    else if (strcmp(novaCelula->item->nome, q->item->nome) == -1) {
                        //else if(strcmp(novaCelula->item->nome, anterior->item->nome) == 1) {
                        anterior->proximo = novaCelula;
                        novaCelula->proximo = q;
                        break; // pare de procurar.
                    }
                        // OPÇÃO PARA INSERIR DEPOIS DO q (SENDO q->proximo != NULL)
                        // TEM QUE GARANTIR QUE O item FIQUE ANTES DO q->proximo.
                        // NO CASO É: Se somente se, q->item der 1 (inserir depois do q) e q->proximo der -1 (inserir antes)
                    else if (strcmp(novaCelula->item->nome, q->item->nome) == 1 &&
                             strcmp(novaCelula->item->nome, q->proximo->item->nome) == -1) {
                        // SEGUIR A SEQUENCIA. Primeiro falar q nova celula aponta para q->proximo
                        novaCelula->proximo = q->proximo;
                        q->proximo = novaCelula;
                        break; // pare de procurar.
                    }
                    else {
                        q = q->proximo; // continue procurando.
                    }
                }
                else {
                    printf("Nao pode inserir o passageiro. Nome invalido.\n");
                    break;
                }
            }
        }
        else {
            // CASO A LISTA ESTIVER VAZIA, O ITEM SERÁ INSERIDO POR ULTIMO DE QUALQUER FORMA.
            // SOMENTE PARA INSERIR UM ITEM COM A LISTA VAZIA,
            // POIS EM NENHUMA DAS OPÇÕES A CIMA GARANTE ISSO.
            lista->ultimo->proximo = novaCelula;
            lista->ultimo = novaCelula;
            return;
        }
    }
    else {
        printf("Nao pode inserir o item. Lista ou passageiro nao existem.\n");
    }
}

void printPassageiro(Passageiro passageiro) {
    printf("|| ------------------------------ Passageiro ------------------------------ ||\n");
    printf("Nome do passageiro: %s\n", passageiro.nome);
    printf("Cpf do passageiro: %lli\n", passageiro.cpf);
    printf("Endereco do passageiro: %s\n", passageiro.endereco);
    printf("Telefone do passageiro: %lli\n", passageiro.telefone);
    printPassagens(*passageiro.passagens);
    //printf("|| ------------------------------------------------------------------------ ||\n");
}

void printPassageiros(ListaPassageiro lista) {
    pCelulaPassageiro q;
    q = lista.primeiro->proximo;
    if (!listaVaziaPassageiro(lista)) {
        while (q != NULL) {
            printPassageiro(*q->item);
            q = q->proximo;
        }
    }
    else {
        printf("Lista de passageiros vazia.\n");
    }
}

bool checkCpfListaPassageiro(ListaPassageiro lista, long long int cpf) {
    // return true Se tiver um cpf igual
    // return false se nao tiver um cpf igual
    if (!listaVaziaPassageiro(lista)) {
        pCelulaPassageiro q = lista.primeiro->proximo;
        while (q != NULL) {
            if (q->item->cpf == cpf) {
                return true;
            }
            else if (q->proximo == NULL && q->item->cpf != cpf) {
                return false;
            }
            else {
                q = q->proximo;
            }
        }
    }
    else {
        return false; // Lista vazia. Ninguem para comparar.
    }
}

void freePassageiro(pPassageiro passageiro) {
    if (passageiro) {
        // Dando free no malloc() do char array nome
        if (passageiro->nome) {
            free(passageiro->nome);
        }
        // Dando free no malloc() do char array endereco
        if (passageiro->endereco) {
            free(passageiro->endereco);
        }
        if (passageiro->passagens) {
            freeListaPassagem(passageiro->passagens);
        }

        // Dando free no malloc() do passageiro aux
        free(passageiro);
    }
}

void freeCelulaPassageiro(pCelulaPassageiro passageiro) {
    if (passageiro) {
        // Dando free na struct do passageiro
        if (passageiro->item) {
            freePassageiro(passageiro->item);
        }
        // Dando free na celula do passageiro
        passageiro->proximo = NULL;
        free(passageiro);
    }
}

void freeListaPassageiro(pListaPassageiro listaPassageiro) {
    if (listaPassageiro) {
        pCelulaPassageiro q = listaPassageiro->primeiro->proximo;
        if (!listaVaziaPassageiro(*listaPassageiro)) {
            while (q != NULL) {
                freeCelulaPassageiro(q);
                q = q->proximo;
            }
        }
        else {
            //listaPassageiro->primeiro->proximo = NULL; // apontando o sentinela para NULL
            freeCelulaPassageiro(listaPassageiro->primeiro); // FREE NO SENTINELA
            // Dando free no malloc() do criaListaPassageiro()
            free(listaPassageiro);
        }
    }
}

bool retirarUltimoListaPassageiro(pListaPassageiro lista) {
    if (!listaVaziaPassageiro(*lista)) {
        pCelulaPassageiro q = lista->primeiro->proximo;
        while (q != NULL) {
            // Caso tiver uma unica celula na lista
            if (lista->primeiro->proximo == q) {
                lista->primeiro->proximo = NULL; // Apontar o sentinela para NULL
                lista->ultimo = lista->primeiro; // Fazer com que a lista fique vazia
                freeCelulaPassageiro(q); // liberar a celula q
                return true;
            }
            else if (q->proximo == lista->ultimo) {
                freeCelulaPassageiro(q->proximo); // == lista->ultimo FREE celula ultimo
                q->proximo = NULL;
                lista->ultimo = q; // Agora, o anterior ao ultimo é o ultimo
                return true;
            }
            else {
                q = q->proximo;
            }
        }
    }
    else {
        printf("Nao pode retirar. Lista Vazia.\n");
        return false;
    }
}

bool inserirUltimoListaPassageiro(pListaPassageiro lista, pPassageiro passageiro) {
    pCelulaPassageiro novaCelula = criaCelulaPassageiro(passageiro);
    lista->ultimo->proximo = novaCelula;
    lista->ultimo = novaCelula;
}

bool retirarPassageiro(pListaPassageiro lista, long long int cpf) {
    if (!listaVaziaPassageiro(*lista)) {
        pCelulaPassageiro q = lista->primeiro->proximo;
        pCelulaPassageiro anterior = lista->primeiro;
        while (q != NULL) {
            if (q->item->cpf == cpf) {
                anterior->proximo = q->proximo;
                // Atualizando o ultimo da lista
                if(q->proximo == NULL && anterior != lista->primeiro) {
                    anterior->proximo = NULL;
                    lista->ultimo = anterior;
                }
                if(q->proximo == NULL && anterior == lista->primeiro) {
                    lista->primeiro = lista->ultimo;
                }
                freeCelulaPassageiro(q);
                return true;
            }

            anterior = q;
            q = q->proximo;
        }
    }
    else {
        printf("Nao pode retirar o passageiro. Lista vazia.\n");
        return false;
    }
}

int qtdListaPassageiro(ListaPassageiro lista) {
    int qtd = 0;
    if (!listaVaziaPassageiro(lista)) {
        pCelulaPassageiro q = lista.primeiro->proximo;
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

pPassageiro primeiroListaPassageiro(pListaPassageiro lista) {
    if(!listaVaziaPassageiro(*lista)) {
        return lista->primeiro->proximo->item;
    }
    else {
        return NULL;
    }
}
#endif //V6_LISTAPASSAGEIRO_H
