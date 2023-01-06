#include <iostream>

int main() {
    unsigned int u = 10, u2 = 42; // "unsigned int" can be abbreviated to just "unsigned"
    std::cout << u2 - u << std::endl; // Prints out 32
    std::cout << u - u2 << std::endl; // int has 16 bits, so it can represent 0 to 65535.
                                      // Thus this prints out (10 - 42) mod 65536 = 65504.
                                      // CORRECTION: Seems like the minimum int size is actually 32 bits
                                      // in this computer so instead of 2^16 - 1 = 65535 as the max
                                      // we got 2^32 - 1 = 4294967295. So the actual answer is
                                      // (10 - 42) mod 4294967296 = 4294967264.
    int i = 10, i2 = 42; // This is signed
    std::cout << i2 - i << std::endl; // Prints out 32.
    std::cout << i - i2 << std::endl; // Prints out -32, since int is signed.
    std::cout << i - u << std::endl; // Prints out 0. i gets cast to unsigned.
    std::cout << u - i << std::endl; // Prints out 0. i gets cast to unsigned.

    std::cout << 09 << std::endl;

    return 0;
}
