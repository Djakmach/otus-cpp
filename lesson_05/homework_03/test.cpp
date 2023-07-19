#include <iostream>
#include <format>
#include <string>
#include <fstream>
#include <filesystem>


int get_max(int argc, char *argv[]) {
    std::cout << "argc " << argc << '\n';
    std::cout << "argv_0 " << argv[0] << '\n';
    std::cout << "argv_1 " << argv[1] << '\n';
    std::cout << "argv_2 " << argv[2] << '\n';

    if (argc == 1) {
        int default_max_number = 100;
        return default_max_number;
    }
    if (argc == 3) {
        std::string key{argv[1]};
        if (key == "--max") {
            int max_number = std::stoi(argv[2]);
            return max_number;
        }
    }
}


int main(int argc, char** argv) {
    std::cout << "MAX_NUMBER = " << get_max(argc, argv) << '\n';
}