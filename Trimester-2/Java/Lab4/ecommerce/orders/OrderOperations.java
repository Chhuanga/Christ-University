package ecommerce.orders;

import ecommerce.products.Product;

public interface OrderOperations {
    void createOrder(int orderId, Product[] products);

    void cancelOrder(int orderId);

    double calculateTotal(Product[] products);
}