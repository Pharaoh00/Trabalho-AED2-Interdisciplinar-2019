//
// Created by HamonRa on 17/11/2019.
//

#ifndef V6_ADICIONARPASSAGEIROLISTA_V2_H
#define V6_ADICIONARPASSAGEIROLISTA_V2_H

void adiconarPassageiroLista_v2(pListaVoo lista) {
    int qtdLista = 0;
    int qtdFila = 0;
    int nVoo = 0;
    int error = 0;
    char opcao[10];

    bool subMenu = true;
    pVoo voo = NULL;

    while(subMenu) {

        printf("\n");
        nVoo = criaNvoo();
        voo = procurarVoo(*lista, nVoo);
        if(voo) {
            qtdLista = qtdListaPassageiro(*voo->listaPassageiros);
            qtdFila = qtdFilaPassageiro(*voo->filaPassageiros);

            char nome[MAX_ARRAY_VALUE];
            long long int cpf;
            char endereco[MAX_ARRAY_VALUE];
            long long int telefone;

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
                error = 0; // resetando o erros.

                printf("Digite o endereco do passageiro: ");
                fflush(stdin);
                gets(endereco);
                while (!checkString(endereco)) {
                    printf("endereco invalido.\n");
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

                // criando uma lista de passagens do passageiro vazia.
                pListaPassagem passagens = criaListaPassagem();

                // Criando o passageiro
                pPassageiro passageiro = criaPassageiro(nome, cpf, endereco, telefone, passagens);

                // valor aleatorio para a poltrona
                int poltrona = randomInt(MAX_VALUE_POLTRONA, MIN_VALUE_POLTRONA);
                pPassagem passagem = criaPassagem(&voo->nVoo, &passageiro->cpf, poltrona, &voo->hPartida, &voo->hChegada);
            }
            else {
                printf("CPF '%lli' ja existe.\n", cpf);
            }
        }
        else {
            printf("Numero do Voo '%i' nao encontrado.\n");
        }
    }
}

#endif //V6_ADICIONARPASSAGEIROLISTA_V2_H
