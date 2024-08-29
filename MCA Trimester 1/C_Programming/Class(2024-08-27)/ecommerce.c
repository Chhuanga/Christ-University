
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct order
{
    int order_id;
    char product_name[20];
    int quantity;
    float price;
};
void display(struct order *o)
{
    printf("Order ID: %d\n", o->order_id);
    printf("Product Name: %s\n", o->product_name);
    printf("Quantity: %d\n", o->quantity);
    printf("Price: %f\n", o->price);
}
void input(struct order *o)
{
    printf("Enter Order ID: ");
    scanf("%d", &o->order_id);
    printf("Enter Product Name: ");
    scanf("%s", o->product_name);
    printf("Enter Quantity: ");
    scanf("%d", &o->quantity);
    printf("Enter Price: ");
    scanf("%f", &o->price);
}
int main()
{
    struct order *o;
    o = (struct order *)malloc(sizeof(struct order));
    input(o);
    display(o);
    return 0;
}