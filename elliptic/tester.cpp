#include "utils.h"
#include "point.h"
#include <iostream>

int main(){
  elliptic_point::set_curve(1, 6);
  elliptic_point::set_mod(11);
  elliptic_point a = elliptic_point(2,7);
  for(int b = 0; b <= 25; ++b){
    elliptic_point c = a * b;
    std::cout << "a * b = c: " << a << " * " << b << " = " << c << '\n';
  }
  return 0;
}

