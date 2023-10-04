#include "Display.h"
#include "OLED.h"
#include "utils.h"

Display::Display() {
    // Inicialize o OLED
    oledInit();
}

Display::~Display() {
    // Desligue o OLED ao destruir a instância
    oledOff();
}

void Display::clear() {
    // Limpe o display
    oledClear();
}

void Display::printChar(char c) {
    // Insira um caractere no display
    printChar(c);
}


void Display::displayOff() {
    // Desliga o display
    oledOff();
}
