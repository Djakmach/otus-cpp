#include <cassert>
#include "checkcardnum.h"

void test_incorrect_non_digit() {
    assert(!checkcardnum("456126121234b467"));
}

int main() {
    test_incorrect_non_digit();
}
