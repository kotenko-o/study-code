#include <iostream>
#include <string>
#include <iomanip>

constexpr int MIN_RESTOCK_AMOUNT = 1;
constexpr int MIN_SELL_AMOUNT = 1;
constexpr int MIN_STOCK = 0;

constexpr double MIN_PRICE = 0.01;
constexpr double MIN_DISCOUNT = 0.01;
constexpr double MAX_DISCOUNT = 99;

class Article {
    private:
        std::string name;
        double price;
        int stock;
        std::string &p_category;
        int id;
    public:
        Article(const std::string &name, double price, int stock, std::string &category,
                int id) : name(name), price(price), stock(stock), p_category(category), id(id) {}
        /**
         * @brief Setzt die Preis
         * @param[in]   preis       Neue preis
         */
        void setPrice(double price);
        /**
         * @brief Verkauft (Entfern) die Ware
         * @param[in]   amount      Anzehl der zu verkauften Waren
         */
        void sell(int amount);
        /**
         * @brief Hinzufügen neuen Waren
         * @param[in]   amount      Anzahl der zu hinzufügenden Waren
         */
        void restock(int amount);
        /**
         * @brief Ermitteln der Preis mit dem Rabatt
         * @param[in]   percent     Wie hoch soll Rabatt sein
         * @return      double      Preis mit Rabatt
         */
        double applyDiscount(double percent);
        /**
         * @brief getter der Price
         * @return      double  Preis
         */
        double getPrice() {
            return this->price;
        }
        /**
         * @brief Getter für Verfügbarkeit
         * @return      bool        Ist die Ware vorhanden
         */
        bool isAvailable() {
            return this->stock > 0;
        }
        /**
         * @brief   Gibt die Info über Ware aus
         */
        void printInfo();
};

double Article::applyDiscount(double percent) {
    if (percent < MIN_DISCOUNT ||
        percent > MAX_DISCOUNT) {
            return this->price;
        }
    return this->price - this->price * percent / 100;
}

void Article::setPrice(double price) {
    if (price < MIN_PRICE) {
        return;
    }
    this->price = price;
}

void Article::sell(int amount) {
    if (amount < MIN_SELL_AMOUNT ||
        this->stock - amount < MIN_STOCK) {
        return;
    }
    this->stock -= amount;
    return;
}

void Article::restock(int amount) {
    if (amount < MIN_RESTOCK_AMOUNT) {
        return;
    }
    this->stock += amount;
    return;
}

void Article::printInfo() {
    std::cout << "Article: " << name << std::endl;
    std::cout << "Category: " << p_category << std::endl;
    std::cout << "Price: " << price << std::endl;
    std::cout << "Stock: " << stock << std::endl;
    std::cout << "ID: " << id << std::endl;
}

int main() {
    std::string electro = "Electronics";
    Article a = Article("Laptop", 999.99, 10, electro, 101);

    a.printInfo();
    a.sell(15);
    a.restock(-5);
    a.setPrice(-100);
    a.applyDiscount(150);

    if (a.isAvailable()) std::cout << "Article available" << std::endl;

    a.printInfo();
    return 0;
}