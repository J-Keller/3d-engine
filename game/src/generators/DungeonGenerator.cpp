//
// Created by Jonas on 2/15/20.
//

#include <iostream>
#include "DungeonGenerator.h"

int randomInt(int exclusiveMax);
int randomInt(int min, int max);
bool randomBool(double probability = 0.5);

std::random_device rd;
std::mt19937 mt(rd());

DungeonGenerator::DungeonGenerator(int width, int height) :
    width(width),
    height(height),
    tiles(width * height, UNUSED),
    rooms(),
    exits() {

}

glm::vec3 DungeonGenerator::generate(int maxFeatures) {
  // place the first room in the center
  if (!makeRoom(width / 2, height / 2, static_cast<Direction>(randomInt(4), true))) {
    std::cout << "Unable to place the first room." << std::endl;
    return {0.0f, 0.0f, 0.0f};
  }
  // we already places 1 feature (the first room)
  for (int i = 1; i < maxFeatures; i++) {
    if (!createFeature()) {
      std::cout << "Unable to place more features (placed " << i << ")" << std::endl;
      break;
    }
  }
  if (!placeObject(UP_STAIRS)) {
    std::cout << "Unable to place stairs up." << std::endl;
    return {0.0f, 0.0f, 0.0f};
  }
  if (!placeObject(DOWN_STAIRS)) {
    std::cout << "Unable to place down stairs." << std::endl;
    return {0.0f, 0.0f, 0.0f};
  }

  return findSpawn();
}

