#include "Screen.h"
#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable : 4996)

BOOL NT_SetConsoleDisplayMode(HANDLE hOutputHandle, DWORD dwNewMode)
{
	typedef BOOL(WINAPI *SCDMProc_t) (HANDLE, DWORD, LPDWORD);
	SCDMProc_t SetConsoleDisplayMode;
	HMODULE hKernel32;
	BOOL bFreeLib = FALSE, ret;
	const char KERNEL32_NAME[] = "kernel32.dll";

	hKernel32 = GetModuleHandleA(KERNEL32_NAME);
	if (hKernel32 == NULL)
	{
		hKernel32 = LoadLibraryA(KERNEL32_NAME);
		if (hKernel32 == NULL)
			return FALSE;

		bFreeLib = true;
	}

	SetConsoleDisplayMode =
		(SCDMProc_t)GetProcAddress(hKernel32, "SetConsoleDisplayMode");
	if (SetConsoleDisplayMode == NULL)
	{
		SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
		ret = FALSE;
	}
	else
	{
		DWORD tmp;
		ret = SetConsoleDisplayMode(hOutputHandle, dwNewMode, &tmp);
	}

	if (bFreeLib)
		FreeLibrary(hKernel32);

	return ret;
}

void Screen::setFullScreen()
{
	NT_SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), 1);
}

void Screen::CleanScreen()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

void Screen::gotoxy(SHORT x, SHORT y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1,y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void Screen::resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void Screen::textcolor(int x)
{
	HANDLE color;
	color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, x);
}

bool Screen::checkKey(int key)
{
	return GetAsyncKeyState(key);
}


void Screen::Processing()
{
	string quotes[10];
	gotoxy(83, 28); cout << "Processing..."; Sleep(500);
	quotes[0] = "Ask not what your country can do for you; ask what you can do for your country.";
	quotes[1] = "If you want something done right, do it yourself.";
	quotes[2] = "Knowledge is power.";
	quotes[3] = "To acquire knowledge, one must study; but to acquire wisdom, one must observe.";
	quotes[4] = "Learn form yesterday, Life for to day, Hope for tomorrow.";
	quotes[5] = "A new Language, a new Life.";
	quotes[6] = "I walk slowly, but I never walk backward.";
	quotes[7] = "Old way won't open new door.";
	quotes[8] = "Remember why you started.";
	quotes[9] = "Good Luck.";
	srand(time(NULL));
	int x = rand() % 10;
	gotoxy(90 - quotes[x].length() / 2, 30); cout << quotes[x];
}

void Screen::Playing()
{
	textcolor(11);
	gotoxy(60, 2); cout << " ___    __           ___                 __   _____  ____   ___        ";
	gotoxy(60, 3); cout << "|      /__\\   |     |    |    | |       /__\\    |   |    | |   | ";
	gotoxy(60, 4); cout << "|     /    \\  |     |    |    | |      /    \\   |   |    | |---'   ";
	gotoxy(60, 5); cout << "|___ /      \\ |____ |___ |____| |____ /      \\  |   |____| | \\__";
}

void Screen::CreateInputConvert()
{
	textcolor(8);
	gotoxy(10, 13); cout << "Input:";
	gotoxy(18, 12); cout << " ------------------------------------------------";
	gotoxy(18, 13); cout << "|                                                |";
	gotoxy(18, 14); cout << " ------------------------------------------------";

	gotoxy(10, 17); cout << "Result:";
	gotoxy(18, 16); cout << " ------------------------------------------------";
	gotoxy(18, 17); cout << "|                                                |";
	gotoxy(18, 18); cout << " ------------------------------------------------";
	
	textcolor(11);
	gotoxy(20, 13); //For read input
}

void Screen::WriteResultConvert()
{
	gotoxy(20, 17);
	//Write Result
}

void Screen::CreateInputBasic()
{
	textcolor(8);
	gotoxy(60, 9); cout << " ----";
	gotoxy(60, 10), cout << "|    |";
	gotoxy(60, 11); cout << " ----";

	gotoxy(18, 12); cout << " ------------------------------------------------";
	gotoxy(18, 13); cout << "|                                                |";
	gotoxy(18, 14); cout << " ------------------------------------------------";

	gotoxy(60, 15); cout << " ----";
	gotoxy(60, 16), cout << "|    |";
	gotoxy(60, 17); cout << " ----";


	gotoxy(18, 18); cout << " ------------------------------------------------";
	gotoxy(18, 19); cout << "|                                                |";
	gotoxy(18, 20); cout << " ------------------------------------------------";

	gotoxy(16, 21); cout << "______________________________________________________";

	gotoxy(18, 22); cout << " ------------------------------------------------";
	gotoxy(18, 23); cout << "|                                                |";
	gotoxy(18, 24); cout << " ------------------------------------------------";
	textcolor(11);
}

void Screen::WriteResultBasic()
{
	gotoxy(19, 23);
	//Write result
}
