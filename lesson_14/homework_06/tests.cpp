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
std::ostream& operator<<(std::ostream& stream, const ListContainer<T>& my_list) {
    stream << '[';
    size_t size_list = my_list.get_size();
    for (size_t i=0; i < size_list; ++i) {
        stream << my_list.get_value(i);
        if (i < size_list - 1) std::cout << ", "; 
    }
    stream << ']' << '\n';
    return stream;
}


template <typename T>
void test_push_back(T& x) {
    std::cout << "---------test_push_back--------" << "\n";
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

    std::cout << x;
    std::cout << "---------------------------------" << "\n\n";

}

template <typename T>
void test_get_value(const T& x, size_t index) {
    std::cout << "--------test_get_value--------" << "\n\n";
    std::cout << "get_value(" << index << "): " << x.get_value(index) << '\n';
    std::cout << "---------------------------------" << "\n\n";

}

template <typename T>
void test_increment_ptr(T x) {
    std::cout << "-----test_increment_ptr-------" << "\n";

    T* ptr = &(x[0]);
    std::cout << ptr << ": " << *ptr << '\n';
    ++ptr;
    std::cout << ptr << ": " << *ptr << '\n';
    ++ptr;
    std::cout << ptr << ": " << *ptr << "\n";
    std::cout << "---------------------------------" << "\n\n";
    
}

template <typename T>
void test_get_size(const T& x) {
    std::cout << "---------test_get_size------------" << "\n";
    std::cout << "size: " << x.get_size() << '\n';
    std::cout << "sizeof: " << sizeof(x) << '\n';   // TODO почему то размер Контейнера одинаковый при SerialConteiner<int> и SerialConteiner<double>
    std::cout << "---------------------------------" << "\n\n";

}

template <typename T>
void test_insert(T& x) {
    std::cout << "---------test_insert------------" << "\n";
    std::cout << "insert(0, 10) " << "\n";
    x.insert(0, 10);
    x.print();
    std::cout << "insert(4, 20) " << "\n";
    x.insert(4, 20);
    x.print();
    std::cout << "push_back(30) " << "\n";
    x.push_back(30);
    x.print();


    std::cout << "---------------------------------" << "\n\n";
}

template <typename T>
void test_erase(T& x) {
    std::cout << "---------test_erase----------" << "\n";
    std::cout << "erase(" << 2 << "): " << "\n";
    x.erase(2);
    x.get_size();
    std::cout << "erase(" << 3 << "): " << "\n";
    x.erase(3);
    x.get_size();
    std::cout << "erase(" << 5 << "): " << "\n";
    x.erase(4);
    x.get_size();
    std::cout << "x: " << x;
    std::cout << "---------------------------------" << "\n\n";
}

template<typename T>
void all_tests_for_container(T& container) {
    
    test_push_back(container);
    std::cout << container;
    test_erase(container);
    test_insert(container);
}

int main() {

    // SerialConteiner<int> x;
    // std::cout << "SerialConteiner<int>" << "\n\n";
    // all_tests_for_container(x);

    // SerialConteiner<double> y;
    // std::cout << "\n\n\nSerialConteiner<double>" << "\n\n";
    // all_tests_for_container(y);

    // ListContainer<int> z;
    // std::cout << "\n\n\nListContainer<int>" << "\n\n";
    // all_tests_for_container(z);

    ListContainer<int> k;
    k.push_back(0);    
    k.push_back(1);    
    k.push_back(2);
    std::cout << k.get_size() << '\n';
    k.print();

    k.erase(1);   
    k.print();

}
