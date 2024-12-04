package ecommerce.products;

public class ElectronicProduct extends Product {
    private String brand;

    public ElectronicProduct(String name, double price, String brand) {
        super(name, price);
        this.brand = brand;
    }

    @Override
    public String getDescription() {
        return "Electronic Product: " + getName() + ", Brand: " + brand + ", Price: $" + getPrice();
    }
}