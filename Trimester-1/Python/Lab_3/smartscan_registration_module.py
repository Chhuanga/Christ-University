user_db=[]

create = lambda name, email: {'name': name, 'email': email}

insert = lambda user: user_db.append(user)

fetch_all = lambda: user_db


decode_smartscan_code = lambda code: dict(zip(['name', 'email'], code.split(',')))

def RegisterUserFromSmartScan(code):
    user_data = decode_smartscan_code(code)
    user = create(user_data['name'],user_data['email'])
    insert(user)
    print(fetch_all())