library(ggplot2)
library(plyr)

# Load the dataset
data <- read.csv("D:/Christ University/MCA Trimester 2/R/bank.csv")

# Single-variable visualizations: Using 'age' column

# 1. Bar plot
ggplot(data, aes(x = age)) +
  geom_bar(fill = "steelblue") + 
  labs(title = "Bar Plot of Age", x = "Age", y = "Count")

# 2. Pie chart
# Calculate frequencies for the pie chart
age_counts <- data.frame(table(data$age))
colnames(age_counts) <- c("age", "freq") # Rename columns
age_counts$percentage <- (age_counts$freq / sum(age_counts$freq)) * 100

# Pie chart
ggplot(age_counts, aes(x = "", y = percentage, fill = as.factor(age))) +
  geom_bar(stat = "identity", width = 1) +
  coord_polar("y") +
  labs(title = "Pie Chart of Age", fill = "Age")

# 3. Box plot
ggplot(data, aes(x = "", y = age)) +
  geom_boxplot(fill = "lightgreen") +
  labs(title = "Box Plot of Age", y = "Age", x = "")

# 4. Density plot
ggplot(data, aes(x = age)) +
  geom_density(fill = "purple", alpha = 0.5) +
  labs(title = "Density Plot of Age", x = "Age", y = "Density")

# 5. Histogram
ggplot(data, aes(x = age)) +
  geom_histogram(binwidth = 5, fill = "orange", color = "black", alpha = 0.7) +
  labs(title = "Histogram of Age", x = "Age", y = "Frequency")


# Two-variable visualizations:

# 1. Bar plot (Count of deposits per age group)
ggplot(data, aes(x = age, fill = deposit)) +
  geom_bar(position = "dodge") +  # Position the bars side by side
  labs(title = "Bar Plot of Age by Deposit", x = "Age", y = "Count") +
  scale_fill_manual(values = c("steelblue", "lightgreen"))  # Customize bar colors

# 2. Scatter plot (Age vs. Duration of call)
ggplot(data, aes(x = age, y = duration, color = deposit)) +
  geom_point(alpha = 0.6) + # Use alpha for transparency
  labs(title = "Scatter Plot of Age vs Duration by Deposit", x = "Age", y = "Duration") +
  scale_color_manual(values = c("steelblue", "lightgreen"))

# 3. Violin plot (Age distribution by Deposit status)
ggplot(data, aes(x = deposit, y = age, fill = deposit)) +
  geom_violin(trim = TRUE) + # Trim the tails of the violin plot
  labs(title = "Violin Plot of Age Distribution by Deposit", x = "Deposit", y = "Age") +
  scale_fill_manual(values = c("steelblue", "lightgreen"))

# 4. Box plot (Age distribution by Deposit status)
ggplot(data, aes(x = deposit, y = age, fill = deposit)) +
  geom_boxplot() +
  labs(title = "Box Plot of Age by Deposit", x = "Deposit", y = "Age") +
  scale_fill_manual(values = c("steelblue", "lightgreen"))


# Multi-variable visualizations:

# Selecting relevant columns using plyr's `ldply` instead of `dplyr` functions
numerical_data <- data[c("age", "balance", "duration", "campaign")]

# Reshape the data to long format using plyr's `ldply`
long_data <- ldply(names(numerical_data), function(var) {
  data.frame(age = numerical_data$age, value = numerical_data[[var]], variable = var)
})

# 1. Bar Plot (For multiple categorical variables, e.g., 'job' and 'deposit')
ggplot(data, aes(x = job, fill = deposit)) + 
  geom_bar(position = "dodge") + 
  labs(title = "Bar Plot of Job by Deposit", x = "Job", y = "Count") +
  scale_fill_manual(values = c("steelblue", "lightgreen")) +
  theme(axis.text.x = element_text(angle = 45, hjust = 1))  # Rotate x-axis labels for readability

# 2. Pair Plot (Using facets for individual scatter plots)
ggplot(long_data, aes(x = age, y = value, color = variable)) +
  geom_point(alpha = 0.6) +
  facet_wrap(~variable, scales = "free") +
  labs(title = "Pair Plot of Numerical Variables by Age", x = "Age", y = "Value") +
  scale_color_manual(values = c("steelblue", "lightgreen", "purple", "orange"))
