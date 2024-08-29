 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct course
{
    char name[20];
    int duration;
    float fees;
};
void display(struct course *c)
{
    printf("Course Name: %s\n", c->name);
    printf("Course Duration: %d\n", c->duration);
    printf("Course Fees: %f\n", c->fees);
}
void input(struct course *c)
{
    printf("Enter Course Name: ");
    scanf("%s", c->name);
    printf("Enter Course Duration: ");
    scanf("%d", &c->duration);
    printf("Enter Course Fees: ");
    scanf("%f", &c->fees);
}
int main()
{
    struct course *c;
    c = (struct course *)malloc(sizeof(struct course));
    input(c);
    display(c);
    return 0;
}
