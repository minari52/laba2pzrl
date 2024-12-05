#include "calc.h"
#include <stdio.h>

int calculate(int operand1, char operator, int operand2) {
    switch (operator) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '%': 
            if (operand2 == 0) {
                printf("Error: Division by zero in modulo operation\n");
                return 0;
            }
            return operand1 % operand2;
        default:
            printf("Error: Invalid operator '%c'\n", operator);
            return 0;
    }
}

void decrypt_results(int *results, int count, int key, char *output) {
    for (int i = 0; i < count; i++) {
        output[i] = (char)(results[i] - key);
    }
    output[count] = '\0'; 
}
