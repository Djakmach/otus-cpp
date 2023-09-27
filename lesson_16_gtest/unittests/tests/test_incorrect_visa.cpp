#include <cassert>
#include "checkcardnum.h"

void test_incorrect_visa() {
    assert(!checkcardnum("4561261212345465"));
}

int main() {
    test_incorrect_visa();
}
