//==============================================================
//Nombre   : Serpiente.cpp
//Autor    : Josue Daniel Portales Rodriguez
//Version  : 1.0
//Descripcion : Implementacion de la clase Serpiente
//==============================================================

#include "Serpiente.hpp"

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



