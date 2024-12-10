install.packages(c("ggplot2","ggpubr","tidyverse"))

library(ggplot2)
library(ggpubr)
library(tidyverse)
crop.data<-read.csv("crop_data.csv")

summary(crop.data)

one.way<-aov(yield ~ fertilizer, data=crop.data)
summary(one.way)

two_way<-aov(yield ~ fertilizer+density, data=crop.data)
summary(two_way)

interaction<- aov(yield ~ fertilizer*density, data=crop.data)
summary(interaction)