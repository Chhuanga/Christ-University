class NegativeAmountError(Exception):
    pass

def process_transaction(transaction,balance):
    print("Press 1 for deposit: ")
    print("Press 2 for withdrawal: ")
    a=int(input("Enter your choice: "))
    if a==1:
        amount=float(input("Enter the amount to be deposited: "))
        if amount<0:
            raise NegativeAmountError("Amount cannot be negative")
        else:
            balance+=amount
            transaction.append(amount)
    else if a==2:
        amount=float(input("Enter the amount to be withdrawn: "))
        if amount<0:
            raise NegativeAmountError("Amount cannot be negative")
        elif amount>balance:
            print("Insufficient balance")
        else:
            balance-=amount
            transaction.append(-amount)
            return balance
    else:
        print("Invalid Input")
        return balance

    