#include "point.h"
#include "utils.h"

elliptic_point::elliptic_point(int x, int y){
  this->x = x;
  this->y = y;
  isPOI = false;
}

elliptic_point::elliptic_point(int x, int y, bool isPOI){
  this->x = x;
  this->y = y;
  this->isPOI = isPOI;
}

void elliptic_point::set_curve(int ain, int bin){
  a = ain;
  b = bin;
}

void elliptic_point::set_mod(int modin){
  mod = modin;
}

int elliptic_point::a = 0;
int elliptic_point::b = 0;
int elliptic_point::mod = 0;

bool elliptic_point::operator==(const elliptic_point &rhs) const{
  return ((this->isPOI && rhs.isPOI) || ((this->x == rhs.x) && (this->y == rhs.y)));
}

elliptic_point elliptic_point::operator+(const elliptic_point &P) const{
  int lambda = 0;
  elliptic_point toReturn(0,0);
  
  if(this->isPOI)
    return P;
  else if(P.isPOI)
    return elliptic_point(this->x, this->y, this->isPOI);
  
  if((*this) == P){
    if(P.y == 0){
      toReturn.isPOI = true;
      return toReturn;
    }
    int twoypinv = modular_inverse(modular_positive(2 * P.y, mod), mod);
    lambda = modular_positive((3 * P.x * P.x + a) * twoypinv, mod);
  }else{
    if(this->x == P.x){
      toReturn.isPOI = true;
      return toReturn;
    }
    int xsinv = modular_inverse(modular_positive(this->x - P.x, mod), mod);
    lambda = modular_positive((this->y - P.y) * xsinv, mod);
  }

  toReturn.x = modular_positive(((lambda * lambda) - (P.x) - (this->x)), mod);
  toReturn.y = modular_positive(((lambda * (P.x - toReturn.x)) - P.y), mod);
  
  return toReturn;
}

elliptic_point elliptic_point::operator*(int mult) const{
  return mult_helper(*this, mult);
}

elliptic_point elliptic_point::mult_helper(const elliptic_point &p, int mult) const{
  if(mult == 0)
    return elliptic_point(0,0,true);
  else if(mult == 1)
    return p;
  else if(mult % 2){
    elliptic_point newp = mult_helper(p, (mult - 1) / 2);
    return (newp + newp + p);
  }else{
    elliptic_point newp = mult_helper(p, mult / 2);
    return (newp + newp);
  }
}
