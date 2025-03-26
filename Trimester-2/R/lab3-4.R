#Lab-3:

library(ggplot2)
library(dplyr)

data <- read.csv("data.csv")


# A. How many variables and observations does the dataset have?
obs <- nrow(data)
vars <- ncol(data)
obs
vars

# B. Extract variable2 and 3 and assign as vector
v2 <- data[[2]]
v3 <- data[[3]]
v2
v3

# C. How many different blood groups are in a dataset?
bg<-length(unique(data$BLOOD))
bg

# D. List the unique SMOKE categories.
smk <-length(unique(data$SMOKE))
smk

# E. How many had cholesterol levels above 300?
clst<-sum(data$CHOL > 300)
clst

# F. What is the mean height value for mortality is alive?
mean_ht <-mean(data$HEIGHT[data$MORT == "alive"])
mean_ht               

# G. Find the age of the tallest O-Blood Group person.
tal <- data$AGE[which.max(data$HEIGHT[data$BLOOD == "o"])]
tal

#H. How many nonsmokers are alive who are below 40 years
nalive <-sum(data$SMOKE == "nonsmo" & data$MORT == "alive" & data$AGE < 40)
nalive


#Lab-4:

# A. Using a single variable, draw a bar plot, pie chart, box plot, and histogram, using the appropriate format.
# Bar:
barplot(table(data$BLOOD), 
        main = "Bar Plot of Blood Groups",
        col = "red",
        ylab = "Number of People",
        xlab = "Blood")
# Pie:
pie(table(data$BLOOD),main="Blood Group")

# Box:
boxplot(data$HEIGHT, 
        main = "Height",
        col = "red",
        ylab = "Height")

# Histogram:
hist(data$HEIGHT, main="Height", xlab="Height", ylab="Amount")

# B. Using two variables, draw a bar plot, scatter plot, and box plot using the appropriate format.

age <- cut(data$AGE, breaks = seq(18, 60, by = 5), right = FALSE)
avg_ht <- tapply(data$HEIGHT, age, mean)
age
avg_ht

# Bar:
barplot(avg_ht, main = "Average Height by Age Group", xlab = "Age Group", ylab = "Average Height")

# Scatter:
plot(data$AGE,data$HEIGHT, main = "AGE vs HEIGHT", xlab = "AGE", ylab = "HEIGHT", col = "black")

# Box Plot
boxplot(data$HEIGHT ~ age, main = "Boxplot of HEIGHT by Age Group", xlab = "Age Group", ylab = "Height", col = "lightgreen")

# C. Using the multivariable draw a bar plot and pair plot, use the appropriate format.

#Bar:
barplot(as.matrix(data.frame(data$AGE,data$HEIGHT,data$WEIGHT)))

#Pair:
pairs(data.frame(data$HEIGHT,data$AGE,data$WEIGHT))
