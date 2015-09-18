#include <iostream>
#include <string>

#define ALPH_SIZE 26

//This tool encrypts and decrypts a given text with a given key.
//It takes one argument for the key and then either 'd' to decrypt,
//or 'e' to encrypt.  Pass in the text through stdin.

char encryp(char k, char t){
  return (((k - 'a') + (t - 'a')) % ALPH_SIZE) + 'a';
}

int modular_positive(int a){
  if(a > 0)
    return (a % ALPH_SIZE);
  int b = (-a / ALPH_SIZE) + 1;
  return (a + (b * ALPH_SIZE)) % ALPH_SIZE;
}

char decrypt(char k, char t){
  int c = ((k - 'a') - (t - 'a'));
  return modular_positive(c) + 'a';
}

int main(int argc, char* argv[]){

  if(argc != 3){
    std::cout << "Usage: " << argv[0] << " <key> <d|e>\n";
      return 1;
  }

  if(argv[2][0] != 'e' && argv[2][0] != 'd'){
    std::cout << "Usage: " << argv[0] << " <key> <d|e>\n";
      return 1;
  }

  bool encrypt = (argv[2][0] == 'e');

  std::string text;
  std::string key(argv[1]);
  std::cin >> text;

  for(int i = 0; i < text.length(); ++i){
    char k = key[i % key.length()];
    if(encrypt)
      std::cout << encryp(k, text[i]);
    else
      std::cout << decrypt(k, text[i]);
  }

  std::cout << '\n';

  return 0;
}
