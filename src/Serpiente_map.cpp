#include "Serpiente_map.hpp"
#include <pthread.h>
#include <iostream>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <time.h>
#include "Macros.hpp"

using namespace std;

Serpiente_Map::Serpiente_Map(Serpiente *serpiente)
{
    this->serpiente = serpiente;
    clear_map(this->map_array);
    srand(time(NULL));
    update_Serpiente_food(true);
}

void Serpiente_Map::redraw(void)
{
    clear_map(this->map_array);
    for (int i = 0; i < MAP_END; i++)
    {
        cout << endl;
    }
    update_score();
    vector<pair<int, int>> Serpiente_parts = serpiente->Serpiente_parts;
    for (int i = 0; i < Serpiente_parts.size(); i++)
    {
        pair<int, int> tmp = Serpiente_parts[i];
        map_array[tmp.first][tmp.second] = SERPIENTE_CHAR;
    }
    update_Serpiente_head(map_array, serpiente);
    update_Serpiente_food(false);
    map_array[Serpiente_food.first][Serpiente_food.second] = SERPIENTE_FOOD_CHAR;
    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        for (int j = 0; j < MAP_WIDTH; j++)
        {
            cout << map_array[i][j] << " ";
        }
        cout << endl;
    }
}

void Serpiente_Map::update_Serpiente_food(bool force_update)
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
                Serpiente->set_Serpiente_food(serpiente_food);
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

void update_Serpiente_head(char map_array[MAP_HEIGHT][MAP_WIDTH], Serpiente *serpiente)
{
    char Serpiente_head_char = serpiente_CHAR;
    enum Direccion direccion = serpiente->get_direccion();
    switch (direccion)
    {
    case West:
        Serpiente_head_char = SERPIENTE_HEAD_WEST;
        break;
    case North:
        Serpiente_head_char = SERPIENTE_HEAD_NORTH;
        break;
    case East:
        Serpiente_head_char = SERPIENTE_HEAD_EAST;
        break;
    case South:
        Serpiente_head_char = SERPIENTE_HEAD_SOUTH;
        break;
    }
    pair<int, int> serpiente_head = serpiente->serpiente_head;
    map_array[serpiente_head.first][serpiente_head.second] = serpiente_head_char;
}

void Serpiente_Map::update_score(void)
{
    cout << "Score:" << serpiente->length << endl;
}
