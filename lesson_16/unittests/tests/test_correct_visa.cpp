#include <cassert>
#include "checkcardnum.h"

void test_correct_visa() {
    assert(checkcardnum("4561261212345467"));
}

int main() {
    test_correct_visa();
}