#include <iostream>

int main() {
    /* The passed fragment is not legal because
     * when we end the statement in the first line
     * and start the statement in the second line
     * we do not pass a left hand argument to the output
     * operator in the second hand line. This will cause an
     * error. The same error is present between the second and
     * thid lines shown.
     *
     * To fix the error we need to remove the semi-colons at
     * the end of the first and second lines shown in the book.
     *
     * Note when we comment those out the program runs just fine.
     */

    std::cout << "Enter two numbers:" << std::endl;
    int var1 = 0, var2 = 0;
    std::cin >> var1 >> var2;
    std::cout << "The sum of " << var1 //;
              << " and " << var2 //;
              << " is " << var1 + var2 << std::endl;
}
