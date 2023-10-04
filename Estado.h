// Estado.h
#pragma once

class Estado {
public:
    enum Estados {
        S000,
        S025,
        S050,
        S075,
        S100,
        S125,
        S150
    };

    Estado();

    int getEstadoAtual();
    void selectS000();
    void selectS025();
    void selectS050();
    void selectS075();
    void selectS100();
    void selectS125();
    void selectS150();

private:
    Estados currentState;
};
