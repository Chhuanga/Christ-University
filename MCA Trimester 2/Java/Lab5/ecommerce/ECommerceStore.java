
// ECommerceStore.java
import java.util.Scanner;

import ecommerce.products.Product;

class Product {
    private String name;
    private int stock;

    public Product(String name, int stock) {
        this.name = name;
        this.stock = stock;
    }

    public synchronized void buyProduct() {
        if (stock > 0) {

            System.out.println(Thread.currentThread().getName() + " bought 1 " + name);
            stock--;
        } else {
            System.out.println(Thread.currentThread().getName() + " tried to buy " + name + " but it's out of stock.");
        }
    }

    public void showStock() {
        System.out.println(name + " stock: " + stock);
    }
}

class Customer extends Thread {
    private Product product;

    public Customer(Product product) {
        this.product = product;
    }

    public void run() {
        try {
            Thread.sleep(200);
            product.buyProduct();

        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

public class ECommerceStore extends Thread {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Product product = new Product("Laptop", 5);

        while (true) {

            System.out.println("1. Buy Product");
            System.out.println("2. Show Stock");
            System.out.println("3. Exit");
            System.out.print("Enter your choice: ");
            int choice = scanner.nextInt();

            switch (choice) {
                case 1:

                    for (int i = 0; i < 5; i++) {
                        new Customer(product).start();
                        try {
                            Thread.sleep(1000);
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                    }

                    break;
                case 2:
                    product.showStock();
                    break;
                case 3:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }
}