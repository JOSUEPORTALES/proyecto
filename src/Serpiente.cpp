//==============================================================
//Nombre   : Serpiente.cpp
//Autor    : Josue Daniel Portales Rodriguez
//Version  : 1.0
//Descripcion : Implementacion de la clase Serpiente
//==============================================================

/*#include "Serpiente.hpp"

Serpiente::Serpiente(COORD _serpPos, int _serpVelocidad)
{
    seprPos = _seprPos;
    serpVelocidad = _serpVelocidad; 
    serpLong = 1;
    serpDireccion = 'S';
}

void Serpiente::cambiarDireccion(char _nuevaDireccion)
{
    serpDireccion = _nuevaDireccion;
}
*/
/*void Serpiente::movimiento()
{
    switch (serpDireccion)
    {
    case 'A':
        
        break;
    
    default:
        break;
    }
}
*/

#include "Serpiente.hpp"
#include <pthread.h>
#include <iostream>
#include <vector>
#include <utility>
#include "Serpiente_map.hpp"
#include "Macros.hpp"

using namespace std;

void *input_thread_work(void *arg)
{
    struct Serpiente *Serpiente = (struct Serpiente *)arg;
    while (true)
    {
        enum Direccion direccion = get_Entrada();
        Serpiente->update_next_direccion(direccion);
    }
}

Serpiente::Serpiente(void)
{
    direccion = East;
    next_direccion = direccion;
    food_eaten = false;
    is_dead = false;
    length = INITIAL_Serpiente_LENGTH;
    clear_Serpiente_world();
    initialize_Serpiente();
    sem_init(&Serpiente_sema, 0, 1);
    pthread_create(&input_thread, NULL, input_thread_work, this);
}

void Serpiente::update_direccion(enum Direccion direccion)
{
    sem_wait(&this->Serpiente_sema);
    switch (direccion)
    {
    case West:
        if (this->direccion != East)
        {
            this->direccion = direccion;
        }
        break;
    case North:
        if (this->direccion != South)
        {
            this->direccion = direccion;
        }
        break;
    case East:
        if (this->direccion != West)
        {
            this->direccion = direccion;
        }
        break;
    case South:
        if (this->direccion != North)
        {
            this->direccion = direccion;
        }
        break;
    }
    sem_post(&this->Serpiente_sema);
}

void Serpiente::update_next_direccion(enum Direccion direccion)
{
    this->next_direccion = direccion;
}

enum Direccion Serpiente::get_direccion(void)
{
    enum Direccion result = East;
    sem_wait(&this->Serpiente_sema);
    result = this->direccion;
    sem_post(&this->Serpiente_sema);
    return result;
}

void Serpiente::validate_direccion(void)
{
    if (next_direccion != Error)
    {
        update_direccion(next_direccion);
    }
}

void Serpiente::update_movement(void)
{
    pair<int, int> movement_part;
    enum Direccion direccion = get_direccion();
    switch (direccion)
    {
    case West:
        movement_part = make_pair(Serpiente_head.first, Serpiente_head.second - 1);
        break;
    case North:
        movement_part = make_pair(Serpiente_head.first - 1, Serpiente_head.second);
        break;
    case East:
        movement_part = make_pair(Serpiente_head.first, Serpiente_head.second + 1);
        break;
    case South:
        movement_part = make_pair(Serpiente_head.first + 1, Serpiente_head.second);
        break;
    }
    Serpiente_head = movement_part;
    Serpiente_parts.push_back(movement_part);
    food_eaten = Serpiente_head.first == Serpiente_food.first && Serpiente_head.second == Serpiente_food.second;
    if (food_eaten)
    {
        length++;
    }
    else
    {
        pair<int, int> tail = Serpiente_parts.front();
        Serpiente_world_array[tail.first][tail.second]--;
        Serpiente_parts.erase(Serpiente_parts.begin());
    }
    int head_value = ++Serpiente_world_array[Serpiente_head.first][Serpiente_head.second];
    if (head_value > 1)
    {
        is_dead = true;
    }
}

void Serpiente::set_Serpiente_food(pair<int, int> Serpiente_food)
{
    this->Serpiente_food = Serpiente_food;
}

void Serpiente::clear_Serpiente_world(void)
{
    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        for (int j = 0; j < MAP_WIDTH; j++)
        {
            Serpiente_world_array[i][j] = 0;
        }
    }
}

void Serpiente::initialize_Serpiente(void)
{
    for (int i = 0; i < INITIAL_Serpiente_LENGTH; i++)
    {
        pair<int, int> Serpiente_part = make_pair(MAP_HEIGHT / 2, MAP_WIDTH / 2 - (INITIAL_Serpiente_LENGTH / 2) + i);
        Serpiente_parts.push_back(Serpiente_part);
        Serpiente_world_array[Serpiente_part.first][Serpiente_part.second] = 1;
    }
    Serpiente_head = Serpiente_parts[Serpiente_parts.size() - 1];
}
