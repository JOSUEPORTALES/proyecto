//==============================================================
//Nombre   : Serpiente.cpp
//Autor    : Josue Daniel Portales Rodriguez
//Version  : 1.0
//Descripcion : Definicion de la clase Serpiente
//==============================================================

#include <windows.h>

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

