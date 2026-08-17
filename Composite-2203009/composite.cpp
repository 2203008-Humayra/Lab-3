#include <iostream>
#include <vector>
using namespace std;

// Component
class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() {}
};

// Leaf
class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle\n";
    }
};

// Leaf
class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing Rectangle\n";
    }
};

// Composite
class ShapeGroup : public Shape {
private:
    vector<Shape*> shapes;

public:
    void add(Shape* shape) {
        shapes.push_back(shape);
    }

    void draw() override {
        for (Shape* shape : shapes) {
            shape->draw();
        }
    }
};

// Client
int main() {

    Circle circle;
    Rectangle rectangle;

    ShapeGroup group;

    group.add(&circle);
    group.add(&rectangle);

    group.draw();

    return 0;
}
