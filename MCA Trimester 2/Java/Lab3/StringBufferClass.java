package ecommerce.utils;

public class StringBufferClass {
    private java.lang.StringBuffer buffer;

    public StringBufferClass() {
        this.buffer = new java.lang.StringBuffer();
    }

    public StringBufferClass append(String additionalString) {
        this.buffer.append(additionalString);
        return this;
    }

    @Override
    public String toString() {
        return this.buffer.toString();
    }
}