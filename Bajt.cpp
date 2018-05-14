#include "stdafx.h"
#include "Bajt.h"

Bajt::Bajt(int x, int y)
{
	bajt = x * 16 + y;
}

Bajt::Bajt(int x)
{
	bajt = x * 16;
}

std::string Bajt::getHex()
{
	std::stringstream s;
	s << std::hex << getDec();
	return s.str();
}

std::bitset<8> Bajt::getBinary()
{
	std::bitset<8> b(bajt);
	return b;
}

bool Bajt::isEvenNumOfOnes()
{
	if (getBinary().count() % 2 == 0)
		return true;
	else
		return false;
}