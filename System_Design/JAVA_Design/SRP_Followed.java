// Description: This code demonstrates the Single Responsibility Principle (SRP) being followed in a shopping cart system. The ShoppingCart class is responsible for managing products and calculating totals. While there is separate class for printing Invoice and Saving to Database which make sure that each class handles only single main function.

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
    public void saveCartDetails(ShoppingCart cart){
        // Code to save cart details to database
        System.out.println("Saving cart details to database...");
    }
}

public class SRP_Followed {
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
        dbManager.saveCartDetails(cart);
    }
}
