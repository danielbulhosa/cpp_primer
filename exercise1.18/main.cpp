#include <iostream>

int main() {
    int value = 0, currVal = 0;
    std::cout << "Please enter a sequence of integers: " << std::endl;

    if (std::cin >> value){
        currVal = value;
        int count = 1;

        while (std::cin >> value){
            // Would be good to break if value == "\n", haven't learned how to break yet.
            if (value == currVal){
                ++count;
            }
            else {
                std::cout << "The current value " << currVal << " was repeated " << count << " times." << std::endl;
                count = 1;
                currVal = value;
            }
        }
        // Note that << doesn't concatenate strings. It passes additional output to the IO object.
        // Thus even though the syntax is similar to string concatenation it's actually a different operation.
        std::cout << "The current value " << currVal << " was repeated " << count << " times." << std::endl;
    }

    return 0;
}
