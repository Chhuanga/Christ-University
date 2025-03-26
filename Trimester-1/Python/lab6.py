import numpy as np

# Define the data structure
data_type = [
    ('Employee ID', int),
    ('Department', 'U20'),
    ('Years of Experience', float),
    ('Projects Completed', int),
    ('Client Satisfaction Rating', float)
]

# this generates  data for 20 employees
data = np.zeros(20, dtype=data_type)

# Populating  the data
data['Employee ID'] = np.arange(1, 21)
data['Department'] = np.random.choice(['Engineering', 'HR', 'Marketing', 'Sales'], 20)
data['Years of Experience'] = np.random.uniform(0, 15, 20)
data['Projects Completed'] = np.random.randint(1, 21, 20)
data['Client Satisfaction Rating'] = np.random.uniform(1.0, 5.0, 20)

# Function to filter by department
def filter_by_department(data, department):
    return data[data['Department'] == department]

#Employee with the highest Client Satisfaction Rating
highest_rated_employee = data[data['Client Satisfaction Rating'].argmax()]


avg_projects_completed = data['Projects Completed'].mean()
avg_years_experience = data['Years of Experience'].mean()

less_experienced_employees = data[data['Years of Experience'] < 2]


print("Data:\n", data)
print("\nEmployees in Engineering department:\n", filter_by_department(data, 'Engineering'))
print("\nHighest Rated Employee:\n", highest_rated_employee)
print("\nAverage Projects Completed:", avg_projects_completed)
print("Average Years of Experience:", avg_years_experience)
print("\nEmployees with less than 2 years of experience:\n", less_experienced_employees)