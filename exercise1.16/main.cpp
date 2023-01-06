#include <iostream>

int main() {
    int val = 0, sum = 0;

    std::cout << "Enter as many integers as desired to sum" << std::endl;
    // Unbounded input only runs successfully in debug mode: https://youtrack.jetbrains.com/issue/CPP-5704
    while (std::cin >> val){
        sum += val;
    }

    std::cout << "The sum of the values was " << sum << std::endl;
    return 0;
}

