#include <string>
#include <iostream>
#include <iomanip>

constexpr int MIN_NAME_LENGTH = 3;
constexpr int MAX_NAME_LENGTH = 30;

constexpr double MIN_DEPOSIT = 0;

constexpr double MIN_WITHRAW = 1;
constexpr double MIN_STAND = 0;

class BankAccount {
    private:
        std::string owner;
        double balance;
        bool isNameValid(const std::string &name);
    public:
        /**
         * @brief Setter für die Name des Owners
         * @param[in]   name        Name des Owners
         * @return      int         0 - OK,
         *                          1 - Fehler, Name nicht gesetzt
         */
        int setOwner(const std::string &name);
        /**
         * @brief Gibt den Owner zurueck
         */
        std::string getOwner() {
            return this->owner;
        }
        /**
         * @brief Bearbeitet Einzahlung aufs Konto
         * @param[in]   amount      zu einzahlender Beitrag
         * @return      int         0 - OK,
         *                          1 - einzahlung zu klein
         */
        int deposit(double amount);
        /**
         * @brief Bearbeitet Auszahlung vom Konto
         * @param[in]   amount      zu auszahlender Beitrag
         * @return      int         0 - OK,
         *                          1 - auszahlung zu klein
         *                          2 - zu kleiner Restbetrag
         */
        int withdraw(double amount);
        /**
         * @brief Funktion, um Balance zu bekommen
         * @return  double      Aktueller stand
         */
        double getBalace();
        /**
         * @brief Konsolausgabe der Info über Konto
         */
        void getAccountInfo();
};

int main() {
    BankAccount myAccount;
    myAccount.setOwner("Pupkin Zalupkin");

    myAccount.getAccountInfo();

    myAccount.deposit(1234.12);

    myAccount.getAccountInfo();

    myAccount.withdraw(99999);
    myAccount.getAccountInfo();

    myAccount.withdraw(20);

    myAccount.getAccountInfo();
    return 0;
}

/**
 * @brief Hilfsfunktion, um die Formelle Korrektheit der Name zu überprüfen
 * @param[in]   name        Name des Owners
 */
bool BankAccount::isNameValid(const std::string &name) {
    if (name.length() < MIN_NAME_LENGTH || name.length() > MAX_NAME_LENGTH) {
        return false;
    }
    return true;
}

int BankAccount::setOwner(const std::string &name) {
    if (isNameValid(name)) {
        this->owner = name;
        return 0;
    }
    return 1;
}

int BankAccount::deposit(double amount) {
    if (amount < MIN_DEPOSIT) {
        return 1;
    }
    this->balance += amount;
    return 0;
}

int BankAccount::withdraw(double amount) {
    if (amount < MIN_WITHRAW) {
        return 1;
    }
    if (this->balance - amount < MIN_STAND) {
        return 2;
    }
    this->balance -= amount;
    return 0;
}

double BankAccount::getBalace() {
            return this->balance;
        }

void BankAccount::getAccountInfo() {
    std::cout << "Name: " << std::setw(MAX_NAME_LENGTH) << this->owner << " | Balance: " << this->balance << std::endl;
}