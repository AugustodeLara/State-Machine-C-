#include "Display.h"
#include "Oled.h"
#include "utils.h"
#include <cstring> // Inclua a biblioteca cstring

Display::Display() {
    // Inicialize o OLED
    oledInit();
}

Display::~Display() {
    // Desligue o OLED ao destruir a instância
    //oledOff();
    //oledClear();
    //printChar('X');
    //delay(2000000); // 2 segundos em microssegundos
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


void Display::displayMessage(const char* message) {
    oledClear(); // Limpe o display
    for (int i = 0; i < strlen(message); i++) {
        printChar(message[i]); // Insira cada caractere da mensagem no display
    }
}
