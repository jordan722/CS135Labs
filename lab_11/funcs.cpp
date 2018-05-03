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
  if(length(p1) > length(p2)){
    return p1;
  }
  else{
    return p2;
  }
}

int main() {
    //Coord3D pointP = {10, 20, 30};
    //cout << length(&pointP) << endl; // would print 37.4166

    Coord3D pointP = {10, 20, 30};
    Coord3D pointQ = {-20, 21, -22};

    cout << "Address of P: " << &pointP << endl;
    cout << "Address of Q: " << &pointQ << endl << endl;

    Coord3D * ans = fartherFromOrigin(&pointP, &pointQ);

    cout << "ans = " << ans << endl; // So which point is farther?
}
