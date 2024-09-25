import pandas as pd
import matplotlib.pyplot as plt

#Loading the data into a DataFrame
file_path = 'ETE\sales_data_analysis - sales_data_analysis.csv' 
df = pd.read_csv(file_path)

# Plotting a bar chart 
revenue_by_category = df.groupby('Product_Category')['Revenue'].sum()
revenue_by_category.plot(kind='bar', title='Total Revenue by Product Category')
plt.xlabel('Product Category')
plt.ylabel('Total Revenue')
plt.show()

# Plotting a pie chartcd
units_sold_by_category = df.groupby('Product_Category')['Units_Sold'].sum()
units_sold_by_category.plot(kind='pie', title='Proportion of Total Units Sold by Product Category', autopct='%1.1f%%')
plt.ylabel('')  
plt.show()