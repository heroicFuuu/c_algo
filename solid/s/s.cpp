// single responsibility principle, srp
// 認為「對象應該僅具有一種單一功能」的概念。

// bad
class Report {
  public:
    void generate() { /* 產生報表 */
    }
    void print() { /* 列印報表 */
    }
};

// good
class Report {
  public:
    void generate() { /* 產生報表 */
    }
};

class Printer {
  public:
    void print(const Report& r) { /* 負責印表 */
    }
};
