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
void test_push_back(T& x) {
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
    // std::cout << x;
}

template <typename T>
void test_get_value(T x, size_t index) {
    std::cout << "get value with index " << index << ':' << x.get_value(index) << '\n';
}

template <typename T>
void test_increment_ptr(T x) {

    T* ptr = &(x[0]);
    std::cout << ptr << ": " << *ptr << '\n';
    ++ptr;
    std::cout << ptr << ": " << *ptr << '\n';
    ++ptr;
    std::cout << ptr << ": " << *ptr << "\n\n";
}

template <typename T>
void test_get_size(T x) {
    std::cout << "size: " << x.get_size() << '\n';
    std::cout << "sizeof: " << sizeof(x) << '\n' << '\n';   // TODO почему то размер Контейнера одинаковый при SerialConteiner<int> и SerialConteiner<double>
}

template <typename T>
void test_insert(T x, size_t index) {
    std::cout << "insert_position: " << index << "\n";
    x.insert(index, 42);
    x.print();
    // std::cout << "x: " << x << "\n\n";
}

template <typename T>
void test_erase(T x, size_t index) {
    std::cout << "erase_position: " << index << "\n";
    x.erase(index);
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
    test_push_back(z);

    test_get_value(z, 5);

    test_get_size(z);

    test_insert(z, 0);
    test_insert(z, 10);

    
    


//     std::cout << "get_value(0): " << z.get_value(0) << '\n';
//     std::cout << "get_value(1): " << z.get_value(1) << '\n';
//     std::cout << "get_value(2): " << z.get_value(2) << '\n';

//     z.print();

//     z.insert(1, 42);

//     z.print();
}
