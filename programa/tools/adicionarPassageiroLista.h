//
// Created by HamonRa on 17/11/2019.
//

#ifndef V6_ADICIONARPASSAGEIROLISTA_H
#define V6_ADICIONARPASSAGEIROLISTA_H

bool adicionarPassageiroLista(pVoo voo) {
    char opcao[MAX_ARRAY_VALUE];
    pPassageiro passageiro = NULL;

    long long int cpf = 0;
    char nome[MAX_ARRAY_VALUE];
    char endereco[MAX_ARRAY_VALUE];
    long long int telefone = 0;
    int poltrona = randomInt(MAX_VALUE_POLTRONA, MIN_VALUE_POLTRONA);
    int error = 0;

    printf("\n");
    cpf = criaCpf();
    if(!checkCpfListaPassageiro(*voo->listaPassageiros, cpf)) {
        printf("Digite o nome do passageiro: ");
        fflush(stdin);
        gets(nome);
        while (!checkString(nome)) {
            printf("Nome invalido.\n");
            printf("Digite o nome novamente: ");
            fflush(stdin);
            gets(nome);
            error++;
            if (error > 2) {
                printf("Tente digitar somente letras. Sem acentos.\n");
                printf("Tente sem caracteres especiais.\n");
                printf("Por exemplo: 'á' ou 'ô' - '-' ou '*'.\n");
            }
        }
        error = 0; // resetando o erros;

        printf("Digite o endereco do passageiro: ");
        fflush(stdin);
        gets(endereco);
        while(!checkString(endereco)) {
            printf("Endereco invalido.\n");
            printf("Digite o endereco novamente: ");
            fflush(stdin);
            gets(endereco);
            error++;
            if (error > 2) {
                printf("Tente digitar somente letras. Sem acentos.\n");
                printf("Tente sem caracteres especiais.\n");
                printf("Por exemplo: 'á' ou 'ô' - '-' ou '*'.\n");
            }
        }
        error = 0; // resetando o erros;

        telefone = criaTelefone();

        // Inicializando a lista de passagens do passageiro.
        pListaPassagem passagens = criaListaPassagem();

        // Criando o passageiro.
        passageiro = criaPassageiro(nome, cpf, endereco, telefone, passagens);
        if(passageiro) {
            // Criando a passagem do passageiro com o voo atual.
            pPassagem passagem = criaPassagem(&voo->nVoo, &passageiro->cpf, poltrona, &voo->hPartida, &voo->hChegada);
            // inserindo a passagem na lista de passagens.
            inserirPassagem(passagens, passagem);

            printPassageiro(*passageiro);
            // Inserir o passageiro no voo
            printf("Dados do Passageiro correto? s/n: ");
            fflush(stdin);
            gets(opcao);
            if(strcmp("s", opcao) == 0) {

                int qtdLista = qtdListaPassageiro(*voo->listaPassageiros);
                int qtdFila = qtdFilaPassageiro(*voo->filaPassageiros);

                if(qtdLista < voo->qtdMaximaLista) {
                    inserirUltimoListaPassageiro(voo->listaPassageiros, passageiro);
                    printf("Passageiro adicionado na lista do voo.\n");
                    return true;
                }
                else if(qtdFila < voo->qtdMaximaFila) {
                    printf("Lista do voo cheia.\n");
                    printf("Deseja adicionar o passageiro na fila de espera? s/n: ");
                    fflush(stdin);
                    gets(opcao);
                    if(strcmp("s", opcao) == 0) {
                        enfileirarPassageiro(voo->filaPassageiros, passageiro);
                        printf("Passageiro adicionado na fila de espera.\n");
                        return true;
                    }
                }
                else {
                    // Passageiro nao quis ser adicionaro na fila de espera.
                    return false;
                }
            }
        }
        else {
            // Erro na criação do passageiro.
            // Talvez nunca aconteça nada?
            // Se acontecer, retorne false.
            return false;
        }
    }
    else {
        printf("Passageiro com o cpf %lli ja existe na reserva.\n", cpf);
        return false;
    }
}

#endif //V6_ADICIONARPASSAGEIROLISTA_H
