#include <iostream>
#include <math.h>
#include "def.h"

using namespace std;

double length(Coord3D *p){
  double x = (*p).x;
  double y = (*p).y;
  double z = (*p).z;
  double xy = sqrt(x*x+y*y);
  double xyz = sqrt(xy*xy+z*z);
  return xyz;
}

Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2){
  double distance_one = length(p1);
  double distance_two = length(p2);
  if (distance_one > distance_two){
    return p1;
  }
  else{
    return p2;
  }
}

void move(Coord3D *ppos, Coord3D *pvel, double dt){
  (*ppos).x += (*pvel).x * dt;
  (*ppos).y += (*pvel).y * dt;
  (*ppos).z += (*pvel).z * dt;
}

Coord3D* createCoord3D(double x, double y, double z){
  Coord3D *ans = new Coord3D;
  (*ans).x = x;
  (*ans).y = y;
  (*ans).z = z;
  return ans;
}

void deleteCoord3D(Coord3D *p){
  delete p;
}

Particle* createParticle(double x, double y, double z,double vx, double vy, double vz){
  Particle *ans = new Particle;
  (*ans).x = x;
  (*ans).y = y;
  (*ans).z = z;
  (*ans).vx = vx;
  (*ans).vy = vy;
  (*ans).vz = vz;
  return ans;
}

void setVelocity(Particle *p, double vx, double vy, double vz){
  (*p).vx = vx;
  (*p).vy = vy;
  (*p).vz = vz;
}

Coord3D getPosition(Particle *p){
  Coord3D ans = {(*p).x,(*p).y, (*p).z};
  return ans;
}

void move(Particle *p, double dt){
  (*p).x += (*p).vx * dt;
  (*p).y += (*p).vy * dt;
  (*p).z += (*p).vz * dt;
}

void deleteParticle(Particle *p){
  delete p;
}
