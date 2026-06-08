// Description: This code demonstrates a violation of the Single Responsibility Principle (SRP) in a shopping cart system. The ShoppingCart class is responsible for managing products, calculating totals, and also has methods for printing invoices and saving to a database, which should ideally be handled by separate classes.

import java.util.ArrayList;

class Product {
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
    ArrayList<Product> products;

    public ShoppingCart(){
        this.products = new ArrayList<>();
    }

    public void addProduct(Product product){
        products.add(product);
    }
    public void removeProduct(Product product){
        products.remove(product);
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
    public void printInvoice(){
        System.out.println("Invoice");
        for(Product p: products){
            p.getDetails();
        }
        System.out.println("Total: $"+ calculateTotal());
    }
    public void saveToDatabase(){
        // Code to save cart details to database (violates SRP)
        System.out.println("Saving cart details to database...");
    }

}


public class SRP_Violated {
    public static void main(String[] args){
        Product p1= new Product("Laptop", 999.990);
        Product p2= new Product("Smartphone", 499.990);
        Product p3= new Product("Headphones", 199.990);
        ShoppingCart cart = new ShoppingCart();
        cart.addProduct(p1);
        cart.addProduct(p2);
        cart.addProduct(p3);
        double totalPrice = cart.calculateTotal();
        System.out.println("Total Price: $"+ totalPrice);
        cart.printInvoice();
        cart.saveToDatabase(); // ------------------------->This method violates the Single Responsibility Principle (SRP)
    }
}
