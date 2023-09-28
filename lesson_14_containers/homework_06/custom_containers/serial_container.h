#include <iostream>


template <typename T>
class SerialConteiner {
public:
    SerialConteiner() : _size{0}, _data{nullptr} {}

    SerialConteiner(const SerialConteiner& other) : _size{other._size}, _data{nullptr} {
        _data = new T[_size];
        for (size_t i = 0; i < _size; ++i) {
            _data[i] = other[i];
        }
    }

    SerialConteiner& operator=(SerialConteiner& other) {
        if (this != &other) {
            _size = other._size;
            _data = new T[_size];
            for (size_t i = 0; i < _size; ++i) {
            _data[i] = other[i];
        }
        }
        return *this;
    }


    SerialConteiner& operator=(SerialConteiner&& other) {
        if (this != &other) { 
            
            _size = other._size;
            _data = other._data;
            other._size = 0;
            other._data = nullptr;
        }
        return *this;
    }



    void push_back(T value) {
        T* new_space_data = new T[_size + 1];

        for (size_t i = 0; i < _size; ++i) {
            new_space_data[i] = _data[i];
        }

        new_space_data[_size] = value;
        delete[] _data;
        _data = new_space_data;
        ++_size;

    }

    void insert(size_t index, T value) {
        if (index > _size) throw std::string{"Error"};
        ++_size;
        T* new_space_data = new T[_size];
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

    T get_value(size_t index) const {
        return _data[index];
    }

    size_t get_size() const {
        return _size;
    }

    ~SerialConteiner() {
        delete[] _data;
    }

    T& operator[](size_t i) {
        return _data[i];
    }

    const T& operator[](size_t i) const {
        return _data[i];
    }

private:
    size_t _size;
    T* _data;
};