#include <iostream>

#include "checkcardnum.h"

int main() {
    std::string visa = "4561261212345467";
    for (size_t i = 0; i < visa.size(); ++i) {
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            std::string copy_visa = visa;
            copy_visa[i] = ch;
            if (checkcardnum(copy_visa)) {
                std::cout << copy_visa << '\n';
                return 0;
            }
        }
    }
}