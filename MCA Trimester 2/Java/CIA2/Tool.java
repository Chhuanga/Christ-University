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
