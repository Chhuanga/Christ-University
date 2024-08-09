import xml.etree.ElementTree as ET
import xmlschema
import pandas as pd
import folium

# Validate XML file
def validate_xml(xml_file, xsd_file):
    schema = xmlschema.XMLSchema(xsd_file)
    valid = schema.is_valid(xml_file)
    if valid:
        print("XML is valid.")
    else:
        print("XML is invalid.")
    return valid

# Display XML data in table format
def display_xml_data(xml_file):
    tree = ET.parse(xml_file)
    root = tree.getroot()
    
    races = []
    for race in root.findall('Race'):
        race_data = {
            "RaceID": race.find('RaceID').text,
            "RaceName": race.find('RaceName').text,
            "Location": race.find('Location').text,
            "Date": race.find('Date').text,
            "Winner": race.find('Winner').text,
            "Laps": race.find('Laps').text,
            "FastestLap": race.find('FastestLap').text,
            "Points": race.find('Points').text
        }
        races.append(race_data)
    
    df = pd.DataFrame(races)
    print("F1 Stats Table:")
    print(df)

# Plot route on map
def plot_route(start_location, end_location):
    map_ = folium.Map(location=start_location, zoom_start=5)
    folium.Marker(start_location, tooltip='Start Location').add_to(map_)
    folium.Marker(end_location, tooltip='End Location').add_to(map_)
    folium.PolyLine([start_location, end_location], color='blue').add_to(map_)
    map_.save('route_map.html')
    print("Route map saved as 'route_map.html'")

# Main function
def main():
    xml_file = 'f1_stats.xml'
    xsd_file = 'f1_stats.xsd'

    if validate_xml(xml_file, xsd_file):
        display_xml_data(xml_file)
        # Example locations for the route
        start_location = [-37.8136, 144.9631]  # Melbourne
        end_location = [26.0325, 50.5106]      # Sakhir
        plot_route(start_location, end_location)

if __name__ == "__main__":
    main()
