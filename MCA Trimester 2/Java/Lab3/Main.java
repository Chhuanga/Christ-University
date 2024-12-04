import ecommerce.products.*;
import ecommerce.utils.*;

public class Main {
    public static void main(String[] args) {
        // Create ElectronicProduct
        ElectronicProduct laptop = new ElectronicProduct("Laptop", 1200.00, "Dell");
        System.out.println(laptop.getDescription());

        // Create ClothingProduct
        ClothingProduct tshirt = new ClothingProduct("T-Shirt", 20.00, "M");
        System.out.println(tshirt.getDescription());

        // Use StringClass
        StringClass stringClass = new StringClass("Product: ");
        stringClass.append("Laptop").append(", Brand: Dell");
        System.out.println("StringClass: " + stringClass);

        // Use StringBufferClass
        StringBufferClass stringBufferClass = new StringBufferClass();
        stringBufferClass.append("Product: ").append("T-Shirt").append(", Size: M");
        System.out.println("StringBufferClass: " + stringBufferClass);
    }
}