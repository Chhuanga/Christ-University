import lxml.etree as ET

# Load XML and XSLT files
xml_file = 'f1_stats.xml'
xslt_file = 'transform.xsl'

# Parse the XML and XSLT files
xml_doc = ET.parse(xml_file)
xslt_doc = ET.parse(xslt_file)

# Transform the XML using the XSLT
transform = ET.XSLT(xslt_doc)
result_tree = transform(xml_doc)

# Save the result to an HTML file
html_file = 'f1_stats.html'
with open(html_file, 'wb') as f:
    f.write(ET.tostring(result_tree, pretty_print=True, method="html"))

print(f"Transformation complete! The HTML file is saved as {html_file}.")
