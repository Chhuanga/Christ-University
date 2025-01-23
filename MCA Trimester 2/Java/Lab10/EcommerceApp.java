import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.text.NumberFormatter;
import java.text.NumberFormat;
import java.util.regex.Pattern;

public class EcommerceApp {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Ecommerce Application");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(1000, 800); // Increased window size

        Font customFont = new Font("Arial", Font.PLAIN, 14);

        JTabbedPane tabbedPane = new JTabbedPane();

        // Product Panel
        JPanel productPanel = new JPanel(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(10, 10, 10, 10);
        gbc.fill = GridBagConstraints.HORIZONTAL;

        // Product Name
        gbc.gridx = 0;
        gbc.gridy = 0;
        JLabel productNameLabel = new JLabel("Product Name:");
        productNameLabel.setFont(customFont);
        productPanel.add(productNameLabel, gbc);
        gbc.gridx = 1;
        JTextField productNameField = new JTextField(30); // Increased field width
        productNameField.setFont(customFont);
        productPanel.add(productNameField, gbc);

        // Price
        gbc.gridx = 0;
        gbc.gridy = 1;
        JLabel priceLabel = new JLabel("Price:");
        priceLabel.setFont(customFont);
        productPanel.add(priceLabel, gbc);
        gbc.gridx = 1;

        NumberFormat format = NumberFormat.getInstance();
        NumberFormatter formatter = new NumberFormatter(format);
        formatter.setValueClass(Double.class);
        formatter.setMinimum(0.0);
        formatter.setAllowsInvalid(false);
        JFormattedTextField priceField = new JFormattedTextField(formatter);
        priceField.setColumns(30);
        priceField.setFont(customFont);
        productPanel.add(priceField, gbc);

        // Stock
        gbc.gridx = 0;
        gbc.gridy = 2;
        JLabel stockLabel = new JLabel("Stock Quantity:");
        stockLabel.setFont(customFont);
        productPanel.add(stockLabel, gbc);
        gbc.gridx = 1;

        // Number formatter for stock
        NumberFormatter stockFormatter = new NumberFormatter(NumberFormat.getIntegerInstance());
        stockFormatter.setValueClass(Integer.class);
        stockFormatter.setMinimum(0);
        stockFormatter.setAllowsInvalid(false);
        JFormattedTextField stockField = new JFormattedTextField(stockFormatter);
        stockField.setColumns(30);
        stockField.setFont(customFont);
        productPanel.add(stockField, gbc);

        gbc.gridx = 0;
        gbc.gridy = 3;
        JLabel categoryLabel = new JLabel("Category:");
        categoryLabel.setFont(customFont);
        productPanel.add(categoryLabel, gbc);
        gbc.gridx = 1;
        JComboBox<String> categoryComboBox = new JComboBox<>(
                new String[] { "Electronics", "Books", "Clothing", "Home & Garden", "Sports", "Beauty" });
        categoryComboBox.setFont(customFont);
        productPanel.add(categoryComboBox, gbc);

        gbc.gridx = 0;
        gbc.gridy = 4;
        JLabel descriptionLabel = new JLabel("Description:");
        descriptionLabel.setFont(customFont);
        productPanel.add(descriptionLabel, gbc);
        gbc.gridx = 1;
        gbc.gridwidth = 2;
        JTextArea descriptionArea = new JTextArea(6, 30); // Increased size
        descriptionArea.setFont(customFont);
        descriptionArea.setLineWrap(true);
        descriptionArea.setWrapStyleWord(true);
        JScrollPane scrollPane = new JScrollPane(descriptionArea);
        productPanel.add(scrollPane, gbc);
        gbc.gridwidth = 1;

        gbc.gridx = 0;
        gbc.gridy = 5;
        gbc.gridwidth = 2;
        JPanel productButtonPanel = new JPanel();
        JButton addProductButton = new JButton("Add Product");
        addProductButton.setFont(customFont);
        JButton clearProductButton = new JButton("Clear");
        clearProductButton.setFont(customFont);
        productButtonPanel.add(addProductButton);
        productButtonPanel.add(clearProductButton);
        productPanel.add(productButtonPanel, gbc);
        gbc.gridwidth = 1;

        gbc.gridx = 0;
        gbc.gridy = 6;
        gbc.gridwidth = 2;
        String[] productColumns = { "Name", "Price", "Stock", "Category", "Description" };
        DefaultTableModel productTableModel = new DefaultTableModel(productColumns, 0) {
            @Override
            public boolean isCellEditable(int row, int column) {
                return false; // Make table read-only
            }
        };
        JTable productTable = new JTable(productTableModel);
        productTable.setAutoResizeMode(JTable.AUTO_RESIZE_ALL_COLUMNS);
        productTable.getColumnModel().getColumn(4).setPreferredWidth(200);
        JScrollPane productTableScrollPane = new JScrollPane(productTable);
        productTableScrollPane.setPreferredSize(new Dimension(800, 200));
        productPanel.add(productTableScrollPane, gbc);
        gbc.gridwidth = 1;

        tabbedPane.addTab("Product Details", productPanel);

        JPanel customerPanel = new JPanel(new GridBagLayout());

        gbc.gridx = 0;
        gbc.gridy = 0;
        JLabel customerNameLabel = new JLabel("Customer Name:");
        customerNameLabel.setFont(customFont);
        customerPanel.add(customerNameLabel, gbc);
        gbc.gridx = 1;
        JTextField customerNameField = new JTextField(30);
        customerNameField.setFont(customFont);
        customerPanel.add(customerNameField, gbc);

        // Email
        gbc.gridx = 0;
        gbc.gridy = 1;
        JLabel emailLabel = new JLabel("Email:");
        emailLabel.setFont(customFont);
        customerPanel.add(emailLabel, gbc);
        gbc.gridx = 1;
        JTextField emailField = new JTextField(30);
        emailField.setFont(customFont);
        customerPanel.add(emailField, gbc);

        // Phone
        gbc.gridx = 0;
        gbc.gridy = 2;
        JLabel phoneLabel = new JLabel("Phone Number:");
        phoneLabel.setFont(customFont);
        customerPanel.add(phoneLabel, gbc);
        gbc.gridx = 1;
        JTextField phoneField = new JTextField(30);
        phoneField.setFont(customFont);
        customerPanel.add(phoneField, gbc);

        // Customer Type
        gbc.gridx = 0;
        gbc.gridy = 3;
        JLabel customerTypeLabel = new JLabel("Customer Type:");
        customerTypeLabel.setFont(customFont);
        customerPanel.add(customerTypeLabel, gbc);
        gbc.gridx = 1;
        JComboBox<String> customerTypeComboBox = new JComboBox<>(new String[] { "Regular", "Premium", "VIP" });
        customerTypeComboBox.setFont(customFont);
        customerPanel.add(customerTypeComboBox, gbc);

        // Customer Buttons
        gbc.gridx = 0;
        gbc.gridy = 4;
        gbc.gridwidth = 2;
        JPanel customerButtonPanel = new JPanel();
        JButton addCustomerButton = new JButton("Add Customer");
        addCustomerButton.setFont(customFont);
        JButton clearCustomerButton = new JButton("Clear");
        clearCustomerButton.setFont(customFont);
        customerButtonPanel.add(addCustomerButton);
        customerButtonPanel.add(clearCustomerButton);
        customerPanel.add(customerButtonPanel, gbc);
        gbc.gridwidth = 1;

        // Customer Table
        gbc.gridx = 0;
        gbc.gridy = 5;
        gbc.gridwidth = 2;
        String[] customerColumns = { "Name", "Email", "Phone", "Type" };
        DefaultTableModel customerTableModel = new DefaultTableModel(customerColumns, 0) {
            @Override
            public boolean isCellEditable(int row, int column) {
                return false; // Make table read-only
            }
        };
        JTable customerTable = new JTable(customerTableModel);
        JScrollPane customerTableScrollPane = new JScrollPane(customerTable);
        customerTableScrollPane.setPreferredSize(new Dimension(800, 200));
        customerPanel.add(customerTableScrollPane, gbc);
        gbc.gridwidth = 1;

        tabbedPane.addTab("Customer Details", customerPanel);

        // Product Button Actions
        addProductButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (validateProductInput()) {
                    String name = productNameField.getText();
                    Double price = ((Number) priceField.getValue()).doubleValue();
                    Integer stock = ((Number) stockField.getValue()).intValue();
                    String category = (String) categoryComboBox.getSelectedItem();
                    String description = descriptionArea.getText();

                    productTableModel.addRow(new Object[] {
                            name,
                            String.format("$%.2f", price),
                            stock,
                            category,
                            description
                    });
                    clearProductFields();
                }
            }

