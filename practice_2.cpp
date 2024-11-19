#include <iostream>
using namespace std;

class Rectangle {
    private:
        double length, breadth;
    public:
        Rectangle() {
            length = 0;
            breadth = 0;
        }
        Rectangle(double l, double b) {
            this->length = l;
            this->breadth = b;
        }
        
        double calculateArea() {
            return length * breadth;
        }
};

class Triangle {
    private:
        double side1, side2, side3;
    public:
        Triangle() {
            side1 = 0;
            side2 = 0;
            side3 = 0;
        }

        Triangle(double a, double b, double c) {
            this->side1 = a;
            this->side2 = b;
            this->side3 = c;
        }
        
        double calculatePerimeter() {
            return side1 + side2 + side3;
        }
};

int main() {
    Rectangle R1(5.0, 4.0);
    cout << "Area of the Rectangle: " << R1.calculateArea() << endl;

    Triangle T1(3.0, 4.0, 5.0);
    cout << "Perimeter of the Triangle: " << T1.calculatePerimeter() << endl;

    return 0;
}
