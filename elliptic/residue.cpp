#include <iostream>
#include <vector>
#include <map>
#include <utility>

int main(){
  int a, b, mod;
  std::cout << "Input a, b, and modulus:\n";
  std::cin >> a >> b >> mod;

  std::map<int, std::vector<int> > residues;
  std::map<int, std::vector<int> >::iterator it;
  
  for(int i = 1; i < mod; ++i){
    int key = (i * i) % mod;
    it = residues.find(key);
    if(it == residues.end()){
      std::vector<int> vec = std::vector<int>(1, i);
      residues.insert(std::pair<int, std::vector<int> >(key, vec));
    }else{
      (*it).second.push_back(i);
    }
  }

  for(it = residues.begin(); it != residues.end(); ++it){
    std::cout << it->first << " is made from " << it->second.at(0) << " and " << it->second.at(1) << '\n';    
  }

  std::cout << "\nPoint at infinity\n";

  int counter = 1;
  for(int i = 0; i < mod; ++i){
    int y = ((i * i * i) + (a * i) + b) % mod;
    it = residues.find(y);
    if(it != residues.end()){
      std::cout  << "X = " << i << " and Y = " << it->second.at(0) << "," << it->second.at(1) << '\n';
      counter += 2;
    }
  }

  std::cout << "Group has " << counter << " elements\n";
  
}
