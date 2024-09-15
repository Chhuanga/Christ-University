import pandas as pd

# Step 1: Load the Data
covid_df = pd.read_csv('MCA Trimester 1\Python\Lab-7\synthetic_covid_data.csv')
gdp_df = pd.read_csv('MCA Trimester 1\Python\Lab-7\synthetic_gdp_data.csv')

# Step 2: Display the first few rows of each dataset
print("COVID-19 Data:")
print(covid_df.head())
print("\nGDP Growth Data:")
print(gdp_df.head())

# Step 3: Ensure that the month column in the COVID-19 dataset is of type datetime64
covid_df['month'] = pd.to_datetime(covid_df['month'], format='%Y-%m')

# Step 4: Check for any duplicates in both datasets and remove them if necessary
covid_df.drop_duplicates(inplace=True)
gdp_df.drop_duplicates(inplace=True)

# Step 5: Add a new column active_cases to the COVID-19 dataset
covid_df['active_cases'] = covid_df['confirmed_cases'] - covid_df['recovered']

# Step 6: Aggregate the COVID-19 dataset by country and quarter
covid_df['quarter'] = covid_df['month'].dt.to_period('Q')
aggregated_covid_df = covid_df.groupby(['country', 'quarter']).agg({
    'confirmed_cases': 'sum',
    'deaths': 'sum',
    'active_cases': 'sum'
}).reset_index()

# Step 7: Merge the aggregated COVID-19 data with the GDP data
merged_df = pd.merge(aggregated_covid_df, gdp_df, on=['country', 'quarter'])

# Step 8: Display the resulting DataFrame after the merge
print("\nMerged DataFrame:")
print(merged_df.head())

# Step 9: Identify which country experienced the highest overall GDP growth during the pandemic
highest_gdp_growth_country = gdp_df.groupby('country')['gdp_growth'].sum().idxmax()
print(f"\nCountry with the highest overall GDP growth during the pandemic: {highest_gdp_growth_country}")

# Step 10: Determine which country had the highest number of total COVID-19 confirmed cases and deaths
total_confirmed_cases = covid_df.groupby('country')['confirmed_cases'].sum().idxmax()
total_deaths = covid_df.groupby('country')['deaths'].sum().idxmax()
print(f"Country with the highest number of total COVID-19 confirmed cases: {total_confirmed_cases}")
print(f"Country with the highest number of total COVID-19 deaths: {total_deaths}")

# Step 11: Conclusion
conclusion = """
Conclusion:
The analysis shows that the country with the highest overall GDP growth during the pandemic is {highest_gdp_growth_country}.
The country with the highest number of total COVID-19 confirmed cases is {total_confirmed_cases}, and the country with the highest number of total COVID-19 deaths is {total_deaths}.
There appears to be a complex relationship between COVID-19 cases and economic growth, with some countries experiencing significant economic impacts despite varying levels of COVID-19 cases and deaths.
""".format(highest_gdp_growth_country=highest_gdp_growth_country, total_confirmed_cases=total_confirmed_cases, total_deaths=total_deaths)

print(conclusion)