#pragma once
#include "display.h"
#include "OLED.cpp"
#include <string>
#include <vector>

volatile unsigned int *data = (volatile unsigned int *)0x80000a00;


class OLED_driver : public display
{
public:

	void mostra(string txt) {
		// conversor string para char*
		//std::vector<char> writable(txt.begin(), txt.end());
		//writable.push_back('\0');	
		//printString(&writable[0]);
		printString(txt);
	}
	void apagar_tela() {
		oledClear();
	}

	bool apaga(){
		if (*data == 822083840) { return 1; }
		else { return 0; }
	}
	bool atualiza(){
		if (*data == 822084096) { return 0; }
		else { return 1; }
	}
	void liga(){
		oledInit();
		delay(2000000);
		oledFill();
		delay(2000000);
		oledClear();
	}


};

