#include <iostream>



template <typename T>
T max(T a, T b)
{
	return (a > b) ? a : b;
}

/*
int max(int a, int b)
{
    return (a > b) ? a : b;
}

float max(float a, float b)
{
    return (a > b) ? a : b;
}
*/
template <typename T>
bool is_equal(T a, T b)
{
    return a == b;
}

int main() 
{
	std::cout << "max(42, 123) = " << max(42, 123) << std::endl;
	std::cout << "max(1.5f, 1.9f) = " << max(1.5f, 1.9f) << std::endl;

    std::cout << "max(Bob, Ann) = " << max("Bob", "Ann") << std::endl;

	return 0;
}
