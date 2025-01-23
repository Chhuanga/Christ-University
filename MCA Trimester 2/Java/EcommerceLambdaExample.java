import java.util.Scanner;
import java.util.function.Consumer;
import java.util.function.Function;
import java.util.function.Predicate;
import java.util.function.Supplier;

import ecommerce.Order;

public class EcommerceLambdaExample {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Order order = new Order("Laptop", 150000); // Price in rupees

        while (true) {
            System.out.println("\nMenu:");
            System.out.println("1. Print Order Details");
            System.out.println("2. Calculate Discount");
            System.out.println("3. Check Free Shipping Eligibility");
            System.out.println("4. Generate Order ID");
            System.out.println("5. Exit");
            System.out.print("Choose an option: ");
            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    Consumer<Order> printOrder = o -> System.out
                            .println("Order: " + o.getProductName() + ", Price: ₹" + o.getPrice());
                    printOrder.accept(order);
                    break;
                case 2:
                    Function<Order, Double> calculateDiscount = o -> o.getPrice() * 0.10;
                    double discount = calculateDiscount.apply(order);
                    System.out.println("Discount: ₹" + discount);
                    break;
                case 3:
                    Predicate<Order> isEligibleForFreeShipping = o -> o.getPrice() > 10000;
                    boolean eligibleForFreeShipping = isEligibleForFreeShipping.test(order);
                    System.out.println("Eligible for free shipping: " + eligibleForFreeShipping);
                    break;
                case 4:
                    Supplier<String> generateOrderId = () -> "ORD" + System.currentTimeMillis();
                    String orderId = generateOrderId.get();
                    System.out.println("Generated Order ID: " + orderId);
                    break;
                case 5:
                    System.out.println("Exiting...");
                    scanner.close();
                    return;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }
}

class Order {
    private String productName;
    private double price;

    public Order(String productName, double price) {
        this.productName = productName;
        this.price = price;
    }

    public String getProductName() {
        return productName;
    }

    public double getPrice() {
        return price;
    }
}