# Load the dataset
data <- read.csv("D:\\Christ University\\MCA Trimester 2\\R\\study_exam_data.csv")

# Fit a simple linear regression model
model <- lm(Exam_Score ~ Study_Hours, data = data)

# Summarize the model
summary(model)

# Plot the data and the regression line
plot(data$Study_Hours, data$Exam_Score, 
     main = "Study Hours vs Exam Score", 
     xlab = "Study Hours", 
     ylab = "Exam Score", 
     pch = 19, col = "blue")
abline(model, col = "red", lwd = 2);

# Predict the exam score for 10 hours of study
new_data <- data.frame(Study_Hours = 10)
predict(model, new_data, interval = "confidence")
