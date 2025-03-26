






public class Main {
    public static void main(String[] args) {
        SalariedEmployee salariedEmployee = new SalariedEmployee("Alice", "1985-04-12", 123456, "2020-01-01", 60000);
        System.out.println("Salaried Employee's Pay: " + salariedEmployee.collectPay());
        salariedEmployee.retire();
        System.out.println("Salaried Employee's Pay after retirement: " + salariedEmployee.collectPay());

        HourlyEmployee hourlyEmployee = new HourlyEmployee("Bob", "1990-06-15", 789012, "2021-05-20", 25);
        System.out.println("Hourly Employee's Pay: " + hourlyEmployee.collectPay());
        System.out.println("Hourly Employee's Double Pay: " + hourlyEmployee.getDoublePay());
    }
}
