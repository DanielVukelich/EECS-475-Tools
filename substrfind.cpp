#include <stdio.h>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

//Prints out all substrings of a certain length in a given ciphertext.
//Define the length by passing it as an argument.  It must be greater than 1.
//Pass in the ciphertext through stdin

bool cmppairs(std::pair<std::string, int> a, std::pair<std::string, int> b){
  return a.second > b.second;
}

int main(int argc, char* argv[]){

  if(argc != 2){
    std::cout << "Usage: " << argv[0] << " <substring_size>\n";
    return 1;
  }

  int substrlen = atoi(argv[1]);

  if(substrlen < 2){
    std::cout << "Usage: " << argv[0] << " <substring_size>\n";
    std::cout << "substring_size must be greater than 1\n";
    return 1;
  }

  std::unordered_map<std::string, int> substrmap;

  std::string text;
  std::cin >> text;

  for(int i = 0; i < text.length(); ++i){
    std::string sub = text.substr(i, substrlen);
    std::pair<std::unordered_map<std::string, int>::iterator, bool> result =  substrmap.insert({sub, 1});
    if(!result.second){
      (*(result.first)).second += 1;
    }
  }

  std::vector<std::pair<std::string, int>> tosort;
  for(std::unordered_map<std::string, int>::iterator i = substrmap.begin(); i != substrmap.end(); ++i){
    if((*i).second > 1){
      tosort.push_back(*i);
    }
  }

  std::sort(tosort.begin(), tosort.end(), cmppairs);

  std::cout << "Found " << tosort.size() << " substrings of length " << substrlen << " that repeated:\n";

  for(int i = 0; i < tosort.size(); ++i)
    std::cout << tosort[i].first << " appeared " << tosort[i].second << " times\n";

  return 0;
}
