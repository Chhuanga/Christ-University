// Worker Class
public class Worker {
    protected String name;
    protected String birthDate;
    protected String endDate;

    public Worker(String name, String birthDate) {
        this.name = name;
        this.birthDate = birthDate;
    }

    public int getAge() {
        return 2024 - Integer.parseInt(birthDate.split("-")[0]);
    }

    public double collectPay() {
        return 0.0;
    }

    public void terminate(String endDate) {
        this.endDate = endDate;
    }
}

