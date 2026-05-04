#include <iostream>
#include <cmath>

class Vector2D {
    private:
        double x;
        double y;
    public:
        /**
         * @brief       Konstruktor mit default Werten
         */
        Vector2D() : x(0.0), y(0.0) {};
        /**
         * @brief       Parametrizierter Konstruktor
         * @param[in]   x       Die X-Koordinate
         * @param[in]   Y       Die Y-Koordinate
         */
        Vector2D(double x, double y) : x(x), y(y) {};
        /**
         * @brief       Getter der X-Koordinate
         * @return      double      Wert der X
         */
        double getX() {
            return this->x;
        }
        /**
         * @brief       Getter der Y-Koordinate
         * @return      double      Wert der Y
         */
        double getY() {
            return this->y;
        }
        /**
         * @brief       Gibt den Wert des Vektors aus
         */
        void printVector() {
            std::cout << "Coordinates: (" << x << ", " << y << ")" << std::endl;
        }
        /**
         * @brief       Berechnet die exakte Länge des Vektors
         * @return      double      Die Länge des Vektors
         */
        double getLength() {
            return sqrt(this->x * this->x + this->y * this->y);
        }
        
        /**
         * @brief       Berechnet die gerundete Länge des Vektors
         * @param[in]   precision   Anzahl der Nachkomastellen
         * @return      double      Die gerundete Länge des Vektors
         */
        double getLength(int precision) {
            double factor = std::pow(10.0, precision);
            return std::round(this->getLength() * factor) / factor;
        }
};

int main() {
    Vector2D vec1 = Vector2D();
    Vector2D vec2 = Vector2D(4.0, 4.0);
    vec1.printVector();
    vec2.printVector();
    std::cout << vec2.getLength() << std::endl;
    std::cout << vec2.getLength(2) << std::endl;
    return 0;
}