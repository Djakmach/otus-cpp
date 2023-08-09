#include <iostream>
// #include <format>
#include <string>
#include <fstream>
#include <filesystem>
#include <map>
#include <cstring>

#include "utils.h"
#include <io.h>


namespace {
    std::string name_file_scores = "scores.txt";        //TODO допустимо или есть вариант лучше?
    const int MIN_NUMBER = 0;                           //TODO как поступить с переменными MIN_NUMBER, MAX_NUMBER, invaition_message?
    int MAX_NUMBER;
    std::string invaition_message;

}

int get_user_number(std::string user_input) {
    if (!is_number(user_input)) {
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cout << "Error! String is not numeric" << "\n";
        std::cout << invaition_message << std::endl;
        return -1;
    }
    int user_number = is_valid_int(user_input);
    if (user_number == -1) {
        std::cout << "Error! Number is too long" << "\n";
        std::cout << invaition_message << std::endl;
        return -1;
    }
    
    if (!is_number_in_range(MIN_NUMBER, user_number, MAX_NUMBER)) {
        std::cout << "Error! Number is out of range [" << MIN_NUMBER << ".." << MAX_NUMBER << "]" << std::endl;
        std::cout << invaition_message << std::endl;
        return -1;
    }
    return user_number;
}

int get_arg(int argc, char* argv[]) {
    if (argc == 1) {
        int default_max_number = 100;
        return default_max_number;
    }
    if (argc > 1) {
        const char* max = "-max";
        std::string key = argv[1];
        if (std::strcmp(argv[1], "-max") == 0) {   
            int max_number = std::stoi(argv[2]);
            std::cout << max_number << '\n';
            return max_number;
        } else if (key == "-table") {
            show_score_board();
            return -1;
        } else {
            std::cout << "Error! Invakid command.\n";
            return -1;
        }
    } else {
        std::cout << "5 " << '\n';

        std::cout << "Error! Invakid command.\n";
        return -1;
    }
}

int main(int argc, char *argv[]) {
    std::srand(time(NULL));
    MAX_NUMBER = get_arg(argc, argv);
    if (MAX_NUMBER == -1) {
        return -1;
    }

    int hidden_number = std::rand() % MAX_NUMBER;
    std::string user_name;
    std::string user_input;
    int attempts = 1;
    invaition_message = "Enter your guess in range [" + std::to_string(MIN_NUMBER) + ".." +  std::to_string(MAX_NUMBER) + "]";

    std::cout << "Hi! Enter your name, please:" << std::endl;
    std::getline (std::cin, user_name);

    std::cout << invaition_message << std::endl;

    while (true) {
        std::getline(std::cin, user_input);
        
        int user_number = get_user_number(user_input);
        if (user_number == -1) {
            continue;
        }
        if (user_number == hidden_number) {
            std::cout << "you win! attempts = " << attempts << std::endl;
            if (!write_to_score_board(user_name, attempts)) {
                std::cout << "Error! doesn't write score board" << '\n';
                return 1;
            }
            if (!show_score_board()) {
                std::cout << "Error! doesn't print score board" << '\n';
                return 1;
            }
            break;
        } else if(user_number < hidden_number) {
            std::cout << "greater then " << user_number << std::endl;
        } else {
            std::cout << "less then " << user_number << std::endl;
        }
        ++attempts;
    }

    return 0;
}