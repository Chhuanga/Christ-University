//Find the length of the string without using functions

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
    for (i=0; i<strlen(str); i++)
    {
        printf("%c", str[strlen(str)-i-1]);
    }
}
//function to count the number of alphabets, digits and special characters in a string
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
int main()
{
    char str[100];
    int i;
    printf("Enter the string\n");
    scanf("%s", str);
    length(str);

}