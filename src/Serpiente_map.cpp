#include "Serpiente_map.hpp"
#include <pthread.h>
#include <iostream>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <time.h>
#include "Macros.hpp"

using namespace std;

Serpiente_map::Serpientemap(Serpiente *serpiente)
{
    this->Serpiente = Serpiente;
    clear_map(this->map_array);
    srand(time(NULL));
    update_Serpiente_food(true);
}

void SerpienteMap::redraw(void)
{
    clear_map(this->map_array);
    for (int i = 0; i < MAP_END; i++)
    {
        cout << endl;
    }
    update_score();
    vector<pair<int, int>> Serpiente_parts = Serpiente->Serpiente_parts;
    for (int i = 0; i < Serpiente_parts.size(); i++)
    {
        pair<int, int> tmp = Serpiente_parts[i];
        map_array[tmp.first][tmp.second] = Serpiente_CHAR;
    }
    update_Serpiente_head(map_array, Serpiente);
    update_Serpiente_food(false);
    map_array[Serpiente_food.first][Serpiente_food.second] = Serpiente_FOOD_CHAR;
    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        for (int j = 0; j < MAP_WIDTH; j++)
        {
            cout << map_array[i][j] << " ";
        }
        cout << endl;
    }
}

void SerpienteMap::update_Serpiente_food(bool force_update)
{
    if (Serpiente->food_eaten || force_update)
    {
        while (true)
        {
            int random_i = rand() % MAP_WIDTH;
            int random_j = rand() % MAP_HEIGHT;
            if (map_array[random_i][random_j] == MAP_CHAR)
            {
                Serpiente_food = make_pair(random_i, random_j);
                Serpiente->set_Serpiente_food(Serpiente_food);
                Serpiente->food_eaten = false;
                break;
            }
        }
    }
}

void clear_map(char map_array[MAP_HEIGHT][MAP_WIDTH])
{
    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        for (int j = 0; j < MAP_WIDTH; j++)
        {
            map_array[i][j] = MAP_CHAR;
        }
    }
}

void update_Serpiente_head(char map_array[MAP_HEIGHT][MAP_WIDTH], Serpiente *Serpiente)
{
    char Serpiente_head_char = Serpiente_CHAR;
    enum Direccion direccion = Serpiente->get_direccion();
    switch (direccion)
    {
    case West:
        Serpiente_head_char = Serpiente_HEAD_WEST;
        break;
    case North:
        Serpiente_head_char = Serpiente_HEAD_NORTH;
        break;
    case East:
        Serpiente_head_char = Serpiente_HEAD_EAST;
        break;
    case South:
        Serpiente_head_char = Serpiente_HEAD_SOUTH;
        break;
    }
    pair<int, int> Serpiente_head = Serpiente->Serpiente_head;
    map_array[Serpiente_head.first][Serpiente_head.second] = Serpiente_head_char;
}

void SerpienteMap::update_score(void)
{
    cout << "Score:" << Serpiente->length << endl;
}
