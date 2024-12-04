package ecommerce.products;

public class Product implements ProductOperations {
    private String name;
    private double price;

    public Product(String name, double price) {
        this.name = name;
        this.price = price;
    }

    @Override
    public void addProduct(String name, double price) {
        System.out.println("Product added: " + name + " with price $" + price);
    }

    @Override
    public void removeProduct(String name) {
        System.out.println("Product removed: " + name);
    }

    @Override
    public double calculatePrice() {
        return this.price;
    }
}