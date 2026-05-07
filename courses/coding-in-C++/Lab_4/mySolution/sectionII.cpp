#include <iostream>

constexpr double PI = 3.1415926;

class Shape {
    private:
    protected:
    public:
        virtual double computeArea() {
            return 0.0;
        }
        virtual ~Shape() {}
};

class Circle : public Shape {
    public:
        double r;
        virtual double computeArea() override {
            return PI * this->r * this->r;
        }
};

class Rectangle : public Shape {
    public:
        double a;
        double b;
        virtual double computeArea() override {
            return this->a * this->b;
        }
};

int main() {
    Circle* my_circle = new Circle();
    Rectangle* my_rectangle = new Rectangle();
    my_circle->r = 1.0;
    my_rectangle->a = 5.0;
    my_rectangle->b = 2.0;

    std::cout << "Cir.: " << my_circle->computeArea() << ", Rec.: " << my_rectangle->computeArea() << std::endl;

    Circle* my_2_circle = new Circle();
    Rectangle* my_2_rectangle = new Rectangle();
    my_2_circle->r = 2.0;
    my_2_rectangle->a = 1.0;
    my_2_rectangle->b = 2.0;

    Shape* arr[4];
    arr[0] = my_circle;
    arr[1] = my_2_circle;
    arr[2] = my_rectangle;
    arr[3] = my_2_rectangle;

    for (int i = 0; i < 4; i++)
        std::cout << "S = " << arr[i]->computeArea() << std::endl;

}