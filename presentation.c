#include<stdio.h>
int main(){
    char name[60];
    int age;
    float height;
    printf("enter user name:\n");
    scanf("%s", &name);

    printf("Enter your Age:\n");
    scanf("%d", &age);

    printf("Enter your height\n");
    scanf("%f", &height);

    printf("Your name is %s \n",name);
    printf("Your age is %d \n",age);
    printf("Your height is %f \n",height);

    return 0;
}