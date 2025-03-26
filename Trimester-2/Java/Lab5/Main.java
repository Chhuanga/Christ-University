import ecommerce.products.*;
import ecommerce.orders.*;
import ecommerce.orders.Order;

public class Main {
    public static void main(String[] args) {
        // Create products
        Product laptop = new Product("Laptop", 1200.00);
        Product phone = new Product("Phone", 800.00);

        // Add products
        laptop.addProduct("Laptop", 1200.00);
        phone.addProduct("Phone", 800.00);

        // Create order
        Product[] products = { laptop, phone };
        Order<Product> order = new Order<>();
        order.createOrder(1, products);

        // Calculate total
        double total = order.calculateTotal(products);
        System.out.println("Total Order Price: $" + total);

        // Cancel order
        order.cancelOrder(1);
    }
}