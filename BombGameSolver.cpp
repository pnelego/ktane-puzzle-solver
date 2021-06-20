// BombGameSolver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "ComplicatedWires.h"

int main()
{
    ComplicatedWires complicatedWires;
    unsigned lastDigit;
    unsigned numBatteries;
    bool hasParallel;
    //get bomb information
    std::cout << "Welcome to bomb solver - solver of the more-- annoying modules." << std::endl;
    std::cout << "Lets get some information....." << std::endl << std::endl;

    std::cout << "Please enter the last digit of the serial number: ";
    std::cin >> lastDigit;

    std::cout << std::endl << "Please Enter the number of batteries: ";
    std::cin >> numBatteries;

    std::cout << std::endl << "Is there a red parallel port? (y/n): ";
    std::string parallelInput;
    std::cin >> parallelInput;

    if ( parallelInput == "y")
        hasParallel = true;
    else if (parallelInput == "n")
        hasParallel = false;
    else {
        hasParallel = false;
        std::cout << std::endl << "Weird response, defaulting to no." << std::endl;
    }
  

    std::cout << "Availible Modules:" << std::endl;
    std::cout << "1 - Complicated Wires" << std::endl;


    unsigned choice;
    std::cin >> choice;

    std::cout << std::endl << "Launching... " << std::endl;

    switch (choice) {
    case 1:
        complicatedWires.launch(lastDigit, numBatteries, hasParallel);
    }

    return 0;
}

