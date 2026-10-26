
#include <iostream>
#include <cmath>
using namespace std;

// Base class
class Shape {
public:
    virtual double area() = 0;
    virtual double perimeter() = 0;

    virtual ~Shape() {}
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) {
        radius = r;
    }

    double area() override {
        return 3.14159 * radius * radius;
    }

    double perimeter() override {
        return 2 * 3.14159 * radius;
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    double area() override {
        return length * width;
    }

    double perimeter() override {
        return 2 * (length + width);
    }
};

// Derived class: Triangle
class Triangle : public Shape {
private:
    double a, b, c;

public:
    Triangle(double x, double y, double z) {
        a = x;
        b = y;
        c = z;
    }

    double area() override {
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double perimeter() override {
        return a + b + c;
    }
};

int main() {
    int choice;

    cout << "SHAPE AREA AND PERIMETER CALCULATOR\n";
    cout << "1. Circle\n";
    cout << "2. Rectangle\n";
    cout << "3. Triangle\n";
    cout << "Enter your choice: ";
    cin >> choice;

    Shape* shape = nullptr;

    if (choice == 1) {
        double r;
        cout << "Enter radius: ";
        cin >> r;

        if (r <= 0) {
            cout << "Invalid radius!\n";
            return 0;
        }

        shape = new Circle(r);
    }
    else if (choice == 2) {
        double l, w;
        cout << "Enter length and width: ";
        cin >> l >> w;

        if (l <= 0 || w <= 0) {
            cout << "Invalid dimensions!\n";
            return 0;
        }

        shape = new Rectangle(l, w);
    }
    else if (choice == 3) {
        double a, b, c;
        cout << "Enter three sides: ";
        cin >> a >> b >> c;

        if (a <= 0 || b <= 0 || c <= 0 ||
            a + b <= c || a + c <= b || b + c <= a) {
            cout << "Invalid triangle sides!\n";
            return 0;
        }

        shape = new Triangle(a, b, c);
    }
    else {
        cout << "Invalid choice!\n";
        return 0;
    }

    cout << "\nArea = " << shape->area() << endl;
    cout << "Perimeter = " << shape->perimeter() << endl;

    delete shape;
    return 0;
}
