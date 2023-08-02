#include <iostream>
// #include <format>
#include <string>
#include <fstream>
// #include <filesystem>
#include <vector>
#include <map>


std::string name_file_scores = "scores.txt";

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
}


int main(int argc, char** argv) {
    if (!show_score_board())
        std::cout << "Error! doesn't print score board" << '\n';
        return 1;
    
}

