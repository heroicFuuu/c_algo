#include "utilis.h"

void print_vector_elements(vector<int>& arr) {
    int size = arr.size();
    if (size == 0) {
        std::cout << "0 elements" << std::endl;
        return;
    }

    for (int i = 0; i < size - 1; ++i)
        std::cout << arr[i] << ", ";

    std::cout << arr[size - 1] << std::endl;
};

vector<int> generate_random_vector(int size, int min_val, int max_val) {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min_val, max_val);

    vector<int> v = vector<int>(size);
    for (int i = 0; i < size; i++) {
        v[i] = dis(gen);
    }
    return v;
};