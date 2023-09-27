#include <cassert>
#include "checkcardnum.h"

void test_skip_spaces() {
    assert(checkcardnum("4561 2612 1234 5467"));
}

int main() {
    test_skip_spaces();
}