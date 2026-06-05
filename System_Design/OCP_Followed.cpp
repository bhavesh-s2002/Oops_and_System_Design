// Description: This code demonstrates the Open Close Principle (OCP) being followed in a shopping cart system. The DataBasePersistence Class is an abstract class with a pure virtual function saveToDB, which is implemented by three different classes (MongoDBPersistence, SQLDBPersistence, FileDBPersistence) for saving cart details to different types of databases. This design allows us to add new database types without modifying existing code, adhering to the OCP.

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
class DataBasePersistence{  // Abstract Class
    ShoppingCart* shoppingCart;
    public:
        virtual void saveToDB(ShoppingCart* shoppingCart)=0; // Pure Virtual Function
};

class MongoDBPersistence : public DataBasePersistence{
    public:
        void saveToDB(ShoppingCart* shoppingCart) override{
            // Code to save cart details to Mongo database
            cout <<"Saving cart details to MongoDB..."<<endl;
        }
};

class SQLDBPersistence : public DataBasePersistence{
    public:
        void saveToDB(ShoppingCart* shoppingCart) override{
            // Code to save cart details to MySQL database
            cout <<"Saving cart details to My SQL DataBase..."<<endl;
        }
};

class FileDBPersistence : public DataBasePersistence{
    public:
        void saveToDB(ShoppingCart* shoppingCart) override{
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
    DataBasePersistence* mongoDB = new MongoDBPersistence();
    DataBasePersistence* sqlDB = new SQLDBPersistence();
    DataBasePersistence* fileStorage = new FileDBPersistence();
    mongoDB->saveToDB(cart);
    sqlDB->saveToDB(cart);
    fileStorage->saveToDB(cart);

    return 0;
}