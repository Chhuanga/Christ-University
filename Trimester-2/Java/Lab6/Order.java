package ecommerce.orders;

import ecommerce.products.ProductOperations;

public class Order<T extends ProductOperations> implements OrderOperations<T> {
    private int orderId;
    private T[] products;

    @Override
    public void createOrder(int orderId, T[] products) {
        this.orderId = orderId;
        this.products = products;
        System.out.println("Order created with ID: " + orderId);
    }

    @Override
    public void cancelOrder(int orderId) {
        System.out.println("Order cancelled with ID: " + orderId);
    }

    @Override
    public double calculateTotal(T[] products) {
        double total = 0;
        for (T product : products) {
            total += product.calculatePrice();
        }
        return total;
    }
}