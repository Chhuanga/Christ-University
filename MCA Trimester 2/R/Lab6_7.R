library(ggplot2)
library(dplyr)

data<-read.csv("training_productivity_anova.csv")

#viewing the rows in the dataset

head(data)

one_way <- aov(Productivity ~ Training_Method, data = data)
summary(one_way)

tukey <- TukeyHSD(one_way)
print(tukey)

two_way <- aov(Productivity ~ Training_Method * Department, data = data)
summary(two_way)

#Visualisation of the data

#boxplot

ggplot(data, aes(x = Training_Method, y = Productivity, fill = Training_Method)) +
  geom_boxplot() +
  labs(title = "Boxplot of Productivity by Training Method", x = "Training Method", y = "Productivity") +
  theme_minimal()

#Density Plot
ggplot(data, aes(x = Productivity, fill = Training_Method)) +
geom_density(alpha = 0.5) +
  labs(title = "Density Plot of Productivity by Training Method", x = "Productivity", y = "Density") +
  theme_minimal()

#Interaction Plot

interaction.plot(data$Training_Method, data$Department, data$Productivity,
                 main = "Interaction Plot",
                 xlab = "Training Method",
                 ylab = "Productivity",
                 col = c("red", "blue", "green"), legend = TRUE)