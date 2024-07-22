// A program used to read user input digitally and output as binary values on LED system and 7-segment display
// Make also add timer functionality
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define STR_ADD "add" // Addition
#define STR_SUB "sub" // Subtract
#define STR_MUL "mul" // Multiply
#define STR_DIV "div" // Division
#define STR_SQR "sqr" // Square Root
#define STR_TMR "tmr" // Timer
float operationCheck(char* input) {
    int a, b;
    if (strcmp(input, STR_ADD) == 0) {
        printf("\nEnter the two values to be added: ");
        scanf("%d %d", &a, &b);
        // TODO: Output GPIO voltage pins to show input numbers on segment LEDs

        return ((float)a+b);
    } else if (strcmp(input, STR_SUB) == 0) {
        printf("\nEnter the two values to be subtracted: ");
        scanf("%d %d", &a, &b);
        // TODO: Output GPIO voltage pins to show input numbers on segment LEDs

        return ((float)a-b);
    } else if (strcmp(input, STR_MUL) == 0) {
        printf("\nEnter the two values to be multiplied: ");
        scanf("%d %d", &a, &b);
        // TODO: Output GPIO voltage pins to show input numbers on segment LEDs

        return ((float)a*b);
    } else if (strcmp(input, STR_DIV) == 0) {
        printf("\nEnter the two values to be divided: ");
        scanf("%d %d", &a, &b);
        if (b == 0) {
            printf("\n Second number cannot be divided by zero. Enter a new value for second number: ");
            scanf("%d", &b);
        }
        // TODO: Output GPIO voltage pins to show input numbers on segment LEDs

        return ((float)a/b);
    } else {
        printf("\nInvalid operation.\n");
    }
}

int main() {
    const char EXIT_STR[] = "No";
    const char SPECIAL_STR[] = "adv";
    char response[3];

    const char TIMER[] = "tmr";

    do {
        // Clear GPIO display

        printf("Enter the calculation to be done: ");
        char inputMode[3];
        scanf("%s", inputMode);
        if (strcmp(inputMode, SPECIAL_STR) == 0) {
            printf("Enter the special operation (tmr, NULL, NULL): ");
            scanf("%s", inputMode);
            if(strcmp(inputMode, TIMER) == 0) {
                printf("Enter the length of the timer: ");
                int timeLength;
                scanf("%d", &timeLength);
                for (int i = timeLength; i >= 0; i--) {
                    system("clear");
                    printf("Timer: %d\n", timeLength);
                }
            }
        } else {
            float temp = operationCheck(inputMode);
            if(temp == (int)temp) {
                printf("%d\n", (int)temp); // Prints as a integer value
            } else {
                printf("%f\n", temp);
            }
        }
        printf("Continue? (Yes: Save number | No: exit)\n");
        scanf("%3s", response);

    } while(strcmp(response, EXIT_STR));
    return 0;
}
