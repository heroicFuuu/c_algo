#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using P = std::pair<int, int>;
using std::vector;

bool readVec(vector<vector<P>>& tests_vec, const std::string& path, std::string& err_msg);

int test_vec();