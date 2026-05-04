#include <iostream>

constexpr double PI = 3.1415926;

class GeometricShape {
    private:
    public:
        virtual double getArea() const {
            return 0.0;
        }
        virtual ~GeometricShape() = 0;
};

GeometricShape::~GeometricShape() {
            std::cout << "Shape destroyed" << std::endl;
}

class Circle : public GeometricShape {
    private:
        double r;
    public:
        Circle(double r) : r(r) {}
        double getArea() const override {
            return PI * this->r * this->r;
        }
        ~Circle() {
            std::cout << "Circle destroyed" << std::endl;
        }
};  


class Rectangle : public GeometricShape {
    private:
        double len_x;
        double len_y;
    public:
        Rectangle(double len_x, double len_y) : len_x(len_x), len_y(len_y) {}
        double getArea() const override {
            return this->len_x * this->len_y;
        }
        ~Rectangle() {
            std::cout << "Rectangle destroyed" << std::endl;
        }
};

int main() {
    GeometricShape* my_shapes[4];
    my_shapes[0] = new Circle(1);
    my_shapes[1] = new Circle(5);
    my_shapes[2] = new Rectangle(1, 2);
    my_shapes[3] = new Rectangle(3, 4);
    for (int i = 0; i < 4; i++)
        std::cout << my_shapes[i]->getArea() << std::endl;
}