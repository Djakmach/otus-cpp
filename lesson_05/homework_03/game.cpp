#include <iostream>
#include <format>
#include <string>
#include <fstream>
#include <filesystem>

// #include <limits> 
// #include <climits> 

#include "game.h"


std::string name_file_scores = "scores.txt";

bool is_number(const std::string &str) {   
    for (char ch : str) {
        if (!std::isdigit(ch)) {
            return false;
        }
    }
    return true;
}

bool is_valid_int(const std::string &str) {   
    try {
        int number = std::stoi(str);
    } catch (std::exception &e) {
        return false;
    }
    return true;
}

bool is_number_in_range(const int MIN_NUMBER, const int user_number, const int MAX_NUMBER) {
    if (user_number < MIN_NUMBER || user_number > MAX_NUMBER) {
        // std::cout << "is_number_in_range: true" << '\n';
        return false;
    }
    // std::cout << "is_number_in_range: false" << '\n';
    return true;
    
}

bool write_to_score_board(const std::string &user_name, const int attempts) {
	std::fstream file{name_file_scores, std::fstream::app};
    if (!file.is_open()) {
        std::cout << "Error! File was not opened!" << std::endl;
		return false;
    }
    file << user_name << '\t' << attempts << std::endl;
    file.close();
}

void show_score_board() {
    std::cout <<  "High scores table:" << std::endl;
    std::fstream file{name_file_scores, std::fstream::in};
    if (!file.is_open()) {
        std::cout << "Error! File was not opened!" << std::endl;
        return;
    }
    std::string line;
    while (getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
}

int get_arg(int argc, char* argv[]) {
    // std::cout << "argc " << argc << '\n';
    // std::cout << "argv_0 " << argv[0] << '\n';
    // std::cout << "argv_1 " << argv[1] << '\n';
    // std::cout << "argv_2 " << argv[2] << '\n';


    if (argc == 1) {

        int default_max_number = 100;
        return default_max_number;
    std::cout << "true " << '\n';
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
    // TODO не обработанная ветка
    } else {
        std::cout << "5 " << '\n';

        std::cout << "Error! Invakid command.\n";
        return -1;
    }
}

int main(int argc, char *argv[]) {
    std::srand(time(NULL));
    const int MAX_NUMBER = get_arg(argc, argv);
    if (MAX_NUMBER == -1) {
        return -1;
    }
        std::cout << "MAX_NUMBER = " << MAX_NUMBER << '\n';
    const int MIN_NUMBER = 0;
    int hidden_number = std::rand() % MAX_NUMBER;
    std::string user_name;
    std::string user_input;
    int attempts = 1;
    std::string invaition_message = "Enter your guess in range [" + std::to_string(MIN_NUMBER) + ".." +  std::to_string(MAX_NUMBER) + "]";

    // std::cout << "Hidden_number " << hidden_number << std::endl;
    std::cout << "Hi! Enter your name, please:" << std::endl;
    std::getline (std::cin, user_name);

    std::cout << invaition_message << std::endl;

    while (true) {
        std::getline(std::cin, user_input);
        
        std::cerr << "is_string_number " << is_number(user_input) << '\n';
        std::cerr << "is_valid_int " << is_valid_int(user_input) << '\n';
        
        if (!is_number(user_input)) {
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cout << "Error! String is not numeric" << "\n";
            std::cout << invaition_message << std::endl;
            continue;
        }
        if (!is_valid_int(user_input)) {
            std::cout << "Error! Number is too long" << "\n";
            std::cout << invaition_message << std::endl;
            continue;
        }
        int user_number = std::stoi(user_input);
        std::cerr << "is_number_in_range " << is_number_in_range(MIN_NUMBER, user_number, MAX_NUMBER) << '\n';
        if (!is_number_in_range(MIN_NUMBER, user_number, MAX_NUMBER)) {
            std::cout << "Error! Number is out of range [" << MIN_NUMBER << ".." << MAX_NUMBER << "]" << std::endl;
            std::cout << invaition_message << std::endl;
            continue;
        }
        
        if (user_number == hidden_number) {
            std::cout << "you win! attempts = " << attempts << std::endl;
            write_to_score_board(user_name, attempts);

            show_score_board();
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