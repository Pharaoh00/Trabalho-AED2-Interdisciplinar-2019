//
// Created by HamonRa on 17/11/2019.
//

#ifndef V6_GERENCIAMENTO_H
#define V6_GERENCIAMENTO_H

void voosPadrao(pListaVoo voos) {

    pListaPassageiro listaPassageiros = criaListaPassageiro();
    pPilhaBagagem bagagens = criaPilhaBagagem();
    pFilaPassageiro filaPassageiro = criaFilaPassageiro();
    pVoo voo = criaVoo(5050, "BH", "RIO", 1300, 1345,
                       MAX_VALUE_QTD_LISTA_PASSAGEIRO, MAX_VALUE_QTD_FILA_PASSAGEIRO,
                       listaPassageiros, bagagens, filaPassageiro);
    inserirVoo(voos, voo);

    listaPassageiros = criaListaPassageiro();
    bagagens = criaPilhaBagagem();
    filaPassageiro = criaFilaPassageiro();
    voo = criaVoo(3044, "BH", "SAO PAULO", 1500, 1615,
                  MAX_VALUE_QTD_LISTA_PASSAGEIRO, MAX_VALUE_QTD_FILA_PASSAGEIRO, listaPassageiros,
                  bagagens, filaPassageiro);
    inserirVoo(voos, voo);

    listaPassageiros = criaListaPassageiro();
    bagagens = criaPilhaBagagem();
    filaPassageiro = criaFilaPassageiro();
    voo = criaVoo(1717, "BH", "SALVADOR", 0100, 1115,
                  MAX_VALUE_QTD_LISTA_PASSAGEIRO, MAX_VALUE_QTD_FILA_PASSAGEIRO, listaPassageiros,
                  bagagens, filaPassageiro);
    inserirVoo(voos, voo);
}

void mostrarOrdem(Voo voo) {
    int ordem = 1;
    //float maxPeso = voo.bagagens->topo->item->peso;
    //float minPeso = voo.bagagens->topo->item->peso;
    pBagagem maxPesoBagagem = voo.bagagens->topo->item;
    pBagagem minPesoBagagem = voo.bagagens->topo->item;
    pCelulaBagagem q = voo.bagagens->topo;
    if (!pilhaVaziaBagagem(*voo.bagagens) && !listaVaziaPassageiro(*voo.listaPassageiros)) {
        while (q != voo.bagagens->fundo) {
            pPassageiro passageiro = procurarPassageiroLista(*voo.listaPassageiros, *q->item->cpf, "^", false); // sem msg de erro
            printf("A mala do passageiro: %s com o cpf %lli sera a %i a sair.\n", passageiro->nome, *q->item->cpf,
                   ordem);
            //printf("A mala do passageiro %lli sera a %i a sair.\n", *q->item->cpf, ordem);
            ordem++;
            if (maxPesoBagagem->peso < q->item->peso) {
                //maxPeso = q->item->peso;
                maxPesoBagagem = q->item;
            }
            if (minPesoBagagem->peso > q->item->peso) {
                //minPeso = q->item->peso;
                minPesoBagagem = q->item;
            }
            q = q->proximo;
        }
        pPassageiro passageiro = procurarPassageiroLista(*voo.listaPassageiros, *maxPesoBagagem->cpf, "^", true); // com msng de erro
        printf("A bagagem com o maior peso tem %.2f - Passageiro: %s\n", maxPesoBagagem->peso, passageiro->nome);
        passageiro = procurarPassageiroLista(*voo.listaPassageiros, *minPesoBagagem->cpf, "^", true); // com msg de erro
        printf("A bagagem com o maior peso tem %.2f - Passageiro: %s\n", minPesoBagagem->peso, passageiro->nome);
    } else {
        printf("Nao pode mostrar a ordem de saida das bagagens ou dos Passageiros.\nPilha ou Lista vazia.\n\n");
    }
}

#endif //V6_GERENCIAMENTO_H
