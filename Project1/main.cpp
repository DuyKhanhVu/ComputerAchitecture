#include "Screen.h"
#include "Menu.h"

int main()
{
	Screen Scr;
	bool endPro = true; //End Program for loop
	do
	{
		Scr.resizeConsole(1500, 1500);
		//Sleep(500);
		system("cls");
		Menu Menu;
		Scr.Playing();
		string typeInput = Menu.SelectTypeInput(); 
		
		
		for (;;)
		{
			system("cls");
			Scr.Playing();
			if (typeInput == "File")
			{
				string Fi_Name, Fo_Name;
				Menu.CreateMenu_File();
				Menu.gotoxy(26, 11); 
				cin >> Fi_Name; //File input
				Menu.gotoxy(26, 16);
				cin >> Fo_Name; //File output
				Scr.Processing();

				//Processing

				endPro = Menu.LoopPro();
			}
				
			else 
			{
				Menu.CreateMenu_Keyboard();
				string typeCal = Menu.Menu_Keyboard_SelectCalculatorType();
				if (typeCal == "\n")
				{
					endPro = false; break;
				}
				else if (typeCal == "Converter")
				{
					string typeCon = Menu.ConverterCalculator_SelectBase(); //Type converter
					Scr.CreateInputConvert();
					string InputNum;
					cin >> InputNum;

					if (typeCon == "BinToDec")
					{
						//Processing
					}
					else if ("DecToBin")
					{
						//Processing
					}
					else if ("BinToHex")
					{
						//Processing
					}
					else if ("HexToBin")
					{
						//Processing
					}
					
					Scr.WriteResultConvert();
				}
				else if (typeCal == "Basic")
				{
					Scr.CreateInputBasic();

					Scr.gotoxy(62, 10);
					int base; // 2 4 8 10 16
					cin >> base;

					Scr.gotoxy(20, 13);
					string Num1;
					cin >> Num1;
					
					Scr.gotoxy(62, 16);
					string Ope; // + - * / & | ~ << >>
					cin >> Ope;

					Scr.gotoxy(20, 19);
					string Num2;
					cin >> Num2;

					//Processing with Num1, Ope and Num2
					Scr.WriteResultBasic();
				}
				endPro = Menu.LoopPro();
			}
			if (endPro == false) break;
		}
	} while (endPro);
	//system("pause");
}