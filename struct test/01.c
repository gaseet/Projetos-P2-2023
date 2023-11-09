#include <stdio.h>
#include <string.h>

struct Person {
  char name[50];
  int age;
  float salary;
};

int main() {
    struct Person person1;

    printf("Enter the person's name: ");
    scanf("%s", person1.name);

    printf("Enter the person's age: ");
    scanf("%d", &person1.age);

    printf("Enter the person's salary: ");
    scanf("%f", &person1.salary);

    printf("Person's name: %s\n", person1.name);
    printf("Person's age: %d\n", person1.age);
    printf("Person's salary: $%.2f\n", person1.salary);

    return 0;
}
