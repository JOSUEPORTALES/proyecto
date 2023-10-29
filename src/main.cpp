#include <stdio.h>
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unistd.h>
#include <bits/stdc++.h>
#include "Entrada.hpp"
#include "Serpiente.hpp"
#include "Serpiente_map.hpp"
#include <utility>
#include "Macros.hpp"

using namespace std;

Serpiente serpiente;
SerpienteMap Serpiente_map(&serpiente);

void initialize()
{
    input_init();
    input_enter_off();
}

bool is_game_end()
{
    bool result = false;
    pair<int, int> Serpiente_head = Serpiente.Serpiente_head;
    if (Serpiente_head.first < 0 || Serpiente_head.first >= MAP_HEIGHT || Serpiente_head.second < 0 || Serpiente_head.second >= MAP_WIDTH)
    {
        result = true;
    }
    if (Serpiente.is_dead)
    {
        result = true;
    }
    return result;
}

void game_over()
{
    cout << "GAME IS OVER" << endl;
}

void start_game()
{
    while (true)
    {
        Serpiente.update_movement();
        if (is_game_end())
        {
            game_over();
            break;
        }
        Serpiente_map.redraw();

        usleep(PAUSE_LENGTH);

        Serpiente.validate_direction();
    }
}

int main()
{
    initialize();
    start_game();
    return 0;
}
