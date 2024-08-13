#include <stdio.h>
#include <string.h>

void length(char str[])
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
        ;
    printf("The length of the string is %d\n", i);
}

void reversestring(char str[])
//reverse individual characters in a string
{
    int i;
    for (i = 0; i < strlen(str); i++)
    {
        printf("%c", str[strlen(str) - i - 1]);
    }
    printf("\n");
}

//function to count the number of alphabets
void count(char str[])
{
    int i, alphabets = 0, digits = 0, special = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            alphabets++;
        else if (str[i] >= '0' && str[i] <= '9')
            digits++;
        else
            special++;
    }
    printf("The number of alphabets is %d\n", alphabets);
    printf("The number of digits is %d\n", digits);
    printf("The number of special characters is %d\n", special);
}

void vowelconsonant(char str[])
{
    int i, vowels = 0, consonants = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
            vowels++;
        else
            consonants++;
    }
    printf("The number of vowels is %d\n", vowels);
    printf("The number of consonants is %d\n", consonants);
}

void bubbleSort(char str[])
{
    int i, j;
    int n = strlen(str);

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (str[j] > str[j + 1])
            {
                // Swap characters
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

void substring(char str[], int start, int length)
{
    int i;
    printf("The substring is: ");
    for (i = start; i < start + length; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");
}

void lowertouper(char str[])
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
    }
    printf("The string in uppercase is: %s\n", str);
}

void frequency(char str[])
{
    int count[256] = {0};
    int i;

    for (i = 0; str[i] != '\0'; i++)
    {
        count[str[i]]++;
    }

    printf("Character Frequency\n");
    for (i = 0; i < 256; i++)
    {
        if (count[i] != 0)
        {
            printf("%c\t%d\n", i, count[i]);
        }
    }
}

int main()
{
    while(1){

    
    int choice;
    printf("Menu:\n");
    printf("1. Find the length of the string\n");
    printf("2. Reverse the string\n");
    printf("3. Count the number of alphabets, digits, and special characters\n");
    printf("4. Count the number of vowels and consonants\n");
    printf("5. Sort the string in ascending order\n");
    printf("6. Extract a substring\n");
    printf("7. Convert lowercase to uppercase\n");
    printf("8. Find the frequency of each character\n");
    printf("9. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            {
                char str[100];
                printf("Enter the string: ");
                scanf(" %[^\n]s", str);
                length(str);
                break;
            }
        case 2:
            {
                char str[100];
                printf("Enter the string: ");
                scanf(" %[^\n]s", str);
                reversestring(str);
                break;
            }
        case 3:
            {
                char str[100];
                printf("Enter the string: ");
                scanf(" %[^\n]s", str);
                count(str);
                break;
            }
        case 4:
            {
                char str[100];
                printf("Enter the string: ");
                scanf(" %[^\n]s", str);
                vowelconsonant(str);
                break;
            }
        case 5:
            {
                char str[100];
                printf("Enter the string: ");
                scanf(" %[^\n]s", str);
                bubbleSort(str);
                printf("The sorted string is: %s\n", str);
                break;
            }
        case 6:
            {
                char str[100];
                int start, length;
                printf("Enter the string: ");
                scanf(" %[^\n]s", str);
                printf("Enter the starting index of the substring: ");
                scanf("%d", &start);
                printf("Enter the length of the substring: ");
                scanf("%d", &length);
                substring(str, start, length);
                break;
            }
        case 7:{
            char str[100];
            printf("Enter the string: ");
            scanf(" %[^\n]s", str);
            lowertouper(str);
            break;
        }
        case 8:{
            char str[100];
            printf("Enter the string: ");
            scanf(" %[^\n]s", str);
            frequency(str);
            break;
        }
        case 9:
            return 0;
        default:
            printf("Invalid choice\n");
            break;
    }
    }
}-