            private boolean validateProductInput() {
                if (productNameField.getText().trim().isEmpty()) {
                    showError("Product name cannot be empty");
                    return false;
                }
                if (priceField.getValue() == null) {
                    showError("Please enter a valid price");
                    return false;
                }
                if (stockField.getValue() == null) {
                    showError("Please enter a valid stock quantity");
                    return false;
                }
                if (descriptionArea.getText().trim().isEmpty()) {
                    showError("Description cannot be empty");
                    return false;
                }
                return true;
            }

            private void clearProductFields() {
                productNameField.setText("");
                priceField.setValue(null);
                stockField.setValue(null);
                descriptionArea.setText("");
            }
        });

        clearProductButton.addActionListener(e -> {
            productNameField.setText("");
            priceField.setValue(null);
            stockField.setValue(null);
            descriptionArea.setText("");
        });

        addCustomerButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (validateCustomerInput()) {
                    String name = customerNameField.getText();
                    String email = emailField.getText();
                    String phone = phoneField.getText();
                    String type = (String) customerTypeComboBox.getSelectedItem();
                    customerTableModel.addRow(new Object[] { name, email, phone, type });
                    clearCustomerFields();
                }
            }

            private boolean validateCustomerInput() {
                if (customerNameField.getText().trim().isEmpty()) {
                    showError("Customer name cannot be empty");
                    return false;
                }
                if (!isValidEmail(emailField.getText())) {
                    showError("Please enter a valid email address");
                    return false;
                }
                if (!isValidPhone(phoneField.getText())) {
                    showError("Please enter a valid phone number");
                    return false;
                }
                return true;
            }

            private boolean isValidEmail(String email) {
                return Pattern.compile("^[A-Za-z0-9+_.-]+@(.+)$").matcher(email).matches();
            }

            private boolean isValidPhone(String phone) {
                return Pattern.compile("^\\d{10}$").matcher(phone).matches();
            }

            private void clearCustomerFields() {
                customerNameField.setText("");
                emailField.setText("");
                phoneField.setText("");
            }
        });

        clearCustomerButton.addActionListener(e -> {
            customerNameField.setText("");
            emailField.setText("");
            phoneField.setText("");
        });

        frame.add(tabbedPane);
        frame.setVisible(true);
    }

    private static void showError(String message) {
        JOptionPane.showMessageDialog(null, message, "Error", JOptionPane.ERROR_MESSAGE);
    }
}