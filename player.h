
#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
class Player {       // The class
  public:             // Access specifier
        double x;        // Attribute (double variable)
        double y;        // Attribute (double variable)
        bool collisionDection[4];  // Attribute (Boolean Array) (0 -On Ground 1 - Celling Above 2 - Wall Left 3 - Wall Right)
        Vector2 speed;
        int inventory[1];
};
#endif
