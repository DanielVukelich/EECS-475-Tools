#include "utils.h"
#include <vector>
#include <utility>

int calc_gcd(std::vector<std::pair<int, int> > &euclidean){
  std::pair<int, int> last = euclidean.at(euclidean.size() - 1);
  if(last.second == 0)
    return last.first;
  std::pair<int, int> next(last.second, last.first % last.second);
  euclidean.push_back(next);
  return calc_gcd(euclidean);
}

int modular_positive(int y, int mod){
  if(y >= 0)
    return y % mod;
  int x = -1 * y;
  return (((x - (x % mod)) + y + mod) % mod);
}

int modular_inverse(int a, int mod){
  std::vector<std::pair<int, int> > euclidean;
  std::pair<int, int> begin(a, mod);
  euclidean.push_back(begin);
  int gcd = calc_gcd(euclidean);
  if(gcd != 1)
    return -1;
  int y = 0;
  for(int i = euclidean.size() - 2; i >= 1; --i){
    y = (gcd - (euclidean.at(i).first * y))/euclidean.at(i).second;
  }
  return modular_positive(y, mod);
}

