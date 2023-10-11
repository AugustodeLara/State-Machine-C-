// Maquina.cpp
#include "Maquina.h"
#include "Display.h"
#include <iostream>
#include "Oled.h"
#include "utils.h"
#include <cstring> // Inclua a biblioteca cstring

Maquina::Maquina() {
    stateMachine = new Estado();
    sensors = new Sensores();
    display = new Display();
    controller = new Controlador(sensors, stateMachine, display);
}

Maquina::~Maquina() {
    delete sensors;
    delete controller;
    delete stateMachine;
    delete display;
}

void Maquina::onExecute() {
    char S000[] = "S000";
    char S025[] = "S025";
    char S050[] = "S050";
    char S075[] = "S075";
    char S100[] = "S100";
    char S125[] = "S125";
    char S150[] = "S150";

    oledInit();

    while (true) {
        switch (stateMachine->getEstadoAtual()) {
            case Estado::S000:
                std::cout << "Estado S000" << std::endl;
                oledClear();

                for (int i = 0; i < strlen(S000); i++) {
                    printChar(S000[i]);
                }

                *stateMachine = controller->onCallbackS000();
                break;
            case Estado::S025:
                std::cout << "Estado S025" << std::endl;
               // oledClear();

              //  for (int i = 0; i < strlen(S025); i++) {
               //     printChar(S025[i]);
             //   }

                *stateMachine = controller->onCallbackS025();
                break;
            case Estado::S050:
                std::cout << "Estado S050" << std::endl;
             //   oledClear();

            //    for (int i = 0; i < strlen(S050); i++) {
                 //   printChar(S050[i]);
            //    }

                *stateMachine = controller->onCallbackS050();
                break;
            case Estado::S075:
                std::cout << "Estado S075" << std::endl;
              //  oledClear();

              //  for (int i = 0; i < strlen(S075); i++) {
               //     printChar(S075[i]);
               // }

                *stateMachine = controller->onCallbackS075();
                break;
            case Estado::S100:
                std::cout << "Estado S100" << std::endl;
               // oledClear();

               // for (int i = 0; i < strlen(S100); i++) {
               //     printChar(S100[i]);
               // }

                *stateMachine = controller->onCallbackS0100();
                break;
            case Estado::S125:
                std::cout << "Estado S125" << std::endl;
                //oledClear();

                //for (int i = 0; i < strlen(S125); i++) {
                //    printChar(S125[i]);
                //}

                *stateMachine = controller->onCallbackS0125();
                break;
            case Estado::S150:
                std::cout << "Estado S150" << std::endl;
                //oledClear();

                //for (int i = 0; i < strlen(S150); i++) {
                //    printChar(S150[i]);
               // }

                *stateMachine = controller->onCallbackS0150();
                break;
            default:
                std::cout << "Estado desconhecido" << std::endl;
                return;
        }
    }
}
