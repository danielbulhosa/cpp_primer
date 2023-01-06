#include <iostream>

int main() {
    int sum = 0;

    // Only redoing exercise 1.9, we get the gist.
    for (int val = 50; val <= 100; ++val){
        sum += val;
    }

    std::cout << "The sum of the numbers between 50 and 100 is " << sum << std::endl;

    return 0;
}
