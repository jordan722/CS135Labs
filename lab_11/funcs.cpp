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


int main() {
  double x, y, z;
  cout << "Enter position: ";
  cin >> x >> y >> z;
  Coord3D *ppos = createCoord3D(x,y,z);

  cout << "Enter velocity: ";
  cin >> x >> y >> z;
  Coord3D *pvel = createCoord3D(x,y,z);

  move(ppos, pvel, 10.0);

  cout << "Coordinates after 10 seconds: "
   << (*ppos).x << " " << (*ppos).y << " " << (*ppos).z << endl;

   deleteCoord3D(ppos); // release memory
   deleteCoord3D(pvel);
   // make new particle
   Particle *p = createParticle(1.0, 1.5, 2.0, 0.1, 0.2, 0.3);
    double time = 0.0;
    double dt = 0.1;
    while(time < 3.0) {
        // update its velocity
        setVelocity(p, 10.0 * time, 0.3, 0.1);

        // move the particle
        move(p, dt);
        time += dt;

        // reporting its coordinates
        cout << "Time: " << time << " \t";
        cout << "Position: "
             << getPosition(p).x << ", "
             << getPosition(p).y << ", "
             << getPosition(p).z << endl;
    }
    // remove the particle, deallocating its memory
    deleteParticle(p);
}
