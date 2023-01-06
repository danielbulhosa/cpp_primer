#include <iostream>
#include <vector> // Example import of standard library
#include <string>

/*
 * Takeaways:
 *
 * - C++ makes explicit many things that Python makes implicit such as:
 *   - Pointing variables to the same data vs. not. Python points new variables
 *     to existing data when we assign an existing variable to a new variable. C++
 *     creates and stores new data for a new variable even if it is assigned the
 *     value of an old variable -- if we want to reuse the old variable data we
 *     need to create a reference.
 *   - If you want to assign values to a vector or array you need to make sure the
 *     loop through the array ACTUALLY terminates at the end of the array. Otherwise
 *     (unlike Python) the loop will continue without throwing an error and overwrite
 *     other objects in memory. In Python the language itself does not allow us to
 *     write beyond the end of an array. <-- this is called MEMORY LEAKAGE.
 *   - C++ makes explicit the memory locations of data.
 *
 * - Syntactical features:
 *   - Values vs. references can be distinguished. Not possible in Python.
 *   - Indexing pointers retrieves the value N slots away from the pointer,
 *     where N is the index passed.
 *   - for-range loops allow us to iterate through indexable objects (it appears).
 *   - Incrementing a variable increases the value stored in that variable. If the
 *     variable is a pointer the memory address stored in it is increased based on
 *     the memory footprint of its type. If we increment a non-pointer variable it
 *     gets incremented normally (like an integer increases by 1 for example, whetehr
 *     the original variable or a reference to it).
 *   - Exact action of increment operator depends on data type.
 *   - new creates a pointer to the top of an array of memory that is set to the side
 *     for storing data.
 *   - Arrays of any type are declared by saying T t[n] where T is the type, t is the
 *     variable, and n is the number of entries in the array.
 *
 *  - Shared with Python:
 *    - Ternary operations.
 *    - Indexing notation, string notation.
 *    - Unary and binary operators.
 *    -
 *
 * How we interpret C++ variables is a lot more literal than how we interpret Python ones.
 * A lot of the abstraction is in the language itself, Python handles a lot under the hood.
 */

int main() {
    std::vector<int> v(10); // Example vector declaration (default values are zero)
    int u[10] = {0,1,2,3,4,5,6,7,8,9}; // Example array declaration and assignment

    for (int i = 0; i < 10; ++i) {
        v[i] = i;
        bool u_equals_v = (u[i] == v[i]); // Example comparison stored into value
        std::string s = (u_equals_v ? "True" : "False"); // Example ternary operation
        std::cout << "Are array and vector elements equal: " << s << std::endl;
        std::cout << "Array element at position " << i << " " << v[i] << std::endl;
        std::cout << "Address of element at position " << i << " " << &v[i] << std::endl; // Get memory address of vector entry
    }

    int* v0 = &v[0];
    for (int i = 0; i < 10; ++i){
        std::cout << "Element accessed from address " << i << " " << *v0 << std::endl;
        ++v0; // Example of incrementing address to move across array. Note this doesn't increment v[0].
    }

    int& v00 = (int &) v[0]; // Note that the syntax `int &` casts the integer to a reference.
    std::cout << "The type of `v00` is: " << typeid(v[0]).name() << std::endl;
    for (int i = 0; i < 10; ++i){
        // Note that when we call the reference variable it returns the actual value.
        std::cout << "Element accessed from reference: " << i << " " << v00 << std::endl;
        ++v00; // WARNING: Note that here what we are incrementing is the value referenced,
               // which is v[0]. Thus v[0] will not be 0 anymore, it will be 10!
    }
    std::cout << "The current value at `v[0]` is: " << v[0] << std::endl; // We expect that the value here changed!

    for (int i: u){ // This is a range-for look, it iterates over an iterable. Similar to Python for loops.
        std::cout << "This is a test that we can loop through the list, " << i << std::endl;
    }

    /*
     * In Python when we initialize a variable to equal another the second variable
     * is really just a pointer (or reference) to the first. However, although this
     * assignment is implicit in Python it is explicit in C++. So for example:
     */

    int a = 1; //
    int b = a; // Should have different memory address as a
    int &c = a; // Should have same memory address as a
    int d = 1; // Should have different memory address as a and b

    std::cout << "Memory address a: " << &a << std::endl;
    std::cout << "Memory address b: " << &b << std::endl;
    std::cout << "Memory address c: " << &c << std::endl;
    std::cout << "Memory address d: " << &d << std::endl;

    /*
     * Note that in Python small constants have unique memory addresses.
     * In C++ we can store the same constant in as many memory addresses
     * as we would like (we stored 1 in three different memory addresses above).
     */


    /*
     * Below we allocate memory space to a variable and then try to assign values
     * to that space. It seems that `new int[10]` creates a pointer but that if
     * we index the pointer we get the values... Interesting.
     */

    int* p = new int[10];
    std::cout << "The output of the keyword new is an address: " << p << std::endl;
    std::cout << "The type of p is: " << typeid(p).name() << std::endl;
    std::cout << "The type of `new int[10]` is: " << typeid(new int[10]).name() << std::endl;

    // This shows indexing the pointer yields different values at different addresses.
    std::cout << "FIRST LOOP" << std::endl;
    for (int i : {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14}){
        std::cout << "p value at index " << i << ": " << p[i] << std::endl;
        std::cout << "p address at index " << i << ": " << &p[i] << std::endl;
    }

    // We can index the pointer to get the values and then replace the values
    // at different indices with the values we want. This WORKS! However, it
    // doesn't use the pointer directly to make the assignment which is our goal.
    std::cout << "SECOND LOOP" << std::endl;
    for (int i : {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14}){
        std::cout << "Current p value: " << p << std::endl;
        std::cout << "Current &p[N] value (address): " << &p[i] << std::endl;
        std::cout << "Current value stored at p: " << p[i] << std::endl;
        p[i] = i;
        std::cout << "New value stored at p: " << p[i] << std::endl;
    }

    std::cout << "THIRD LOOP" << std::endl;
    int* pcopy = p;
    // Note that we need to make a copy of p because if we increment and index p
    // we get weird indexing behavior (because the index and pointer both move so
    // we get double the index motion unintentionally). Note that indexing a pointer
    // at N is the same as calculating the address N steps away and getting the value there.
    // So p[N] is the same as *(p + N x # bytes for datatype).
    for (int i : {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14}){
        std::cout << "Current p value: " << p << std::endl;
        *pcopy = -i;
        ++pcopy;
        std::cout << "New value stored at p[i]: " << p[i] << std::endl;
        std::cout << "Should be same value stored at pcopy[0]: " << p[i] << std::endl;
    }

    /*
     * FIXME - would want to do structs, constants, bracket assignment, auto keyword, switch statements, and classes next.
     */

    return 0;
}
