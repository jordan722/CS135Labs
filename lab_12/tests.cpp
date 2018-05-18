#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "def.h"
#include "doctest.h"

using namespace std;


TEST_CASE("Length"){
  cout << "Testing Length" << endl;
  Coord3D pointA = {0, 0, 0};
  CHECK(length(&pointA) == 0);
  Coord3D pointB = {0, 0, 10};
  CHECK(length(&pointB) == 10.0);
  Coord3D pointC = {10, 20, 20};
  CHECK(length(&pointC) == 30.0);
}


TEST_CASE("fartherFromOrigin"){
  cout << "Testing fartherFromOrigin" << endl;
  Coord3D pointA = {5, 3, 4};
  Coord3D pointB = {20, -13, -12};
  Coord3D * ans = fartherFromOrigin(&pointA, &pointB);
  CHECK((*ans).x == pointB.x);
  CHECK((*ans).y == pointB.y);
  CHECK((*ans).z == pointB.z);
}


TEST_CASE("move"){
  cout << "Testing move" << endl;
  Coord3D pos = {0, 0, 50.0};
  Coord3D vel = {1, 5, -2};
  move(&pos, &vel, 1.0); // struct pos gets changed
  CHECK(pos.x == 1);
  CHECK(pos.y == 5);
  CHECK(pos.z == 48);
}


TEST_CASE("Allocate Memory and Deleting objects"){
  cout << "Testing Allocate Memory and Deleting objects" << endl;
  double x = 0; double y = 10; double z = 20;
  Coord3D *ppos = createCoord3D(x,y,z);
  x = 3.2; y = -1.9; z = 3.42;
  Coord3D *pvel = createCoord3D(x,y,z);
  move(ppos, pvel, 5.0);
  CHECK((*ppos).x == 16.0);
  CHECK((*ppos).y == 0.5);
  CHECK((int)(*ppos).z == 37);
  deleteCoord3D(ppos); // release memory
  deleteCoord3D(pvel);
}
