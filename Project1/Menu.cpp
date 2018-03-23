#include "Menu.h" 

string Menu::SelectTypeInput()
{
	textcolor(11);
	gotoxy(80, 20); cout << "Choose type input";
	textcolor(10);
	gotoxy(84, 21); cout << "File input";
	textcolor(14);
	gotoxy(82, 22); cout << "Keyboard input";
	textcolor(12);
	gotoxy(72, 24); cout << "Press W S and SPACE to choose LEVEL";
	textcolor(11);
	int y = 21;
	int value = 1;
	bool choose = false;
	gotoxy(80, y); cout << ">>";
	gotoxy(96, y); cout << "<<";
	do
	{
		if (kbhit())
		{
			gotoxy(80, y); cout << ">>";
			gotoxy(96, y); cout << "<<";
			char c = getch();
			if ((c == 'S') && (y < 22))
			{
				gotoxy(80, y); cout << "  ";
				gotoxy(96, y); cout << "  ";
				y++;
				value++;
				gotoxy(80, y); cout << ">>";
				gotoxy(96, y); cout << "<<";
			}
			if ((c == 'W') && (y > 21))
			{
				gotoxy(80, y); cout << "  ";
				gotoxy(96, y); cout << "  ";
				y--;
				value--;
				gotoxy(80, y); cout << ">>";
				gotoxy(96, y); cout << "<<";
			}
			if (c == 32) break;
		}
	} while (!choose);
	if (value == 1) return "File";
	else if (value == 2) return "Keyboard";
}
void Menu::CreateMenu_File()
{
	textcolor(10);
	int y = 7;
	for (int i = 0;i < 20;i++)
	{
		gotoxy(88, y);
		cout << "||";
		y++;
	}
	textcolor(14);
	gotoxy(120, 7); cout << "MENU";
	gotoxy(115, 9); cout << "    B  : Back";
	gotoxy(115, 10); cout << "Press ESC  : EXIT";

	textcolor(8);
	gotoxy(25, 10); cout << " --------------------------------------";
	gotoxy(25, 11); cout << "|                                     |";
	gotoxy(25, 12); cout << " --------------------------------------";
	gotoxy(10, 11); cout << "File input:";

	gotoxy(25, 15); cout << " --------------------------------------"; 
	gotoxy(25, 16); cout << "|                                     |";
	gotoxy(25, 17); cout << " --------------------------------------";
	gotoxy(10, 16); cout << "File output:";

	textcolor(11);
}

void Menu::CreateMenu_Keyboard()
{
	textcolor(10);
	int y = 7;
	for (int i = 0;i < 20;i++)
	{
		gotoxy(88, y);
		cout << "||";
		y++;
	}
	textcolor(7);
	gotoxy(120, 7); cout << "MENU";
	gotoxy(108, 8); cout << "A S to move and Space to select";
	gotoxy(115, 9); cout << "    B  : Back";
	gotoxy(115, 10); cout << "Press ESC  : EXIT";
}

string Menu::Menu_Keyboard_SelectCalculatorType()
{
	textcolor(11);
	gotoxy(112, 12); cout << "Choose type Calculator";
	textcolor(10);
	gotoxy(113, 13); cout << "Converter Calculator";
	textcolor(14);
	gotoxy(115, 14); cout << "Basic Calculator";
	textcolor(11);
	int y = 13;
	int value = 1;
	bool choose = false;
	gotoxy(111, y); cout << ">>";
	gotoxy(133, y); cout << "<<";
	do
	{
		if (kbhit())
		{
			gotoxy(111, y); cout << ">>";
			gotoxy(133, y); cout << "<<";
			char c = getch();
			if ((c == 'S') && (y < 14))
			{
				gotoxy(111, y); cout << "  ";
				gotoxy(133, y); cout << "  ";
				y++;
				value++;
				gotoxy(111, y); cout << ">>";
				gotoxy(133, y); cout << "<<";
			}
			if ((c == 'W') && (y > 13))
			{
				gotoxy(111, y); cout << "  ";
				gotoxy(133, y); cout << "  ";
				y--;
				value--;
				gotoxy(111, y); cout << ">>";
				gotoxy(133, y); cout << "<<";
			}
			if (c == 32) break;
			if (c == 27) return "\n";
		}
	} while (!choose);
	if (value == 1) return "Converter";
	else if (value == 2) return "Basic";
}

string Menu::ConverterCalculator_SelectBase()
{
	textcolor(11);
	gotoxy(108, 16); cout << "Convert from |     | to |     |";
	
	int left, right;
	gotoxy(124, 16);
	cin >> left;

	gotoxy(135, 16);
	cin >> right;	
	
	if ((left == 2) && (right == 10)) return "BinToDec";
	else if (((left == 10) && (right == 2))) return "DecToBin";
	else if (((left == 2) && (right == 16))) return "BinToHex";
	else if (((left == 16) && (right == 2))) return "HexToBin";
}
	
bool Menu::LoopPro()
{
	do
	{
		if (kbhit())
		{
			char c = getch();
			switch (c)
			{
			case 'B':
				return true; //Continue with input type choosed
			case 27:
				return false; //Exit
			}
		}
	} while (true);
}