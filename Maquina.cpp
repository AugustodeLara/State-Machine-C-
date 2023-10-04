// Maquina.cpp
#include "Maquina.h"
#include <iostream>

Maquina::Maquina() {
    stateMachine = new Estado();
    sensors = new Sensores();
    controller = new Controlador(sensors, stateMachine);
}

Maquina::~Maquina() {
    delete sensors;
    delete controller;
    delete stateMachine;
}

void Maquina::onExecute() {
    int i = 0;
    while (true) {
     

        std::cout << "======================================================" << std::endl;
        if(i == 0){
        sensors->updateSensors(true, false, false, false, false, false); 
        }
        if(i == 1){
            sensors->updateSensors(false, true, false, false, false, false);
        }
        if(i == 2){
           sensors->updateSensors(true, false, false, false, false, false);
        }
        if(i == 3){
           sensors->updateSensors(false, false, false, true, false, false);
        }
        if(i == 4){
           sensors->updateSensors(false, false, true, false, false, false);
        }
        if(i == 5){
           sensors->updateSensors(false, false, true, false, false, false);
        }
        if(i == 6){
           sensors->updateSensors(false, false, false, false, true, false);
        }
        if(i == 7){
           sensors->updateSensors(false, false, false, false, false, true);
        }
        if(i > 7){
            i = 0;
        }
        switch (stateMachine->getEstadoAtual()) {
            case Estado::S000:
                std::cout << "Estado S000" << std::endl;
                *stateMachine = controller->onCallbackS000();
                break;
            case Estado::S025:
                std::cout << "Estado S025" << std::endl;
                *stateMachine = controller->onCallbackS025();
                break;
            case Estado::S050:
                std::cout << "Estado S050" << std::endl;
                *stateMachine = controller->onCallbackS050();
                break;
            case Estado::S075:
                std::cout << "Estado S075" << std::endl;
                *stateMachine = controller->onCallbackS075();
                break;
            case Estado::S100:
                std::cout << "Estado S100" << std::endl;
                *stateMachine = controller->onCallbackS0100();
                break;
            case Estado::S125:
                std::cout << "Estado S125" << std::endl;
                *stateMachine = controller->onCallbackS0125();
                break;
            case Estado::S150:
                std::cout << "Estado S150" << std::endl;
                *stateMachine = controller->onCallbackS0150();
                break;
            default:
                std::cout << "Estado desconhecido" << std::endl;
                return;
        }
        i++;
    }
}
