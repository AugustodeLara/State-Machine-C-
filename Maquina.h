// Maquina.h
#pragma once
#include "Display.h"
#include "Estado.h"
#include "Sensores.h"
#include "Controlador.h"

class Maquina {
public:
    Maquina();
    ~Maquina();

    void onExecute();

private:
    Estado* stateMachine;
    Sensores* sensors;
    Controlador* controller;
    Display* display;
};
