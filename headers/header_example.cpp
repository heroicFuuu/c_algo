// cheatsheet.cpp
#include <iostream>
using namespace std;

// ---------------- Containers ----------------
#include <vector>
void demo_vector() {
    vector<int> v = {1, 2, 3};
    v.push_back(4);
    cout << "vector back: " << v.back() << endl;
}

#include <deque>
void demo_deque() {
    deque<int> dq = {1, 2};
    dq.push_front(0);
    dq.push_back(3);
    cout << "deque front: " << dq.front() << endl;
}

#include <list>
void demo_list() {
    list<int> l = {1, 2, 3};
    l.push_back(4);
    cout << "list back: " << l.back() << endl;
}

#include <set>
void demo_set() {
    set<int> s = {3, 1, 2};
    cout << "set smallest: " << *s.begin() << endl;
}

#include <unordered_set>
void demo_unordered_set() {
    unordered_set<int> us = {1, 2, 3};
    cout << "unordered_set size: " << us.size() << endl;
}

#include <map>
void demo_map() {
    map<int, string> mp;
    mp[1] = "one";
    auto it = mp.upper_bound(0); // 找到第一個 key > 0
    if (it != mp.end())
        cout << "map key: " << it->first << endl;
    auto it2 = prev(it, 1); // std::prev 來自 <iterator>
    cout << "map prev: " << it2->first << endl;
}

#include <unordered_map>
void demo_unordered_map() {
    unordered_map<string, int> ump;
    ump["apple"] = 3;
    cout << "unordered_map[apple]: " << ump["apple"] << endl;
}

#include <queue>
void demo_queue() {
    queue<int> q;
    q.push(1);
    q.push(2);
    cout << "queue front: " << q.front() << endl;
}

#include <queue> // 同一個 header 有 priority_queue
void demo_priority_queue() {
    priority_queue<int> pq;
    pq.push(3);
    pq.push(1);
    pq.push(2);
    cout << "priority_queue top: " << pq.top() << endl;
}

#include <stack>
void demo_stack() {
    stack<int> st;
    st.push(10);
    cout << "stack top: " << st.top() << endl;
}

#include <utility> // for pair
void demo_pair() {
    pair<int, string> p = {1, "one"};
    cout << "pair: " << p.first << " " << p.second << endl;
}

// ---------------- Algorithms ----------------
#include <algorithm>
void demo_algorithm() {
    vector<int> v = {3, 1, 2};
    sort(v.begin(), v.end());
    cout << "sorted: " << v[0] << " " << v[1] << " " << v[2] << endl;
    auto it = lower_bound(v.begin(), v.end(), 2);
    cout << "lower_bound(2): " << *it << endl;
}

#include <numeric>
void demo_numeric() {
    vector<int> v = {1, 2, 3, 4};
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << "accumulate: " << sum << endl;
}

// ---------------- Strings ----------------
#include <string>
void demo_string() {
    string s = "123";
    int x = stoi(s); // string to int
    cout << "stoi: " << x << endl;
}

#include <sstream>
void demo_sstream() {
    stringstream ss("10 20 30");
    int a, b, c;
    ss >> a >> b >> c;
    cout << "stringstream: " << a + b + c << endl;
}

#include <cctype>
void demo_cctype() {
    char c1 = 'a';
    char c2 = 'Z';
    cout << (char) toupper(c1) << endl; // A
    cout << (char) tolower(c2) << endl; // z
}

void demo_check() {
    char c1 = 'a', c2 = '9', c3 = ' ';
    cout << isalpha(c1) << endl; // 1 (是字母)
    cout << isdigit(c2) << endl; // 1 (是數字)
    cout << isalnum(c2) << endl; // 1 (數字也是字母數字組)
    cout << isspace(c3) << endl; // 1 (空白符號)
}

// ---------------- Others ----------------
#include <tuple>
void demo_tuple() {
    tuple<int, string, double> t = {1, "hi", 3.14};
    cout << "tuple get<1>: " << get<1>(t) << endl;
}

#include <bitset>
void demo_bitset() {
    bitset<8> b(42);
    cout << "bitset: " << b << endl;
}

#include <functional>
void demo_functional() {
    function<int(int, int)> f = [](int a, int b) { return a + b; };
    cout << "function: " << f(2, 3) << endl;
}

#include <memory>
void demo_memory() {
    unique_ptr<int> p = make_unique<int>(42);
    cout << "unique_ptr: " << *p << endl;
}

#include <iterator> // for std::prev, std::next
void demo_iterator() {
    vector<int> v = {1, 2, 3};
    auto it = next(v.begin()); // 指向第二個元素
    cout << "iterator next: " << *it << endl;
}

int main() {
    demo_vector();
    demo_deque();
    demo_list();
    demo_set();
    demo_unordered_set();
    demo_map();
    demo_unordered_map();
    demo_queue();
    demo_priority_queue();
    demo_stack();
    demo_pair();
    demo_algorithm();
    demo_numeric();
    demo_string();
    demo_sstream();
    demo_cctype();
    demo_tuple();
    demo_bitset();
    demo_functional();
    demo_memory();
    demo_iterator();
    return 0;
}
