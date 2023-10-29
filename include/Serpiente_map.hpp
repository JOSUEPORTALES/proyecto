#ifndef _Serpiente_Map_hpp
#define _Serpiente_Map_hpp

#include "Serpiente.hpp"
#include "Macros.hpp"

class Serpiente_Map
{
public:
  Serpiente_Map(Serpiente *serpiente);
  void redraw();
  pair<int, int> Serpiente_food;
  void update_Serpiente_food(bool force_update);
  void update_score();

private:
  char map_array[MAP_HEIGHT][MAP_WIDTH];
  Serpiente *serpiente;
};

void clear_map(char map_array[MAP_HEIGHT][MAP_WIDTH]);
void update_Serpiente_head(char map_array[MAP_HEIGHT][MAP_WIDTH], Serpiente *serpiente);

#endif