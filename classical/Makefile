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

keyfind: keyfind.cpp
	g++ keyfind.cpp -o keyfind

.PHONY: clean
clean:
	rm affinehelp
	rm keyfind
	rm chianalyz
	rm freqanlyz
	rm substrfind
	rm vigenere
