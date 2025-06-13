//
// Created by Jonas Keller on 07.06.25.
//

#include "Player.h"

Player::Player(AbstractCamera *camera, BoxCollider *collider) {
    this->camera = camera;
    this->collider = collider;
}
