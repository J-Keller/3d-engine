//
// Created by Jonas on 2/15/20.
//

#ifndef INC_3D_ENGINE_DUNGEONGENERATOR_H
#define INC_3D_ENGINE_DUNGEONGENERATOR_H

#include <vector>
#include <random>
#include <utility>
#include "../../../lib/src/rendering/Mesh.h"
#include "../../../lib/src/physics/collision/colliders/BoxCollider.h"

/**
 * Create a 2D dungeon floor map
 *
 * This can be used in 3D to create a dungeon level with only a single floor
 *
 * Source:
 * http://www.roguebasin.com/index.php?title=C%2B%2B_Example_of_Dungeon-Building_Algorithm
 */
class DungeonGenerator {
 public:

  enum Tile {
    UNUSED = '.',
    FLOOR = ' ',
    CORRIDOR = ',',
    WALL = '#',
    CLOSED_DOOR = '+',
    OPEN_DOOR = '-',
    UP_STAIRS = '<',
    DOWN_STAIRS = '>',
  };

  enum Direction {
    NORTH,
    SOUTH,
    WEST,
    EAST,
    DIRECTION_COUNT,
  };

  DungeonGenerator(int width, int height);

  glm::vec3 generate(int maxFeatures);
  std::pair<std::vector<Mesh>, std::vector<BoxCollider>> generateMesh(int maxFeatures = 100);
  void print();

 private:

  struct Rect {
    int x, y;
    int width, height;
  };

  int width, height;
  std::vector<char> tiles;
  std::vector<Rect> rooms;
  std::vector<Rect> exits;

  char getTile(int x, int y) const;
  void setTile(int x, int y, char tile);
  bool createFeature();
  bool createFeature(int x, int y, Direction dir);
  bool makeRoom(int x, int y, Direction dir, bool firstRoom = false);
  bool makeCorridor(int x, int y, Direction dir);
  bool placeRect(const Rect &rect, char tile);
  bool placeObject(char tile);
  glm::vec3 findSpawn();

};

#endif //INC_3D_ENGINE_DUNGEONGENERATOR_H
