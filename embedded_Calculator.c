// A program used to read user input digitally and output as binary values on LED system and 7-segment display
// Make also add timer functionality
#include <stdio.h>
#include <stdlib.h>

int main() {
    const char EXIT_STR[] = "No";
    char response[3];
    // List of functions
    float operationCheck(int operationType) {
        switch (operationType) {
            case 1: // Addition
                printf("\nEnter the two values to be added: ");
                int a, b;
                scanf("%d %d", &a, &b);
                // TODO: Output voltage to show input numbers on segment LEDs

                return (a+b);
                break;
            case 2: // Subtraction
                printf("\nEnter the two values to be subtracted: ");
                scanf("%d %d", &a, &b);
                // TODO: Output voltage to show input numbers on segment LEDs

                return (a-b);
                break;
            case 3: // Multiplication
                printf("\nEnter the two values to be multiplied: ");
                scanf("%d %d", &a, &b);
                // TODO: Output voltage to show input numbers on segment LEDs

                return (a*b);
                break;
            case 4: // Division
                printf("\nEnter the two values to be multiplied: ");
                scanf("%d %d", &a, &b);
                while (b == 0) {
                    printf("\n Second number cannot be divided by zero. Enter a new value for second number: ");
                    scanf("%d", &b);
                }
                // TODO: Output voltage to show input numbers on segment LEDs

                return (a/b);
                break;
            default:
                printf("\nInvalid operation.\n");
        }
    }


    do {
        printf("Enter the calculation to be done: ");
        int mathOperation;
        scanf("%d", &mathOperation);
        if(operationCheck(mathOperation) % 1 > 0) {
            printf("%f", operationCheck(mathOperation)); // Prints as a float value
        } else {
            printf("%d", (int)operationCheck(mathOperation));
        }
        
        printf("Continue? (Yes: Save number | No: exit)\n");
        scanf("%3s", response);

    } while(strcmp(response, EXIT_STR));

}