package ecommerce.orders;

import ecommerce.products.Product;

public class Order implements OrderOperations {
    private int orderId;
    private Product[] products;

    @Override
    public void createOrder(int orderId, Product[] products) {
        this.orderId = orderId;
        this.products = products;
        System.out.println("Order created with ID: " + orderId);
    }

    @Override
    public void cancelOrder(int orderId) {
        System.out.println("Order cancelled with ID: " + orderId);
    }

    @Override
    public double calculateTotal(Product[] products) {
        double total = 0;
        for (Product product : products) {
            total += product.calculatePrice();
        }
        return total;
    }
}