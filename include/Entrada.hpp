#ifndef _Entrada_hpp
#define _Entrada_hpp


enum Direccion {
    Error = -1,
    West = 0,
    North = 1,
    East = 2,
    South = 3
};

void Entrada_init(void);
void Entrada_enter_off(void);
void Entrada_enter_on(void);
enum Direccion get_Entrada(void);

#endif