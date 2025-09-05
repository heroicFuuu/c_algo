#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

using P = std::pair<int,int>;
using std::vector;


bool readVec(vector<vector<P>>& tests_vec,const std::string& path, std::string& err_msg);

int test_vec();