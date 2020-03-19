
//  |===================================================|
//  |   Title:    Stack Practice                        |
//  |   Author:   Drake G. Cummings                     |
//  |   Purpose:  To practice using STL stacks in C++   |
//  |===================================================|

#include <iostream>
#include "StackOperations.hpp"

int main() {
    std::cout << "Gimme a big number - up to 10 digit(s)" << std::endl;

    // Take user input
    int chosenNumber;
    std::cin >> chosenNumber;

    DrakeOnline::TestInt testInt;

    // Display digit count
    std::cout << "Number " << chosenNumber << " has " << testInt.CountDigits(chosenNumber) << " digits" << std::endl;

    // Display the number backwards
    std::cout << "Backwards, it is: " << testInt.Reverse(chosenNumber) << std::endl;

    // Test whether it is a palindrome
    if(testInt.IsPalindrome(chosenNumber)) {
        std::cout << "And it's a palindrome!" << std::endl;
    } else {
        std::cout << "Not a palindrome." << std::endl;
    }

    return 0;
}
