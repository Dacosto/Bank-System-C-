#include <iostream>
#include <string>

class BankAccount
{
private:
    std::string name;
    double balance;

public:
    BankAccount(std::string accountName, double initialBalance)
        : name(accountName), balance(initialBalance) {}

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
        }
    }

    void withdraw(double amount)
    {
        
        if (amount <= balance)
        {
            balance -= amount;
        }
        else
        {
            std::cout << "Insufficient funds." << std::endl;
        }
    }
    void tax(double amount)
    {
        int tax = 5000;
        if (balance > tax)
        {
            balance -= amount;
        }

    }

    void display()
    {
        std::cout << "Account: " << name << "\nBalance: $" << balance << std::endl;
    }
};

int main()
{
    int k = 0;
    int tax = 5000;
    std::string name;
    double initialDeposit;

    std::cout << "Enter your name: ";
    getline(std::cin, name);
    std::cout << "Enter initial deposit: ";
    std::cin >> initialDeposit;

    BankAccount account(name, initialDeposit);

    int choice;
    double amount;

    do
    {
        std::cout << "\n1. Deposit" << std::endl;
        std::cout << "2. Withdraw" << std::endl;
        std::cout << "3. Display Account" << std::endl;
        std::cout << "4. Taxes" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Enter deposit amount: ";
            std::cin >> amount;
            account.deposit(amount);
            break;
        case 2:
            std::cout << "Enter withdrawal amount: ";
            std::cin >> amount;
            account.withdraw(amount);
            break;
        case 3:
            account.display();
            break;
        case 4:
            std::cout << "Click Enter to pay the taxes!: ";
            
            while (k != 13)
            
            {
                k = _getwch();
            }
            account.tax(tax);
            break;
        case 5:
            break;
        default:
            std::cout << "Invalid choice." << std::endl;
        }
    } while (choice != 5);

    return 0;
}