#pragma once
#include <iostream>

class ComplicatedWires
{
	public:
		void launch(unsigned lastDigit, unsigned numBatteries, bool hasParallel);
	private:
		bool isEven(unsigned num);
		bool solveWire(bool containsRed, bool containsBlue, bool hasStar, bool hasLED, unsigned numBatteries, unsigned lastDigit,  bool hasParallel );
		void checkWire(unsigned lastDigit, unsigned numBatteries, bool hasParallel);

		bool checkResponse(std::string input);
};

