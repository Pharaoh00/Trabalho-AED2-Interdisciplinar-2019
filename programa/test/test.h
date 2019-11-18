//
// Created by HamonRa on 17/11/2019.
//

#ifndef V6_TEST_H
#define V6_TEST_H

void testCriaPassageiros(pListaVoo voos) {

    pVoo voo;
    pPassageiro passageiro;
    pPassagem passagem;

    voo = procurarVoo(*voos, 5050);
    pListaPassagem listaPassagem = criaListaPassagem();
    passageiro = criaPassageiro("Gabriela", 101010109, "NULL", 31999999999, listaPassagem);
    passagem = criaPassagem(&voo->nVoo, &passageiro->cpf, 4121, &voo->hPartida, &voo->hChegada);
    inserirPassagem(passageiro->passagens, passagem);
    pBagagem bagagem;
    float peso = randomFloat(MIN_VALUE_PESO_BAGAGEM, MAX_VALUE_PESO_BAGAGEM);
    bagagem = criaBagagem(&voo->nVoo, &passageiro->cpf, peso);
    empilharBagagem(voo->bagagens, bagagem);
    //inserirPassageiro(voo->listaPassageiros, passageiro);
    inserirUltimoListaPassageiro(voo->listaPassageiros, passageiro);

    voo = procurarVoo(*voos, 5050);
    listaPassagem = criaListaPassagem();
    passageiro = criaPassageiro("Benjamin", 111111119, "NULL", 31999999999, listaPassagem);
    passagem = criaPassagem(&voo->nVoo, &passageiro->cpf, 4121, &voo->hPartida, &voo->hChegada);
    inserirPassagem(passageiro->passagens, passagem);
    peso = randomFloat(MIN_VALUE_PESO_BAGAGEM, MAX_VALUE_PESO_BAGAGEM);
    bagagem = criaBagagem(&voo->nVoo, &passageiro->cpf, peso);
    empilharBagagem(voo->bagagens, bagagem);
    //inserirPassageiro(voo->listaPassageiros, passageiro);
    inserirUltimoListaPassageiro(voo->listaPassageiros, passageiro);

    voo = procurarVoo(*voos, 5050);
    listaPassagem = criaListaPassagem();
    passageiro = criaPassageiro("Yago", 121212129, "NULL", 31999999999, listaPassagem);
    passagem = criaPassagem(&voo->nVoo, &passageiro->cpf, 4121, &voo->hPartida, &voo->hChegada);
    inserirPassagem(passageiro->passagens, passagem);
    peso = randomFloat(MIN_VALUE_PESO_BAGAGEM, MAX_VALUE_PESO_BAGAGEM);
    bagagem = criaBagagem(&voo->nVoo, &passageiro->cpf, peso);
    empilharBagagem(voo->bagagens, bagagem);
    //inserirPassageiro(voo->listaPassageiros, passageiro);
    inserirUltimoListaPassageiro(voo->listaPassageiros, passageiro);

    voo = procurarVoo(*voos, 5050);
    listaPassagem = criaListaPassagem();
    passageiro = criaPassageiro("Alice", 131313139, "NULL", 31999999999, listaPassagem);
    passagem = criaPassagem(&voo->nVoo, &passageiro->cpf, 4121, &voo->hPartida, &voo->hChegada);
    inserirPassagem(passageiro->passagens, passagem);
    peso = randomFloat(MIN_VALUE_PESO_BAGAGEM, MAX_VALUE_PESO_BAGAGEM);
    bagagem = criaBagagem(&voo->nVoo, &passageiro->cpf, peso);
    empilharBagagem(voo->bagagens, bagagem);
    //inserirPassageiro(voo->listaPassageiros, passageiro);
    inserirUltimoListaPassageiro(voo->listaPassageiros, passageiro);

    voo = procurarVoo(*voos, 5050);
    listaPassagem = criaListaPassagem();
    passageiro = criaPassageiro("Fernando", 141414149, "NULL", 31999999999, listaPassagem);
    passagem = criaPassagem(&voo->nVoo, &passageiro->cpf, 4121, &voo->hPartida, &voo->hChegada);
    inserirPassagem(passageiro->passagens, passagem);
    peso = randomFloat(MIN_VALUE_PESO_BAGAGEM, MAX_VALUE_PESO_BAGAGEM);
    bagagem = criaBagagem(&voo->nVoo, &passageiro->cpf, peso);
    empilharBagagem(voo->bagagens, bagagem);
    //inserirPassageiro(voo->listaPassageiros, passageiro);
    inserirUltimoListaPassageiro(voo->listaPassageiros, passageiro);

    voo = procurarVoo(*voos, 5050);
    listaPassagem = criaListaPassagem();
    passageiro = criaPassageiro("Ziraldo", 151515159, "NULL", 31999999999, listaPassagem);
    passagem = criaPassagem(&voo->nVoo, &passageiro->cpf, 4121, &voo->hPartida, &voo->hChegada);
    inserirPassagem(passageiro->passagens, passagem);
    peso = randomFloat(MIN_VALUE_PESO_BAGAGEM, MAX_VALUE_PESO_BAGAGEM);
    bagagem = criaBagagem(&voo->nVoo, &passageiro->cpf, peso);
    empilharBagagem(voo->bagagens, bagagem);
    //inserirPassageiro(voo->listaPassageiros, passageiro);
    inserirUltimoListaPassageiro(voo->listaPassageiros, passageiro);

    voo = procurarVoo(*voos, 1717);
    listaPassagem = criaListaPassagem();
    passageiro = criaPassageiro("Mary Carla Leal Taveira", 161616169, "NULL", 31999999999,
                                listaPassagem);
    passagem = criaPassagem(&voo->nVoo, &passageiro->cpf, 4120, &voo->hPartida, &voo->hChegada);
    inserirPassagem(passageiro->passagens, passagem);
    peso = randomFloat(MIN_VALUE_PESO_BAGAGEM, MAX_VALUE_PESO_BAGAGEM);
    bagagem = criaBagagem(&voo->nVoo, &passageiro->cpf, peso);
    empilharBagagem(voo->bagagens, bagagem);
    //inserirPassageiro(voo->listaPassageiros, passageiro);
    inserirUltimoListaPassageiro(voo->listaPassageiros, passageiro);
}

void testEnfileirarPassageiro(pListaVoo voos) {

    pVoo voo;
    pPassageiro passageiro;
    pPassagem passagem;


    voo = procurarVoo(*voos, 5050);
    pListaPassagem listaPassagem = criaListaPassagem();
    passageiro = criaPassageiro("Ziraldo", 101010109, "NULL", 31999999999, listaPassagem);
    passagem = criaPassagem(&voo->nVoo, &passageiro->cpf, 4121, &voo->hPartida, &voo->hChegada);
    inserirPassagem(passageiro->passagens, passagem);
    enfileirarPassageiro(voo->filaPassageiros, passageiro);

    voo = procurarVoo(*voos, 5050);
    listaPassagem = criaListaPassagem();
    passageiro = criaPassageiro("Alice", 151515159, "NULL", 31999999999, listaPassagem);
    passagem = criaPassagem(&voo->nVoo, &passageiro->cpf, 4121, &voo->hPartida, &voo->hChegada);
    inserirPassagem(passageiro->passagens, passagem);
    enfileirarPassageiro(voo->filaPassageiros, passageiro);

}

#endif //V6_TEST_H
