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

        /**
         * @brief       Setter für X-Koordinate
         * @param[in]   x       Neue X-Koordinate
         */
        void setX(double x) {
            this->x = x;
        }

        /**
         * @brief       Setter für Y-Koordinate
         * @param[in]   y       Neue Y-Koordinate
         */
        void setY(double y) {
            this->y = y;
        }

        /**
         * @brief       Addition von einem anderen Vector zu diesem
         * @param[in]   v2      Der andere Vektor
         */
        void operator+=(Vector2D &v2) {
            this->x += v2.getX();
            this->y += v2.getY();
        }

        /**
         * @brief       Addition zweier Vektoren
         * @param[in]   v2      Der "rechte" Vektor
         * @return              Ref. auf die Summen-Vektor    
         */
        Vector2D operator+(Vector2D &v2) {
            return Vector2D(this->getX() + v2.getX(), this->getY() + v2.getY());
        }
};

int main() {
    Vector2D vec1 = Vector2D();
    Vector2D vec2 = Vector2D(4.0, 4.0);
    
    std::cout << "Vec1: ";
    vec1.printVector();
    std::cout << "Vec2: ";
    vec2.printVector();

    vec1.setX(-1);
    vec1.setY(3);
    std::cout << "Neue Vec1: ";
    vec1.printVector();

    std::cout << "Laenge Vec2 (Standard + Prec. 2): ";
    std::cout << vec2.getLength() << ", " << vec2.getLength(2) << std::endl;

    
    std::cout << "Vec2 += Vec1: ";
    vec2 += vec1;
    vec2.printVector();

    std::cout << "Vec2 + Vec1: ";
    (vec2 + vec1).printVector();

    return 0;
}