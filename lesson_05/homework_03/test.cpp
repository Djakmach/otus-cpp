#include <iostream>
#include <format>
#include <string>
#include <fstream>
#include <filesystem>
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

void show_score_board() {
    std::cout <<  "High scores table:" << std::endl;
    std::fstream file{name_file_scores, std::fstream::in};
    if (!file.is_open()) {
        std::cout << "Error! File was not opened!" << std::endl;
        return;
    }
    std::string line;
    std::vector<std::string> names;
    std::map<std::string, int> scores; 
    while (getline(file, line)) {
        std::string user_name;
        for (int i; i < line.size(); ++i) {
            char ch = line[i];
            if (ch != '\t') {
                user_name.push_back(ch);
            }
            // std::cout << line[i+1] << '\n';
        }
        bool res = check_str_in_arr(user_name, names);
        if (!res) {
            names.push_back(user_name);
        }
    }
    for (std::string name : names) {
        std::cout << name << '\n';
    }
    file.close();
}


int main(int argc, char** argv) {
    show_score_board();
    
}

