#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdlib.h>

#define ALPH_SIZE 26

//This tool analyzes the frequency of characters as they appear in a ciphertext.
//If you pass in an optional integer argument 'len', it will perform frequency
//analyses on every len'th letter.  This is usefull for vigenerre ciphers.
//Pass the ciphertext in through stdin.

struct elt{
  char map;
  int count;
};

bool cmpelt(elt a, elt b){
  return (a.count > b.count);
}

int main(int argc, char* argv[]){

  int keylen = 1;
  
  if(argc > 1){
    keylen = atoi(argv[1]);
    if(argc > 2 || keylen < 1){
      std::cout << "Usage: " << argv[0] << " [optional repetition_length]\nrepetition_len must be > 0";
      return 0;
    }
  }
  
  std::string text;
  std::cin >> text;

  for(int reps = 0; reps < keylen; ++reps){

    std::cout << "\n****Begin analysis on every "
	      << keylen
	      << " letter(s), starting at letter "
	      << reps << "****\n"; 
    
    std::vector<elt> bucket(ALPH_SIZE);
    for(int i = 0; i < ALPH_SIZE; ++i){
      bucket[i].map = (i + 'a');
      bucket[i].count = 0;
    }
    
    for(int i = reps; i < text.length(); i += keylen){
      bucket[text[i] - 'a'].count += 1;
    }
    
    std::sort(bucket.begin(), bucket.end(), cmpelt);
    
    double textlen = (double) text.length();
    for(int i = 0; i < ALPH_SIZE; ++i){
      std::cout << bucket[i].map << " has frequency "
		<< (double) ((double)bucket[i].count / textlen)
		<< '\n';
    }

    std::cout << "****END ANALYSIS ROUND " << reps + 1 << "****\n\n";
  }
  
  return 0;
}
