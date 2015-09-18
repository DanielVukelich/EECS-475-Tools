#include <iostream>
#include <string>

#define ALPH_SIZE 26


int modular_positive(int a){
  if(a > 0)
    return (a % ALPH_SIZE);
  int b = (-a / ALPH_SIZE) + 1;
  return (a + (b * ALPH_SIZE)) % ALPH_SIZE;
}

char decrypt(int ainv, int b, char c){
  c -= 'a';
  return (modular_positive(ainv * (c - b))) + 'a';
}

char encrypt(int a, int b, char c){
  c -= 'a';
  return (modular_positive(a * c + b)) + 'a';
}

int main(int argc, char* argv[]){

  if(argc != 3){
    std::cout << "Usage: ./affinehelp <ciphertext_char> <plaintext_char>\n"
	      << "Where <plaintext_char> encrypts to <ciphertext_char>\n";
    return 0;
  }
  
  char ciph, clear;
  ciph = argv[1][0];
  clear = argv[2][0];
  
  std::cout << "Ciphertext: ";
  std::string text;
  std::cin >> text;
  std::cout << "\n\n";
  
  const int asiz = 12;
  const int aVals[] = {1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25};
  const int aInVals[] = {1, 9, 21, 15, 3, 19, 7, 23, 11, 5, 17, 25};

  for(int a = 0; a < asiz; ++a){
    for(int b = 0; b < ALPH_SIZE; ++b){
            
      if(encrypt(aVals[a], b, clear) != ciph){
	continue;
      }

      std::cout << "A,B = " << aVals[a] << ',' << b << ":\n";
      for(int i = 0; i < text.length(); ++i)
	std::cout << (decrypt(aInVals[a], b, text[i]));
      
      std::cout << "\n\n";
    }
  }

  return 0;
}
