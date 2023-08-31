// #include "serial_conteiner.h"


// void SerialConteiner::push_back(T value) {
//     T* new_space_data = new T[_size + 1];

//     for (size_t i = 0; i < _size; ++i) {
//         new_space_data[i] = _data[i];
//     }

//     new_space_data[_size] = value;
//     delete[] _data;
//     _data = new_space_data;
//     ++_size;

// }


// void SerialConteiner::insert(size_t index, T value) {
//         if (index > _size) throw std::string{"Error"};
//         ++_size;
//         T* new_space_data = new T[_size];
//         bool flag = false;
//         for (size_t i = 0; i < _size; ++i){ 
//             if (i == index) {
//                 new_space_data[i] = value;
//                 flag = true;
//                 continue;
//             }
//             if (flag)
//                 new_space_data[i] = _data[i - 1];
//             else
//                 new_space_data[i] = _data[i];
//         }
//         delete[] _data;
//         _data = new_space_data;
//         new_space_data = nullptr;
//     }

// void SerialConteiner::erase(size_t index) {
//     if (index > _size) throw std::string{"Error"};
//     --_size;
//     for (size_t i = 0; i < _size; ++i) {
//         if (i >= index) _data[i] = _data[i + 1];
//     }
// }

// void SerialConteiner::print() {
//     std::cout << '[';
//     for (size_t i = 0; i < _size; ++i) {
//         std::cout << _data[i];
//         if (i != _size-1) std::cout << ", ";
//     }
//     std::cout << ']' << '\n';

// }
