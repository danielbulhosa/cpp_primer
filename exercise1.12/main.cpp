#include <iostream>

int main() {
    // This script will sum all numbers between -100 and 100,
    // which will return zero since the sum is anti-symmetric.
    int sum = 0;

    for (int i = -100; i <= 100; ++i){
        sum += i;
    }

    std::cout << "The value of the sum is " << sum << std::endl;

    return 0;
}
