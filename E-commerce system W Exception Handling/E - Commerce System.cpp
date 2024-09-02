// Write a C++ program that simulates an e-commerce system by 
//defining a Product class with attributes for product name, price, quantity, and 
//description. Implement methods to display product details and manage the 
//product quantity. Create an Order class derived from Product that includes an 
//attribute for the order quantity. Ensure the order quantity is valid and update 
//the product's available quantity accordingly, throwing exceptions for invalid 
//values. In the main function, create an instance of the Order class, display the 
//order and product details, and handle any exceptions related to invalid input 
//values
#include <iostream>
#include <stdexcept>

using namespace std;

class Product {
private:
    string productName;
    double price;
    int quantity;
    string description;

public:
    Product(string n, double p, int q, string d) : productName(n), price(p), quantity(q), description(d) {}

    string getProductName() const { return productName; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }
    string getDescription() const { return description; }

    void setQuantity(int q) { quantity = q; }

    void displayProductDetails() const {
        cout << "Product Name: " << productName << endl;
        cout << "Price: $" << price << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Description: " << description << endl;
    }
};

class Order {
private:
    Product product;
    int orderQuantity;

public:
    Order(Product p, int oq) : product(p), orderQuantity(oq) {}

    int getOrderQuantity() const { return orderQuantity; }

    void placeOrder() {
        if (orderQuantity <= 0 || orderQuantity > product.getQuantity()) {
            throw invalid_argument("Invalid order quantity");
        }
        product.setQuantity(product.getQuantity() - orderQuantity); 
    }

    void displayOrderDetails() const {
        cout << "Order Details:" << endl;
        product.displayProductDetails();
        cout << "Order Quantity: " << orderQuantity << endl;
        cout << endl;
        cout << "Product Details after Order:" << endl;
        product.displayProductDetails();
    }
};

int main() {
    try {
        Product product("Product X", 19.99, 10, "A great product");
        Order order(product, 3);
        cout << "Product Details before Order:" << endl;
        product.displayProductDetails();
        cout << endl;
        order.placeOrder();
        order.displayOrderDetails();
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
