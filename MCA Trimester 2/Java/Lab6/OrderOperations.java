package ecommerce.orders;

import ecommerce.products.ProductOperations;

public interface OrderOperations<T extends ProductOperations> {
    void createOrder(int orderId, T[] products);
    void cancelOrder(int orderId);
    double calculateTotal(T[] products);
}