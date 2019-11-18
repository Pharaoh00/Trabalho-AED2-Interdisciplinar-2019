//
// Created by HamonRa on 17/11/2019.
//

#ifndef V6_CRIACPF_H
#define V6_CRIACPF_H

long long int criaCpf() {
    long long int cpf = 0;
    int error = 0;
    printf("Digite o CPF do passageiro: ");
    fflush(stdin);
    scanf("%lli", &cpf);
    while(!checkLongLongInt(cpf)) {
        printf("CPF digitando invalido.\n");
        printf("Digite o CPF novamente: ");
        fflush(stdin);
        scanf("%lli", &cpf);
        error++;
        if(error > 2) {
            printf("Tente digitar somente numeros.\n");
            printf("Tente sem caracteres especiais.\n");
            printf("Por exemplo: 'á' ou 'ô' - '-' ou '*'.\n");
        }
    }
    return cpf;
}

#endif //V6_CRIACPF_H
