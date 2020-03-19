#include <stack>
#include <iostream>
#include "StackOperations.hpp"

namespace DrakeOnline {

    int TestInt::CountDigits(int number) {

        // Test for case 0
        if(number==0) { return 1; }

        //Test if number is negative
        if(number<0) { number *= -1 ;}

        int numberOfDigits = 0;
        while(number != 0) {
            number/=10;
            numberOfDigits++;
        }

        return numberOfDigits;
    }


    int TestInt::Reverse(int number) {

        // Test if number is negative
        bool isNegative = false;
        if(number < 0) {
            isNegative = true;
            number *= -1;
        }

        int digitCount = CountDigits(number);
        int lastDigit = 0;
        std::stack<int> numberStack;

        // Reduce the number by a digits place each time, adding the rightmost to the stack
        for(unsigned short int i = 0; i < digitCount; i++) {

            lastDigit = number - ((number/10)*10);

            numberStack.push(lastDigit);

            number/=10;
        }

        // For the final number
        int reversedInteger = 0;
        // Tracking the current numbers place
        int currentTenthPower = 1;

        for(unsigned short int i = 1; i < digitCount+1; i++) {

            // Control number's place based on loop count
            currentTenthPower = 1;
            for(unsigned short int j = 1; j<i; j++) {
                currentTenthPower *= 10;
            }

            // Multiply current digit by number's place then add it to our final number
            reversedInteger += numberStack.top() * currentTenthPower;
            numberStack.pop();
        }

        // Reapply number negativity, if necessary
        if(isNegative) {
            return reversedInteger*-1;
        } else {
            return reversedInteger;
        }

    }


    bool TestInt::IsPalindrome(int number) {
        return number == Reverse(number);
    }
}
