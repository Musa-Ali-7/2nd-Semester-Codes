#include <iostream>
#include <string>

using namespace std;

// Base class Payment
class Payment {
public:
    virtual void processPayment() = 0; 
    virtual ~Payment() {}
};

// Derived class CreditCardPayment
class CreditCardPayment : public Payment {
private:
    string cardNumber;
    string cardHolderName;
    string expiryDate;
    string cvv;

public:
    CreditCardPayment(string number, string name, string expiry, string cvv) 
        : cardNumber(number), cardHolderName(name), expiryDate(expiry), cvv(cvv) {}

    void verifyCardDetails() {
        cout << "Verifying card details for " << cardHolderName << "...\n";
        // Simulate verification steps
        cout << "Card number: " << cardNumber << "\n";
        cout << "Expiry date: " << expiryDate << "\n";
        cout << "CVV: " << cvv << "\n";
        cout << "Card details verified successfully.\n";
    }

    void processPayment() override {
        verifyCardDetails();
        cout << "Processing credit card payment...\n";
    }
};

// Derived class PayPalPayment
class PayPalPayment : public Payment {
private:
    string email;

public:
    PayPalPayment(string email) : email(email) {}

    void redirectToPayPal() {
        cout << "Redirecting to PayPal login for " << email << "...\n";
        // Simulate redirection steps
        cout << "Logged in to PayPal successfully.\n";
    }

    void processPayment() override {
        redirectToPayPal();
        cout << "Processing PayPal payment...\n";
    }
};

// Derived class BankTransferPayment
class BankTransferPayment : public Payment {
private:
    string bankAccountNumber;
    string bankName;

public:
    BankTransferPayment(string accountNumber, string bankName) 
        : bankAccountNumber(accountNumber), bankName(bankName) {}

    void interactWithBankAPI() {
        cout << "Interacting with bank API for account " << bankAccountNumber << " at " << bankName << "...\n";
        // Simulate bank interaction steps
        cout << "Bank transfer initiated successfully.\n";
    }

    void processPayment() override {
        interactWithBankAPI();
        cout << "Processing bank transfer payment...\n";
    }
};

int main() {
    Payment* payments[3];
    
    payments[0] = new CreditCardPayment("1234-5678-9012-3456", "John Doe", "12/25", "123");
    payments[1] = new PayPalPayment("johndoe@example.com");
    payments[2] = new BankTransferPayment("9876543210", "XYZ Bank");

    for (int i = 0; i < 3; ++i) {
        payments[i]->processPayment();
        cout << endl;
    }

    // Free allocated memory
    for (int i = 0; i < 3; ++i) {
        delete payments[i];
    }

    return 0;
}

