#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;
//creating global variables to store maximum size of orders, products and customers
const int m_orders = 100;
const int m_products = 100;
const int m_customers = 100;
//creating class of product
class Product 
{
public:
    char name[50];
    double price;
    bool availability;
    //default comstructor
    Product()
    {
        strcpy(name, "");
        price = 0.0;
        availability = false;
    }
    //function to add product
    void AddProduct(const char* prodName, double prodPrice, bool isAvailable) 
    {
        strcpy(name, prodName);
        price = prodPrice;
        availability = isAvailable;
    }
    //function to update the availability of product
    void UpdateAvailability(bool isAvailable) 
    {
        availability = isAvailable;
    }
};
//creating class of order
class Order 
{
public:
    int orderID;
    char date[20];
    Product products[m_products];
    int productQuantities[m_products];
    int productCount;
    //default constructor
    Order() 
    {
        orderID = 0;
        strcpy(date, "");
        productCount = 0;
    }
    //function to add order
    void AddOrder(int id, const char* orderDate) 
    {
        orderID = id;
        strcpy(date, orderDate);
    }
    //function to add product to the specific order
    void AddProductToOrder(const Product& product, int quantity) 
    {
        if (productCount < m_products) 
        {
            products[productCount] = product;
            productQuantities[productCount] = quantity;
            productCount++;
        }
    }
    //function to calculte total price of the products
    double CalculateTotal()
    {
        double total = 0.0;
        for (int i = 0; i < productCount; i++) 
        {
            if (products[i].availability) 
            {
                total += products[i].price * productQuantities[i];
            }
        }
        return total;
    }
    //function to display order details
    void ViewOrderDetails() 
    {
        cout << "Order ID: " << orderID << ", Date: " << date << endl;
        for (int i = 0; i < productCount; i++)
        {
            cout << "Product: " << products[i].name << ", Quantity: " << productQuantities[i] << ", Price: $" << products[i].price << endl;
        }
        cout << "Total Cost: $" << CalculateTotal() << endl;
    }
};
//creating class of customer
class Customer
{
public:
    char name[50];
    char address[100];
    Order orders[m_orders];
    int orderCount;
    //default constructor
    Customer()
    {
        strcpy(name, "");
        strcpy(address, "");
        orderCount = 0;
    }
    //function to add customer 
    void AddCustomer(const char* custName, const char* custAddress) 
    {
        strcpy(name, custName);
        strcpy(address, custAddress);
    }
    //function to place order
    void PlaceOrder(Order& order)
    {
        if (orderCount < m_orders) 
        {
            orders[orderCount++] = order;
        }
    }
    //function to display details of order
    void ViewOrders() 
    {
        cout << "Customer: " << name << ", Address: " << address << endl;
        for (int i = 0; i < orderCount; i++) 
        {
            orders[i].ViewOrderDetails();
        }
    }
};

int main() 
{
    Customer customer;
    customer.AddCustomer("Abdullah Aj", "154 Milaad Street");
    Product p1, p2;
    p1.AddProduct("Mobile", 10000.00, true);
    p2.AddProduct("Headphone", 90.00, true);
    Order order;
    order.AddOrder(1, "2024-03-31");
    order.AddProductToOrder(p1, 1);
    order.AddProductToOrder(p2, 2);
    customer.PlaceOrder(order);
    customer.ViewOrders();
    return 0;
}
