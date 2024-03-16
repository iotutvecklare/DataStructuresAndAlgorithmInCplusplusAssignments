#include <iostream>
#include <map>
#include <string>

class Bank {
private:
    std::map<std::string, double> accounts;

public:
    void createAccount(const std::string &accountNumber) {
        if (accounts.find(accountNumber) == accounts.end()) {
            accounts[accountNumber] = 0.0;
            std::cout << "Account created for account number: " << accountNumber << std::endl;
        } else {
            std::cout << "The account with account number " << accountNumber << " already exists." << std::endl;
        }
    }

    bool login(const std::string &accountNumber) {
        if (accounts.find(accountNumber) != accounts.end()) {
            std::cout << "Login successful. Welcome!" << std::endl;
            return true;
        } else {
            std::cout << "The account with account number " << accountNumber << " was not found." << std::endl;
            return false;
        }
    }

    void deposit(const std::string &accountNumber, double amount) {
        if (accounts.find(accountNumber) != accounts.end()) {
            accounts[accountNumber] += amount;
            std::cout << amount << " has been deposited into account number " << accountNumber << std::endl;
            std::cout << "The new balance is: " << accounts[accountNumber] << std::endl;
        } else {
            std::cout << "The account with account number " << accountNumber << " was not found." << std::endl;
        }
    }

    void withdraw(const std::string &accountNumber, double amount) {
        if (accounts.find(accountNumber) != accounts.end()) {
            if (accounts[accountNumber] >= amount) {
                accounts[accountNumber] -= amount;
                std::cout << amount << " has been withdrawn from account number " << accountNumber << std::endl;
                std::cout << "The new balance is: " << accounts[accountNumber] << std::endl;
            } else {
                std::cout << "Insufficient balance in account number " << accountNumber << std::endl;
            }
        } else {
            std::cout << "The account with account number " << accountNumber << " was not found." << std::endl;
        }
    }
};

void showMenu() {
    std::cout << "Welcome to the ATM!" << std::endl;
    std::cout << "1. Create account" << std::endl;
    std::cout << "2. Login" << std::endl;
    std::cout << "3. Deposit money" << std::endl;
    std::cout << "4. Withdraw money" << std::endl;
    std::cout << "0. Exit" << std::endl;
}

