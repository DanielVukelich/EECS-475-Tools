#include <iostream>

int main(){
  char a, b, diff;
  int ai, bi, di;
  std::cout << "This tool is for finding the base 26 (alphabetical) key of a substitution cipher (vigenere, ceasar, etc).\n\n";
  std::cout << "Type in a substituted character and the character you think it corresponds to, and it will print the key that would be needed to create that substitution.\n\n";
  std::cout << "Usage example: de\n";
  std::cout << "would mean you think that ciphertext d maps to plaintext e.  Type '!!' to quit.\n";
  do{
    std::cin >> a >> b;
    ai = a - 'a';
    bi = b - 'a';
    di = ai - bi;
    if(di < 0)
      di += 26;
    diff = 'a' + di;
    std::cout << diff << '\n';
  }while(a != '!' && b != '!');
  return 0;
}