std::pair<std::vector<Mesh>, std::vector<BoxCollider>> DungeonGenerator::generateMesh(int maxFeatures) {
  std::vector<Mesh> mesh;
  std::vector<BoxCollider> colliders;

  Mesh floor;
  Mesh wall;

  if (tiles.empty()) {
    generate(maxFeatures);
  }

  std::vector<float> wallVertices;
  std::vector<float> floorVertices;

  for (int y = 0; y <= height; y++) {
    for (int x = 0; x <= width; x++) {

      auto fx = (float) x;
      auto fy = (float) y;

      // TODO: change stuff here for other tiles
      // TODO: fix texture coordinates some are mirrored or wrongly rotated
      switch (getTile(x, y)) {
        case FLOOR:
        case CORRIDOR:
        case OPEN_DOOR:
        case CLOSED_DOOR:
        case UP_STAIRS:
        case DOWN_STAIRS:
          floorVertices.insert(floorVertices.end(), {
              1.0f * fx, 0.0f, 1.0f * fy, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, // top left
              1.0f * (fx + 1), 0.0f, 1.0f * (fy + 1), 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // bottom right
              1.0f * (fx + 1), 0.0f, 1.0f * fy, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, // top right

              1.0f * (fx + 1), 0.0f, 1.0f * (fy + 1), 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // bottom right
              1.0f * fx, 0.0f, 1.0f * fy, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, // top left
              1.0f * fx, 0.0f, 1.0f * (fy + 1), 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom left
          });
          break;
        case WALL:
          //top
          wallVertices.insert(wallVertices.end(), {
              1.0f * fx, 1.0f, 1.0f * fy, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, // top left
              1.0f * (fx + 1), 1.0f, 1.0f * (fy + 1), 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // bottom right
              1.0f * (fx + 1), 1.0f, 1.0f * fy, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, // top right

              1.0f * (fx + 1), 1.0f, 1.0f * (fy + 1), 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // bottom right
              1.0f * fx, 1.0f, 1.0f * fy, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, // top left
              1.0f * fx, 1.0f, 1.0f * (fy + 1), 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom left
          });

          // bottom
          wallVertices.insert(wallVertices.end(), {
              1.0f * fx, 0.0f, 1.0f * fy, 1.0f, 0.0f, 0.0f, -1.0f, 0.0f, // top left
              1.0f * (fx + 1), 0.0f, 1.0f * fy, 1.0f, 1.0f, 0.0f, -1.0f, 0.0f, // top right
              1.0f * (fx + 1), 0.0f, 1.0f * (fy + 1), 0.0f, 1.0f, 0.0f, -1.0f, 0.0f, // bottom right

              1.0f * (fx + 1), 0.0f, 1.0f * (fy + 1), 0.0f, 1.0f, 0.0f, -1.0f, 0.0f, // bottom right
              1.0f * fx, 0.0f, 1.0f * (fy + 1), 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, // bottom left
              1.0f * fx, 0.0f, 1.0f * fy, 1.0f, 0.0f, 0.0f, -1.0f, 0.0f, // top left
          });

          // left
          wallVertices.insert(wallVertices.end(), {
              1.0f * fx, 0.0f, 1.0f * fy, 1.0f, 0.0f, -1.0f, 0.0f, 0.0f, // top left
              1.0f * fx, 1.0f, 1.0f * (fy + 1), 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, // bottom right
              1.0f * fx, 1.0f, 1.0f * fy, 1.0f, 1.0f, -1.0f, 0.0f, 0.0f, // top right

              1.0f * fx, 1.0f, 1.0f * (fy + 1), 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, // bottom right
              1.0f * fx, 0.0f, 1.0f * fy, 1.0f, 0.0f, -1.0f, 0.0f, 0.0f, // top left
              1.0f * fx, 0.0f, 1.0f * (fy + 1), 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, // bottom left
          });

          //right
          wallVertices.insert(wallVertices.end(), {
              1.0f * (fx + 1), 0.0f, 1.0f * fy, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, // top left
              1.0f * (fx + 1), 1.0f, 1.0f * fy, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // top right
              1.0f * (fx + 1), 1.0f, 1.0f * (fy + 1), 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, // bottom right

              1.0f * (fx + 1), 1.0f, 1.0f * (fy + 1), 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, // bottom right
              1.0f * (fx + 1), 0.0f, 1.0f * (fy + 1), 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
              1.0f * (fx + 1), 0.0f, 1.0f * fy, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, // top left
          });

          //back
          wallVertices.insert(wallVertices.end(), {
              1.0f * fx, 0.0f, 1.0f * fy, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f, // top left
              1.0f * (fx + 1), 1.0f, 1.0f * fy, 0.0f, 1.0f, 0.0f, 0.0f, -1.0f, // bottom right
              1.0f * (fx + 1), 0.0f, 1.0f * fy, 1.0f, 1.0f, 0.0f, 0.0f, -1.0f, // top right

              1.0f * (fx + 1), 1.0f, 1.0f * fy, 0.0f, 1.0f, 0.0f, 0.0f, -1.0f, // bottom right
              1.0f * fx, 0.0f, 1.0f * fy, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f, // top left
              1.0f * fx, 1.0f, 1.0f * fy, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, // bottom left
          });

          // front
          wallVertices.insert(wallVertices.end(), {
              1.0f * fx, 0.0f, 1.0f * (fy + 1), 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, // top left
              1.0f * (fx + 1), 0.0f, 1.0f * (fy + 1), 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // top right
              1.0f * (fx + 1), 1.0f, 1.0f * (fy + 1), 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, // bottom right

              1.0f * (fx + 1), 1.0f, 1.0f * (fy + 1), 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, // bottom right
              1.0f * fx, 1.0f, 1.0f * (fy + 1), 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, // bottom left
              1.0f * fx, 0.0f, 1.0f * (fy + 1), 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, // top left
          });

          colliders.emplace_back(glm::vec3(fx, 0, fy), glm::vec3(fx + 1, 1, fy + 1));
          break;
        default:continue;
      }

    }
  }

  floor.addVertices(floorVertices);
  wall.addVertices(wallVertices);

  mesh.insert(mesh.end(), {floor, wall});

  return {mesh, colliders};
}

void DungeonGenerator::print() {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      std::cout << getTile(x, y);
    }

    std::cout << std::endl;
  }
}

char DungeonGenerator::getTile(int x, int y) const {
  if (x < 0 || y < 0 || x >= width || y >= height) {
    return UNUSED;
  }
  return tiles[x + y * width];
}

void DungeonGenerator::setTile(int x, int y, char tile) {
  tiles[x + y * width] = tile;
}

