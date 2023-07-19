#include <iostream>
#include <format>
#include <string>
#include <fstream>
#include <filesystem>

// #include <limits> 
// #include <climits> 

#include "game.h"


bool is_string_has_spaces(const std::string &str) {   
    for (char ch : str) {
        if (ch == ' ') {
            return true;
        }
    }
    return false;
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

bool write_to_score_board(const std::string &name_file_scores, const std::string &user_name, const int attempts) {
	std::fstream file{name_file_scores, std::fstream::app};
    if (!file.is_open()) {
        std::cout << "Error! File was not opened!" << std::endl;
		return false;
    }
    file << user_name << '\t' << attempts << std::endl;
    file.close();
}

void show_score_board(const std::string &name_file_scores) {
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

int get_arg(int argc, char *argv[]) {
    // std::cout << "argc " << argc << '\n';
    // std::cout << "argv_0 " << argv[0] << '\n';
    // std::cout << "argv_1 " << argv[1] << '\n';
    // std::cout << "argv_2 " << argv[2] << '\n';

    if (argc == 1) {
        int default_max_number = 100;
        return default_max_number;
    std::cout << "true " << '\n';
    }

    if (argc == 3) {
        std::cout << "true " << '\n';
        std::string key{argv[1]};
        if (key == "--max") {
            int max_number = std::stoi(argv[2]);
            std::cout << max_number << '\n';
            return max_number;
        }
    // TODO не обработанная ветка
    }
}

int main(int argc, char *argv[]) {
    std::srand(time(NULL));
    // const int MAX_NUMBER = get_arg(argc, argv);
    std::cout << "MAX_NUMBER = " << get_arg(argc, argv) << '\n';
    const int MIN_NUMBER = 0;
    const int MAX_NUMBER = 100;
    int hidden_number = std::rand() % MAX_NUMBER;
    std::string user_name;
    std::string user_input;
    int attempts = 1;
    std::string file_scores = "scores.txt";
    std::string invaition_message = "Enter your guess in range [" + std::to_string(MIN_NUMBER) + ".." +  std::to_string(MAX_NUMBER) + "]";

    // std::cout << "Hidden_number " << hidden_number << std::endl;
    std::cout << "Hi! Enter your name, please:" << std::endl;
    std::getline (std::cin, user_name);

    std::cout << invaition_message << std::endl;

    while (true) {
        std::getline(std::cin, user_input);
        
        std::cerr << "is_string_has_spaces " << is_string_has_spaces(user_input) << '\n';
        std::cerr << "is_valid_int " << is_valid_int(user_input) << '\n';

        if (!is_valid_int(user_input)) {
            std::cout << "Error! Invalid input" << "\n";
            std::cout << invaition_message << std::endl;
            continue;
        }
        if (is_string_has_spaces(user_input)) {
            std::cout << "Error! String contain spaces" << "\n";
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
            write_to_score_board(file_scores, user_name, attempts);

            std::cout <<  "High scores table:" << std::endl;
            show_score_board(file_scores);
            break;
        } else if(user_number < hidden_number) {
            std::cout << "greater than " << user_number << std::endl;
        } else {
            std::cout << "less than " << user_number << std::endl;
        }
        ++attempts;
    }

    return 0;
}