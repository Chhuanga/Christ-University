//Book Structures

#include <stdio.h>
#include <string.h>

struct Book {
    char title[50];
    char author[50];
    int price;
};

int main() {
    struct Book books[3]; 
    int i;

    for (i = 0; i < 3; i++) {
        printf("Enter the title of book %d: ", i + 1);
        scanf("%49s", books[i].title); 

        printf("Enter the author of book %d: ", i + 1);
        scanf("%49s", books[i].author);

        printf("Enter the price of book %d: ", i + 1);
        scanf("%d", &books[i].price);
    }

    int leastExpensiveIndex = 0;
    for (i = 1; i < 3; i++) {
        if (books[i].price < books[leastExpensiveIndex].price) {
            leastExpensiveIndex = i;
        }
    }
    printf("\nDetails of the least expensive book:\n");
    printf("Title: %s\n", books[leastExpensiveIndex].title);
    printf("Author: %s\n", books[leastExpensiveIndex].author);
    printf("Price: %d\n", books[leastExpensiveIndex].price);
    
    int maxexpensiveIndex=0;
    for(i=1;i<3;i++)
    {
        if(books[i].price>books[maxexpensiveIndex].price){
            maxexpensiveIndex=i;
            
        }
    }
    printf("\nDetails of the most expensive book:\n");
    printf("Title: %s\n", books[maxexpensiveIndex].title);
    printf("Author: %s\n", books[maxexpensiveIndex].author);
    printf("Price: %d\n", books[maxexpensiveIndex].price);

    return 0;
}