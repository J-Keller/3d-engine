//
// Created by Jonas on 11/25/23.
//

#ifndef MCCLONE_COLLISIONCHECKER_H
#define MCCLONE_COLLISIONCHECKER_H


#include "colliders/BoxCollider.h"
#include "colliders/PointCollider.h"
#include "colliders/SphereCollider.h"


class CollisionChecker {
public:
    static bool collide(BoxCollider a, BoxCollider b);
    static bool collide(BoxCollider a, PointCollider b);
    static bool collide(BoxCollider a, SphereCollider b);
    static bool collide(PointCollider a, PointCollider b);
    static bool collide(PointCollider a, SphereCollider b);
    static bool collide(SphereCollider a, SphereCollider b);
};


#endif //MCCLONE_COLLISIONCHECKER_H
