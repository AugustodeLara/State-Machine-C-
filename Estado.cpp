// Estado.cpp
#include "Estado.h"

Estado::Estado() : currentState(S000) {}

int Estado::getEstadoAtual() {
    return currentState;
}

void Estado::selectS025() {
    currentState = S025;
}

void Estado::selectS050() {
    currentState = S050;
}

void Estado::selectS075() {
    currentState = S075;
}

void Estado::selectS100() {
    currentState = S100;
}

void Estado::selectS125() {
    currentState = S125;
}

void Estado::selectS150() {
    currentState = S150;
}

void Estado::selectS000() {
    currentState = S000;
}
