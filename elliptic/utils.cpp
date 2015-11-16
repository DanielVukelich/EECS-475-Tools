#include "utils.h"
#include <utility>

int calc_inv(std::pair<int, int> vals, int mod){
  if(vals.second == 1)
    return 1;
  std::pair<int, int> next(vals.second, vals.first % vals.second);
  int prevy = calc_inv(next, mod);
  int todiv = (1 - (vals.first * prevy));
  if((todiv % vals.second) != 0)
    todiv = (1 - (vals.first * modular_positive(prevy, mod)));
  int y = todiv / vals.second;
  return y;
}

int modular_positive(int y, int mod){
  int toret = y - (mod * (y / mod));
  if(toret < 0)
    toret += mod;
  return toret;
}

int modular_inverse(int a, int mod){
  std::pair<int, int> begin(mod, a);
  if(mod < a)
    begin = std::pair<int, int>(a, mod);
  return modular_positive(calc_inv(begin, mod), mod);
}

