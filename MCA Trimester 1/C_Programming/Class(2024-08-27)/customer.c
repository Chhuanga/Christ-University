
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct customer
{
    char name[20];
    int account_no;
    float balance;
};
void display(struct customer *c)
{
    printf("Customer Name: %s\n", c->name);
    printf("Account Number: %d\n", c->account_no);
    printf("Balance: %f\n", c->balance);
}
void input(struct customer *c)
{
    printf("Enter Customer Name: ");
    scanf("%s", c->name);
    printf("Enter Account Number: ");
    scanf("%d", &c->account_no);
    printf("Enter Balance: ");
    scanf("%f", &c->balance);
}
int main()
{
    struct customer *c;
    c = (struct customer *)malloc(sizeof(struct customer));
    input(c);
    display(c);
    return 0;
}
  