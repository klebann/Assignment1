#include <bitset>
#include <iostream>
#include <sstream>
#pragma once

class Bajt
{
public:
	Bajt(int x, int y);
	Bajt(int x);

	unsigned getDec() { return bajt; }
	std::string getHex();
	std::bitset<8> getBinary();
	bool isEvenNumOfOnes();
	void printHex() { std::cout << std::hex << getDec() << std::endl; }
	void printBinary() { std::cout << getBinary() << std::endl; }

	//compare function for sort asc
	bool operator < (const Bajt& _next) const { return (bajt < _next.bajt); }

	//compare function for sort desc
	bool operator > (const Bajt& _next) const { return (bajt > _next.bajt); }

private:
	unsigned __int8 bajt; //stored as dec number
};