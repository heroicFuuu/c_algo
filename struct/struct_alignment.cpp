#include <cstddef> // offsetof
#include <iostream>
#include <type_traits>

struct S {
    int a;
    short b;
    char c;
    char d;
    char e;
    int f;
};

struct A {
    int a;
    short b;
    int c;
    char d;
};

struct B {
    int a;
    short b;
    char c;
    int d;
};

template <typename T> void print_layout(const char* name) {
    std::cout << "==== " << name << " ====\n";
    std::cout << "sizeof(" << name << ") = " << sizeof(T) << "\n";
    std::cout << "alignof(" << name << ") = " << alignof(T) << "\n";
    std::cout << "成員偏移量 (bytes):\n";
}

int main() {
    struct S s;
    struct S* ps = &s;
    struct S* origs = ps++;

    print_layout<S>("S");
    std::cout << "  offsetof(S, a) = " << offsetof(S, a) << "\n";
    std::cout << "  offsetof(S, b) = " << offsetof(S, b) << "\n";
    std::cout << "  offsetof(S, c) = " << offsetof(S, c) << "\n";
    std::cout << "  offsetof(S, d) = " << offsetof(S, d) << "\n";
    std::cout << "  offsetof(S, e) = " << offsetof(S, e) << "\n";
    std::cout << "  offsetof(S, f) = " << offsetof(S, f) << "\n";
    std::cout << "  sizeof S(byte) = " << (char*) ps - (char*) origs << "\n\n";

    struct A a;
    struct A* pa = &a;
    struct A* origa = pa++;

    print_layout<A>("A");
    std::cout << "  offsetof(A, a) = " << offsetof(A, a) << "\n";
    std::cout << "  offsetof(A, b) = " << offsetof(A, b) << "\n";
    std::cout << "  offsetof(A, c) = " << offsetof(A, c) << "\n";
    std::cout << "  offsetof(A, d) = " << offsetof(A, d) << "\n";
    std::cout << "  sizeof A(byte) = " << (char*) pa - (char*) origa << "\n\n";

    struct B b;
    struct B* pb = &b;
    struct B* origb = pb++;

    print_layout<B>("B");
    std::cout << "  offsetof(B, a) = " << offsetof(B, a) << "\n";
    std::cout << "  offsetof(B, b) = " << offsetof(B, b) << "\n";
    std::cout << "  offsetof(B, c) = " << offsetof(B, c) << "\n";
    std::cout << "  offsetof(B, d) = " << offsetof(B, d) << "\n";
    std::cout << "  sizeof B(byte) = " << (char*) pb - (char*) origb << "\n\n";

    // 常見 ABI 下可加入一些靜態檢查（若不同平台可能需要移除或調整）
    static_assert(alignof(S) == 4, "S align 假設為 4 bytes（常見 x86_64 ABI）");
    static_assert(sizeof(S) == 16, "S 大小常見為 16 bytes");
    static_assert(sizeof(A) == 16, "A 大小常見為 16 bytes");
    static_assert(sizeof(B) == 12, "B 大小常見為 12 bytes");

    return 0;
}