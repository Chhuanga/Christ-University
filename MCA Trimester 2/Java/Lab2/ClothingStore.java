// Base class for all clothing items
class Item {
    private String name;
    private double price;
    private String brand;

    public Item(String name, double price, String brand) {
        this.name = name;
        this.price = price;
        this.brand = brand;
    }

    public String getName() {
        return name;
    }

    public double getPrice() {
        return price;
    }

    public void printItem() {
        System.out.println(brand + " " + name + ": $" + price);
    }
}

// Class for Clothing items with size and color options
class Clothing extends Item {
    private String size;
    private String color;
    private String[] customizations;
    private int maxCustomizations;
    private double basePrice;

    public Clothing(String name, String size, String color, double basePrice, String brand) {
        super(name, basePrice, brand);
        this.size = size;
        this.color = color;
        this.customizations = new String[3];  // max 3 customizations
        this.maxCustomizations = 3;
        this.basePrice = basePrice;
    }

    public void addCustomization(String customization, double price) {
        for (int i = 0; i < maxCustomizations; i++) {
            if (customizations[i] == null) {
                customizations[i] = customization;
                System.out.println("Added " + customization + " for an extra $" + price);
                break;
            }
        }
    }

    @Override
    public void printItem() {
        super.printItem();
        System.out.println(" - Size: " + size);
        System.out.println(" - Color: " + color);
        for (String customization : customizations) {
            if (customization != null) {
                System.out.println(" + " + customization);
            }
        }
    }
}

// LuxuryItem class for premium clothing items
class LuxuryItem extends Clothing {
    public LuxuryItem(String name, String size, String color, String brand) {
        super(name, size, color, 999.99, brand);
    }

    @Override
    public void addCustomization(String customization, double price) {
        System.out.println("Luxury items cannot be customized.");
    }
}

// Accessory class for items like belts, jewelry, etc.
class Accessory extends Item {
    private String material;

    public Accessory(String name, String material, double price, String brand) {
        super(name, price, brand);
        this.material = material;
    }

    @Override
    public void printItem() {
        super.printItem();
        System.out.println(" - Material: " + material);
    }
}

// Shoes class with specific shoe attributes
class Shoes extends Item {
    private String size;
    private String style;

    public Shoes(String name, String size, String style, double price, String brand) {
        super(name, price, brand);
        this.size = size;
        this.style = style;
    }

    @Override
    public void printItem() {
        super.printItem();
        System.out.println(" - Size: " + size);
        System.out.println(" - Style: " + style);
    }
}

// ShoppingCart class that combines multiple items
class ShoppingCart {
    private Clothing mainItem;
    private Accessory accessory;
    private Shoes shoes;

    public ShoppingCart() {
        this.mainItem = new Clothing("T-Shirt", "M", "Black", 29.99, "BrandX");
        this.accessory = new Accessory("Belt", "Leather", 49.99, "BrandX");
        this.shoes = new Shoes("Sneakers", "42", "Casual", 89.99, "BrandX");
    }

    public ShoppingCart(Clothing mainItem, Accessory accessory, Shoes shoes) {
        this.mainItem = mainItem;
        this.accessory = accessory;
        this.shoes = shoes;
    }

    public void addCustomization(String customization, double price) {
        this.mainItem.addCustomization(customization, price);
    }

    public void printOrder() {
        System.out.println("Your shopping cart contains:");
        mainItem.printItem();
        accessory.printItem();
        shoes.printItem();
        double total = mainItem.getPrice() + accessory.getPrice() + shoes.getPrice();
        System.out.println("Subtotal: $" + total);
        System.out.println("Tax (8%): $" + (total * 0.08));
        System.out.println("Total: $" + (total * 1.08));
    }
}

public class ClothingStore {
    public static void main(String[] args) {
        // Default Shopping Cart
        ShoppingCart defaultCart = new ShoppingCart();
        defaultCart.printOrder();

        System.out.println("\n--- Custom Order ---\n");

        // Custom Shopping Cart
        Clothing customShirt = new Clothing("Polo Shirt", "L", "Navy", 79.99, "BrandX");
        Accessory customWatch = new Accessory("Watch", "Stainless Steel", 199.99, "BrandX");
        Shoes customShoes = new Shoes("Oxford", "43", "Formal", 159.99, "BrandX");
        ShoppingCart customCart = new ShoppingCart(customShirt, customWatch, customShoes);

        customCart.addCustomization("Monogram", 15.00);
        customCart.addCustomization("Special Buttons", 10.00);
        customCart.printOrder();

        System.out.println("\n--- Luxury Order ---\n");

        // Luxury Shopping Cart
        LuxuryItem luxurySuit = new LuxuryItem("Designer Suit", "M", "Charcoal", "LuxuryBrand");
        ShoppingCart luxuryCart = new ShoppingCart(luxurySuit, 
            new Accessory("Silk Tie", "Silk", 299.99, "LuxuryBrand"),
            new Shoes("Italian Leather Shoes", "42", "Formal", 599.99, "LuxuryBrand"));
        luxuryCart.printOrder();
    }
}

