package ecommerce.products;

public class ClothingProduct extends Product {
    private String size;

    public ClothingProduct(String name, double price, String size) {
        super(name, price);
        this.size = size;
    }

    @Override
    public String getDescription() {
        return "Clothing Product: " + getName() + ", Size: " + size + ", Price: $" + getPrice();
    }
}