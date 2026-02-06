#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <string>


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

        Sleep(90);
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


int score = 0;
string playerName;
void setColor2048(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void printjadval(int jadval[4][4])
{
    cout << "#------#------#------#------#\n";
    for (int i = 0; i < 4; i++)
    {
        cout << "|";
        for (int j = 0; j < 4; j++)
        {
            if (jadval[i][j] == 0)
            {
                cout << "      |";
            }
            else
            {
                int val = jadval[i][j];

                if (val == 2)
                    setColor2048(9);
                else if (val == 4)
                    setColor2048(12);
                else if (val == 8)
                    setColor2048(10);
                else if (val == 16)
                    setColor2048(14);
                else if (val == 32)
                    setColor2048(11);
                else if (val == 64)
                    setColor2048(13);
                else
                    setColor2048(15);

                printf(" %4d ", val);
                setColor2048(7);
                cout << "|";
            }
        }
        cout << "\n#------#------#------#------#\n";
    }
}
void moveleft(int a[4])
{
    int chap[4] = {0, 0, 0, 0};
    int index = 0;
    for (int i = 0; i < 4; i++)
        if (a[i] != 0)
            chap[index++] = a[i];

    for (int i = 0; i < 3; i++)
    {
        if (chap[i] != 0 && chap[i] == chap[i + 1])
        {
            chap[i] *= 2;
            score += chap[i];
            chap[i + 1] = 0;
        }
    }

    int b[4] = {0, 0, 0, 0};
    int index2 = 0;
    for (int i = 0; i < 4; i++)
        if (chap[i] != 0)
            b[index2++] = chap[i];

    for (int i = 0; i < 4; i++)
        a[i] = b[i];
}

void moveright(int a[4])
{
    int reversed[4];
    for (int i = 0; i < 4; i++)
        reversed[i] = a[3 - i];
    moveleft(reversed);
    for (int i = 0; i < 4; i++)
        a[i] = reversed[3 - i];
}

void transpose(int jadval[4][4])
{
    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 4; j++)
            swap(jadval[i][j], jadval[j][i]);
}

void moverightjadval(int jadval[4][4])
{
    for (int i = 0; i < 4; i++)
        moveright(jadval[i]);
}

void moveleftjadval(int jadval[4][4])
{
    for (int i = 0; i < 4; i++)
        moveleft(jadval[i]);
}

void moveupjadval(int jadval[4][4])
{
    transpose(jadval);
    moveleftjadval(jadval);
    transpose(jadval);
}

void movedownjadval(int jadval[4][4])
{
    transpose(jadval);
    moverightjadval(jadval);
    transpose(jadval);
}

void addrandomnumber(int jadval[4][4])
{
    int count = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (jadval[i][j] == 0)
                count++;

    if (count == 0)
        return;

    int r = rand() % count;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (jadval[i][j] == 0)
            {
                if (r == 0)
                {
                    jadval[i][j] = (rand() % 10 < 9) ? 2 : 4;
                    return;
                }
                r--;
            }
        }
    }
}
bool checklose(int jadval[4][4])
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (jadval[i][j] == 0)
                return false;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 3; j++)
            if (jadval[i][j] == jadval[i][j + 1])
                return false;

    for (int j = 0; j < 4; j++)
        for (int i = 0; i < 3; i++)
            if (jadval[i][j] == jadval[i + 1][j])
                return false;

    return true;
}

bool checkwin(int jadval[4][4])
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (jadval[i][j] == 2048)
                return true;
    return false;
}
void game2048()
{
    srand(time(0));

    cout << "Enter player name: ";
    getline(cin, playerName);

    int jadval[4][4] = {0};
    addrandomnumber(jadval);
    addrandomnumber(jadval);

    while (true)
    {
        system("cls");
        printjadval(jadval);
        cout << "Score: " << score << endl;
        cout << "Use keys W/A/S/D to move. Press Ctrl+C to exit.\n";

        char c = _getch();

        int oldjadval[4][4];
        memcpy(oldjadval, jadval, sizeof(jadval));

        if (c == 'w' || c == 'W')
            moveupjadval(jadval);
        else if (c == 'a' || c == 'A')
            moveleftjadval(jadval);
        else if (c == 'd' || c == 'D')
            moverightjadval(jadval);
        else if (c == 's' || c == 'S')
            movedownjadval(jadval);
        else
            continue;

        bool changed = false;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if (oldjadval[i][j] != jadval[i][j])
                    changed = true;

        if (changed)
            addrandomnumber(jadval);

        if (checkwin(jadval))
        {
            system("cls");
            printjadval(jadval);
            cout << "YOU WIN\n";
            break;
        }

        if (checklose(jadval))
        {
            system("cls");
            printjadval(jadval);
            cout << "YOU LOST\n";
            break;
        }
    }

    ofstream file("scores.txt", ios::app);
    if (file.is_open())
    {
        file << playerName << " " << score << endl;
        file.close();
    }
}

int main()
{
    startSection();

    int game = mainMenu();

    if (game == 0)
    {
        clear();
        soundStartGame();
        game2048();
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