#ifndef point_h
#define point_h

#include <ostream>

class elliptic_point{
 public:
  elliptic_point(int x, int y);
  elliptic_point(int x, int y, bool isPOI);
  static void set_curve(int ain, int bin);
  static void set_mod(int mod);
  elliptic_point operator+(const elliptic_point &P) const;
  elliptic_point operator*(int mult) const;
  bool operator==(const elliptic_point &rhs) const;
  
  friend std::ostream& operator<< (std::ostream& stream, const elliptic_point& point){
    if(!point.isPOI)
      stream << "(" << point.x << "," <<  point.y << ")";
    else
      stream << "Point of Infinity";
    return stream;
  }
  
 private:
  elliptic_point mult_helper(const elliptic_point &p, int mult) const;
  static int a;
  static int b;
  static int mod;
  int x;
  int y;
  bool isPOI;
};

#endif
