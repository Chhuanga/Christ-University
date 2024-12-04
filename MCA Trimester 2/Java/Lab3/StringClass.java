package ecommerce.utils;

public class StringClass {
    private String string;

    public StringClass(String initialString) {
        this.string = initialString;
    }

    public StringClass append(String additionalString) {
        this.string += additionalString;
        return this;
    }

    @Override
    public String toString() {
        return this.string;
    }
}