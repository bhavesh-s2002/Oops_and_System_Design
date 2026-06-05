// Description: This code demonstrates the violation of Open Close Principle (OCP) in a shopping cart system. The DataBaseStorage class has multiple methods for saving cart details to different types of databases (MongoDB, MySQL, File Storage), which violates the OCP as it requires modification of existing code to add support for new database types. Ideally, we should have separate classes for each database type that implement a common interface, allowing us to add new database types without modifying existing code.

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
class DataBaseStorage{ //-----------------> Modifying the code in the class to fit the requirements. (Violates OCP)
    ShoppingCart* shoppingCart;
    public:
        void saveToMongoDB(ShoppingCart* shoppingCart){
            // Code to save cart details to Mongo database
            cout <<"Saving cart details to MongoDB..."<<endl;
        }
        void saveToMySQL(ShoppingCart* shoppingCart){
            // Code to save cart details to MySQL database
            cout <<"Saving cart details to My SQL DataBase..."<<endl;
        }
        void saveToFileStorage(ShoppingCart* shoppingCart){
            // Code to save cart details to File Storage System
            cout <<"Saving cart details to File Storage System..."<<endl;
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
    dbStorage->saveToMongoDB(cart);
    dbStorage->saveToMySQL(cart);
    dbStorage->saveToFileStorage(cart);

    return 0;
}