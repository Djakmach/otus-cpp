#include <cassert>
#include <iostream>

#include "checkcardnum.h"

void test_correct_visa() {
    assert(checkcardnum("4561261212345467"));
}

void test_incorrect_visa() {
    assert(!checkcardnum("4561261212345465"));
}

void test_skip_spaces() {
    assert(checkcardnum("4561 2612 1234 5467"));
}

int main() {
    std::cout << "test_correct_visa..." << std::flush;
    test_correct_visa();
    std::cout << "OK" << std::endl;
    
    std::cout << "test_incorrect_visa..." << std::flush;
    test_incorrect_visa();
    std::cout << "OK" << std::endl;

    std::cout << "test_skip_spaces..." << std::flush;
    test_skip_spaces();
    std::cout << "OK" << std::endl;
}