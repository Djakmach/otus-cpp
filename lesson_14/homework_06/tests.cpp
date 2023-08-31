#include <iostream>
#include <array>
#include <vector>

#include <serial_container.h>
#include <list_container.h>


template <typename T>
std::ostream& operator<<(std::ostream& stream, const SerialConteiner<T>& my_list) {
    stream << '[';
    size_t size = my_list.get_size();
    for (size_t i = 0; i < size; ++i) {
        stream << my_list.get_value(i);
        // проверка на последний символ
        if (i != size-1) stream << ", ";
    }
    stream << ']' << '\n';
    return stream;

}


template <typename T>
void test(SerialConteiner<T> x) {
    x.push_back(0);
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
    x.push_back(5);
    x.push_back(6);
    x.push_back(7);
    x.push_back(8);
    x.push_back(9);

    x.print();
    std::cout << x;

    T* ptr = &(x[0]);
    std::cout << ptr << ": " << *ptr << '\n';
    ++ptr;
    std::cout << ptr << ": " << *ptr << '\n';
    ++ptr;
    std::cout << ptr << ": " << *ptr << "\n\n";

    std::cout << "size: " << x.get_size() << '\n';
    std::cout << "sizeof: " << sizeof(x) << '\n' << '\n';   // TODO почему то размер Контейнера одинаковый при SerialConteiner<int> и SerialConteiner<double>


    size_t insert_position = 4;
    std::cout << "insert_position: " << insert_position << "\n";
    x.insert(insert_position, 42);
    std::cout << "x: " << x << "\n\n";

    size_t erase_position = 4;
    std::cout << "erase_position: " << erase_position << "\n";
    x.erase(erase_position);
    std::cout << "x: " << x << "\n";
}


int main() {
    // SerialConteiner<int> x;
    // SerialConteiner<double> y;

    // std::cout << "---------------------------------" << "\n";
    // std::cout << "SerialConteiner<int>" << "\n";
    // test(x);
    // std::cout << "---------------------------------" << "\n\n";

    // std::cout << "SerialConteiner<double>" << "\n";
    // test(y);
    // std::cout << "---------------------------------" << "\n\n";


    ListContainer<int> z;
    z.push_back(42);
    z.push_back(33);
    z.push_back(44);

    std::cout << "get_value(0): " << z.get_value(0) << '\n';
    std::cout << "get_value(1): " << z.get_value(1) << '\n';
    std::cout << "get_value(2): " << z.get_value(2) << '\n';

    z.print();







}
