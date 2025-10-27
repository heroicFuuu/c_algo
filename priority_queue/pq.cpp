#include "readVec.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using std::priority_queue;
using std::vector;
// using P = std::pair<int,int>;

std::ostream& operator<<(std::ostream& os, const P& p) {
    return os << "{" << p.first << ", " << p.second << "} ";
}

void printVec(const vector<int>& v) {
    for (auto e : v)
        std::cout << e << " ";
    std::cout << "\n";
    return;
}

void printDirect(const vector<P>& v) {
    for (auto e : v)
        std::cout << e;
    std::cout << "\n";
    return;
}

template <typename T, typename Container, typename Compare>
void printHeap(priority_queue<T, Container, Compare>& heap) {
    while (!heap.empty()) {

        std::cout << heap.top() << " ";
        heap.pop();
    }
    std::cout << "\n";
    return;
}
void printSep() {
    for (int i = 0; i < 50; i++)
        std::cout << "#";
    std::cout << std::endl;
}
int main(int argc, char** argv) {

    std::vector<std::vector<int>> tests_int = {
        {1, 2, 3, 9, 8, 7, 6, 5, 4}, // 測試1
        {5, 4, 3, 2, 1},             // 測試2
        {10, 1, 9, 2, 8, 3, 7},      // 測試3
        {42},                        // 測試4 (單元素)
        {2, 2, 2, 1, 1, 3},          // 測試5 (含重複)
        {100, -5, 0, 50, -10}        // 測試6 (含負數)
    };
    // comp(a, b)
    // true -> 第一個參數優先
    //優先就是排序後結果中位置比較靠左的地方

    for (int i = 0; i < tests_int.size(); i++) {
        std::cout << "Test " << (i + 1) << " 原始: ";
        printVec(tests_int[i]);
    }

    printSep();

    for (int i = 0; i < tests_int.size(); i++) {
        std::cout << "Test " << (i + 1) << " comp : default - ";
        sort(tests_int[i].begin(), tests_int[i].end(), std::less<int>());
        printVec(tests_int[i]);
    }
    printSep();

    // 用 less()
    for (int i = 0; i < tests_int.size(); i++) {
        std::cout << "Test " << (i + 1) << " comp : less() - ";
        sort(tests_int[i].begin(), tests_int[i].end(), std::less<int>());
        printVec(tests_int[i]);
    }

    printSep();

    // greater
    for (int i = 0; i < tests_int.size(); i++) {
        std::cout << "Test " << (i + 1) << " comp : greater - ";
        sort(tests_int[i].begin(), tests_int[i].end(), std::greater<int>());
        printVec(tests_int[i]);
    }

    /// priority queue
    printSep();
    // comp(a, b)
    // true -> 第二個參數優先
    // heap中是預設maxHeap

    for (int i = 0; i < tests_int.size(); i++) {
        std::cout << "Test " << (i + 1) << " maxHeap : std::less<int> - ";
        priority_queue<int, vector<int>, std::less<int>> maxHeap(tests_int[i].begin(),
                                                                 tests_int[i].end());
        printHeap(maxHeap);
    }

    printSep();

    for (int i = 0; i < tests_int.size(); i++) {
        std::cout << "Test " << (i + 1) << " minHeap : std::greater<int> - ";
        priority_queue<int, vector<int>, std::greater<int>> minHeap(tests_int[i].begin(),
                                                                    tests_int[i].end());
        printHeap(minHeap);
    }

    printSep();

    vector<vector<P>> tests_vec;
    std::string err_msg;
    if (!readVec(tests_vec, "./direction.txt", err_msg)) {
        std::cerr << err_msg;
        exit(1);
    }

    // define compare func
    auto comp_less = [](const P& a, const P& b) {
        double dist_a = std::sqrt(a.first * a.first + a.second * a.second);
        double dist_b = std::sqrt(b.first * b.first + b.second * b.second);
        return dist_a < dist_b;
    };

    auto comp_greater = [](const P& a, const P& b) {
        double dist_a = std::sqrt(a.first * a.first + a.second * a.second);
        double dist_b = std::sqrt(b.first * b.first + b.second * b.second);
        return dist_a > dist_b;
    };

    printSep();
    // 由小到大
    for (int i = 0; i < tests_vec.size(); i++) {
        std::cout << "[vector] Test " << (i + 1) << " comp_less - ";
        sort(tests_vec[i].begin(), tests_vec[i].end(), comp_less);
        printDirect(tests_vec[i]);
    }
    printSep();
    for (int i = 0; i < tests_vec.size(); i++) {
        std::cout << "[vector] Test " << (i + 1) << " comp_greater - ";
        sort(tests_vec[i].begin(), tests_vec[i].end(), comp_greater);
        printDirect(tests_vec[i]);
    }
    printSep();
    // 由大到小
    for (int i = 0; i < tests_vec.size(); i++) {
        std::cout << "[heap  ] Test " << (i + 1) << " comp_less - ";

        priority_queue<P, vector<P>, decltype(comp_less)> pq(tests_vec[i].begin(),
                                                             tests_vec[i].end(), comp_less);
        printHeap(pq);
    }
    printSep();
    // 由小到大
    for (int i = 0; i < tests_vec.size(); i++) {
        std::cout << "[heap  ] Test " << (i + 1) << " comp_greater - ";

        priority_queue<P, vector<P>, decltype(comp_greater)> pq(tests_vec[i].begin(),
                                                                tests_vec[i].end(), comp_greater);
        printHeap(pq);
    }

    return 0;
}