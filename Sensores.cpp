#include "Sensores.h"
#include "Estado.h"
#include <iostream> // Para usar std::cout

// Endereços dos registradores da FPGA
volatile unsigned int *Sensores::data = (volatile unsigned int *)0x80000a00;

Sensores::Sensores() {
    // Inicialize o estado dos botões
    stateSensor025 = false;
    stateSensor050 = false;
    stateSensor100 = false;
    stateSensorDEV = false;
    stateSensorETIRPS = false;
    stateSensorMEET = false;    

}


Sensores::Sensores(bool test025, bool test050, bool test100, bool testDEV, bool testMEET, bool testETIRPS) {
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
    bool buttonPressed = ((*data & (1 << 16)) != 0); // Verifica se o bit 16 (BTNU) está definido
    
    // Verifica se o botão foi pressionado e o estado anterior estava desligado
    if (buttonPressed && !stateSensor025) {
        stateSensor025 = true; // Atualiza o estado
        std::cout << "LOG: detectEvent025: Botão 0,25 pressionado" << std::endl;
    }
    else if (!buttonPressed) {
        stateSensor025 = false; // Atualiza o estado quando o botão for liberado
    }

    return stateSensor025;
}

bool Sensores::detectEvent050() {
    // Lógica de detecção do evento de moeda de 0,50 (baseado no botão BTNL)
    bool buttonPressed = ((*data & (1 << 17)) != 0); // Verifica se o bit 17 (BTNL) está definido
    
    // Verifica se o botão foi pressionado e o estado anterior estava desligado
    if (buttonPressed && !stateSensor050) {
        stateSensor050 = true; // Atualiza o estado
        std::cout << "LOG: detectEvent050: Botão 0,50 pressionado" << std::endl;
    }
    else if (!buttonPressed) {
        stateSensor050 = false; // Atualiza o estado quando o botão for liberado
    }

    return stateSensor050;
}

bool Sensores::detectEvent100() {
    // Lógica de detecção do evento de moeda de 1,00 (baseado no botão BTND)
    bool buttonPressed = ((*data & (1 << 18)) != 0); // Verifica se o bit 18 (BTND) está definido
    
    // Verifica se o botão foi pressionado e o estado anterior estava desligado
    if (buttonPressed && !stateSensor100) {
        stateSensor100 = true; // Atualiza o estado
        std::cout << "LOG: detectEvent100: Botão 1,00 pressionado" << std::endl;
    }
    else if (!buttonPressed) {
        stateSensor100 = false; // Atualiza o estado quando o botão for liberado
    }

    return stateSensor100;
}

bool Sensores::detectEventDEV() {
    // Lógica de detecção do evento de devolução de moedas (baseado no botão BTNR)
    bool buttonPressed = ((*data & (1 << 19)) != 0); // Verifica se o bit 19 (BTNR) está definido
    
    // Verifica se o botão foi pressionado e o estado anterior estava desligado
    if (buttonPressed && !stateSensorDEV) {
        stateSensorDEV = true; // Atualiza o estado
        std::cout << "LOG: detectEventDEV: Botão de devolução pressionado" << std::endl;
    }
    else if (!buttonPressed) {
        stateSensorDEV = false; // Atualiza o estado quando o botão for liberado
    }

    return stateSensorDEV;
}

bool Sensores::detectEventMEET() {
    // Lógica de detecção do evento de escolha do refrigerante MEET (baseado no botão BTNC)
    bool buttonPressed = ((*data & (1 << 20)) != 0); // Verifica se o bit 20 (BTNC) está definido
    
    // Verifica se o botão foi pressionado e o estado anterior estava desligado
    if (buttonPressed && !stateSensorMEET) {
        stateSensorMEET = true; // Atualiza o estado
        std::cout << "LOG: detectEventMEET: Botão MEET pressionado" << std::endl;
    }
    else if (!buttonPressed) {
        stateSensorMEET = false; // Atualiza o estado quando o botão for liberado
    }

    return stateSensorMEET;
}

bool Sensores::detectEventETIRPS() {
    // Lógica de detecção do evento de escolha do refrigerante ETIRPS (baseado na chave SW0)
    bool switchState = ((*data & (1 << 8)) != 0); // Verifica se o bit 8 (SW0) está definido
    
    // Verifica se a chave está na posição 1 e o estado anterior estava em 0
    if (switchState && !stateSensorETIRPS) {
        stateSensorETIRPS = true; // Atualiza o estado
        std::cout << "LOG: detectEventETIRPS: Chave SW0 na posição 1" << std::endl;
    }
    else if (!switchState) {
        stateSensorETIRPS = false; // Atualiza o estado quando a chave estiver em outra posição
    }

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