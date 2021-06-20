#include "ComplicatedWires.h"


void ComplicatedWires::launch(unsigned lastDigit, unsigned numBatteries, bool hasParallel)
{
    std::cout << "Wire solver - How many wires? : ";
    unsigned wireCount;
    std::cin >> wireCount;

    std::cout << std::endl << "Got it, lets get started." << std::endl;

    for (int i = 0; i < wireCount; i++) {
        checkWire(lastDigit, numBatteries, hasParallel);
    }
}


void ComplicatedWires::checkWire(unsigned lastDigit, unsigned numBatteries, bool hasParallel)
{
    bool red, blue, star, LED;
    std::string response;
    
    std::cout << "Does the wire have red? (y/n): ";
    std::cin >> response;
    red = checkResponse(response);
    response.clear();

    std::cout <<"Does the wire have blue? (y/n): ";
    std::cin >> response;
    blue = checkResponse(response);
    response.clear();

    std::cout << "Does the wire have a star? (y/n): ";
    std::cin >> response;
    star = checkResponse(response);
    response.clear();

    std::cout << "Does the wire have an LED? (y/n): ";
    std::cin >> response;
    LED = checkResponse(response);
    response.clear();


    bool shouldCut = solveWire(red, blue, star, LED, numBatteries, lastDigit, hasParallel);
    if (shouldCut) {
        std::cout << std::endl << "Cut it" << std::endl << std::endl << std::endl;
    }
    else {
        std::cout << std::endl << "Dont Cut It" << std::endl << std::endl << std::endl;
    }

}

bool ComplicatedWires::checkResponse(std::string input)
{
    if (input == "y")
        return true;
    else if (input == "n")
        return false;
    else {
        return false;
        std::cout << std::endl << "Weird response, defaulting to no." << std::endl;
    }
}



bool ComplicatedWires::solveWire(bool containsRed, bool containsBlue, bool hasStar, bool hasLED, unsigned numBatteries, unsigned lastDigit, bool hasParallel)
{
    if (containsRed || containsBlue || hasStar || hasLED) {


        //handle any white wires
        if (!containsRed && !containsBlue) {
            if (hasStar && hasLED) {
                return (numBatteries >= 2) ? true : false;
            }

            //if we reach this point, both markers cant possibly be true.
            //so if it has a star, its safe to cut, if it doesnt have a star, the LED has to be illuminated (as an effect of the first gate)
            //ergo if it has a star, cut, otherwise dont.
            return hasStar;

      
        }

        //handle blue and red wires
        if (containsRed && containsBlue) {
            if (hasStar && hasLED) {
                return false;
            }

            if (hasStar) {
                return hasParallel;
            }

            return isEven(lastDigit);
        }


        //handle red only
        if (containsRed) {
            if (hasStar && hasLED) {
                return (numBatteries >= 2) ? true : false;
            }


            //i know there is a better way here; brain farted
            if (hasLED) {

                return (numBatteries >= 2) ? true : false;
            }

            if (hasStar) {
                return true;
            }


            return isEven(lastDigit);

        }

        //this if isn't needed, but keeping it here to keep things making sense
        if (containsBlue) {
            if (hasStar && hasLED) {
                return hasParallel;
            }

            if (hasStar) {
                return false;
            }

            if (hasLED) {
                return hasParallel;
            }

            return isEven(lastDigit);
        }
    }

    //if none of the 4 base conditions are met, cut away!
    return true;
}



bool ComplicatedWires::isEven(unsigned num)
{
    return !(num % 2);
}

