#include "Sensores.h"
#include "Estado.h"
#include <iostream> // Para usar std::cout

// Endereços dos registradores da FPGA
volatile unsigned int *data = (volatile unsigned int *)0x80000a00;

Sensores::Sensores() : state(state) {
    // Inicialize o estado dos botões
    stateSensor025 = false;
    stateSensor050 = false;
    stateSensor100 = false;
    stateSensorDEV = false;
    stateSensorETIRPS = false;
    stateSensorMEET = false;    

}


Sensores::Sensores(bool test025, bool test050, bool test100, bool testDEV, bool testMEET, bool testETIRPS) : state(state) {
    // Inicialize o estado dos botões
    stateSensor025 = test025;
    stateSensor050 = test050;
    stateSensor100 = test100;
    stateSensorDEV = testDEV;
    stateSensorMEET = testMEET;
    stateSensorETIRPS = testETIRPS;    

}

bool Sensores::detectEvent025() {
    // Lógica de detecção do evento de moeda de 0,25 (baseado no botão BTNU)
    /*estadoBotao025 = ((*data & (1 << 16)) != 0); // Verifica se o bit 16 (BTNU) está definido

    if (estadoBotao025) {
        std::cout << "LOG: detectEvent025: Botão 0,25 pressionado" << std::endl;
    }

    return estadoBotao025 ?: false;
    */
    return stateSensor025;
}

bool Sensores::detectEvent050() {
    // Lógica de detecção do evento de moeda de 0,50 (baseado no botão BTNL)
    /*
    estadoBotao050 = ((*data & (1 << 17)) != 0); // Verifica se o bit 17 (BTNL) está definido

    if (estadoBotao050) {
        std::cout << "LOG: detectEvent050: Botão 0,50 pressionado" << std::endl;
    }

    return estadoBotao050 ?: false;
    */
    return stateSensor050;
}

bool Sensores::detectEvent100() {
    // Lógica de detecção do evento de moeda de 1,00 (baseado no botão BTND)
    /*
    estadoBotao100 = ((*data & (1 << 18)) != 0); // Verifica se o bit 18 (BTND) está definido

    if (estadoBotao100) {
        std::cout << "LOG: detectEvent100: Botão 1,00 pressionado" << std::endl;
    }

    return estadoBotao100 ?: false;
    */
    return stateSensor100;
}

bool Sensores::detectEventDEV() {
    // Lógica de detecção do evento de devolução de moedas
    // Pode incluir lógica específica aqui, se necessário

    // Adicione um log aqui se necessário
    // Exemplo: std::cout << "LOG: detectEventDEV: Botão de devolução pressionado" << std::endl;

    return stateSensorDEV;
}

bool Sensores::detectEventMEET() {
    // Lógica de detecção do evento de escolha do refrigerante MEET (baseado no botão BTNR)
    /*
    estadoBotaoMEET = ((*data & (1 << 19)) != 0); // Verifica se o bit 19 (BTNR) está definido

    if (estadoBotaoMEET) {
        std::cout << "LOG: detectEventMEET: Botão MEET pressionado" << std::endl;
    }

    return estadoBotaoMEET  ?: false;
    */
    return stateSensorMEET;
}

bool Sensores::detectEventETIRPS() {
    // Lógica de detecção do evento de escolha do refrigerante ETIRPS (baseado no botão BTNC)
    /*
    estadoBotaoETIRPS = ((*data & (1 << 20)) != 0); // Verifica se o bit 20 (BTNC) está definido

    if (estadoBotaoETIRPS) {
        std::cout << "LOG: detectEventETIRPS: Botão ETIRPS pressionado" << std::endl;
    }

    return estadoBotaoETIRPS  ?: false;
    */
    return stateSensorETIRPS;
}


// Função para definir o valor do controller
void Sensores::setController(bool value) {
    controller = value;
}

// Função para obter o valor do controller
bool Sensores::detectingSensor() const {
    return controller;
}

void Sensores::updateSensors(bool test025, bool test050, bool test100, bool testDEV, bool testMEET, bool testETIRPS) {
    stateSensor025 = test025;
    stateSensor050 = test050;
    stateSensor100 = test100;
    stateSensorDEV = testDEV;
    stateSensorMEET = testMEET;
    stateSensorETIRPS = testETIRPS;
}