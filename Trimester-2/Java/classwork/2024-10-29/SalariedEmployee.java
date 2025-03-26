// Abstract class Tool
abstract public class Tool {
    private String toolName;

    protected void setToolName(String name) {
        this.toolName = name;
    }

    public String getToolName() {
        return this.toolName;
    }
}

// Interface Maintenance
interface Maintenance {
    void performMaintenance();
}

// Interface CropManagement
interface CropManagement {
    void manageCrop(String cropType);
}

// Class Machine extends Tool and implements Maintenance
class Machine extends Tool implements Maintenance {
    private String machineType;

    public Machine(String toolName, String machineType) {
        setToolName(toolName);
        this.machineType = machineType;
    }

    @Override
    public void performMaintenance() {
        System.out.println("Performing maintenance on the machine.");
    }

    public String getMachineType() {
        return this.machineType;
    }
}

// Class Tractor extends Machine and implements CropManagement
class Tractor extends Machine implements CropManagement {
    private String fuelType;

    public Tractor(String toolName, String machineType, String fuelType) {
        super(toolName, machineType);
        this.fuelType = fuelType;
    }

    @Override
    public void manageCrop(String cropType) {
        System.out.println("Managing crop: " + cropType + " using the tractor.");
    }

    public String getFuelType() {
        return this.fuelType;
    }
}

// Main class to test the program
public class Main {
    public static void main(String[] args) {
        // Create an instance of the Tractor class
        Tractor myTractor = new Tractor("TractorTool", "Agricultural", "Diesel");

        // Set the tool name using the setToolName method
        myTractor.setToolName("John Deere Tractor");

        // Print the tool name
        System.out.println("Tool Name: " + myTractor.getToolName());

        // Manage a crop ("Wheat") using the tractor
        myTractor.manageCrop("Wheat");

        // Call the performMaintenance method for the tractor
        myTractor.performMaintenance();
    }
}