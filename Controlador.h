#pragma once
#include "Sensores.h"
#include "Display.h"
#include "Estado.h"
#include <string>


class Controlador {
public:
    Controlador(Sensores* sensors);
    Controlador(Sensores* sensors, Estado* estado);

    Estado onCallbackS000();
    Estado onCallbackS025();
    Estado onCallbackS050();
    Estado onCallbackS075();
    Estado onCallbackS0100();
    Estado onCallbackS0125();
    Estado onCallbackS0150();

private:
    Sensores* sensors;
    Estado* state;
    Display* display;

    void resetController();
    void waitForTwoSeconds();
    Estado updateStateAndReturn(Estado* newState, bool setController);
    Estado handleEvent000();
    Estado handleEvent025();
    Estado handleEvent050();
    Estado handleEvent075();
    Estado handleEvent100();
    Estado handleEvent125();
    Estado handleEvent150(int retreturnAmountu);
    Estado handleEventDEV(int returnAmount);
    Estado handleEventETIRPS();
    Estado handleEventMEET();
};
