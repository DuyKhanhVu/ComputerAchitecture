#pragma once
#include "Screen.h"

class Menu :public Screen
{
public:
	string SelectTypeInput();
	void CreateMenu_File();
	void CreateMenu_Keyboard();
	string Menu_Keyboard_SelectCalculatorType();
	string ConverterCalculator_SelectBase();
	bool LoopPro();
};

