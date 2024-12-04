
// Interface Maintenance
interface Maintenance {
    void performMaintenance();
}

// Interface CropManagement
interface CropManagement {
    void manageCrop(String cropType);
}

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


public class Main {
    public static void main(String[] args) {

        Tractor myTractor = new Tractor("TractorTool", "Agricultural", "Diesel");
        myTractor.setToolName("John Deere Tractor");
        System.out.println("Tool Name: " + myTractor.getToolName());

        myTractor.manageCrop("Wheat");

        myTractor.performMaintenance();
    }
}