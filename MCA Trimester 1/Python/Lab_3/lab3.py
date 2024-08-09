
import smartscan_registration_module as srm

while True:
    print("x to exit")
    print("Enter smartscan code(name,email): ")
    smartscan_code = input()
    if smartscan_code == 'x' or smartscan_code == 'X':
        break
    srm.RegisterUserFromSmartScan(smartscan_code)


