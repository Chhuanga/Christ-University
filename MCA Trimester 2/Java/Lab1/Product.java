public class ShoeStore {
    private String name;
    private int numShoes;
    private double totalRevenue;
    private int numEmployees;
    private boolean hasOnlineStore;

    public ShoeStore() {
        this.name = "Unnamed Shoe Store";
        this.numShoes = 0;
        this.totalRevenue = 0.0;
        this.numEmployees = 0;
        this.hasOnlineStore = false;
        System.out.println("Default Constructor:");
        displayInfo();
    }

    public ShoeStore(String name, int numShoes, double totalRevenue) {
        this.name = name;
        this.numShoes = numShoes;
        this.totalRevenue = totalRevenue;
        this.numEmployees = 0;
        this.hasOnlineStore = false;
    }

    public ShoeStore(String name, int numShoes, double totalRevenue, int numEmployees, boolean hasOnlineStore) {
        this.name = name;
        this.numShoes = numShoes;
        this.totalRevenue = totalRevenue;
        this.numEmployees = numEmployees;
        this.hasOnlineStore = hasOnlineStore;
    }

    public void displayInfo() {
        System.out.println("Store Name: " + name);
        System.out.println("Number of Shoes: " + numShoes);
        System.out.println("Total Revenue: $" + totalRevenue);
        System.out.println("Number of Employees: " + numEmployees);
        System.out.println("Online Store: " + (hasOnlineStore ? "Yes" : "No"));
        System.out.println();
    }

    public double calculateProfit(double costPerShoe) {
        return totalRevenue - (numShoes * costPerShoe);
    }

    public double calculateProfit(double costPerShoe, double operatingCosts) {
        return totalRevenue - (numShoes * costPerShoe) - operatingCosts;
    }

    public void addShoes(int quantity) {
        numShoes += quantity;
    }

    public void addShoes(int quantity, double price) {
        numShoes += quantity;
        totalRevenue += quantity * price;
    }

    public static void main(String[] args) {
        ShoeStore defaultStore = new ShoeStore();

        ShoeStore myShoeStore = new ShoeStore("Fancy Footwear", 500, 75000.0);
        System.out.println("Parameterized Constructor:");
        myShoeStore.displayInfo();

        ShoeStore onlineStore = new ShoeStore("Sneaker Heaven", 2000, 300000.0, 15, true);
        System.out.println("Fully Parameterized Constructor:");
        onlineStore.displayInfo();

        System.out.println("Profit Calculation:");
        System.out.println("Profit (considering only shoe cost): $" + myShoeStore.calculateProfit(50.0));
        System.out.println("Profit (considering shoe cost and operating costs): $" + myShoeStore.calculateProfit(50.0, 20000.0));

        System.out.println("\nAdding Shoes:");
        myShoeStore.addShoes(100);
        myShoeStore.displayInfo();

        myShoeStore.addShoes(50, 100.0);
        myShoeStore.displayInfo();
    }
}