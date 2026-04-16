#include <iostream>
#include <cstdint>
#include <limits>

#define MAXIMAL_AGE 125

namespace validation {
    bool isAdult(std::uint8_t age);
    bool isSenior(std::uint8_t age);
}

int main() {

    int age_input = MAXIMAL_AGE;

    std::cout << "Please enter your age: ";
    while (
        !(std::cin >> age_input) ||
        (age_input > MAXIMAL_AGE) 
    ) {
        std::cout << "You did not enter a valid number. Please try again." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        age_input = MAXIMAL_AGE;
        std::cout << "Please enter your age: ";
    }

    std::cout << "You are " << age_input << " years old." << std::endl;
    
    if (validation::isSenior(static_cast<uint8_t>(age_input))) {
        std::cout << "That means that you are a senior citizen." << std::endl;
    } else if (validation::isAdult(static_cast<uint8_t>(age_input))) {
        std::cout << "That means that you are an adult." << std::endl;
    } else {
        std::cout << "That means that you are still a kid or teenager." << std::endl;
    }

    return 0;
}

bool validation::isAdult(std::uint8_t age) {
    if (age >= 18) {
        return true;
    }
    return false;
}

bool validation::isSenior(std::uint8_t age) {
    if (age >= 65) {
        return true;
    }
    return false;
}