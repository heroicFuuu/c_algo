#include "readVec.h"

bool readVec(vector<vector<P>>& tests_vec, const std::string& path, std::string& err_msg) {

    tests_vec.clear();

    std::ifstream fin(path);
    if (!fin) {
        std::cerr << "檔案開啟失敗\n";
        return false;
    }

    // std::vector<std::vector<P>> tests_vec;
    std::string line;
    size_t lines_no = 0;

    while (std::getline(fin, line)) {
        ++lines_no;

        // 跳過空行
        if (line.find_first_not_of(" \t\r\n") == std::string::npos)
            continue;

        // 先保留原字串以便報錯訊息
        std::string raw = line;

        // 把 { } , 換成空白方便解析
        for (char& ch : line) {
            if (ch == '{' || ch == '}' || ch == ',')
                ch = ' ';
        }

        std::istringstream iss(line);
        std::vector<P> vec;
        int a, b;
        int token_cnt = 0;

        while (true) {

            if (!(iss >> a)) {
                if (iss.eof())
                    break;
                err_msg = "[error]line number " + std::to_string(lines_no) + " : " + raw + "\n";
                return false;
            }
            ++token_cnt;
            if (!(iss >> b)) {
                err_msg = "[error]line number " + std::to_string(lines_no) + " : " + raw + "\n";
                return false;
            }
            ++token_cnt;

            vec.emplace_back(a, b);
        }
        if (token_cnt == 0) {
            err_msg =
                "第 " + std::to_string(lines_no) + " 行：未解析到任何數字。原始行：[" + raw + "]";
            return false;
        }

        tests_vec.push_back(std::move(vec));
    }

    // 測試輸出

    return true;
}

int test_vec() {

    vector<vector<P>> tests_vec;
    std::string err_msg;
    if (!readVec(tests_vec, "./direction.txt", err_msg)) {
        std::cerr << err_msg;
        exit(1);
    }

    std::cout << "Read data from direction.txt" << std::endl;
    for (size_t i = 0; i < tests_vec.size(); ++i) {
        std::cout << "Test " << (i + 1) << ": ";
        for (auto& p : tests_vec[i]) {
            std::cout << "{" << p.first << "," << p.second << "} ";
        }
        std::cout << "\n";
    }
    return 0;
}