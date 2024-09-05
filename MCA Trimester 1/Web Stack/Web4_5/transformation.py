import lxml.etree as ET

xml_doc = ET.parse("E:/New folder/Christ-University/MCA Trimester 1/Web Stack/Web4_5/formula_one_circuits.xml")
xsd_doc = ET.parse("E:/New folder/Christ-University/MCA Trimester 1/Web Stack/Web4_5/formula_one_circuits.xsd")
xmlschema = ET.XMLSchema(xsd_doc)

is_valid = xmlschema.validate(xml_doc)
if not is_valid:
    print("XML data is invalid:")
    for error in xmlschema.error_log:
        print(f"  - {error.message} (Line {error.line}, Column {error.column})")
else:
    print("XML data is valid according to the schema.")

    xslt = ET.parse("E:/New folder/Christ-University/MCA Trimester 1/Web Stack/Web4_5/transform.xsl")
    transform = ET.XSLT(xslt)
    newdom = transform(xml_doc)
    with open('E:/New folder/Christ-University/MCA Trimester 1/Web Stack/Web4_5/output.html', 'wb') as f:
        f.write(ET.tostring(newdom, pretty_print=True))
    print("HTML output generated successfully!")