bool DungeonGenerator::createFeature() {

  for (int i = 0; i < 1000; i++) {
    if (exits.empty()) {
      break;
    }

    // choose a random side of a room or corridor
    int r = randomInt(exits.size());
    int x = randomInt(exits[r].x, exits[r].x + exits[r].width - 1);
    int y = randomInt(exits[r].y, exits[r].y + exits[r].height - 1);

    // north, south, west, east
    for (int j = 0; j < DIRECTION_COUNT; j++) {
      if (createFeature(x, y, static_cast<Direction>(j))) {
        exits.erase(exits.begin() + r);
        return true;
      }
    }
  }

  return false;
}

bool DungeonGenerator::createFeature(int x, int y, DungeonGenerator::Direction dir) {
  static const int roomChance = 50; // corridorChance = 100 - roomChance

  int dx = 0;
  int dy = 0;

  switch (dir) {
    case NORTH:dy = 1;
      break;
    case SOUTH:dy = -1;
      break;
    case WEST:dx = 1;
      break;
    case EAST:dx = -1;
      break;
    default:break;
  }

  if (getTile(x + dx, y + dy) != FLOOR && getTile(x + dx, y + dy) != CORRIDOR) {
    return false;
  }

  if (randomInt(100) < roomChance) {
    if (makeRoom(x, y, dir)) {
      setTile(x, y, CLOSED_DOOR);
      return true;
    }
  } else {
    if (makeCorridor(x, y, dir)) {
      if (getTile(x + dx, y + dy) == FLOOR) {
        setTile(x, y, CLOSED_DOOR);
      } else {
        setTile(x, y, CORRIDOR);
      }
      return true;
    }
  }

  return false;
}

bool DungeonGenerator::makeRoom(int x, int y, DungeonGenerator::Direction dir, bool firstRoom) {
  static const int minRoomSize = 3;
  static const int maxRoomSize = 6;

  Rect room;

  room.width = randomInt(minRoomSize, maxRoomSize);
  room.height = randomInt(minRoomSize, maxRoomSize);

  switch (dir) {
    case NORTH:room.x = x - room.width / 2;
      room.y = y - room.height;
      break;
    case SOUTH:room.x = x - room.width / 2;
      room.y = y + 1;
      break;
    case WEST:room.x = x - room.width;
      room.y = y - room.height / 2;
      break;
    case EAST:room.x = x + 1;
      room.y = y - room.height / 2;
      break;
    default:break;
  }

  if (placeRect(room, FLOOR)) {
    rooms.emplace_back(room);

    // TODO: WTF
    if (dir != SOUTH || firstRoom) { // north side
      exits.emplace_back(Rect{room.x, room.y - 1, room.width, 1});
    }
    if (dir != NORTH || firstRoom) { // south side
      exits.emplace_back(Rect{room.x, room.y + room.height, room.width, 1});
    }
    if (dir != EAST || firstRoom) { // west side
      exits.emplace_back(Rect{room.x - 1, room.y, 1, room.height});
    }
    if (dir != WEST || firstRoom) { // east side
      exits.emplace_back(Rect{room.x + room.width, room.y, 1, room.height});
    }
    return true;
  }

  return false;
}

