#pragma once
#include "Estado.h"

class Sensores {
public:
    Sensores(); // Passa uma referência para a classe Estado no construtor
    Sensores(bool test025, bool test050, bool test100, bool testDEV, bool testMEET, bool testETIRPS);// Passa uma referência para a classe Estado no construtor


    // Funções para detecção de eventos
    bool detectEvent025();
    bool detectEvent050();
    bool detectEvent100();
    bool detectEventDEV();
    bool detectEventMEET();
    bool detectEventETIRPS();
    void setController(bool value);
    bool detectingSensor() const;
    void updateSensors(bool test025, bool test050, bool test100, bool testDEV, bool testMEET, bool testETIRPS);


private:
    Estado* state; // Referência para a classe Estado
    bool controller;

    // Variáveis para manter o estado dos botões
    bool stateSensor025;
    bool stateSensor050;
    bool stateSensor100;
    bool stateSensorDEV;
    bool stateSensorMEET;
    bool stateSensorETIRPS;
};
