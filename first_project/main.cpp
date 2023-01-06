/* The name of a package being imported between <...>
   is a **header**. All imports have to happen at the
   top of the file. The keyword #include is the statement
   that tells C++ to import the package.
*/
#include <iostream>

int main() {
    /* << is the **output opeator**. The operator
       takes two arguments, the one on the left hand
       side must be a stream (an object handling IO
       for the program) and the one on the right hand
       side must be a value to print (e.g. a string).
    */
    std::cout << "Enter two numbers:" << std::endl;
    /* This is equivalent to:
     * std::cout << "Hello, World!";
     * std:cout << std::endl;
     * That is because the << operator returns the
     * lefthand argument. Here std::endl is a special
     * object that when passed to the standard out
     * ends the line, flushes the buffer, and makes sure
     * the characters stored in the buffer are actually
     * printed. (Very low level, we know).
     *
     * If we do not flush the stream then the statement
     * may print unpredictably or in an unexpected manner,
     * which may make the debugging process confusing.
     */

    /* std:: defines the **namespace** within a which a variable
     * should be found. std::cout means we should use the cout
     * variable defined in the std (standard) library. This avoids
     * namespace collision where it is ambiguous whether we are
     * referring to a cout defined in the std package vs. a different
     * package. This is similar to the idea of modules in Python. We
     * call :: the **scope** operator.
     */

    /* Note that we can define two variables in the same line with
     * shared type declaration. Note that only a single type can be
     * declared in the same line. int v1 = 0, int v2 = 0 fails.
     * However int v1 = 0; int v2 = 0; works fine.
     */
    int v1 = 0, v2 = 0;

    /* << is the output operator, so analogously >> is the
     * **input** operator (not to be confused with bitwise
     * operations in Python). Just like the output operator
     * the input operator returns its left hand argument (which
     * is an IO object) so the statement below is equivalent to:
     *
     * std::cin >> v1;
     * std:cin >> v2;
     */
    std::cin >> v1 >> v2;

    /* Note that semi-colons end statements so we can
     * confidently continue our statement across lines
     * without concern. It appears whitespace is ignored.
     *
     * This is not the case with Python where different
     * kinds of whitespace are used to understand relationships
     * between statements. In this language ; and {} are used for
     * the same purpose, like with Scala.
     */
    std::cout << "The sum of " << v1 << " and " << v2
                 << " is " << v1 + v2 << std::endl;

    return 0;
}