int main() {
    Bank bank;
    std::string accountNumber;
    int choice;
    double amount;

    do {
        showMenu();
        std::cout << "Select an option: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                bank.createAccount(accountNumber);
                break;
            case 2:
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                bank.login(accountNumber);
                break;
            case 3:
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                std::cout << "Enter amount to deposit: ";
                std::cin >> amount;
                bank.deposit(accountNumber, amount);
                break;
            case 4:
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                std::cout << "Enter amount to withdraw: ";
                std::cin >> amount;
                bank.withdraw(accountNumber, amount);
                break;
            case 0:
                std::cout << "Thank you for visiting. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 0);

    return 0;
}



/*
#include <iostream>
#include <map>
#include <string>

typedef std::map<std::string, double> Bank;

void createAccount(Bank &accounts, const std::string &accountNumber) {

    if (accounts.find(accountNumber) == accounts.end()) {

        accounts[accountNumber] = 0.0;
        std::cout << "Account created for account number: " << accountNumber << std::endl;
    } else {
        std::cout << "The account with account number " << accountNumber << " already exists." << std::endl;
    }
}

bool login(Bank &accounts, const std::string &accountNumber) {

    if (accounts.find(accountNumber) != accounts.end()) {
        std::cout << "Login successful. Welcome!" << std::endl;
        return true;
    } else {
        std::cout << "The account with account number " << accountNumber << " was not found." << std::endl;
        return false;
    }
}

void deposit(Bank &accounts, const std::string &accountNumber, double amount) {

    if (accounts.find(accountNumber) != accounts.end()) {

        accounts[accountNumber] += amount;
        std::cout << amount << " has been deposited into account number " << accountNumber << std::endl;
        std::cout << "The new balance is: " << accounts[accountNumber] << std::endl;
    } else {
        std::cout << "The account with account number " << accountNumber << " was not found." << std::endl;
    }
}

void withdraw(Bank &accounts, const std::string &accountNumber, double amount) {

    if (accounts.find(accountNumber) != accounts.end()) {

        if (accounts[accountNumber] >= amount) {

            accounts[accountNumber] -= amount;
            std::cout << amount << " has been withdrawn from account number " << accountNumber << std::endl;
            std::cout << "The new balance is: " << accounts[accountNumber] << std::endl;
        } else {
            std::cout << "Insufficient balance in account number " << accountNumber << std::endl;
        }
    } else {
        std::cout << "The account with account number " << accountNumber << " was not found." << std::endl;
    }
}

void showMenu() {
    std::cout << "Welcome to the ATM!" << std::endl;
    std::cout << "1. Create account" << std::endl;
    std::cout << "2. Login" << std::endl;
    std::cout << "3. Deposit money" << std::endl;
    std::cout << "4. Withdraw money" << std::endl;
    std::cout << "0. Exit" << std::endl;
}

int main() {
    Bank accounts;
    std::string accountNumber;
    int choice;
    double amount;

    do {
        showMenu();
        std::cout << "Select an option: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                createAccount(accounts, accountNumber);
                break;
            case 2:
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                login(accounts, accountNumber);
                break;
            case 3:
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                std::cout << "Enter amount to deposit: ";
                std::cin >> amount;
                deposit(accounts, accountNumber, amount);
                break;
            case 4:
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                std::cout << "Enter amount to withdraw: ";
                std::cin >> amount;
                withdraw(accounts, accountNumber, amount);
                break;
            case 0:
                std::cout << "Thank you for visiting. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 0);

    return 0;
}
*/



/*
#include <iostream>
#include <map>
#include <string>


typedef std::map<std::string, double> Bank;


void createAccount(Bank &accounts, const std::string &accountNumber) {

    if (accounts.find(accountNumber) == accounts.end()) {

        accounts[accountNumber] = 0.0;
        std::cout << "Konto skapat för kontonummer: " << accountNumber << std::endl;
    } else {
        std::cout << "Kontot med kontonummer " << accountNumber << " finns redan." << std::endl;
    }
}

// Logga in på ett befintligt konto
bool login(Bank &accounts, const std::string &accountNumber) {

    if (accounts.find(accountNumber) != accounts.end()) {
        std::cout << "Inloggning lyckades. Välkommen!" << std::endl;
        return true;
    } else {
        std::cout << "Kontot med kontonummer " << accountNumber << " hittades inte." << std::endl;
        return false;
    }
}

void deposit(Bank &accounts, const std::string &accountNumber, double amount) {

    if (accounts.find(accountNumber) != accounts.end()) {

        accounts[accountNumber] += amount;
        std::cout << amount << " har satts in på kontonummer " << accountNumber << std::endl;
        std::cout << "Det nya saldot är: " << accounts[accountNumber] << std::endl;
    } else {
        std::cout << "Kontot med kontonummer " << accountNumber << " hittades inte." << std::endl;
    }
}

// Ta ut pengar från ett konto
void withdraw(Bank &accounts, const std::string &accountNumber, double amount) {

    if (accounts.find(accountNumber) != accounts.end()) {

        if (accounts[accountNumber] >= amount) {

            accounts[accountNumber] -= amount;
            std::cout << amount << " har tagits ut från kontonummer " << accountNumber << std::endl;
            std::cout << "Det nya saldot är: " << accounts[accountNumber] << std::endl;
        } else {
            std::cout << "Otillräckligt saldo på kontonummer " << accountNumber << std::endl;
        }
    } else {
        std::cout << "Kontot med kontonummer " << accountNumber << " hittades inte." << std::endl;
    }
}


void showMenu() {
    std::cout << "Välkommen till bankomaten!" << std::endl;
    std::cout << "1. Skapa konto" << std::endl;
    std::cout << "2. Logga in" << std::endl;
    std::cout << "3. Sätt in pengar" << std::endl;
    std::cout << "4. Ta ut pengar" << std::endl;
    std::cout << "0. Avsluta" << std::endl;
}

int main() {
    Bank accounts;
    std::string accountNumber;
    int choice;
    double amount;

    do {
        showMenu();
        std::cout << "Välj ett alternativ: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Ange kontonummer: ";
                std::cin >> accountNumber;
                createAccount(accounts, accountNumber);
                break;
            case 2:
                std::cout << "Ange kontonummer: ";
                std::cin >> accountNumber;
                login(accounts, accountNumber);
                break;
            case 3:
                std::cout << "Ange kontonummer: ";
                std::cin >> accountNumber;
                std::cout << "Ange belopp att sätta in: ";
                std::cin >> amount;
                deposit(accounts, accountNumber, amount);
                break;
            case 4:
                std::cout << "Ange kontonummer: ";
                std::cin >> accountNumber;
                std::cout << "Ange belopp att ta ut: ";
                std::cin >> amount;
                withdraw(accounts, accountNumber, amount);
                break;
            case 0:
                std::cout << "Tack för besöket. Hejdå!" << std::endl;
                break;
            default:
                std::cout << "Ogiltigt val. Försök igen." << std::endl;
        }
    } while (choice != 0);

    return 0;
}
*/
