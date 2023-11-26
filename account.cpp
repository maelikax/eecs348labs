#include <iostream>
#include <string>
#include <iomanip>

class Account {
    private:
        std::string accountNumber;
        std::string accountHolder;
        double balance;
    
    public:
        Account(const std::string& number, const std::string& holder, double startBalance) : accountNumber(number), accountHolder(holder), balance(startBalance) {}

        virtual ~Account() {}

        void displayDetails() const {
            std::cout << std::fixed << std::setprecision(2);
            std::cout << *this;
            displayAdditional();
            std::cout << std::endl;
        }

        virtual std::string getType() const {
            return "Generic";
        }

        virtual void displayAdditional() const {}

        void deposit(double amount) {
            balance += amount;
        }

        virtual void withdraw(double amount) {
            if (balance >= amount) {
                balance -= amount;
            } else {
                std::cout << "Insufficient funds." << std::endl;
            }
        }

        std::string getAccountNumber() const {
            return accountNumber;
        }

        std::string getAccountHolder() const {
            return accountHolder;
        }

        double getBalance() const {
            return balance;
        }

        friend std::ostream& operator<<(std::ostream& os, const Account& account);
};

class SavingsAccount : public Account {
    private:
        double interestRate;

    public:
        SavingsAccount(const std::string& number, const std::string& holder, double startBalance, double rate) : Account(number, holder, startBalance), interestRate(rate) {}

        std::string getType() const override {
            return "Savings Account";
        }

        void withdraw(double amount) override{
            const double minimumBalance = 100;
            if (getBalance() - amount >= minimumBalance) {
                Account::withdraw(amount);
            } else {
                std::cout << "Withdrawal failed."<< std::endl;
            }
        }

        void displayAdditional() const override {
            std::cout << "\tInterest Rate: " << interestRate * 100 << "%" << std::endl;
        }

        friend std::ostream& operator<<(std::ostream& os, const SavingsAccount& account);
};

class CurrentAccount : public Account {
    private:
        double overdraftLimit;
    public:
        CurrentAccount(const std::string& number, const std::string& holder, double startBalance, double limit) : Account(number, holder, startBalance), overdraftLimit(limit) {}

        std::string getType() const override {
            return "Current Account";
        }

        void withdraw(double amount) override {
            if (getBalance() + overdraftLimit >= amount) {
                Account::withdraw(amount);
            } else {
                std::cout << "Withdrawal failed." << std::endl;
            }
        }

        void displayAdditional() const override {
            std::cout << "\tOverdraft Limit: $" << overdraftLimit << std::endl;
        }

        friend std::ostream& operator<<(std::ostream& os, const CurrentAccount& account);
};

std::ostream& operator<<(std::ostream& os, const Account& account) {
    os << std:: fixed << std::setprecision(2);
    os << "Account Details for " << account.getType() << " (ID: " << account.getAccountNumber() << "):" << std::endl;
    os << "\tHolder: " << account.getAccountHolder() << std::endl;
    os << "\tBalance: $" << account.getBalance() << std::endl;
    return os;
}

std::ostream& operator<<(std::ostream& os, const SavingsAccount& account) {
    os << static_cast<const Account&>(account);
    account.displayAdditional();
    return os;
}

std:: ostream& operator <<(std::ostream&os, const CurrentAccount& account) {
    os << static_cast<const Account&>(account);
    account.displayAdditional();
    return os;
}

CurrentAccount operator+(CurrentAccount& current, SavingsAccount& savings) {
    double transfer = 300;

    if (savings.getBalance() >= transfer) {
        savings.withdraw(transfer);
        current.deposit(transfer);
    }
    return current;
}

int main() {
    SavingsAccount savings("S123", "John Doe", 1000, 0.02);
    CurrentAccount current("C456", "Jane Doe", 2000, 500);

    savings.displayDetails();
    current.displayDetails();

    savings.deposit(500);
    current.withdraw(1000);

    savings.displayDetails();
    current.displayDetails();

    // transfer 300 from savings to current
    current = current + savings;
    
    savings.displayDetails();
    current.displayDetails();

    return 0;
}