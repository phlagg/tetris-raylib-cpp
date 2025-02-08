#ifndef COLORS_H
#define COLORS_H
#include "raylib.h"
#include <vector>

extern const Color darkGrey;
extern const Color green;
extern const Color red;
extern const Color orange;
extern const Color yellow;
extern const Color purple;
extern const Color cyan;
extern const Color blue;
extern const Color background;

std::vector<Color> GetCellColors();

#endif /* COLORS_H */
