// Description: This code demonstrates the violation of Open Close Principle (OCP) in a shopping cart system. The DataBaseStorage class has multiple methods for saving cart details to different types of databases (MongoDB, MySQL, File Storage), which violates the OCP as it requires modification of existing code to add support for new database types. Ideally, we should have separate classes for each database type that implement a common interface, allowing us to add new database types without modifying existing code.

import java.util.ArrayList;

class Product{
    String name;
    double price;
    public Product(String name, double price){
        this.name = name;
        this.price = price;
    }
    public void getDetails(){
        System.out.println("Product: " + name + ", Price: $" + price);
    }
}

class ShoppingCart{
    ArrayList<Product>products = new ArrayList<>();
    public void addProduct(Product product){
        products.add(product);
        System.out.println("Product added to cart: " + product.name);
    }
    public void removeProduct(Product product){
        products.remove(product);
        System.out.println("Product removed from cart: " + product.name);
    }
    public void viewCart(){
        System.out.println("Shopping Cart:");
        for(Product product : products){
            product.getDetails();
        }
    }
    public double calculateTotal(){
        double total=0d;
        for(Product p : products){
            total += p.price;
        }
        return total;
    }
}
class InvoicePrinter{
    public void printInvoice(ShoppingCart cart){
        System.out.println("Invoice:");
        for(Product p : cart.products){
            p.getDetails();
        }
        System.out.println("Total: $" + cart.calculateTotal());
    }
}
class DatabaseManager{
    public void saveToMongoDB(ShoppingCart cart){
        // Code to save cart details to MongoDB
        System.out.println("Saving cart details to MongoDB...");
    }
    public void saveToMySQL(ShoppingCart cart){
        // Code to save cart details to MySQL
        System.out.println("Saving cart details to MySQL...");
    }
    public void saveToFileSystem(ShoppingCart cart){
        // Code to save cart details to file system
        System.out.println("Saving cart details to file system...");
    }
}
public class OCP_Violated {

    public static void main(String[] args){
        Product product1 = new Product("Laptop", 999.99);
        Product product2 = new Product("Smartphone", 499.99);
        Product product3 = new Product("Headphones", 199.99);
        ShoppingCart cart = new ShoppingCart();
        cart.addProduct(product1);
        cart.addProduct(product2);
        cart.addProduct(product3);
        cart.viewCart();
        double total = cart.calculateTotal();
        System.out.println("Total Price: $" + total);
        InvoicePrinter printer = new InvoicePrinter();
        printer.printInvoice(cart);
        DatabaseManager dbManager = new DatabaseManager();
        dbManager.saveToMongoDB(cart);
        dbManager.saveToMySQL(cart);
        dbManager.saveToFileSystem(cart);
    }
}
