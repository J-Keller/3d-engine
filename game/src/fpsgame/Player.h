//
// Created by Jonas Keller on 07.06.25.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "../../../lib/src/physics/collision/colliders/BoxCollider.h"
#include "../cameras/FPSCamera.h"

class Player {

public:
    AbstractCamera *camera;
    BoxCollider *collider;

    Player(AbstractCamera *camera, BoxCollider *collider);
};



#endif //PLAYER_H
