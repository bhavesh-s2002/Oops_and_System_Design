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

class ShoppingCart{
    vector<Product*> products;
    public:
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
        void printInvoice(){
            cout <<"Invoice:"<<endl;
            for(auto p : products){
                p->getDetails();
            }
            cout <<"Total: $"<<calculateTotal()<<endl;
        }
        void saveToDatabase(){
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
    cart->printInvoice();
    cart->saveToDatabase(); // ------------------------->This method violates the Single Responsibility Principle (SRP)
    return 0;
}