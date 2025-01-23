package ecommerce.products;

public interface DiscountOperations extends ProductOperations {
    void applyDiscount(double discountRate);
    double calculateDiscount();
}