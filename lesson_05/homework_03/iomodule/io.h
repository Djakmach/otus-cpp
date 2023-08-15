#pragma once

#include <string>


bool write_to_score_board(const std::string &user_name, int attempts, const std::string& name_file_scores);

bool show_score_board(const std::string& name_file_scores);