#pragma once

class Display {
public:
    Display(); // Construtor
    ~Display(); // Destrutor

    void clear(); // Limpa o display
    void printChar(char c); // Insere um caractere no display
    void setCursor(int x, int y); // Define a posição do cursor
    void displayOn(); // Liga o display
    void displayOff(); // Desliga o display
    void displayMessage(const char* message); // Exibe uma mensagem no display

};
