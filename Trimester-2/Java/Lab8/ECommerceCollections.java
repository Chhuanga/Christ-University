import java.util.ArrayList;
import java.util.HashSet;
import java.util.HashMap;
import java.util.LinkedList;

public class ECommerceCollections {

    public static void main(String[] args) {
        // ArrayList to store product names
        ArrayList<String> productList = new ArrayList<>();
        productList.add("Laptop");
        productList.add("Smartphone");
        productList.add("Tablet");
        System.out.println("Product List: " + productList);

        // HashSet to store unique customer IDs
        HashSet<Integer> customerIDs = new HashSet<>();
        customerIDs.add(101);
        customerIDs.add(102);
        customerIDs.add(103);
        customerIDs.add(101); // Duplicate, will not be added
        System.out.println("Customer IDs: " + customerIDs);

        // HashMap to store product prices in INR
        HashMap<String, Double> productPrices = new HashMap<>();
        productPrices.put("Laptop", 75000.00);
        productPrices.put("Smartphone", 20000.00);
        productPrices.put("Tablet", 15000.00);
        System.out.println("Product Prices (INR): " + productPrices);

        // LinkedList to store order history
        LinkedList<String> orderHistory = new LinkedList<>();
        orderHistory.add("Order1: Laptop");
        orderHistory.add("Order2: Smartphone");
        orderHistory.add("Order3: Tablet");
        System.out.println("Order History: " + orderHistory);

        // Iterate over collections
        System.out.println("\nIterating over Product List:");
        for (String product : productList) {
            System.out.println(product);
        }

        System.out.println("\nIterating over Customer IDs:");
        for (Integer id : customerIDs) {
            System.out.println(id);
        }

        System.out.println("\nIterating over Product Prices (INR):");
        for (String product : productPrices.keySet()) {
            System.out.println(product + ": ₹" + productPrices.get(product));
        }

        System.out.println("\nIterating over Order History:");
        for (String order : orderHistory) {
            System.out.println(order);
        }
    }
}