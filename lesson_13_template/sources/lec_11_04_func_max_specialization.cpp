#include <cstring>
#include <iostream>
#include <string>

namespace lec11
{

//primary template
template <typename T>
T max(T a, T b) 
{
	return (a > b) ? a : b;
}

//full specialization for T=const char*
//full specialization is preffered to primary template
template <>
const char* max<const char *>(const char *a, const char *b)
{
	// First need to find length of the both strings
	const size_t a_length = std::strlen(a);
	const size_t b_length = std::strlen(b);

    // Now we should iterate all symbols from the first and the second string
	const size_t min_length = (a_length < b_length) ? a_length : b_length;

	for (size_t i = 0; i < min_length; ++i) 
	{
		if (a[i] > b[i]) 
		{
			return a;
		} 
		else if (a[i] < b[i]) 
		{
			return b;
		}
	}

	// In case all symbols are equal it returns a string of bigger length
	return (a_length < b_length) ? b : a;
}

}

int main() {

	std::cout << "max(42, 123) = " << lec11::max(42, 123) << std::endl;
    std::cout << "max(Bob, Ann) = " << lec11::max("Bob", "Ann") << std::endl;

	std::cout << "max(\"123\", \"234\") = " << lec11::max("123", "234") << std::endl;
	std::cout << "max(\"123\", \"23\")  = " << lec11::max("123", "23") << std::endl;
	std::cout << "max(\"123\", \"12\")  = " << lec11::max("123", "12") << std::endl;

	return 0;
}

