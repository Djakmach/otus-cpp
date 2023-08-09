#include <iostream>
#include <string>
#include <vector>

#include "utils.h"


int is_valid_int(const std::string &str) {   
  try {
    int number = std::stoi(str);
    return number;
  } catch (std::exception &e) {
    return -1;
  }
}

bool is_number(const std::string &str) {   
  for (char ch : str) {
    if (!std::isdigit(ch)) {
      return false;
    }
  }
  return true;
}

bool is_number_in_range(const int MIN_NUMBER, const int user_number, const int MAX_NUMBER) {
    if (user_number < MIN_NUMBER || user_number > MAX_NUMBER) {
        return false;
    }
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