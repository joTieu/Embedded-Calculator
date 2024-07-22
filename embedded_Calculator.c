// A program used to read user input digitally and output as binary values on LED system and 7-segment display
// Make also add timer functionality
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
float operationCheck(int operationType) {
    switch (operationType) {
        case 1: // Addition
            printf("\nEnter the two values to be added: ");
            int a, b;
            scanf("%d %d", &a, &b);
            // TODO: Output voltage to show input numbers on segment LEDs

            return ((float)a+b);
            break;
        case 2: // Subtraction
            printf("\nEnter the two values to be subtracted: ");
            scanf("%d %d", &a, &b);
            // TODO: Output voltage to show input numbers on segment LEDs

            return ((float)a-b);
            break;
        case 3: // Multiplication
            printf("\nEnter the two values to be multiplied: ");
            scanf("%d %d", &a, &b);
            // TODO: Output voltage to show input numbers on segment LEDs

            return ((float)a*b);
            break;
        case 4: // Division
            printf("\nEnter the two values to be divided: ");
            scanf("%d %d", &a, &b);
            if (b == 0) {
                printf("\n Second number cannot be divided by zero. Enter a new value for second number: ");
                scanf("%d", &b);
            }
            // TODO: Output voltage to show input numbers on segment LEDs
            return ((float)a/b);
        default:
            printf("\nInvalid operation.\n");
    }
}

int main() {
    const char EXIT_STR[] = "No";
    char response[3];
    // List of functions

    do {
        printf("Enter the calculation to be done: ");
        int mathOperation;
        scanf("%d", &mathOperation);
        float temp = operationCheck(mathOperation);
        if(temp == (int)temp) {
            printf("%d\n", (int)temp); // Prints as a integer value
        } else {
            printf("%f\n", temp);
        }
        // printf("The result is: %d\n", operationCheck(mathOperation));
        
        printf("Continue? (Yes: Save number | No: exit)\n");
        scanf("%3s", response);

    } while(strcmp(response, EXIT_STR));
    return 0;
}
