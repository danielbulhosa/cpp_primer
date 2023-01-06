#include <iostream>

int main() {

    int val1 = 0, val2 = 0;
    std::cout << "Please enter two integers: " << std::endl;
    std::cin >> val1 >> val2;
    int sign = (val2 - val1)/abs(val2 - val1); // Technically don't know abs yet but guessed it

    // Specifically avoiding using an if statement for fun.
    // That would certainly would be the cleaner solution
    // by figuring out which number is the lower one.
    while (val1 != val2){
        std::cout << "The current value is " << val1 << std::endl;
        val1 += sign;
    }

    std::cout << "The current value is " << val1 << std::endl;

    return 0;
}
