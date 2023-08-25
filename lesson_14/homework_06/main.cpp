#include <iostream>
#include <array>

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

    void print() {
        std::cout << '[';
        for (size_t i = 0; i < _size; ++i) {
            std::cout << _data[i] << ", ";
        }
        std::cout << ']' << '\n';

    }

    int get_value(size_t index) {
        return _data[index];
    }

    size_t get_size() {
        return _size;
    }


    ~SerialConteiner() {
        delete[] _data;
    }

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


std::ostream& operator<<(std::ostream& stream, const SerialConteiner& list1) {
        stream << list1.get_size();
        
        // stream << '[';
        // for (size_t i = 0; i < list.get_size(); ++i) {
        //     stream << list.get_value(i) << ", ";
        // }
        // stream << ']';
        return stream;

    }

int main() {

    // std::ostream& operator<<(std::ostream& stream, const SerialConteiner& list) 
    // {
    //     stream << '[';
    //     for (size_t i = 0; i < list.get_size(); ++i) {
    //         stream << list.get_value(i) << ", ";
    //     }
    //     stream << ']';
    //     return stream;

    // }

    SerialConteiner x;
    x.push_back(4);
    x.push_back(5);
    x.push_back(42);

    x.print();
    std::cout << x;

}