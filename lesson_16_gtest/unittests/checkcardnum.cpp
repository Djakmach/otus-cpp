#include "checkcardnum.h"

namespace {
int char2digit(char ch) {
    return ch - '0';
}
}

// using Luhn algorithm
bool checkcardnum(const std::string &digits) {
    int number = 0;
    int sum = 0;
    size_t i = 0;
    for (char ch: digits) {
        if (ch == ' ') {
            continue;
        }
        number = char2digit(ch);
        if (i++ % 2 == 0) {
            number *= 2;
            if (number > 9) {
                number -= 9;
            }
        }
        sum += number;
    }
    return sum % 10 == 0; 
}

