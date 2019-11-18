//
// Created by HamonRa on 17/11/2019.
//

#ifndef V6_CRIANVOO_H
#define V6_CRIANVOO_H

int criaNvoo() {
    int nVoo = 0;
    int error = 0;
    printf("Digite o Numero do Voo desejado: ");
    fflush(stdin);
    scanf("%i", &nVoo);
    while(!checkLongLongInt(nVoo)) {
        printf("Numero do voo invalido.\n");
        printf("Digite o Numero do Voo novamente: ");
        fflush(stdin);
        scanf("%i", &nVoo);
        error++;
        if(error > 2) {
            printf("Tente digitar somente numeros.\n");
            printf("Tente sem caracteres especiais.\n");
            printf("Por exemplo: 'á' ou 'ô' - '-' ou '*'.\n");
        }
    }
    return nVoo;
}

#endif //V6_CRIANVOO_H
