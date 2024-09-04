//Car Dealearship management system using structurres
#include <stdio.h>
#include <string.h>
struct car
{
    char name[20];
    char model[20];
    int year;
    int price;
};
int main()
{
    struct car c[5];
    for (int i = 0; i < 5; i++)
    {
        printf("Enter the name of the car %d: ", i + 1);
        scanf("%s", c[i].name);
        printf("Enter the model of the car %d: ", i + 1);
        scanf("%s", c[i].model);
        printf("Enter the year of the car %d: ", i + 1);
        scanf("%d", &c[i].year);
        printf("Enter the price of the car %d: ", i + 1);
        scanf("%d", &c[i].price);
    }
    printf("The details of the cars are: \n");
    for (int i = 0; i < 5; i++)
    {
        printf("The name of the car %d is: %s\n", i + 1, c[i].name);
        printf("The model of the car %d is: %s\n", i + 1, c[i].model);
        printf("The year of the car %d is: %d\n", i + 1, c[i].year);
        printf("The price of the car %d is: %d\n", i + 1, c[i].price);
    }
    return 0;
}

