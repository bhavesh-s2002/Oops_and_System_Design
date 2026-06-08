// Description: This code demonstrates the Single Responsibility Principle (SRP) being followed in a shopping cart system. The ShoppingCart class is responsible for managing products and calculating totals. While there is separate class for printing Invoice and Saving to Database which make sure that each class handles only single main function.

#include <bits/stdc++.h>
using namespace std;

class Product{
    public:
        string name;
        double price;
        Product(string n, double p){
            name = n; price = p;
        }
        void getDetails(){
            cout <<"Product: "<<name<<", Price: $"<<price<<endl;
        }
};

class ShoppingCart{     //---------------------------> Single Class Single method
    public:
    vector<Product*> products;
        void addProduct(Product* p){
            products.push_back(p);
            cout <<"Added "<<p->name<<" to cart."<<endl;
        }
        void removeProduct(Product* p){
            products.erase(remove(products.begin(), products.end(), p), products.end());
            cout <<"Removed "<<p->name<<" from cart."<<endl;
        }
        void viewCart(){
            cout <<"Shopping Cart:"<<endl;
            for(auto p : products){
                p->getDetails();
            }
        }
        double calculateTotal(){
            double total = 0;
            for(auto p : products){
                total += p->price;
            }
            return total;
        }
};
class InvoicePrinter{
    ShoppingCart* shoppingCart;
    public:
        void printInvoice(ShoppingCart* shoppingCart){
            cout <<"Invoice:"<<endl;
            for(auto p : shoppingCart->products){
                p->getDetails();
            }
            cout <<"Total: $"<<shoppingCart->calculateTotal()<<endl;
        }
};
class DataBaseStorage{
    ShoppingCart* shoppingCart;
    public:
        void saveToDatabase(ShoppingCart* shoppingCart){
            // Code to save cart details to database (violates SRP)
            cout <<"Saving cart details to database..."<<endl;
        }
};

int main(){
    Product* p1 = new Product("Laptop", 999.99);
    Product* p2 = new Product("Smartphone", 499.99);
    Product* p3 = new Product("Headphones", 199.99);
    ShoppingCart* cart = new ShoppingCart();
    cart->addProduct(p1);
    cart->addProduct(p2);
    cart->addProduct(p3);
    cart->viewCart();
    double totalPrice= cart->calculateTotal();
    cout<<"Total Price: $"<<totalPrice<<endl;
    InvoicePrinter* printer = new InvoicePrinter();
    printer->printInvoice(cart);
    DataBaseStorage* dbStorage = new DataBaseStorage();
    dbStorage->saveToDatabase(cart);

    return 0;
}