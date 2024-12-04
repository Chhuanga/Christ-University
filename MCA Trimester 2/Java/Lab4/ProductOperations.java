package ecommerce.products;

public interface ProductOperations {
    void addProduct(String name, double price);
    void removeProduct(String name);
    double calculatePrice();
}