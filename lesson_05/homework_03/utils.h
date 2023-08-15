#pragma once

#include <string>
#include <vector>


int is_valid_int(const std::string &str);

bool is_number(const std::string &str);

bool is_number_in_range(const int MIN_NUMBER, const int user_number, const int MAX_NUMBER);

bool check_str_in_arr(const std::string &external_str, const std::vector<std::string> &arr);