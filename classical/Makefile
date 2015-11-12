all: substrfind freqanlyz affinehelp vigenere chianalyz

substrfind: substrfind.cpp
	g++ -std=c++11 substrfind.cpp -o substrfind

freqanlyz: freqanlyz.cpp
	g++ freqanlyz.cpp -o freqanlyz

affinehelp: affinehelp.cpp
	g++ affinehelp.cpp -o affinehelp

vigenere: vigenere.cpp
	g++ vigenere.cpp -o vigenere

chianalyz: chianalyz.cpp
	g++ chianalyz.cpp -o chianalyz

.PHONY: clean
clean:
	rm affinehelp
	rm chianalyz
	rm freqanlyz
	rm substrfind
	rm vigenere
