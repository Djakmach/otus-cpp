#include <iostream>
#include <array>
#include <vector>

class SerialConteiner {
public:
    SerialConteiner() : _size{0}, _data{nullptr} {}

    void push_back(int value) {
        int* new_space_data = new int[_size + 1];

        for (size_t i = 0; i < _size; ++i) {
            new_space_data[i] = _data[i];
        }

        new_space_data[_size] = value;
        delete[] _data;
        _data = new_space_data;
        ++_size;

    }

    void insert(size_t index, int value) {
        if (index > _size) throw std::string{"Error"};
        ++_size;
        int* new_space_data = new int[_size];
        bool flag = false;
        for (size_t i = 0; i < _size; ++i){ 
            if (i == index) {
                new_space_data[i] = value;
                flag = true;
                continue;
            }
            if (flag)
                new_space_data[i] = _data[i - 1];
            else
                new_space_data[i] = _data[i];
        }
        delete[] _data;
        _data = new_space_data;
        new_space_data = nullptr;
    }

    void erase(size_t index) {
        if (index > _size) throw std::string{"Error"};
        --_size;
        for (size_t i = 0; i < _size; ++i) {
            if (i >= index) _data[i] = _data[i + 1];
        }
    }

    void print() {
        std::cout << '[';
        for (size_t i = 0; i < _size; ++i) {
            std::cout << _data[i];
            if (i != _size-1) std::cout << ", ";
        }
        std::cout << ']' << '\n';

    }

    int get_value(size_t index) const {
        return _data[index];
    }

    size_t get_size() const {
        return _size;
    }

    ~SerialConteiner() {
        delete[] _data;
    }

    int& operator[](int i) {
        return _data[i];
    }

    // TODO как реализовать перегрузку  << внутри class
    // std::ostream& operator<<(std::ostream& stream, this) 
    // {
    //     stream << '[';
    //     for (size_t i = 0; i < list._size; ++i) {
    //         stream << list.get_value(i) << ", ";
    //     }
    //     stream << ']';
    //     return stream;

    // }

private:
    size_t _size;
    int* _data;
};


std::ostream& operator<<(std::ostream& stream, const SerialConteiner& my_list) {
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

int main() {

    SerialConteiner x;
    x.push_back(4);
    x.push_back(5);

    x.print();
    std::cout << x;

    int* ptr = &x[0];
    std::cout << *ptr << '\n';
    ++ptr;
    std::cout << *ptr << '\n';

    std::cout << "size: " << x.get_size() << '\n' << '\n';

    x.insert(0, 9);
    std::cout << x << "\n\n";

    x.erase(2);
    std::cout << x << "\n\n";

 

    // std::array<int> a;
}
