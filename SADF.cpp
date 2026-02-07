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
    Beep(1000, 80);
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

    for (int i = 0; i <= 50; i++)
    {
        clear();
        COORD l = {SHORT(i + 1), 20};
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
        COORD l = {SHORT(i + 1), 20};
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
void centerText2048(int x, int y)
{
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void game2048()
{
    srand(time(0));
    centerText2048(68, 20);
    cout << "Enter Player Name: ";
    getline(cin, playerName);
    Sleep(500);
    clear();

    centerText2048(72, 20);
    cout << "Hello " << playerName;
    soundStartGame();
    Sleep(5000);
    clear();

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

void drawFrame()
{
    setColor(15);
    for (int x = 0; x < 154; x++)
    {
        COORD t = {(SHORT)x, 0};
        COORD b = {(SHORT)x, 44};
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), t);
        setColor(13);
        cout << "M";
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), b);
        setColor(5);
        cout << "W";
    }

    for (int y = 0; y < 40; y++)
    {
        COORD l = {0, (SHORT)y};
        COORD r = {155, (SHORT)y};
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), l);
        setColor(9);
        cout << "H";
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), r);
        setColor(3);
        cout << "H";
    }
}

void saveGame(string username, int X, int N, int M, int total)
{
    ofstream file("save.txt");
    file << username << endl;
    file << X << " " << N << " " << M << " " << total;
    file.close();
}
void playCustom()
{
    clear();
    system("color F0");
    drawFrame();

    setColor(0);
    centerText("Published By Arian ", 20);
    Sleep(5000);
    soundStartGame();

    clear();
    drawFrame();
    setColor(10);
    centerText("Enter your name:", 20);

    string username;
    cin >> username;

    int X, N, M;
    clear();
    drawFrame();
    centerText("Enter X number that you want to reach : ", 8);
    cin >> X;
    centerText("Enter N first number : ", 10);
    cin >> N;
    centerText("Enter M second number : ", 12);
    cin >> M;

    int Total = 0;
    bool gameOver = false;

    while (!gameOver)
    {
        clear();
        drawFrame();

        if (Total > 2 * X / 3)
            system("color 4F");
        else if (Total > X / 3)
            system("color 6F");
        else
            system("color 2F");

        setColor(15);
        centerText("Choose N or M", 8);
        centerText("N = " + to_string(N), 10);
        centerText("M = " + to_string(M), 11);

        int userChoice;
        cin >> userChoice;
        Total += userChoice;

        saveGame(username, X, N, M, Total);

        if (Total >= X)
        {
            gameOver = true;
            break;
        }

        int aiChoice;
        if ((Total + M) % (M + N) == X % (M + N))
            aiChoice = M;
        else
            aiChoice = N;

        Total += aiChoice;
        saveGame(username, X, N, M, Total);

        if (Total >= X)
        {
            gameOver = true;
            break;
        }
    }

    clear();
    drawFrame();
    setColor(14);
    centerText("You begin winner hooooooooraaaaaa", 11);
    centerText(username, 13);
    soundStartGame();
    Sleep(5000);
}
bool exitConfirm()
{
    int choice = 0;
    string opt[2] = {"Yes", "No"};

    while (true)
    {
        clear();
        drawFrame();
        centerText("Are you sure that you want to exit???", 10);

        for (int i = 0; i < 2; i++)
        {
            setColor(i == choice ? 12 : 15);
            centerText(opt[i], 12 + i);
        }

        int k = _getch();
        if (k == 224)
        {
            k = _getch();
            if (k == 75 && choice > 0)
                choice--;
            if (k == 77 && choice < 1)
                choice++;
        }
        else if (k == 13)
        {
            return choice == 0;
        }
    }
}

void playDefault(string username)
{
    bool playAgain = true;

    while (playAgain)
    {
        int Total = 0;
        clear();
        system("color 0F");
        drawFrame();

        while (Total < 20)
        {
            clear();
            system("color 0F");
            drawFrame();

            setColor(2);
            centerText("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇", 18);
            centerText("◇                    ◇", 19);
            centerText("◇   TOTAL : " + to_string(Total) + "   ◇", 20);
            centerText("◇                    ◇", 21);
            centerText("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇", 22);

            setColor(15);
            centerText("Choose 1 or 2", 16);

            int userChoice;
            do
            {
                userChoice = _getch() - '0';
            } while (userChoice != 1 && userChoice != 2);

            Total += userChoice;

            if (Total >= 20)
                break;

            int aiChoice;
            if ((Total + 1) % 3 == 2)
                aiChoice = 1;
            else
                aiChoice = 2;

            Total += aiChoice;
        }

        clear();
        drawFrame();
        Sleep(1000);

        setColor(10);
        centerText(username + " is the WINNER!", 12);
        Sleep(3000);

        int choice = 0;
        string options[2] = {"Yes", "No"};

        while (true)
        {
            clear();
            drawFrame();
            setColor(15);
            centerText("Would you like to continue?", 10);

            for (int i = 0; i < 2; i++)
            {
                setColor(i == choice ? 12 : 15);
                centerText(options[i], 12 + i);
            }

            int key = _getch();
            if (key == 224)
            {
                key = _getch();
                if (key == 75 && choice > 0)
                    choice--;
                if (key == 77 && choice < 1)
                    choice++;
            }
            else if (key == 13)
            {
                playAgain = (choice == 0);
                break;
            }
        }
    }

    exit(0);
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
        if (mode == 0)
        {
            playCustom();
        }
        else
        {
            string username = " SADF ";
            playDefault(username);
        }
    }

    return 0;
}