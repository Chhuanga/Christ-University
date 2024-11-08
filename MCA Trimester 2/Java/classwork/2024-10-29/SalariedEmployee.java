// SalariedEmployee Class
public class SalariedEmployee extends Employee {
    private double annualSalary;
    private boolean isRetired;

    public SalariedEmployee(String name, String birthDate, long employeeId, String hireDate, double annualSalary) {
        super(name, birthDate, employeeId, hireDate);
        this.annualSalary = annualSalary;
        this.isRetired = false;
    }

    @Override
    public double collectPay() {
        return isRetired ? annualSalary / 2 : annualSalary / 12;
    }

    public void retire() {
        isRetired = true;
    }
}