#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

#define ALPH_SIZE 26

char caesar_shift(char c, int a){
  return ((c - 'a' + a) % ALPH_SIZE) + 'a';
}

int main(int argc, char* argv[]){

  if(argc != 2){
    std::cout << "Usage: " << argv[0] << " <length_of_key>\n";
    return 1;
  }

  int keylen;
  keylen  = atoi(argv[1]);

  if(keylen < 2){
    std::cout << "Usage: " << argv[0] << " <length_of_key>\n";
    std::cout << "Key length must be > 1\n";
    return 1;
  }

  std::string text, sub;
  std::cin >> text;

  for(int k = 0; k < keylen; ++k){
    
    std::cout << "*****BEGIN ROUND " << k + 1 << "*****\n";

    for(int i = k; i < text.length(); i += keylen){
      sub.push_back(text[i]);
    }
    
    std::vector<std::string> strlist(ALPH_SIZE, sub);
    
    for(int i = 0; i < ALPH_SIZE; ++i){
      for(int j = 0; j < strlist[i].length(); ++j){
	strlist[i][j] = caesar_shift(strlist[i][j], i);
      }
      std::cout << "\nShift of " << i << " makes:\n"<< strlist[i] << "\n\n";
    }
    std::cout << "*****END ROUND " << k + 1 << "*****\n";
    sub = "";
  }
    
  return 0;
}
