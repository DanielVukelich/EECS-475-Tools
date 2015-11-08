#include "utils.h"
#include "point.h"
#include <iostream>

int main(){
  elliptic_point::set_group(11, 1, 6);
  elliptic_point a = elliptic_point(2,7);
  //Test that the code I've written to perform group operations really does work.
  //It should cycle through the group of points on E_11(1,6)
  std::cout << "Testing on group E_11(1,6)\nGenerator G = " << a << '\n';
  elliptic_point c = elliptic_point(0,0);
  elliptic_point POI = elliptic_point(0,0,true);
  for(int b = 1; c != POI; ++b){
    c = a * b;
    std::cout << b << " * G = " << c << '\n';
  }
  
  return 0;
}

