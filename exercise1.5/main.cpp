#include <iostream>

int main() {
    std::cout << "Enter two numbers:" << std::endl;
    int var1 =0 , var2 = 0;
    std::cin >> var1 >> var2;
    std::cout << "The sum of ";
    std::cout << var1;
    std::cout << " and ";
    std::cout << var2;
    std::cout << " is ";
    std::cout << var1 + var2;
    std::cout << std::endl;

    return 0;
}
