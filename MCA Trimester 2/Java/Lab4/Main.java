import ecommerce.products.*;
import ecommerce.orders.*;
import ecommerce.utils.Utility;

public class Main {
    public static void main(String[] args) {
       
        Product product1 = new Product("Laptop", 1000);
        Product product2 = new Product("Phone", 500);
        DiscountedProduct discountedProduct = new DiscountedProduct("Tablet", 300, 10);

   
        product1.addProduct("Laptop", 1000);
        product2.addProduct("Phone", 500);
        discountedProduct.addProduct("Tablet", 300);

        
        discountedProduct.applyDiscount(10);

        
        Product[] products = {product1, product2, discountedProduct};
        Order order = new Order();
        order.createOrder(1, products);

        double total = order.calculateTotal(products);
        Utility.printMessage("Total Order Price: $" + total);
        order.cancelOrder(1);
    }
}