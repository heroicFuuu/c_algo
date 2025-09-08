#include <string>
using std::string;
// Dependency Inversion Principle, DIP
// 認為一個方法應該遵從「依賴於抽象而不是一個實例」[5] 的概念。
// 依賴注入是該原則的一種實現方式。
class MySQLDatabase {
public:
    void save(string data) { /* 存 MySQL */ }
};

class UserService {
    MySQLDatabase db;  //[bad]直接依賴具體實作
public:
    void addUser(string user) { db.save(user); }
};


class IDatabase {
public:
    virtual void save(string data) = 0;
    virtual ~IDatabase() = default;
};

class MySQLDatabase : public IDatabase {
public:
    void save(string data) override { /* 存 MySQL */ }
};

class UserService {
    IDatabase& db;  // [good] 依賴抽象
public:
    UserService(IDatabase& d) : db(d) {}
    void addUser(string user) { db.save(user); }
};
