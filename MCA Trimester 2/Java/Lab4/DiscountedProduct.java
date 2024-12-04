package ecommerce.products;

public class DiscountedProduct extends Product implements DiscountOperations {
    private double discountRate;

    public DiscountedProduct(String name, double price, double discountRate) {
        super(name, price);
        this.discountRate = discountRate;
    }

    @Override
    public void applyDiscount(double discountRate) {
        this.discountRate = discountRate;
        System.out.println("Discount applied: " + discountRate + "%");
    }

    @Override
    public double calculateDiscount() {
        return calculatePrice() * (discountRate / 100);
    }

    @Override
    public double calculatePrice() {
        return super.calculatePrice() - calculateDiscount();
    }
}