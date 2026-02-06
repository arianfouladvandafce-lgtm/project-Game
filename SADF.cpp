#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void clear()
{
    system("cls");
}

void centerText(string text, int y)
{
    COORD pos;
    pos.X = (156 - text.length()) / 2;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    cout << text;
}

void soundMove()
{
    Beep(800, 100);
}
void soundSelect()
{
    Beep(1200, 200);
}
void soundError()
{
    Beep(300, 400);
}
void soundStartGame()
{
    Beep(600, 154);
    Sleep(50);
    Beep(900, 154);
    Sleep(50);
    Beep(1200, 200);
}
void soundTimer()
{
    Beep(1000,80);
}
void startSection()
{
    clear();

    for (int i = 0; i < 3; i++)
    {
        soundTimer();
        Sleep(1000);
    }

    clear();
    setColor(15);
    centerText("wellllcome", 20);
    Sleep(1000);

    clear();
    setColor(10);
    centerText("to", 20);
    Sleep(1000);

    clear();
    setColor(14);

    for (int i = 0; i <= 50 ; i++)
    {
        clear();
        COORD l = {SHORT(i+1), 20};
        COORD r = {SHORT(155 - i), 20};

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), l);
        cout << "SA";

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), r);
        cout << "DF";

        Sleep(120);
    }

    clear();
    centerText(" S D A F ", 20);
    Sleep(3000);
}
int mainMenu()
{
    int choice = 0;
    string options[2] = {" 2048 ", " 7667 "};

    while (true)
    {
        clear();
        setColor(15);
        centerText("+---------------------------+", 10);
        centerText("| FANTASTIC GAMES ARE READY |", 11);
        centerText("| Please choose your Game   |", 12);
        centerText("+---------------------------+", 13);

        for (int i = 0; i < 2; i++)
        {
            setColor(i == choice ? 12 : 15);
            centerText(options[i], 16 + i * 2);
        }

        int key = _getch();   
        if (key == 224)
        {
            key = _getch();
            if (key == 72 && choice > 0)
            {
                choice--;
                soundMove();
            }
            if (key == 80 && choice < 1)
            {
                choice++;
                soundMove();
            }
        }
        else if (key == 13)
        {
            soundSelect();
            return choice;
        }
    }
}
void show7667WithBeep()
{
    clear();
    soundStartGame();

    clear();
    setColor(15);
    centerText("wellllcome", 20);
    Sleep(1000);

    clear();
    setColor(10);
    centerText("to", 20);
    Sleep(1000);

    clear();
    setColor(14);

    for (int i = 0; i <= 30; i++)
    {
        clear();
        COORD l = {SHORT(i+1), 20};
        COORD r = {SHORT(155 - i), 20};

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), l);
        cout << " 76 ";

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), r);
        cout << " 67 ";

        soundTimer();
        Sleep(120);
    }

    clear();
    centerText("7667", 20);
    Sleep(3000);
}


int game7667Menu()
{
    int choice = 0;
    string options[2] = {" Play Custom ", " Play Default "};

    while (true)
    {
        clear();
        setColor(15);
        centerText("+---------------------------+", 10);
        centerText("|        Game 7667          |", 11);
        centerText("+---------------------------+", 12);

        for (int i = 0; i < 2; i++)
        {
            setColor(i == choice ? 12 : 15);
            centerText(options[i], 16 + i * 2);
        }
        int key = _getch();
        if (key == 224)
        {
            key = _getch();
            if (key == 72 && choice > 0)
            {
                choice--;
                soundMove();
            }
            if (key == 80 && choice < 1)
            {
                choice++;
                soundMove();
            }
        }
        else if (key == 13)
        {
            soundSelect();
            return choice;
        }
    }
}
int main()
{
    startSection();

    int game = mainMenu();

    if (game == 0)
    {
        clear();
        setColor(15);
        centerText("Section (2048) - later...", 12);
        soundError();
        Sleep(2000);
    }
    else
    {
        show7667WithBeep();

        int mode = game7667Menu();
        clear();
        setColor(15);

        centerText(mode == 0 ? "2" : "1", 12);
        soundSelect();
        Sleep(3000);
    }

    return 0;
}