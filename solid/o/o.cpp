// open closed principle 
// 認為「軟體應該是對於擴充開放的，但是對於修改封閉的」的概念。

class Shape {
public:
    enum Type { Circle, Square } type;
    double radius, side;
};
// bad
double area(const Shape& s) {
    if (s.type == Shape::Circle) return 3.14 * s.radius * s.radius;
    if (s.type == Shape::Square) return s.side * s.side;
    return 0; // ❌ 每新增一種形狀都要改這裡
}

// good
// class Shape {
// public:
//     virtual double area() const = 0;
//     virtual ~Shape() = default;
// };

// class Circle : public Shape {
//     double radius;
// public:
//     Circle(double r) : radius(r) {}
//     double area() const override { return 3.14 * radius * radius; }
// };

// class Square : public Shape {
//     double side;
// public:
//     Square(double s) : side(s) {}
//     double area() const override { return side * side; }
// };
