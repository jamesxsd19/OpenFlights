import pandas as pd

airport_data = pd.read_csv('airports.dat')
print(airport_data.columns)
routes_data = pd.read_csv('routes.dat')
airport_data = airport_data[['ID', 'Name', 'City', 'Country', 'Latitude', 'Longitude']]
routes_data = routes_data[['SourceID', 'DestID']]
airport_data.to_csv('airports.csv')
routes_data.to_csv('routes.csv')

print(airport_data)
print(routes_data)