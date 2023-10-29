//==============================================================
//Nombre   : Serpiente.cpp
//Autor    : Josue Daniel Portales Rodriguez
//Version  : 1.0
//Descripcion : Definicion de la clase Serpiente
//==============================================================

/*#include <windows.h>

class Serpiente 
{
    private:
        COORD serpPos;
        int serpLong;
        int serpVelocidad;
        char serpDireccion;

    public:
        //Constructor
        Serpiente(COORD _serpPos, _serpVelocidad);  

        //Funciones 
        void cambiarDireccion(char _nuevaDireccion);
        void movimiento();
        
}
*/
#ifndef _Serpiente_h
#define _Serpiente_h

#include "Entrada.hpp"
#include <thread>
#include <semaphore.h>
#include <vector>
#include <utility>
#include "Macros.hpp"

using namespace std;

class Serpiente
{
public:
  Serpiente();
  void update_direccion(enum Direccion direccion);
  void update_next_direccion(enum Direccion direccion);
  enum Direccion get_direccion();
  void validate_direccion();
  vector<pair<int, int>> Serpiente_parts;
  pair<int, int> Serpiente_head;
  void update_movement();
  void set_Serpiente_food(pair<int, int> Serpiente_food);
  bool food_eaten;
  bool is_dead;
  int length;

private:
  pthread_t input_thread;
  sem_t Serpiente_sema;
  enum Direccion direccion;
  enum Direccion next_direccion;
  pair<int, int> Serpiente_food;
  int Serpiente_world_array[MAP_HEIGHT][MAP_WIDTH];
  void clear_Serpiente_world();
  void initialize_Serpiente();
};

#endif