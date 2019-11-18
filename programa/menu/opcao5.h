//
// Created by HamonRa on 17/11/2019.
//

#ifndef V6_OPCAO5_H
#define V6_OPCAO5_H

void opcao5(pListaVoo lista) {

    FILE *fptr;
    fptr = fopen("passageiros.txt", "w");
    if (fptr == NULL) {
        printf("Nao pode gravar o arquivo.\n");
    }
    else {
        pCelulaVoo q = lista->primeiro->proximo;
        while (q != NULL) {
            fprintf(fptr, "|| --------------------------------- Voo ---------------------------------- ||\n");
            fprintf(fptr, "Numero do voo: %i\n", q->item->nVoo);
            fprintf(fptr, "Voo com origem: %s - com destino: %s\n", q->item->origem, q->item->destino);
            fprintf(fptr, "Horario de saida do voo: %i - com chegada (horario local do destino): %i\n",
                    q->item->hPartida, q->item->hChegada);
            fprintf(fptr, "Maximo de passageiros no aviao: %i - maximo passageiros na fila de espera: %i\n",
                    q->item->qtdMaximaLista, q->item->qtdMaximaFila);
            fprintf(fptr, "Quantidade de passageiros na lista: %i\n", qtdListaPassageiro(*q->item->listaPassageiros));
            fprintf(fptr, "Quantidade de passageiros na fila: %i\n", qtdFilaPassageiro(*q->item->filaPassageiros));
            fprintf(fptr, "|| -------------------------- LISTA PASSAGEIROS --------------------------- ||\n\n");
            //printPassageiros(*voo.listaPassageiros);
            pCelulaPassageiro l = q->item->listaPassageiros->primeiro->proximo;
            while (l != NULL) {
                fprintf(fptr, "|| ------------------------------ Passageiro ------------------------------ ||\n");
                fprintf(fptr, "Nome do passageiro: %s\n", l->item->nome);
                fprintf(fptr, "Cpf do passageiro: %lli\n", l->item->cpf);
                fprintf(fptr, "Endereco do passageiro: %s\n", l->item->endereco);
                fprintf(fptr, "Telefone do passageiro: %lli\n", l->item->telefone);

                l = l->proximo;
            }
            fprintf(fptr, "|| --------------------------- FILA PASSAGEIROS --------------------------- ||\n\n");
            pCelulaPassageiro f = q->item->filaPassageiros->frente->proximo;
            while (f != NULL) {
                fprintf(fptr, "|| ------------------------------ Passageiro ------------------------------ ||\n");
                fprintf(fptr, "Nome do passageiro: %s\n", f->item->nome);
                fprintf(fptr, "Cpf do passageiro: %lli\n", f->item->cpf);
                fprintf(fptr, "Endereco do passageiro: %s\n", f->item->endereco);
                fprintf(fptr, "Telefone do passageiro: %lli\n", f->item->telefone);
                f = f->proximo;
            }
            fprintf(fptr, "|| ---------------------------- PILHA BAGAGENS ---------------------------- ||\n\n");
            //printBagagens(fptr, *voo.bagagens);
            pCelulaBagagem b = q->item->bagagens->topo;
            while (b != q->item->bagagens->topo) {
                fprintf(fptr, "|| -------------------------------- Bagagem ------------------------------- ||\n");
                if (b->item->nVoo == NULL) {
                    fprintf(fptr, "Numero do voo: NULL\n");
                }
                else {
                    fprintf(fptr, "Numero do voo: %i\n", *b->item->nVoo);
                }
                if (b->item->cpf == NULL) {
                    fprintf(fptr, "Cpf do passageiro: NULL\n");
                }
                else {
                    fprintf(fptr, "Cpf do passageiro: %lli\n", *b->item->cpf);
                }
                fprintf(fptr, "Peso da bagagem: %.2f\n", b->item->peso);
                b = b->proximo;
            }
            fprintf(fptr, "|| ------------------------------------------------------------------------ ||\n\n");

            q = q->proximo;
        }
    }
    printf("Arquivo gravado com sucesso.\n");
    fclose(fptr);
}

#endif //V6_OPCAO5_H