bool DungeonGenerator::makeCorridor(int x, int y, DungeonGenerator::Direction dir) {
  static const int minCorridorLength = 3;
  static const int maxCorridorLength = 6;

  Rect corridor;
  corridor.x = x;
  corridor.y = y;

  if (randomBool()) { // horizontal corridor
    corridor.width = randomInt(minCorridorLength, maxCorridorLength);
    corridor.height = 1;

    switch (dir) {
      case NORTH:corridor.y = y - 1;

        if (randomBool()) { // west
          corridor.x = x - corridor.width + 1;
        }
        break;
      case SOUTH:corridor.y = y + 1;

        if (randomBool()) { // west
          corridor.x = x - corridor.width + 1;
        }
        break;
      case WEST:corridor.x = x - corridor.width;
        break;
      case EAST:corridor.x = x + 1;
        break;
      default:break;
    }
  } else { // vertical corridor

    corridor.width = 1;
    corridor.height = randomInt(minCorridorLength, maxCorridorLength);

    switch (dir) {
      case NORTH:corridor.y = y - corridor.height;
        break;
      case SOUTH:corridor.y = y + 1;
        break;
      case WEST:corridor.x = x - 1;

        if (randomBool()) { // north
          corridor.y = y - corridor.height + 1;
        }
        break;
      case EAST:corridor.x = x + 1;

        if (randomBool()) { // north
          corridor.y = y - corridor.height + 1;
        }
        break;
      default:break;
    }
  }

  if (placeRect(corridor, CORRIDOR)) {
    if (dir != SOUTH && corridor.width != 1) { // north side
      exits.emplace_back(Rect{corridor.x, corridor.y - 1, corridor.width, 1});
    }
    if (dir != NORTH && corridor.width != 1) { // south side
      exits.emplace_back(Rect{corridor.x, corridor.y + corridor.height, corridor.width, 1});
    }
    if (dir != EAST && corridor.height != 1) { // west side
      exits.emplace_back(Rect{corridor.x - 1, corridor.y, 1, corridor.height});
    }
    if (dir != WEST && corridor.height != 1) { // east side
      exits.emplace_back(Rect{corridor.x + corridor.width, corridor.y, 1, corridor.height});
    }
    return true;
  }

  return false;
}

bool DungeonGenerator::placeRect(const Rect &rect, char tile) {
  if (rect.x < 1 || rect.y < 1 || rect.x + rect.width > width - 1 || rect.y + rect.height > height - 1) {
    return false;
  }

  for (int y = rect.y; y < rect.y + rect.height; ++y) {
    for (int x = rect.x; x < rect.x + rect.width; ++x) {
      if (getTile(x, y) != UNUSED) {
        return false; // the area already used
      }
    }
  }

  for (int y = rect.y - 1; y < rect.y + rect.height + 1; y++) {
    for (int x = rect.x - 1; x < rect.x + rect.width + 1; x++) {
      if (x == rect.x - 1 || y == rect.y - 1 || x == rect.x + rect.width || y == rect.y + rect.height) {
        setTile(x, y, WALL);
      } else {
        setTile(x, y, tile);
      }
    }
  }

  return true;
}

bool DungeonGenerator::placeObject(char tile) {
  if (rooms.empty()) {
    return false;
  }

  int r = randomInt(rooms.size()); // choose a random room
  int x = randomInt(rooms[r].x + 1, rooms[r].x + rooms[r].width - 2);
  int y = randomInt(rooms[r].y + 1, rooms[r].y + rooms[r].height - 2);

  if (getTile(x, y) == FLOOR) {
    setTile(x, y, tile);

    // place one object in one room (optional)
    rooms.erase(rooms.begin() + r);

    return true;
  }

  return false;
}

glm::vec3 DungeonGenerator::findSpawn() {
  // TODO: This is so ugly do something about it
  float x = width / 2;
  float z = height / 2;
  float offsetX = 0;
  float offsetZ = 0;

  int maxTries = 12;
  int triesPerDirection = maxTries / 4;
  while (getTile(x, z) != FLOOR && maxTries > 0) {
    if (maxTries > maxTries - triesPerDirection) {
      offsetZ = 0.5f;
      z++;
    } else if (maxTries > maxTries - (2 * triesPerDirection)) {
      offsetZ = 0.0f;
      offsetX = 0.5f;
      x++;
    } else if (maxTries > maxTries - (3 * triesPerDirection)) {
      offsetZ = -0.5f;
      offsetX = 0.0f;
      z--;
    } else {
      offsetZ = 0.0f;
      offsetX = -0.5f;
      x--;
    }
    maxTries--;
  }

  return {x + offsetX, 0.5f, z + offsetZ};
}

int randomInt(int exclusiveMax) {
  std::uniform_int_distribution<> dist(0, exclusiveMax - 1);
  return dist(mt);
}

int randomInt(int min, int max) // inclusive min/max
{
  std::uniform_int_distribution<> dist(0, max - min);
  return dist(mt) + min;
}

bool randomBool(double probability) {
  std::bernoulli_distribution dist(probability);
  return dist(mt);
}
