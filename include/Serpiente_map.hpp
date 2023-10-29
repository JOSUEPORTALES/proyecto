#ifndef _Serpiente_map_hpp
#define _Serpiente_map_hpp

#include "Serpiente.hpp"
#include "Macros.hpp"

class SerpienteMap
{
public:
  SerpienteMap(Serpiente *serpiente);
  void redraw();
  pair<int, int> Serpiente_food;
  void update_Serpiente_food(bool force_update);
  void update_score();

private:
  char map_array[MAP_HEIGHT][MAP_WIDTH];
  Serpiente *Serpiente;
};

void clear_map(char map_array[MAP_HEIGHT][MAP_WIDTH]);
void update_Serpiente_head(char map_array[MAP_HEIGHT][MAP_WIDTH], Serpiente *Serpiente);

#endif