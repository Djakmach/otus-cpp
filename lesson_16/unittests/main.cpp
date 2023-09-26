#include <iostream>
#include <cstdlib>

#include "checkcardnum.h"

std::string format(const std::string &cardnum);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: checkcardnum <credit card number>\n";
        return EXIT_FAILURE;
    }
    std::string num{format(argv[1])};
    if (checkcardnum(num)) {
        std::cout << "Correct\n";
    } else {
        std::cout << "Incorrect\n";
    }
}

std::string format(const std::string &cardnum) {
    std::string formatted = "";
    for (size_t i = 0; i < cardnum.length(); ++i) {
        formatted.push_back(cardnum[i]);
        if ((i + 1) % 4 == 0) {
            formatted.push_back(' ');
        }
    }
    return formatted;
}