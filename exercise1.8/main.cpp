#include <iostream>

int main() {
    // std::cout << "/*"; valid, because comment character in quotes.
    // std::cout << "*/"; // valid, because comment character in quotes.
    // std:cout << /* "*/" */; // invalid, because first /* officially starts comment.
                               // Then comment gets closed twice. Quote syntax overriden by comment.
                               // Second open quote is then interpreted as first quote as it is considered part of comment.
    std::cout << /* "*/" /*  "/*" */; // Actually valid (thought otherwise). Comment openers and closers are paired.
                                      // Middle comment open bracked is cancelled by quotes on each side.
                                      // Quotes on each end get made into comments and neglected by compiler.

    std::cout << std::endl;

    return 0;
}
