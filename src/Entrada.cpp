#include "Entrada.hpp"
#include <termios.h>
#include <unistd.h>
#include <bits/stdc++.h>
#include <string>
#include <stdio.h>

using namespace std;

struct termios t;

void Entrada_enter_off()
{
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

void Entrada_enter_on()
{
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag |= ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

enum Direccion get_Entrada()
{
    enum Direccion result = East;
    char user_Entrada = getchar();
    switch (user_Entrada)
    {
    case 'a':
        result = West;
        break;
    case 'w':
        result = North;
        break;
    case 'd':
        result = East;
        break;
    case 's':
        result = South;
        break;
    default:
        result = Error;
        cout << "Incorrect button clicked(" << user_Entrada << ")" << endl;
        break;
    }
    return result;
}

void Entrada_init()
{
    
}