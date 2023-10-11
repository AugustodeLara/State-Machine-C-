// Controlador.cpp
#include "Controlador.h"
#include "Display.h"
#include "Estado.h"
#include <iostream>
#include <time.h>
#include "Oled.h"
#include "utils.h"
#include <cstring>

char S000[] = "S000";
char S025[] = "S025";
char S050[] = "S050";
char S075[] = "S075";
char S100[] = "S100";
char S125[] = "S125";
char S150[] = "S150";
char SDEV[] = "SDEV";
char SMEET[] = "SMEET";
char SETIRPS[] = "ETIRPS";

Controlador::Controlador(Sensores* sensors, Estado* state, Display* display)
    : sensors(sensors), state(state), display(display) {
    oledInit();
    oledClear(); 

}

void Controlador::resetController() {
    sensors->setController(false);
}

Estado Controlador::updateStateAndReturn(Estado* newState, bool setController) {
    if (setController) {
        sensors->setController(true);
    }
    return *newState;
}

void Controlador::waitForTwoSeconds() {
    clock_t start_time = clock();
    while ((clock() - start_time) / CLOCKS_PER_SEC < 2) {}
}

Estado Controlador::handleEvent000() {
    state->selectS000();
    return updateStateAndReturn(state, true);
}

Estado Controlador::handleEvent025() {
    state->selectS025();

    return updateStateAndReturn(state, true);
}

Estado Controlador::handleEvent050() {
    state->selectS050();

    return updateStateAndReturn(state, true);
}

Estado Controlador::handleEvent075() {
    state->selectS075();

    return updateStateAndReturn(state, true);
}

Estado Controlador::handleEvent100() {
    state->selectS100();


    return updateStateAndReturn(state, true);
}

Estado Controlador::handleEvent125() {
    state->selectS125();

    return updateStateAndReturn(state, true);
}

Estado Controlador::handleEvent150(int retreturnAmountu) {
    state->selectS150();
    std::cout << "LOG: DEVOLVE " << retreturnAmountu << std::endl;
    std::cout << "LOG: JÁ TEM SUFICIENTE: " << retreturnAmountu << std::endl;

        oledClear();

    for (int i = 0; i < strlen(S150); i++) {
        printChar(S150[i]);
    }

    return updateStateAndReturn(state, true);
}

Estado Controlador::handleEventDEV(int returnAmount) {
    state->selectS000();
    std::cout << "LOG: DEVOLVE " << returnAmount << std::endl;


    return updateStateAndReturn(state, true);
}

Estado Controlador::handleEventETIRPS() {
    state->selectS000();
    oledClear();

    for (int i = 0; i < strlen(SETIRPS); i++) {
        printChar(SETIRPS[i]);
    }
    delay(1000000); // 2 segundos em microssegundos

    return updateStateAndReturn(state, true);
}

Estado Controlador::handleEventMEET() {
    state->selectS000();
    oledClear();

    for (int i = 0; i < strlen(SMEET); i++) {
        printChar(SMEET[i]);
    }
    delay(1000000); // 2 segundos em microssegundos

    return updateStateAndReturn(state, true);
}

Estado Controlador::onCallbackS000() {
    resetController();
    std::cout << "LOG: Estado onS000" << std::endl;
    waitForTwoSeconds();

    while (sensors->detectingSensor() == false) {
        if (sensors->detectEvent025()) {
            std::cout << "LOG: detectEvent025" << std::endl;
            return handleEvent025();
        } else if (sensors->detectEvent050()) {
            std::cout << "LOG: detectEvent050" << std::endl;
            return handleEvent050();
        } else if (sensors->detectEvent100()) {
            std::cout << "LOG: detectEvent100" << std::endl;
            return handleEvent100();
        } else if (sensors->detectEventDEV()) {
            std::cout << "LOG: detectEventDEV" << std::endl;
            return handleEventDEV(0);
        } else if (sensors->detectEventETIRPS()) {
            std::cout << "LOG: detectEventETIRPS" << std::endl;
            std::cout << "LOG: No Money" << std::endl;
            return handleEvent000();
        } else if (sensors->detectEventMEET()) {
            std::cout << "LOG: No Money" << std::endl;
            std::cout << "LOG: detectEventMEET" << std::endl;
            return handleEvent000();
        }
    }

    return *state;
}

Estado Controlador::onCallbackS025() {
    resetController();
    std::cout << "LOG: Estado onS025" << std::endl;
    waitForTwoSeconds();

    while (!sensors->detectingSensor()) {
        if (sensors->detectEvent025()) {
            std::cout << "LOG: detectEvent025" << std::endl;
            return handleEvent050();
        } else if (sensors->detectEvent050()) {
            std::cout << "LOG: detectEvent050" << std::endl;
            return handleEvent075();
        } else if (sensors->detectEvent100()) {
            std::cout << "LOG: detectEvent100" << std::endl;
            return handleEvent125();
        } else if (sensors->detectEventDEV()) {
            std::cout << "LOG: detectEventDEV" << std::endl;
            return handleEventDEV(25);
        } else if (sensors->detectEventETIRPS()) {
            std::cout << "LOG: detectEventETIRPS" << std::endl;
            return handleEvent025();
        } else if (sensors->detectEventMEET()) {
            std::cout << "LOG: No Money" << std::endl;
            std::cout << "LOG: detectEventMEET" << std::endl;
            return handleEvent025();
        }
    }

    return *state;
}

