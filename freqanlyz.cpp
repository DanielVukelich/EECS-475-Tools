#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#define ALPH_SIZE 26

//This tool analyzes the frequency of characters as they appear in a ciphertext.
//Pass the ciphertext in through stdin

struct elt{
  char map;
  int count;
};

bool cmpelt(elt a, elt b){
  return (a.count > b.count);
}

int main(){

  std::vector<elt> bucket(ALPH_SIZE);
  for(int i = 0; i < ALPH_SIZE; ++i){
    bucket[i].map = (i + 'a');
    bucket[i].count = 0;
  }
  
  std::string text;
  std::cin >> text;
  for(int i = 0; i < text.length(); ++i){
    bucket[text[i] - 'a'].count += 1;
  }
  
  std::sort(bucket.begin(), bucket.end(), cmpelt);

  double textlen = (double) text.length();
  for(int i = 0; i < ALPH_SIZE; ++i){
    std::cout << bucket[i].map << " has frequency "
	      << (double) ((double)bucket[i].count / textlen)
	      << '\n';
  }
  
  return 0;
}
