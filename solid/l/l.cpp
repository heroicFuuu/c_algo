#include <iostream>

// Liskov Substitution Principle, LSP
// 認為「程式中的對象應該是可以在不改變程式正確性的前提下被它的子類所替換的」的概念。
// 參考契約式設計。
// bad
// class Bird {
// public:
//     virtual void fly() {}
// };

// class Ostrich : public Bird {
// public:
//     void fly() override { throw "我不會飛!"; } //破壞父類別承諾,
//     這是是只說雖然實作上是正確的且符合語言規範, 但是違反設計邏輯
// };

class Bird { /* 通用鳥類 */
};

class FlyingBird : public Bird {
  public:
    virtual void fly() = 0;
};

class Sparrow : public FlyingBird {
  public:
    void fly() override {
        std::cout << "i'm sparrow , fly...." << std::endl;
    }
};

class Eagle : public FlyingBird {

    void fly() override {
        std::cout << "i'm eagle , fly...." << std::endl;
    }
};

class Ostrich : public Bird {
    // 不繼承 FlyingBird，就不會違反 LSP
};

int main() {
    Eagle eagle = Eagle();
    Sparrow sparrow = Sparrow();
    FlyingBird* fb;

    fb = &eagle;
    fb->fly();

    fb = &sparrow;
    fb->fly();

    return 0;
}
