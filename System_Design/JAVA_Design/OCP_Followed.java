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
abstract class DatabaseManager{
    abstract void save(ShoppingCart cart);
}
class MongoDBManager extends DatabaseManager{
    @Override
    void save(ShoppingCart cart) {
        System.out.println("Saving shopping cart to MongoDB...");
        // Code to save cart to MongoDB
    }
}
class SQLDatabaseManager extends DatabaseManager{
    @Override
    void save(ShoppingCart cart) {
        System.out.println("Saving shopping cart to SQL Database...");
        // Code to save cart to SQL Database
    }
}
class FileSystemManager extends DatabaseManager{
    @Override
    void save(ShoppingCart cart) {
        System.out.println("Saving shopping cart to File System...");
        // Code to save cart to File System
    }
}

public class OCP_Followed {
    public static void main(String[] args){
        Product p1 = new Product("Laptop", 999.99);
        Product p2 = new Product("Smartphone", 499.99);
        Product p3 = new Product("Headphones", 199.99);
        ShoppingCart cart = new ShoppingCart();
        cart.addProduct(p1);
        cart.addProduct(p2);
        cart.addProduct(p3);
        cart.viewCart();
        double total = cart.calculateTotal();
        System.out.println("Total Price: $" + total);
        InvoicePrinter printer = new InvoicePrinter();
        printer.printInvoice(cart);
        DatabaseManager dbManager = new MongoDBManager();
        DatabaseManager sqlManager = new SQLDatabaseManager();
        DatabaseManager fileManager = new FileSystemManager();
        sqlManager.save(cart);
        fileManager.save(cart);
        dbManager.save(cart);
    }
}
