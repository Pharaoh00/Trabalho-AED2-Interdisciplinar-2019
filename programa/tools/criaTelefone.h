//
// Created by HamonRa on 17/11/2019.
//

#ifndef V6_CRIATELEFONE_H
#define V6_CRIATELEFONE_H

long long int criaTelefone() {
    long long int telefone = 0;
    int error = 0;
    printf("Digite o telefone do passageiro: ");
    fflush(stdin);
    scanf("%lli", &telefone);
    while(!checkLongLongInt(telefone)) {
        printf("Telefone digitando invalido.\n");
        printf("Digite o telefone novamente: ");
        fflush(stdin);
        scanf("%lli", &telefone);
        error++;
        if(error > 2) {
            printf("Tente digitar somente numeros.\n");
            printf("Tente sem caracteres especiais.\n");
            printf("Por exemplo: 'á' ou 'ô' - '-' ou '*'.\n");
        }
    }
    return telefone;
}

#endif //V6_CRIATELEFONE_H