Estado Controlador::onCallbackS050() {
    resetController();
    std::cout << "LOG: Estado onS050" << std::endl;
    waitForTwoSeconds();

    while (!sensors->detectingSensor()) {
        if (sensors->detectEvent025()) {
            std::cout << "LOG: detectEvent025" << std::endl;
            return handleEvent075();
        } else if (sensors->detectEvent050()) {
            std::cout << "LOG: detectEvent050" << std::endl;
            return handleEvent100();
        } else if (sensors->detectEvent100()) {
            std::cout << "LOG: detectEvent100" << std::endl;
            return handleEvent125();
        } else if (sensors->detectEventDEV()) {
            std::cout << "LOG: detectEventDEV" << std::endl;
            handleEventDEV(50);
        } else if (sensors->detectEventETIRPS()) {
            std::cout << "LOG: detectEventETIRPS" << std::endl;
            return handleEvent050();
        } else if (sensors->detectEventMEET()) {
            std::cout << "LOG: detectEventMEET" << std::endl;
            std::cout << "LOG: No Money" << std::endl;
            return handleEvent050();
        }
    }

    return *state;
}

Estado Controlador::onCallbackS075() {
    resetController();
    std::cout << "LOG: Estado onS075" << std::endl;
    waitForTwoSeconds();

    while (!sensors->detectingSensor()) {
        if (sensors->detectEvent025()) {
            std::cout << "LOG: detectEvent025" << std::endl;
            return handleEvent100();
        } else if (sensors->detectEvent050()) {
            std::cout << "LOG: detectEvent050" << std::endl;
            return handleEvent125();
        } else if (sensors->detectEvent100()) {
            std::cout << "LOG: detectEvent100" << std::endl;
            return handleEvent150(25);
        } else if (sensors->detectEventDEV()) {
            std::cout << "LOG: detectEventDEV" << std::endl;
            handleEventDEV(75);
        } else if (sensors->detectEventETIRPS()) {
            std::cout << "LOG: detectEventETIRPS" << std::endl;
            std::cout << "LOG: No Money" << std::endl;
            return handleEvent075();
        } else if (sensors->detectEventMEET()) {
            std::cout << "LOG: detectEventMEET" << std::endl;
            std::cout << "LOG: No Money" << std::endl;
            return handleEvent075();
        }
    }

    return *state;
}

Estado Controlador::onCallbackS0100() {
    resetController();
    std::cout << "LOG: Estado onS0100" << std::endl;
    waitForTwoSeconds();

    while (!sensors->detectingSensor()) {
        if (sensors->detectEvent025()) {
            std::cout << "LOG: detectEvent025" << std::endl;
            return handleEvent125();
        } else if (sensors->detectEvent050()) {
            std::cout << "LOG: detectEvent050" << std::endl;
            return handleEvent150(0);
        } else if (sensors->detectEvent100()) {
            std::cout << "LOG: detectEvent100" << std::endl;
            return handleEvent150(50);
        } else if (sensors->detectEventDEV()) {
            std::cout << "LOG: detectEventDEV" << std::endl;
            handleEventDEV(100);
        } else if (sensors->detectEventETIRPS()) {
            std::cout << "LOG: detectEventETIRPS" << std::endl;
            std::cout << "LOG: No Money" << std::endl;
            return handleEvent100();
        } else if (sensors->detectEventMEET()) {
            std::cout << "LOG: detectEventMEET" << std::endl;
            std::cout << "LOG: No Money" << std::endl;
            return handleEvent100();
        }
    }

    return *state;
}

Estado Controlador::onCallbackS0125() {
    resetController();
    std::cout << "LOG: Estado onS0125" << std::endl;
    waitForTwoSeconds();

    while (!sensors->detectingSensor()) {
        if (sensors->detectEvent025()) {
            std::cout << "LOG: detectEvent025" << std::endl;
            return handleEvent150(0);
        } else if (sensors->detectEvent050()) {
            std::cout << "LOG: detectEvent050" << std::endl;
            return handleEvent150(25);
        } else if (sensors->detectEvent100()) {
            std::cout << "LOG: detectEvent100" << std::endl;
            return handleEvent150(75);
        } else if (sensors->detectEventDEV()) {
            std::cout << "LOG: detectEventDEV" << std::endl;
            return handleEventDEV(125);
        } else if (sensors->detectEventETIRPS()) {
            std::cout << "LOG: detectEventETIRPS" << std::endl;
            std::cout << "LOG: No Money" << std::endl;
            return handleEvent125();
        } else if (sensors->detectEventMEET()) {
            std::cout << "LOG: detectEventMEET" << std::endl;
            std::cout << "LOG: No Money" << std::endl;
            return handleEvent125();
        }
    }

    return *state;
}

Estado Controlador::onCallbackS0150() {
    resetController();
    std::cout << "LOG: Estado onS0150" << std::endl;
    waitForTwoSeconds();

    while (!sensors->detectingSensor()) {
        if (sensors->detectEvent025()) {
            std::cout << "LOG: detectEvent025" << std::endl;
            return handleEvent150(25);
        } else if (sensors->detectEvent050()) {
            std::cout << "LOG: detectEvent050" << std::endl;
            return handleEvent150(50);
        } else if (sensors->detectEvent100()) {
            std::cout << "LOG: detectEvent100" << std::endl;
            return handleEvent150(100);
        } else if (sensors->detectEventDEV()) {
            std::cout << "LOG: detectEventDEV" << std::endl;
            return handleEventDEV(150);
        } else if (sensors->detectEventETIRPS()) {
            std::cout << "LOG: detectEventETIRPS" << std::endl;
            std::cout << "LOG: No Money" << std::endl;
            return handleEventETIRPS();
        } else if (sensors->detectEventMEET()) {
            std::cout << "LOG: detectEventMEET" << std::endl;
            std::cout << "LOG: No Money" << std::endl;
            return handleEventMEET();
        }
    }

    return *state;
}
