
// Interface Segregation Principle, ISP
// 認為「多個特定客戶端介面要好於一個寬泛用途的介面」[5] 的概念。
// class IMachine {
// public:
//     virtual void print() = 0;
//     virtual void scan() = 0;
//     virtual void fax() = 0; // ❌ 不是每台機器都有傳真
// };

class IPrinter { public: virtual void print() = 0; };
class IScanner { public: virtual void scan() = 0; };

class MultiFunctionPrinter : public IPrinter, public IScanner {
    void print() override { /* ... */ }
    void scan() override { /* ... */ }
};
