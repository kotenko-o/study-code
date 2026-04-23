#include <string>
#include <iostream>
#include <iomanip>

constexpr char DEF_NAME[] = "New drink";

constexpr int MIN_SUGAR = 0;
constexpr int DEF_SUGAR = 0;
constexpr int MAX_SUGAR = 5;

constexpr int MIN_TEMP = 40;
constexpr int DEF_TEMP = 70;
constexpr int MAX_TEMP = 100;

constexpr bool DEF_WMILK = false;

class DrinkBuilder {
    private:
        std::string name = DEF_NAME;
        int sugar = DEF_SUGAR;
        int temperature = DEF_TEMP;
        bool withMilk = DEF_WMILK;
    public:
        DrinkBuilder& setName(const std::string& name);
        DrinkBuilder& setSugar(int sugar);
        DrinkBuilder& setTemperature(int temperature);
        DrinkBuilder& setWithMilk(bool withMilk);
        void printDrink();
        bool isValid() const;
};

int main() {
    DrinkBuilder drink;
    drink.setName("Coffee").setSugar(1).setTemperature(72).setWithMilk(false).printDrink();
    drink.setName("Tee with milk").setSugar(1).setTemperature(150).setWithMilk(true).printDrink();
    return 0;
}

DrinkBuilder& DrinkBuilder::setName(const std::string& name) {
    this->name = name;
    return *this;
}

DrinkBuilder& DrinkBuilder::setSugar(int sugar) {
    // if (sugar < MIN_SUGAR || sugar > MAX_SUGAR) {
    //     this->sugar = DEF_SUGAR;
    // } else {
        this->sugar = sugar;
    // }
    return *this;
}

DrinkBuilder& DrinkBuilder::setTemperature(int temperature) {
    // if (temperature > MAX_TEMP || temperature < MIN_TEMP) {
    //    this->temperature = DEF_TEMP;
    //} else {
        this->temperature = temperature;
    //}
    return *this;
}

DrinkBuilder& DrinkBuilder::setWithMilk(bool withMilk) {
    this->withMilk = withMilk;
    return *this;
}

void DrinkBuilder::printDrink() {
    std::cout << std::setw(15) << "Name:" << std::setw(15) << this->name << std::endl;
    std::cout << std::setw(15) << "Sugar:" << std::setw(15) << this->sugar << std::endl;
    std::cout << std::setw(15) << "Temperature:" << std::setw(15) << this->temperature << std::endl;
    std::cout << std::setw(15) << "With milk(?):" << std::setw(15) << this->withMilk << std::endl;   
    std::cout << std::setw(15) << "Valid(?):" << std::setw(15) << this->isValid() << std::endl;   
}

bool DrinkBuilder::isValid() const {
    if (this->sugar > MAX_SUGAR || this->sugar < MIN_SUGAR) {
        return false;
    }
    if (this->temperature > MAX_TEMP || this->temperature < MIN_TEMP) {
        return false;
    }
    return true;
}