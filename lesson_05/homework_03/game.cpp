#include <iostream>
#include <format>
#include <string>
#include <fstream>
#include <filesystem>
#include <map>

// #include <limits> 
// #include <climits> 

#include "game.h"

namespace {
    std::string name_file_scores = "scores.txt";        //TODO допустимо или есть вариант лучше?
}

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
        return false;
    }
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
    return true;
}

bool check_str_in_arr(const std::string &external_str, const std::vector<std::string> &arr) {
    for (std::string str_in_arr : arr) {
        int res = external_str.compare(str_in_arr);
        if (res == 0) {
            return true;
        }
    }
    return false;
}   

bool show_score_board() {
    std::cout <<  "High scores table:" << std::endl;
    std::fstream file{name_file_scores, std::fstream::in};
    if (!file.is_open()) {
        std::cout << "Error! File was not opened!" << std::endl;
        return false;
    }
    std::string line;
    std::vector<std::string> names;
    std::map<std::string, int> track_record; 
    while (getline(file, line)) {
        std::string user_name;
        std::string attempts_str = "";
        int attempts_int;
        bool name_found = false;
        std::isalpha(line[0]);

        // проверка что Имя начинается с алфавитного символа
        if (std::isspace(line[0])) {
            return false;
        }

        for (int i = 0; i < line.size(); ++i) {
            if (!name_found) {
                if (line[i] != '\t') {
                    user_name.push_back(line[i]);
                } else {
                    name_found = true;
                }
            } else {
                if (line[i] == '\n') {
                    break;
                } else if (std::isdigit(line[i])) {
                    attempts_str.push_back(line[i]);
                } else {
                    return 1;
                }
            }
        }
        if (attempts_str != "") {
            attempts_int = std::stoi(attempts_str);
        }
        if (track_record.count(user_name)) {
            if (track_record[user_name] > attempts_int) {
                track_record[user_name] = attempts_int;
            }
        } else {
            track_record[user_name] = attempts_int;
        }
    }
    file.close();
    for (auto [name, attempts] : track_record) {
        std::cout << name << '\t' << attempts << '\n';
    }
    return true;

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
    const int MAX_NUMBER = get_arg(argc, argv);
    if (MAX_NUMBER == -1) {
        return -1;
    }
    const int MIN_NUMBER = 0;
    int hidden_number = std::rand() % MAX_NUMBER;
    std::string user_name;
    std::string user_input;
    int attempts = 1;
    std::string invaition_message = "Enter your guess in range [" + std::to_string(MIN_NUMBER) + ".." +  std::to_string(MAX_NUMBER) + "]";

    std::cout << "Hi! Enter your name, please:" << std::endl;
    std::getline (std::cin, user_name);

    std::cout << invaition_message << std::endl;

    while (true) {
        std::getline(std::cin, user_input);
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
        if (!is_number_in_range(MIN_NUMBER, user_number, MAX_NUMBER)) {
            std::cout << "Error! Number is out of range [" << MIN_NUMBER << ".." << MAX_NUMBER << "]" << std::endl;
            std::cout << invaition_message << std::endl;
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