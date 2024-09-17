import pandas as pd

covid_data = pd.read_csv("MCA Trimester 1\Python\Lab-7\synthetic_covid_data.csv")

gdp_data = pd.read_csv("MCA Trimester 1\Python\Lab-7\synthetic_gdp_data.csv")

covid_data['month'] = pd.to_datetime(covid_data['month'])
covid_duplicates = covid_data[covid_data.duplicated()]

gdp_duplicates = gdp_data[gdp_data.duplicated()]

if not covid_duplicates.empty:
    covid_data = covid_data.drop_duplicates()
    print("Duplicates found and removed in covid_data.")
else:
    print("No duplicates found in covid_data.")

if not gdp_duplicates.empty:
    gdp_data = gdp_data.drop_duplicates()
    print("Duplicates found and removed in gdp_data.")
else:
    print("No duplicates found in gdp_data.")

covid_data['active_cases'] = covid_data['confirmed_cases'] - covid_data['recovered']

covid_data['quarter'] = covid_data['month'].dt.to_period('Q')

aggregated_covid_data = covid_data.groupby(['country', 'quarter'])[['confirmed_cases', 'deaths', 'active_cases']].sum().reset_index()

print("COVID Data:")
print(covid_data.head())

print("\nGDP Data:")
print(gdp_data.head())

merged_data = pd.concat([aggregated_covid_data, gdp_data], axis=1)
merged_data = merged_data.set_index('country')

print("MERGED DATA:")
print(merged_data.head())

avg_gdp_growth = merged_data.groupby(['country'])['gdp_growth'].mean()

highest_growth_country = avg_gdp_growth.idxmax()

print("Country with highest overall GDP growth during the pandemic:", highest_growth_country)

total_cases_deaths = merged_data.groupby('country')[['confirmed_cases', 'deaths']].sum()

highest_cases_country = total_cases_deaths['confirmed_cases'].idxmax()

highest_deaths_country = total_cases_deaths['deaths'].idxmax()

print("Country with highest total confirmed cases:", highest_cases_country)
print("Country with highest total deaths:", highest_deaths_country)
